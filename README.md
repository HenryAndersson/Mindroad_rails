# Diary

## Day 1
Plan for today is to be able to control the train through my computer/scripts

[z21 interface](https://www.z21.eu/en/products/z21/connections-z21#52-1271)  
[jmri for z21](https://www.jmri.org/help/en/html/hardware/roco/z21/index.shtml#RocoZ21Ethernet)

Downloaded for Linux: [JMRI 5.2](https://www.jmri.org/download/index.shtml#prod-rel) - Production release

Download Java:  
`sudo apt install default-jdk`  

https://www.z21.eu/en/products/z21start/connections-z21



In the menu, "select your DCC connection" i choose  
"System manufacturer" : "Roco"
"System connection" : "Roco Z21"
"ip" : "192.168.1.250"
"Connection Prefix" : "z"
"Connection Name" : "Z21"


I have no idea what i am doing, what is a "decoder" and which one do i choose?
The ip address of the z21 192.168.1.250 ||  MACaddress of A0:63:91:AF:B9:35
When i start decoder pro and try the locomotive, i don't know what DCCadress.
How do not know where to get this information.


On the [Manual](https://www.z21.eu/media/Kwc_Basic_DownloadTag_Component/47-1122-676-9476-7721-downloadTag/default/1ae598c7/1666183875/10810-multimaus-sv.pdf) for the controller. On page 29 pressing "Menu+1"
you can change the address for the controller/train? I don't really know.
But address 3 is the one that controls the train.


I was wrong, the Z21 device does not appear on the router, The ip above is 
the ip address and MACaddress for the router itself.

Now i think we can not use the z21 like i wanted. I think now you need to buy 
more stuff that's proprietary

Links:
[Youtube](https://www.youtube.com/watch?v=cCQGqAJGVwo)  ||
[Their website](https://www.roco.cc/ren/products/control/accessories/10814-z21-wlan-package.html)


## day 2

[Block detection with MERG](https://www.youtube.com/watch?v=BviPcd8-Vt0)  
[MERG canpan and cansol](https://www.youtube.com/watch?v=jGefnAzpq3w)  
[servo motor control](https://www.youtube.com/watch?v=fHAPXAcW9ZQ)  
[detection with DCC](https://www.youtube.com/watch?v=DtYzP5RgcsA)  
[Detection with sensor](https://www.youtube.com/watch?v=yDWI4ujtuIY)  
[Mimic panel](https://www.youtube.com/watch?v=-qEL5MGZXB4)  


## day 3

program servo on a aurduino nano
