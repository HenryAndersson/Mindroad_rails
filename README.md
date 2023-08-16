# Henrys sommarjobb!

Mycket av det jag skrev tog jag från vad Otto skrev på mindroads [MindChallenge git](https://github.com/MindRoadAB/MindChallenge-Example).  

## Här är många av mina källor som jag anvdände mig utav.
[Servo motor](https://components101.com/motors/servo-motor-basics-pinout-datasheet)
[servo schematics](https://www.electronics-lab.com/project/using-sg90-servo-motor-arduino/)  
[buttons schematics](https://roboindia.com/tutorials/arduino-nano-digital-input-push-button/)  
[nano schematics](https://www.teachmemicro.com/wp-content/uploads/2019/06/Arduino-Nano-pinout.jpg)  
[oled skrärm](https://thesolaruniverse.wordpress.com/2019/10/28/how-to-wire-and-run-a-128x32-oled-display-with-ssd1306-driver-with-an-arduino/)

## Hur kör man koden.
Ladda ner Arduino utvecklingsmiljön. Jag rekommenderar att ladda ner [Zip versionen](https://www.arduino.cc/en/software) för att utveckla.  
Alla bibliotek som behövs (och fler onödiga) finns i mappen ```Arduino-stuff/libraries```.  

I utvecklingsmiljön så kan du länka hela mappen till IDEn så du slipper att behöva länka alla individuellt.  
Om du så vill så kan du genom att gå till ```Sketch -> Include Library -> Add .ZIP Library```  

Du måste ha rätt inställningar till att kunna ladda upp koden och köra den.  
I ```Tools``` menyn kolla att

	- Board: Arduino Nano
	- Processor:ATmega328P (Old Bootloader)

Jag hade problem med att IDEn inte kunde hitta arduinon genom usb. Jag löste det genom  
att ta bort brltty från min dator, vill du inte göra det så får du hitta en annan lösning.  

Jag tog bort den med: ```sudo apt purge brltty```

## Hur koden är uppdelad.
Som i alla arduino så finns det ```void setup``` och ```void loop```  
```void setup``` körs en gång vid start av arduinon och ```void loop``` loopar varje gång den är klar.

Levebrödet med koden ligger i ```void rotate_servor()```  

### Den lever i 4 konstanter och 4 variabler.
```
#define ANGLE_ON 70
#define ANGLE_OFF 0

#define ANGLE_MOVE 3 //degres
#define internalTimer_servo 30  //millisecond
```

```ANGLE_ON``` betyder max värdet för servon när den är "på".
```ANGLE_OFF``` betyder minimum värdet för servon när den är "av".

```ANGLE_MOVE``` betyder hur mycket servon ska röra sig efter varje tidsskillnad.
```internalTimer_servo``` definierar tidsskillnad.

## 3D modellerna.

## Vad sm kan förbättras.
