Dieses Beispiel zeigt ein Design zur Erreichung des OCP f�r
die Varianzen des Verhaltens mit dem 
State Pattern f�r Ampel und der 
Flyweight Factory f�r States
und die Varianzen des Kommunikationsprotokolls mit der Hardware
mit einer Abstract Model Factory die 
die verschiedenen Implementierungen von Lampen (IP, CANBUS)
erzeugt 

Das OCP bzgl. dieser Varianzen ist vollst�ndig erreicht.

Anpassungen an den neuen Standard bzgl. Smartpointer
wurden in MakrosStdMigration.h realisiert

Die Kreuzung und der Sensor sind als eigenst�ndige Komponenten 
in Libraries ausgelagert. VS_KreuzungLib, VS_SensorLib