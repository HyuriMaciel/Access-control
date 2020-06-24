# About :bulb:

This paper presents an embedded system for access control in restricted area through the integration of two authentication strategies: facial recognition and RFID TAGs. Once that face recognition, in an embedded system, is susceptible to failures and RFIDs TAGs can be used by other users, the integration of these two solutions aims to increase the robustness of access control system.  This system can be easily deployed into enterprise environments, meetings and offices rooms. Additionally the system proposed does not require the need to have the system connected to the Internet. Through the evaluations we observed an acceptable execution time and better robustness in access control system, even using simple techniques of face recognition.

![schematic access control](https://github.com/HyuriMaciel/Access-control/blob/master/controle_acesso.png)




For more information, see the articles (Results) below.

## Folders Organization :file_folder:
 - :open_file_folder: [facedetec](https://github.com/HyuriMaciel/Access-control/tree/master/facedetec): Contains the codes that perform facial detection and recognition, the codes were implemented in a BeagleBone Black microcontroller, using the OpenCV library and C ++ language.
 - :open_file_folder: [rfidControl](https://github.com/HyuriMaciel/Access-control/tree/master/rfidControl) Contains the codes that perform the access control by means of an Arduino UNO microcontroller using an RFID reader and a magnetic lock to sign the door lock.

## Technologies used :minidisc:
 - Linguage: C, C++.
 - librarys: OpenCV ...
 
## Components the system :hammer:

- Control Access

|Item|Quant|Especification|
| -------- | -------- | -------- |
|Arduino UNO| 1 |[Arduino](https://www.arduino.cc/)|
|Leito RFID|1|Rfid Mfrc522|
|Display|1|[Datasheet](https://img.filipeflop.com/files/download/Datasheet_Display_16x2.pdf)|
|Rele 5VDC|1|[Datasheet](https://img.filipeflop.com/files/download/Datasheet_Rele_5V.pdf)|
|Trafo|1|Travo 220 Vac ~ 12Vac|
|Potenciometro|1|10k|

- Recagnition Face

|Item|Quant|Especification|
| -------- | -------- | -------- |
|BeagleBone Black| 1 | [BeagleBone](https://beagleboard.org/black)|
|Camera video|1|D-link- HD  Wire-less N Cube|


## Results :notebook:
 - Puplications:
      - MACIEL, HYURI S.; CARDOSO, ISADORA ; SILVA, DAVID F. ; DO NASCIMENTO, CLOVIS G. M. ; RAMOS, HEITOR S. ; RODRIGUES, JOEL J. P. C. ; AQUINO, ANDRE L. L . An           embedded access control system for restricted areas in smart buildings. In: 2016 International Multidisciplinary Conference on Computer and Energy Science           (SpliTech), 2016, Split. 2016 International Multidisciplinary Conference on Computer and Energy Science (SpliTech), 2016. p. 1.[DOI](10.1109/SpliTech.2016.7555926)
      - MACIEL, H. S.; SILVA, D. F. ; NASCIMENTO, C. G. M. ; AQUINO, A. L. L. . Sistema embarcado para o controle de acesso em áreas restritas de prédios inteligentes. In: VIII Simpósio Brasileiro de Computação Ubíqua e Pervasiva (SBCUP), 2016, Porto Alegre. Simpósio Brasileiro de Computação Ubíqua e Pervasiva, 2016.

 
 - Awards
    - Academic Excellence "Locating and tracking people in business buildings", granted by the Federal University of Alagoas in 2016.


## License :lock_with_ink_pen:

This project is under the MIT license [INFO](https://github.com/HyuriMaciel/Access-control/pull/1/commits/90944f09308aeea4f613b6cd8aec4fcd8989c5ba)
