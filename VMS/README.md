## Video Management System(VMS)
Here is the database design (excluding views) with all foreign keys connected:
![](Media/Database_design.png)

## Description

### Installer: <br/>
Create a Installer for VMS.<br/>
![](Media/Installer.png)

## Major Tabs
There are total 7 tabs and each tab has different role <br/>
1. Home = User can watch streaming <br/>
2. Record = User can watch recorded video <br/>
3. SmartSearch = User can search specific objects(i.e red backpack, blue SUV, truck etc.) for any reason <br/>
4. Event = User can search irreular event (i.e covering CCTV from unknown, unplanned CCTV movement etc.) <br/>
5. SmartTraffic = Users can grasp the current traffic situation at a glance <br/>
6. SmartSafety = Users can access the video which CCTV automatically storing incident video using artificial intelligence technology <br/>
7. LiveMap = A user can grasp the location and information of CCTV through a real-time map using GIS </br>
![](Media/major_tabs.png)

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

### Controll PTZ CCTV: <br/>
If the selected CCTV's type is PTZ camera, User can zoom & move the direction of cctv by using PTZ Controller<br/>
User can also use stored directions.<br/>
![](Media/hamburger_menu.png)
![](Media/ptz_controller.png)

### Checking The Location: <br/>
User can check the location of all cctv.<br/>
By using Kakao GIS API, it is more easy to find out where the cctv is.<br/>
User can zoom in & out, move up & down & right & left the map.<br/>
![](Media/cctv_location.png)

### PopUp Location: <br/>
It is possible to make PopUp window for live map.<br/>
![](Media/PopUp.png)

### Live CCTV On Map: <br/>
Whenever the user hover the mouse on the CCTV icon, the program will show the live.<br/>
![](Media/live_cctv.png)

### All CCTVs In One Map: <br/>
In LiveMap session, user can find all the CCTVs just in one map.<br/>
![](Media/live_map.png)

### All Informations about the program: <br/>
User can access the information about 'Log History' 'System Monitoring' 'Version Status'.<br/>
![](Media/log_history.png)
![](Media/system_monitoring.png)
![](Media/version_status.png)
