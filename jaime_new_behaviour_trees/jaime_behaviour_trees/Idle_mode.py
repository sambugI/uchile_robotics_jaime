import py_trees

from behaviours.DetectPerson import DetectPerson
from behaviours.DetectFace import DetectFace
from behaviours.TrackFaceTablet import TrackFaceTablet
from behaviours.WaitForModeSelection import WaitForModeSelection


def create_idle_tree(node):

    #################################################
    # Detección de persona
    #################################################

    detect_person = DetectPerson(node)

    #################################################
    # Detección de rostro
    #################################################

    detect_face = DetectFace(node)

    #################################################
    # Seguimiento de rostro con tablet
    #################################################

    track_face = TrackFaceTablet(node)

    #################################################
    # Ciclo de percepción
    #################################################

    perception = py_trees.composites.Sequence(
        name="PersonFaceTracking",
        memory=True
    )

    perception.add_children([
        detect_person,
        detect_face,
        track_face
    ])

    #################################################
    # Reinicio de percepción
    #
    # Si se pierde el rostro o falla el tracking,
    # se vuelve a buscar una persona.
    #################################################

    perception_loop = py_trees.decorators.Retry(
        child=perception,
        num_failures=py_trees.common.Unlimited
    )

    #################################################
    # Selección de modo mediante tablet
    #################################################

    mode_selection = WaitForModeSelection(node)

    #################################################
    # Idle
    #
    # Percepción y selección de modo funcionan
    # simultáneamente.
    #
    # Idle termina cuando se selecciona un modo.
    #################################################

    idle = py_trees.composites.Parallel(
        name="Idle",
        policy=py_trees.common.ParallelPolicy.SuccessOnOne()
    )

    idle.add_children([
        perception_loop,
        mode_selection
    ])

    return idle