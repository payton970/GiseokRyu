## Video Management System(VMS)
Here is the database design (excluding views) with all foreign keys connected:
![](Media/Database_design.png)

## Description

### Installer: <br/>
Create a Installer for VMS.<br/>
![](Media/Installer.png)

### Default Page: <br/>
This is the default page when progrom open.<br/>
At the left side, it contains all the cctv which are connected to the server. <br/>
User can drag & drop or double clicking the layout icon to watch live streams. <br/>
![](Media/Default.png)

### Event Alert: <br/>
At the left bottom side, if there are any issues occure, there will be warning alerts.<br/>
![](Media/event_alert.png)


### Watch CCTV: <br/>
Each cell will contain each CCTV.<br/>
User can custom the layout up to 8X8(total 64 CCTV) in one layout.<br/>
Also, user can have multiple tabs in Streaming section.<br/>
![](Media/cctv_controll.png)

### Checking the location: <br/>
User can check the location of all cctv.<br/>
By using Kakao GIS API, it is more easy to find out where the cctv is.<br/>
User can zoom in & out, move up & down & right & left the map.<br/>
![](Media/cctv_location.png)

### PopUp location: <br/>
It is possible to make PopUp window for live map.<br/>
![](Media/PopUp.png)

### Live CCTV on Map: <br/>
Whenever the user hover the mouse on the CCTV icon, the program will show the live.<br/>
![](Media/live_cctv.png)
