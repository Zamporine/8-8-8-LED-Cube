# 8-8-8-LED-Cube
The basic codes by CHR, with all animations running on Arduino.
How to use these code and get your UNO connected LED cube running.
What you have to do to get you cube working:-

Basic Algo- 

1. Compile main.c along with other .c files you downloaded
2. Place header files in appropriate directories
3. Compile 
4. Link different .o files (object files obtained after compilation) 
>>Uploading is also tricky!
There's a li'l arduino hack !!
5. Upload .hex file generated
6. Upload .eep file generated

Arduino UNO:-

1. Copy-Past all the .h & .c files in a NEW folder (name it anything)
3. Cut-Paste that NEW folder in C:\Users\<name>\Documents\Arduino\libraries
4. Open Arduino IDE (in different directory then above)
5. File->Preferences
6. Check both options against "Show verbose output during:" , click OK (this step will just just show you what arduino exactly does in the error log (black area below editor).
7. Sketch-> Include Library
8. Select the  library you recently created. (your created library will be automatically added to top of the arduino sketch)
9. Open the .ino file, and, Setp10->
10. HIT VERIFY Button "NOT" Upload Button (even if you hit Upload button, not an issue, but it will directly upload the code to arduino, which you can naturally eras anytime you wish!)
11. if everything goes well, you'll have .hex and .eep files generated "somewhere" :p
>>>Now this is the best part, ;) 
12. Maximise your arduinoIDE, and in the black window (called error console) carefully watch out for the location of the .hex file
 -> most probably, it'll be in the temp folder , but look out for complete path
13. Hope you've installed AVRDude GUI
14. Open AVRDude GUI, in presets, select Arduino UNO (Atmega 328P)
15. In Flash, click on the button next to the entry field (so as to open flash file)
16. Navigate to the location of .hex file, click OK
    -> Click go, wait for some time
17. In,  EEPROM. click on the button nect to the field, navigate to the same location as just above, BUT, this time, click .eep file (Check carefully)
18. Click go , wait for some time


