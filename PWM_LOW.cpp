//Control PWM Lento
// (c) José Angel Moneo Fedz
//utiliza la salidas digitales digitales para realizar un PWM de baja frecuencia
// que pueda usarse para control de grandes cargas o cilos muy largos, o intermitencias.

#include "PWM_LOW.h"
void PWM_LOW::init(){pinMode(_output, OUTPUT);}
void PWM_LOW::init(int out) {_output=out; init(); }
uint32_t  PWM_LOW::get_Dutty() {return Dutty;}  //lee el dutty asignado a una salida
uint32_t  PWM_LOW::get_Period() {return PeriodoBase;}  //lee la frecuencia base programada a una salida
boolean PWM_LOW::is_on() {return Activa;}  //lee el estado programada a una salida
void PWM_LOW::set_Dutty(int d ) {Dutty=d; PeriodoDutty=Dutty*PeriodoBase/100; }   //almacena el Dutty deseado de una salida. Se pasa el % y se convierte en ms sobre frecuenca base
void PWM_LOW::set_Period(int f ) { PeriodoBase=f; PeriodoDutty=Dutty*PeriodoBase/100;  }   //almacena el Dutty deseado de una salida. Se debe dar en ms
void PWM_LOW::on(){Activa=true;} //Permite activar el modo Power_PWM una salida 
void PWM_LOW::off(){Activa=false;} //Permite activar el modo Power_PWM una salida 

void PWM_LOW::run()  { 
                     if(Activa) 
                         { //ejecuta el modo PowerPWM de las salidas activadas
                         if( (millis()-T)< PeriodoDutty) digitalWrite(_output,true);
                         else     digitalWrite(_output,false);  
                         if ( (millis()-T)> PeriodoBase) T=millis();     
             }    

}
