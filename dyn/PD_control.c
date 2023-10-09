#include <stdio.h>
#include <math.h>

int UTA_ID = 1001830469;

// keeps track of previous theta_dot
double ref = 0;

// @brief constants in the robotic arm, found by doing looped trials
// until system became critically damped
double Gravity = 4.280720;
double Friction = .370800;
double Inertia = 0.105306;


/**
 * @param theta - angle of rotation for arm
 * @param theta_dot - rotational velocity of arm
 * @param theta_ref - angle used when changing slider in simulation
 * @param theta_dot_ref - rotational velocity used when manually changing velocity in simulation
*/
double PD_control(double theta, double theta_dot, double theta_ref, double theta_dot_ref) 
{
  // Input torque
  double T = 1;

  // T1 = G * cos(theta) = gravity torque
  double torque1 = Gravity * cos(theta); 
  
  // T2 = B * (theta*) = frictional torque
  double torque2 = Friction * theta_dot;  
  
  // theta** = (theta*_final - theta*_initial) * (1/500) = acceleration
  double acceleration = ((theta_dot-ref)*500.00000);

  // T3 = I * (theta**)
  double torque3 = Inertia * acceleration;

  // Output torque
  printf("Total Torque = %lf | I * theta** = %lf | B * theta* = %lf | G(theta) = %lf |\n", torque3 + torque2 + torque1, torque1, torque2, torque3);
  ref = theta_dot;

  // Damping variables
  double kp = 5;
  double kv = 2 * sqrt(kp);

  // Control torque equation
  double control_torque = (- kp * (theta - theta_ref) - kv * (theta_dot)) + torque1 + torque2;

  return control_torque;
}


