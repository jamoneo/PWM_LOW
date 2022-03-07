# PWM_LOW
Crea un PWM de baja Frecuencia, que puede ser usado como control de cargas con alta inercia térmica, o como intermitente configurable.

run() debe de estar ejecutandose en LOOP, para que se actualice.
Se puede incializar la salida asociada en la creación de la clase con PWM_LOW MyPWM(LED_BUILTIN) 
o hacerlo durente el setup con init(LED_BUILTIN)


    void init();
    void init(int output) ; //Inicializa la clase para una salida determinada
    uint32_t  get_Dutty(); //lee el dutty asignado a una salida
    uint32_t  get_Period(); //lee la frecuencia base programada a una salida
    boolean is_on() ; //lee el estado programada a una salida
    void set_Dutty(int d );  //almacena el Dutty deseado de una salida. Se pasa el % y se convierte en ms
    void set_Period(int f ); //almacena el Dutty deseado de una salida. Se debe dar en ms
    void on(); //Permite activar  el modo Power_PWM una salida
    void off(); //Permite desactivar  el modo Power_PWM una salida 
    void run();  //ejecución ciclo. Debe incluirse en LOOP
