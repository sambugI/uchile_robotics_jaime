import sympy as sym
from sympy import Matrix, atan2, sqrt, asin
import numpy as np

def transform_matrix_x(qx, x=0, y=0, z=0):
    return sym.Matrix([
        [1, 0,             0,              x],
        [0, sym.cos(qx), -sym.sin(qx),     y],
        [0, sym.sin(qx),  sym.cos(qx),     z],
        [0, 0,             0,              1]
    ])

def transform_matrix_y(qy, x=0, y=0, z=0):
    return sym.Matrix([
        [ sym.cos(qy), 0, sym.sin(qy), x],
        [ 0,           1, 0,           y],
        [-sym.sin(qy), 0, sym.cos(qy), z],
        [ 0,           0, 0,           1]
    ])

def transform_matrix_z(qz, x=0, y=0, z=0):
    return sym.Matrix([
        [sym.cos(qz), -sym.sin(qz), 0, x],
        [sym.sin(qz),  sym.cos(qz), 0, y],
        [0,            0,           1, z],
        [0,            0,           0, 1]
    ])

def fk_solution():

    sym.init_printing(use_unicode=True)
    
    # TODO: use these symbols for your solution
    theta_1, theta_2, theta_3 = sym.symbols("theta_1 theta_2 theta_3")


    T1 = transform_matrix_y(qy=theta_1,x=-0.23314,y=0.0,z=0.844018) 

    T2 = T1 @ transform_matrix_y(qy=theta_1,x=-0.02378,y=0.0,z=0.095774)
        
    T3 = T2 @ transform_matrix_y(qy=theta_2,x=0.043667,y=0.0,z=0.203248) 

    T4 = T3 @ transform_matrix_y(qy=theta_2,x=0.037837,y=0.0,z=0.09114)

    T5 = T4 @ transform_matrix_y(qy=theta_3,x=0.1328727,y=0.0,z=0.15276)

    t_0eef = T5 @ transform_matrix_x(qx=0,x=0.0549564,y=0.0,z=0.0) 




    params = theta_1, theta_2, theta_3

    R_0eef = t_0eef[:3, :3]

    r11, r12, r13 = R_0eef[0, :]
    r21, r22, r23 = R_0eef[1, :]
    r31, r32, r33 = R_0eef[2, :]


    roll = atan2(r32, r33)
    pitch = -asin(r31)
    yaw = atan2(r21, r11)

    # Vector de orientación
    orientation = Matrix([roll, pitch, yaw])
    orientation_jacobian = orientation.jacobian(params)


    # POSICIÓN
    tf_pos = t_0eef @ Matrix([0, 0, 0, 1])
    pos_jacobian = tf_pos[:3, :].jacobian(params)

    # Jacobiano completo
    jacobian = Matrix.vstack(pos_jacobian, orientation_jacobian)

    jac_function = sym.lambdify(params, jacobian, modules='numpy')
    fk_function = sym.lambdify(params, t_0eef, modules='numpy')
    pos_jac_function = sym.lambdify(params, pos_jacobian, modules='numpy')
    return jac_function, fk_function, pos_jac_function







