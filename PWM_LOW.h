//Control PWM Lento
// (c) José Angel Moneo Fedz
//utiliza la salidas digitales digitales para realizar un PWM de baja frecuencia
// que pueda usarse para control de grandes cargas o cilos muy largos, o intermitencias.

#pragma once

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif


class PWM_LOW
{
private:
  int _output;
  uint32_t PeriodoBase=1000; //Periodo base 1Hz, redefinible
  uint32_t PeriodoDutty=0; //Periodo base 1Hz, redefinible
  uint32_t  Dutty=0; // % de PWM
  uint32_t  T=0; // Tiempos de cada PWM
  boolean Activa=false; // estado de activación en modo PWM de la salida

public:
  PWM_LOW(){};
  PWM_LOW(int out){_output=out;};
  void init();
  void init(int output) ; //Inicializa la clase para una salida determinada
  uint32_t  get_Dutty(); //lee el dutty asignado a una salida
  uint32_t  get_Period(); //lee la frecuencia base programada a una salida
  boolean is_on() ; //lee el estado programada a una salida
  void set_Dutty(int d );  //almacena el Dutty deseado de una salida. Se pasa el % y se convierte en ms
  void set_Period(int f ); //almacena el Dutty deseado de una salida. Se debe dar en ms
  void on(); //Permite activar  el modo Power_PWM una salida
  void off(); //Permite desactivar  el modo Power_PWM una salida 
  void run();  
};
