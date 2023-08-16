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

Levebrödet med koden ligger i ```void rotate_servo()```  

### rotate_servo() lever i 4 konstanter och 4 variabler.
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
Tillsammans så kan dessa två avgöra hur lång tid det tar servon att göra en uppgift.  

För att ```rotate_servo()``` ska funka så måste arduino exekvera koden varje klockcykel.
Funktionen fungerar på 6 variabler
```
Servo_pin
sev
sev_av
servo_angle
StartTimer_servo

CurrentTime
```

```Servo_pin``` är bara vilken servo du vill rotera på. Utifrån servo biblioteket 
så skaper du en servo objekt ```Servo NAMN``` sen kopplar du objektet med en digital pin.  
``` Servo NAMN ``` och sen i ```void setup()``` har du 2 rader,  
```
pinMode(DIGITAL_PIN, OUTPUT);  
NAMN.attach(DIGITAL_PIN, 530, 2600);  
```

Som sagt så måste rotate_servo läsas i ```void loop()``` varje gång för att få den att funka.

```Servo_pin``` som sagt är ett objekt som Funktionen refererar till att ändra sig.  
```sev``` Är en bool då TRUE rör den sig mot "på" och FALSE rör den sig mot "av"  
```sev_av``` betyder servo available, Jag har andvänt mig utav det så att det inte går  
att trycka på knapparna tills den är klar.  
```servo_angle``` är den nuvarande vinkeln servon är i stunden.  
```StartTimer_servo``` ser till att det blir en tidsskillnaden.  

I ```void loop()``` så måste raden ```currentTime = millis();``` finnas för att funktionen ska funka.  

### Skärm
Att programmera på skärmen krävs 2 bibliotek och några rader kod.  
```
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
```

I ```void setup()``` så behövs
```
  display.clearDisplay();
  display.display();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.cp437(true);
```

Innan varje ändring så ska ```display.clearDisplay()``` köras och efter ändringen så ska ```display.display()``` köras.
Exempelvis:
```
display.clearDisplay();
coolguyfighting(state);
display.display();
```


## 3D modellerna.

## Vad sm kan förbättras.
