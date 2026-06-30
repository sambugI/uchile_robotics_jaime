import py_trees

# Se debe implementar health_node que verifique que corren correctamente todos los nodos.
class InitializeRobot(py_trees.behaviour.Behaviour):

    def __init__(self):
        super().__init__("InitializeRobot")

        self.initialized = False

    def initialise(self):

        self.initialized = False

        # Inicializar controladores
        # verificar nodos
        # verificar sensores

    def update(self):

        if self.initialized:
            return py_trees.common.Status.SUCCESS

        # lógica real aquí

        self.initialized = True

        return py_trees.common.Status.SUCCESS
    



    