program TireMonitor;

uses
  System.StartUpCopy,
  FMX.Forms,
  BLETireMonitor in 'BLETireMonitor.pas' {Form1};

{$R *.res}

begin
  Application.Initialize;
  Application.FormFactor.Orientations := [TFormOrientation.Landscape, TFormOrientation.InvertedLandscape];
  Application.CreateForm(TForm1, Form1);
  Application.Run;
end.
