# SPI (Serial Peripheral Interface)
 - Method of fast communication (20Mhz)
 - Uses lots of pins but also uses a bus which helps
   - Same wires can be connected to several different devices
   - One additional pin used to tell which device you are talking to
## Master -> Slave
SCK -> SCK

SDO -> SDI

SDI <- SDO

CS -> CS

