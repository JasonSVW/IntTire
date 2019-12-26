unit BLETireMonitor;

interface

uses
  System.SysUtils, System.Types, System.UITypes, System.Classes, System.Variants,
  FMX.Types, FMX.Controls, FMX.Forms, FMX.Graphics, FMX.Dialogs, FMX.Layouts,
  FMX.Controls.Presentation, FMX.StdCtrls, FMX.Objects, System.ImageList,
  FMX.ImgList, FMX.ExtCtrls, FMXTee.Engine, FMXTee.Series, FMXTee.Procs,
  FMXTee.Chart, FMX.ListBox, System.Bluetooth, System.Bluetooth.Components,
  FMX.Ani, FMX.Platform.Android, FMX.Edit, FMX.ScrollBox, FMX.Memo;

type
  TServerConnectionTH = class(TThread)
  private
    { Private declarations }
    FSocket: TBluetoothSocket;
  protected
    procedure Execute; override;
  public
    { Public declarations }
    constructor Create(ACreateSuspended: Boolean);
    destructor Destroy; override;
  end;

type
    TWarining = (PnTn, PnTh, PsTn, PsTh, PfTn, PfTh); 
 
type
  TTireStatus = class
    FLTireTemp: Integer;
	FLTirePres: Integer;
	FRTireTemp: Integer;
	FRTirePres: Integer;
	RLTireTemp: Integer;
	RLTirePres: Integer;
	RRTireTemp: Integer;
	RRTirePres: Integer;
end;
     	 

type
  TForm1 = class(TForm)
    GridPanelLayoutMain: TGridPanelLayout;
    ImageDoubleRed: TImage;
    ImageTireRed: TImage;
    LayoutWarningLight: TLayout;
    BtnSet: TButton;
    LayoutVehicle: TLayout;
    ImageVehicle: TImage;
    GridPanelLayout2: TGridPanelLayout;
    RectFLTireRed: TRectangle;
    LayoutFL: TLayout;
    RectFLTireYellow: TRectangle;
    LayoutFR: TLayout;
    RectFRTireRed: TRectangle;
    RectFRTireYello: TRectangle;
    LayoutRL: TLayout;
    RectRLTireRed: TRectangle;
    RectRLTireYellow: TRectangle;
    LayoutRR: TLayout;
    RectRRTireRed: TRectangle;
    RectRRTireYellow: TRectangle;
    ImageTireYellow: TImage;
    ImageFLTire: TImage;
    LblFLTire: TLabel;
    ImageFRTire: TImage;
    LblFRTire: TLabel;
    ImageRLTire: TImage;
    LblRLTire: TLabel;
    ImageRRTire: TImage;
    LblRRTire: TLabel;
    ImageRedYellow: TImage;
    ChartFLTireLife: TChart;
    SeriesFLTireLife: TPieSeries;
    ImageFLTireLife: TImage;
    ImageRLTireLife: TImage;
    ChartRLTireLife: TChart;
    SeriesRLTireLife: TPieSeries;
    ImageFRTireLife: TImage;
    ChartFRTireLife: TChart;
    SeriesFRTireLife: TPieSeries;
    ImageRRTireLife: TImage;
    ChartRRTireLife: TChart;
    SeriesRRTireLife: TPieSeries;
    LblFLTireLife: TLabel;
    LblFRTireLife: TLabel;
    LblRLTireLife: TLabel;
    LblRRTireLife: TLabel;
    RectHide: TRectangle;
    BrushHide: TBrushObject;
    RectBLESetDialog: TRectangle;
    GridPanelLayoutSet: TGridPanelLayout;
    LblSetTitle: TLabel;
    ComboboxPaired: TComboBox;
    LblBLEInfo: TLabel;
    BtnOpenService: TButton;
    BtnCloseService: TButton;
    RectRedWarning: TRectangle;
    GridPanelLayoutRed: TGridPanelLayout;
    ImageRedTire: TImage;
    ImageRedWarning: TImage;
    RectYellowWarning: TRectangle;
    GridPanelLayoutYellow: TGridPanelLayout;
    ImageYellowTire: TImage;
    ImageYellowWarning: TImage;
    LblFastWarning: TLabel;
    CBtnRedConfirm: TCornerButton;
    ImageRedBtn: TImage;
    LblSlowWarning: TLabel;
    CBtnYellowComfirm: TCornerButton;
    ImageTireLogo: TImage;
    LblTitle: TLabel;
    FloatAnimation1: TFloatAnimation;
    GridPanelLayoutTitle: TGridPanelLayout;
    RectAppSet: TRectangle;
    GridPanelLayoutSetBtn: TGridPanelLayout;
    BtnCloseApp: TButton;
    BtnBLESet: TButton;
    BtnHistory: TButton;
    BtnDebug: TButton;
    StyleBook1: TStyleBook;
    BtnInfo: TButton;
    RectHistory: TRectangle;
    GridPanelLayoutStat: TGridPanelLayout;
    BtnHistoryBack: TButton;
    GridPanelLayoutTitle2: TGridPanelLayout;
    LblTitle2: TLabel;
    ImageLogo2: TImage;
    FloatAnimation2: TFloatAnimation;
    ChartTirePres: TChart;
    BarSeriesTirePres: TBarSeries;
    LblTireTmptHistory: TLabel;
    LblTirePresHistory: TLabel;
    ChartTireTmpt: TChart;
    BarSeriesTireTemp: TBarSeries;
    RectDebug: TRectangle;
    GridPanelLayoutDebug: TGridPanelLayout;
    LblDebugTitle: TLabel;
    BtnSender: TButton;
    BtnClearMemo: TButton;
    BtnDebugClose: TButton;
    DisplayR: TMemo;
    LblSender: TLabel;
    EditSender: TEdit;
    RectSoftwareInfo: TRectangle;
    GridPanelLayoutInfo: TGridPanelLayout;
    LblInfoTitle: TLabel;
    BtnInfoClose: TButton;
    LblInfoDetail: TLabel;
    BtnCloseBLESet: TButton;
    procedure BtnSetClick(Sender: TObject);
    procedure BtnOpenServiceClick(Sender: TObject);
    procedure BtnCloseServiceClick(Sender: TObject);
    procedure BtnCloseBLESetClick(Sender: TObject);
    procedure CBtnRedConfirmClick(Sender: TObject);
    procedure CBtnYellowComfirmClick(Sender: TObject);
    procedure FormShow(Sender: TObject);
    function ManagerConnected: Boolean;
    procedure FormCloseQuery(Sender: TObject; var CanClose: Boolean);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure BtnBLESetClick(Sender: TObject);
    procedure BtnCloseAppClick(Sender: TObject);
    procedure BtnHistoryBackClick(Sender: TObject);
    procedure BtnHistoryClick(Sender: TObject);
    procedure BtnInfoCloseClick(Sender: TObject);
    procedure BtnDebugClick(Sender: TObject);
    procedure BtnInfoClick(Sender: TObject);
    procedure BtnDebugCloseClick(Sender: TObject);
    procedure RectHideClick(Sender: TObject);
  private
    { Private declarations }
    FBluetoothManager: TBluetoothManager;
    FDiscoverDevices: TBluetoothDeviceList;
    FPairedDevices: TBluetoothDeviceList;
    FAdapter: TBluetoothAdapter;
    FSocket: TBluetoothSocket;
    ItemIndex: Integer;
    ServerConnectionTH: TServerConnectionTH;
    procedure PairedDevices;
    procedure BLEMonitorServiceOn;
  public
    { Public declarations }
  end;

const
//  ServiceName = 'Basic Text Server';
  ServiceGUI = '{00001101-0000-1000-8000-00805F9B34FB}';

var
  Form1: TForm1;

implementation

{$R *.fmx}
procedure TForm1.FormClose(Sender: TObject; var Action: TCloseAction);
begin
  {退出程序}
  MainActivity.finish;
end;

procedure TForm1.FormCloseQuery(Sender: TObject; var CanClose: Boolean);
begin
//  if MessageDlg('是否退出？',
//    TMsgDlgType.mtConfirmation,
//    [TMsgDlgBtn.mbOK, TMsgDlgBtn.mbCancel],
//    -1) = mrOK then
//    CanClose := true
//  else
//    CanClose := false;
  CanClose := true;
end;

procedure TForm1.BtnBLESetClick(Sender: TObject);
begin
  RectSoftwareInfo.Visible := false;
  RectBLESetDialog.Visible := True;
  RectAppSet.Visible := False;
  RectDebug.Visible := False;

  RectHide.Visible := True;
  RectHistory.Visible := False;
end;

procedure TForm1.BtnCloseAppClick(Sender: TObject);
begin
  Close;
end;

procedure TForm1.BtnCloseServiceClick(Sender: TObject);
begin
  RectHide.Visible := False;
  if ServerConnectionTH <> nil then
  begin
    ServerConnectionTH.Terminate;
    ServerConnectionTH.WaitFor;
    FreeAndNil(ServerConnectionTH);
    ShowMessage('蓝牙侦听进程已停止');
    DisplayR.Lines.Add('蓝牙侦听进程已停止');
    DisplayR.GoToTextEnd;
  end;
  FreeAndNil(FSocket);
  ShowMessage('蓝牙收发服务已停止');
  DisplayR.Lines.Add('蓝牙收发服务已停止');
  DisplayR.GoToLineEnd;
end;

procedure TForm1.BtnDebugClick(Sender: TObject);
begin
  RectDebug.Visible := True;
  RectAppSet.Visible := False;
  RectSoftwareInfo.Visible := false;
  RectBLESetDialog.Visible := False;

  RectHistory.Visible := False;
  RectHide.Visible := True;
end;

procedure TForm1.BtnDebugCloseClick(Sender: TObject);
begin
  RectSoftwareInfo.Visible := false;
  RectBLESetDialog.Visible := False;
  RectAppSet.Visible := false;
  RectDebug.Visible := False;

  RectHide.Visible := False;
  RectHistory.Visible := False;
end;

procedure TForm1.BtnHistoryBackClick(Sender: TObject);
begin
  RectSoftwareInfo.Visible := false;
  RectHistory.Visible := False;
  RectBLESetDialog.Visible := False;
  RectAppSet.Visible := false;
  RectDebug.Visible := False;
  RectHide.Visible := False;
end;

procedure TForm1.BtnHistoryClick(Sender: TObject);
begin

  RectDebug.Visible := False;
  RectAppSet.Visible := False;
  RectSoftwareInfo.Visible := false;
  RectBLESetDialog.Visible := False;

  RectHistory.Visible := True;
  RectHide.Visible := False;

end;

procedure TForm1.BtnInfoClick(Sender: TObject);
begin
  RectDebug.Visible := False;
  RectAppSet.Visible := False;
  RectSoftwareInfo.Visible := True;
  RectBLESetDialog.Visible := False;

  RectHistory.Visible := False;
  RectHide.Visible := True;
end;

procedure TForm1.BtnInfoCloseClick(Sender: TObject);
begin
  RectSoftwareInfo.Visible := false;
  RectBLESetDialog.Visible := False;
  RectAppSet.Visible := false;
  RectDebug.Visible := False;

  RectHide.Visible := False;
  RectHistory.Visible := False;
end;

procedure TForm1.BtnOpenServiceClick(Sender: TObject);
begin
  RectHide.Visible := False;
  if ManagerConnected then
  try
    BLEMonitorServiceOn;
  except
    on E: Exception do
    begin
      DisplayR.Lines.Add(E.Message);
      DisplayR.GoToTextEnd;
      FreeAndNil(FSocket);
    end;
  end;
end;

procedure TForm1.BtnSetClick(Sender: TObject);
begin
  RectSoftwareInfo.Visible := false;
  RectBLESetDialog.Visible := False;
  RectAppSet.Visible := True;
  RectDebug.Visible := False;

  RectHide.Visible := True;
  RectHistory.Visible := False;

end;

procedure TForm1.BtnCloseBLESetClick(Sender: TObject);
begin
  RectSoftwareInfo.Visible := false;
  RectBLESetDialog.Visible := False;
  RectAppSet.Visible := false;
  RectDebug.Visible := False;

  RectHide.Visible := False;
  RectHistory.Visible := False;
//  RectRedWarning.Visible := True;
//  ImageFLTireLife.Visible := False;
//  ImageFRTireLife.Visible := False;
//  ImageRLTireLife.Visible := False;
//  ImageRRTireLife.Visible := False;
//  LayoutVehicle.Visible := False;
//  LayoutWarningLight.Visible := False;
end;

procedure TForm1.CBtnRedConfirmClick(Sender: TObject);
begin
  RectRedWarning.Visible := False;

  ImageFLTireLife.Visible := True;
  ImageFRTireLife.Visible := True;
  ImageRLTireLife.Visible := True;
  ImageRRTireLife.Visible := True;
  LayoutVehicle.Visible := True;
end;

procedure TForm1.CBtnYellowComfirmClick(Sender: TObject);
begin
  　RectYellowWarning.Visible := False;

  ImageFLTireLife.Visible := True;
  ImageFRTireLife.Visible := True;
  ImageRLTireLife.Visible := True;
  ImageRRTireLife.Visible := True;
  LayoutVehicle.Visible := True;

end;

procedure TForm1.BLEMonitorServiceOn;
var
  LDevice: TBluetoothDevice;
begin
  if (FSocket = nil) or (ItemIndex <> ComboboxPaired.ItemIndex) then
  begin
    if ComboboxPaired.ItemIndex > -1 then
    begin
      LDevice := FPairedDevices[ComboboxPaired.ItemIndex] as TBluetoothDevice;
      FSocket := LDevice.CreateClientSocket(StringToGUID(ServiceGUI), False);
      FSocket.Connect;
      if FSocket <> nil then
      begin
        ItemIndex := ComboboxPaired.ItemIndex;
        ShowMessage('命令发送已就绪');
//        DisplayR.Lines.Add('命令发送已就绪');
//        DisplayR.GoToTextEnd;
        ServerConnectionTH := TServerConnectionTH.Create(True);
        ServerConnectionTH.Start;
        ShowMessage('命令接收已启动');
//        DisplayR.Lines.Add('命令接收已启动 ');
//        DisplayR.GoToTextEnd;
      end
      else
        ShowMessage('Out of time -15s-');
    end
    else
      ShowMessage('No paired device selected');
  end

end;

procedure TForm1.PairedDevices;
var
  I: Integer;
begin
  ComboboxPaired.Clear;
  if ManagerConnected then
  begin
    FPairedDevices := FBluetoothManager.GetPairedDevices;
    if FPairedDevices.Count > 0 then
      for I := 0 to FPairedDevices.Count - 1 do
        ComboboxPaired.Items.Add(FPairedDevices[I].DeviceName)
    else
      ComboboxPaired.Items.Add('No Paired Devices');
  end;
end;

procedure TForm1.RectHideClick(Sender: TObject);
begin
  RectSoftwareInfo.Visible := false;
  RectBLESetDialog.Visible := False;
  RectAppSet.Visible := false;
  RectDebug.Visible := False;

  RectHide.Visible := False;
  RectHistory.Visible := False;
end;

function TForm1.ManagerConnected: Boolean;
begin
  if FBluetoothManager.ConnectionState = TBluetoothConnectionState.Connected then
  begin
//    DisplayR.Lines.Add('Device discoverable as "'+FBluetoothManager.CurrentAdapter.AdapterName+'"');
//    DisplayR.GoToTextEnd;
//    Result := True;
  end
  else
  begin
    Result := False;
//    DisplayR.Lines.Add('No Bluetooth device Found');
    ShowMessage('No Bluetooth device Found');
//    DisplayR.GoToTextEnd;
  end
end;

procedure TForm1.FormShow(Sender: TObject);
begin
  RectSoftwareInfo.Visible := false;
  RectBLESetDialog.Visible := False;
  RectAppSet.Visible := false;
  RectDebug.Visible := False;

  RectHide.Visible := False;
  RectHistory.Visible := False;
  RectYellowWarning.Visible := False;
  RectRedWarning.Visible := False;

  try
    FBluetoothManager := TBluetoothManager.Current;
    FAdapter := FBluetoothManager.CurrentAdapter;
    if ManagerConnected then
    begin
      PairedDevices;
      ComboboxPaired.ItemIndex := 0;
    end;
  except
    on E: Exception do
    begin
      ShowMessage(E.Message);
    end;
  end;
end;

{TServerConnection}

constructor TServerConnectionTH.Create(ACreateSuspended: Boolean);
begin
  inherited;
end;

destructor TServerConnectionTH.Destroy;
begin
  FSocket.Free;
  inherited;
end;

procedure TServerConnectionTH.Execute;
var
  Msg: string;
  BLEMsg: string;
  FloatMsgTempt: single;
  FloatMsgTempt1: single;
  StrMsgTempt: string;
  IntMsgTempt: Int32;
  StrLen: Int32;
  LData: TBytes;
  strHead: string;
  strEnd: string;
begin
  while not Terminated do
  try
    if (Form1.FSocket <> nil) then
    begin
      while not Terminated do
      begin
        LData := Form1.FSocket.ReceiveData;

        if Length(LData) > 0 then
          Synchronize(
            procedure
            begin
              BLEMsg := TEncoding.UTF8.GetString(LData);
//              Form1.DisplayR.Lines.Add(BLEMsg);
//              Form1.DisplayR.GoToTextEnd;
              StrLen := Length(BLEMsg);
              if (StrLen = 66) then
              begin
                strHead := Copy(BLEMsg, 1, 6);
                strEnd := Copy(BLEMsg, 61, 6);
                if SameText(strHead, 'AABBFF') and SameText(strEnd, 'FFBBAA') then
//                begin
//                  StrMsgTempt := Copy(BLEMsg, 7, 3);  {车速}
//                  FloatMsgTempt := StrToFloat(StrMsgTempt);
//                  Form1.Series1.YValue[0] := FloatMsgTempt;
//                end;



              end;

            end);
        Sleep(100);
      end;
    end;
  except
    on E: Exception do
    begin
      Msg := E.Message;
      Synchronize(
        procedure
        begin
//          Form1.DisplayR.Lines.Add('Server Socket closed: ' + Msg);
//          Form1.DisplayR.GoToTextEnd;
        end);
    end;
  end;
end;

end.

