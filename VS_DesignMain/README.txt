Dieses Beispiel zeigt ein Design zur Erreichung des OCP für
die Varianzen des Verhaltens mit dem 
State Pattern für Ampel und der 
Flyweight Factory für States
und die Varianzen des Kommunikationsprotokolls mit der Hardware
mit einer Abstract Model Factory die 
die verschiedenen Implementierungen von Lampen (IP, CANBUS)
erzeugt 

Das OCP bzgl. dieser Varianzen ist vollständig erreicht.

Anpassungen an den neuen Standard bzgl. Smartpointer
wurden in MakrosStdMigration.h realisiert

Die Kreuzung und der Sensor sind als eigenständige Komponenten 
in Libraries ausgelagert. VS_KreuzungLib, VS_SensorLib