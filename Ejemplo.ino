/*Intermitente variable
 * Este ejemplo genera un intermitente de frecuencia fina 1hz cuya relacción entre la fase encendido
 * y de apagado va variando cada 2 segundos, pasan do de 10% encendido al 100% encendido
 */


#include "PWM_LOW.h"

#define LED_BUILTIN 2
//PWM_LOW PWM;
PWM_LOW PWM(LED_BUILTIN);

void setup() {
 Serial.begin(115200);
//PWM.init(LED_BUILTIN);
PWM.init();
PWM.set_Dutty(0);
PWM.set_Period(1000);
PWM.on();


}

void loop() {
long t=0;
t=millis();
while(millis()<(t+2000)) PWM.run();
PWM.set_Dutty(PWM.get_Dutty()+5);
if(PWM.get_Dutty()==100)PWM.set_Dutty(0);
}
