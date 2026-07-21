import py_trees

import rclpy
from rclpy.node import Node

from jaime_interfaces.srv import IsReady


class InitializeRobot(py_trees.behaviour.Behaviour):

    def __init__(self, node):

        super().__init__("InitializeRobot")


        self.node = node


        self.initialized = False


        # Clientes de servicios

        self.services = {

            "basic":
                self.node.create_client(
                    IsReady,
                    "/basic/is_ready"
                ),

            "localization":
                self.node.create_client(
                    IsReady,
                    "/localization/is_ready"
                ),

            "navigation":
                self.node.create_client(
                    IsReady,
                    "/navigation/is_ready"
                ),

            "tablet":
                self.node.create_client(
                    IsReady,
                    "/tablet/is_ready"
                ),

            "manipulation":
                self.node.create_client(
                    IsReady,
                    "/manipulation/is_ready"
                ),

            "perception":
                self.node.create_client(
                    IsReady,
                    "/perception/is_ready"
                ),
        }

        self.pending_calls = {}



    def initialise(self):

        self.initialized = False

        self.pending_calls = {}



    def update(self):


        # Si ya terminó

        if self.initialized:

            return py_trees.common.Status.SUCCESS



        all_ready = True



        for name, client in self.services.items():


            # Verificar que existe el servicio

            if not client.service_is_ready():

                self.node.get_logger().warn(
                    f"Waiting for {name} manager"
                )

                all_ready = False

                continue



            # Si todavía no se hizo la consulta

            if name not in self.pending_calls:


                request = IsReady.Request()


                future = client.call_async(request)


                self.pending_calls[name] = future


                all_ready = False


                continue



            future = self.pending_calls[name]



            # Esperar respuesta

            if not future.done():

                all_ready = False

                continue



            response = future.result()



            if response is None:

                self.node.get_logger().error(
                    f"{name} service failed"
                )

                return py_trees.common.Status.FAILURE



            if not response.ready:


                self.node.get_logger().warn(
                    f"{name}: {response.message}"
                )


                all_ready = False



        if all_ready:


            self.node.get_logger().info(
                "Robot initialized successfully"
            )


            self.initialized = True


            return py_trees.common.Status.SUCCESS



        return py_trees.common.Status.RUNNING
    