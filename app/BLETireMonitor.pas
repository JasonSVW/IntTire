unit BLETireMonitor;

interface

uses
  System.SysUtils, System.Types, System.UITypes, System.Classes, System.Variants,
  FMX.Types, FMX.Controls, FMX.Forms, FMX.Graphics, FMX.Dialogs, FMX.Layouts,
  FMX.TextLayout, FMX.Controls.Presentation, FMX.StdCtrls, FMX.Objects,
  System.ImageList, FMX.ImgList, FMX.ExtCtrls, FMXTee.Engine, FMXTee.Series,
  FMXTee.Procs, FMXTee.Chart, FMX.ListBox, System.Bluetooth,
  System.Bluetooth.Components, FMX.Ani, FMX.Edit, FMX.ScrollBox, FMX.Memo,
  FMXTee.RadioGroup, System.UIConsts, DateUtils;            //FMX.Platform.Android

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
  TTireLocation = (LFTire, LRTire, RFTire, RRTire);

type
  TTireInfo = record
    Temp: UInt8;
    TempSt: UInt8;
    Pres: UInt16;
    PrsSenLostErr: UInt8;
    PrsSt: UInt8;
    PrsLeakSt: UInt8;
    Life: UInt8;
    SlowLeakTime: Uint8;
  end;

//type
//  TTireWarningType = (TireTnPn, TireTnPs, TireTnPf, TireThPn, TireThPs, TireThPf);
//
//type
//  TTireSigPresWarningType = (TirePn, TirePs, TirePf);
//
//type
//  TTireWarningType = (TireTnPn, TireTnPs, TireTnPf, TireThPn, TireThPs, TireThPf);

type
  TForm1 = class(TForm)
    GridPanelLayoutMain: TGridPanelLayout;
    ImageDoubleRed: TImage;
    ImageTireRed: TImage;
    LayoutWarningLight: TLayout;
    BtnSet: TButton;
    LayoutVehicle: TLayout;
    ImageVehicle: TImage;
    GridPanelLayoutVehicle: TGridPanelLayout;
    RectLFTireRed: TRectangle;
    LayoutLF: TLayout;
    RectLFTireYellow: TRectangle;
    LayoutRF: TLayout;
    RectRFTireRed: TRectangle;
    RectRFTireYellow: TRectangle;
    LayoutLR: TLayout;
    RectLRTireRed: TRectangle;
    RectLRTireYellow: TRectangle;
    LayoutRR: TLayout;
    RectRRTireRed: TRectangle;
    RectRRTireYellow: TRectangle;
    ImageTireYellow: TImage;
    ImageLFTire: TImage;
    LblLFTirePres: TLabel;
    ImageRFTire: TImage;
    ImageLRTire: TImage;
    ImageRRTire: TImage;
    ImageRedYellow: TImage;
    ChartLFTireLife: TChart;
    SeriesLFTireLife: TPieSeries;
    ImageLFTireLife: TImage;
    ImageLRTireLife: TImage;
    ChartLRTireLife: TChart;
    SeriesLRTireLife: TPieSeries;
    ImageRFTireLife: TImage;
    ChartRFTireLife: TChart;
    SeriesRFTireLife: TPieSeries;
    ImageRRTireLife: TImage;
    ChartRRTireLife: TChart;
    SeriesRRTireLife: TPieSeries;
    LblLFTireLife: TLabel;
    LblRFTireLife: TLabel;
    LblLRTireLife: TLabel;
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
    RectYellowWarning: TRectangle;
    GridPanelLayoutYellow: TGridPanelLayout;
    ImageYellowTire: TImage;
    LblFastWarning: TLabel;
    CBtnRedConfirm: TCornerButton;
    ImageRedBtn: TImage;
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
    GPLayoutLF: TGridPanelLayout;
    LblLFTireTemp: TLabel;
    GPLayoutRF: TGridPanelLayout;
    LblRFTirePres: TLabel;
    LblRFTireTemp: TLabel;
    GPLayoutLR: TGridPanelLayout;
    LblLRTirePres: TLabel;
    LblLRTireTemp: TLabel;
    GPLayoutRR: TGridPanelLayout;
    LblRRTirePres: TLabel;
    LblRRTireTemp: TLabel;
    CBtnYellowConfirm: TCornerButton;
    ImageYellowBtn: TImage;
    RectYellowWarningLbl: TRectangle;
    LblSlowWarning: TLabel;
    RectRedWarningLbl: TRectangle;
    ImageTempRed: TImage;
    BarSeriesTireTemp: TBarSeries;
    LayoutWarningText: TLayout;
    RectPresHigh: TRectangle;
    LblPresHigh: TLabel;
    RectPresLow: TRectangle;
    LblPresLow: TLabel;
    RectFastLeak: TRectangle;
    LblFastLeak: TLabel;
    RectSlowLeak: TRectangle;
    LblSlowLeak: TLabel;
    RectTempWrong: TRectangle;
    LblTempWrong: TLabel;
    RectTireType: TRectangle;
    RBtnTireType: TRadioGroup;
    GridPanelLayoutTireType: TGridPanelLayout;
    BtnTireTypeComfirm: TButton;
    BtnTireTypeCancel: TButton;
    RadioButton2: TRadioButton;
    RadioButton3: TRadioButton;
    RadioButton4: TRadioButton;
    RBtnTirefit: TRadioButton;
    Timer1: TTimer;
    RectTireSetInfo: TRectangle;
    GridPanelLayoutTireInfoSet: TGridPanelLayout;
    BtnTireInfoClose: TButton;
    BtnTireInfoReset: TButton;
    LblTireInfoTitle: TLabel;
    TextTireInfoShow: TText;
    Timer1M: TTimer;
    CBtnWarningComfirm: TCornerButton;
    Image1: TImage;
    Image2: TImage;
    ChartShowTireLife: TChart;
    SeriesTireShowLife: TPieSeries;
    LblTireShowLife: TLabel;
    Chart2: TChart;
    BarSeries1: TBarSeries;
    Chart3: TChart;
    BarSeries2: TBarSeries;
    GridPanelLayoutSTireInfo: TGridPanelLayout;
    LblTireShow: TLabel;
    procedure BtnSetClick(Sender: TObject);
    procedure BtnOpenServiceClick(Sender: TObject);
    procedure BtnCloseServiceClick(Sender: TObject);
    procedure BtnCloseBLESetClick(Sender: TObject);
    procedure CBtnRedComfirmClick(Sender: TObject);
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
    procedure BtnClearMemoClick(Sender: TObject);
    procedure BtnSenderClick(Sender: TObject);
    procedure ComboboxPairedClick(Sender: TObject);
    procedure Button1Click(Sender: TObject);
    procedure BtnTireTypeComfirmClick(Sender: TObject);
    procedure BtnTireTypeCancelClick(Sender: TObject);
    procedure RectFastLeakClick(Sender: TObject);
    procedure RectPresHighClick(Sender: TObject);
    procedure RectSlowLeakClick(Sender: TObject);
    procedure RectPresLowClick(Sender: TObject);
    procedure RectTempWrongClick(Sender: TObject);
    procedure Timer1Timer(Sender: TObject);
    procedure ImageLFTireClick(Sender: TObject);
    procedure ImageLRTireClick(Sender: TObject);
    procedure ImageRFTireClick(Sender: TObject);
    procedure ImageRRTireClick(Sender: TObject);
    procedure BtnTireInfoCloseClick(Sender: TObject);
    procedure BtnTireInfoResetClick(Sender: TObject);
    procedure LayoutLFClick(Sender: TObject);
    procedure LayoutRFClick(Sender: TObject);
    procedure LayoutLRClick(Sender: TObject);
    procedure LayoutRRClick(Sender: TObject);
    procedure Timer1MTimer(Sender: TObject);
    procedure CBtnWarningComfirmClick(Sender: TObject);
//    procedure RectRRTireRedClick(Sender: TObject);
//    procedure RectLFTireRedClick(Sender: TObject);
//    procedure RectLRTireRedClick(Sender: TObject);
//    procedure RectRFTireRedClick(Sender: TObject);
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
    procedure WarningShowUpdate;
  public
    { Public declarations }
    procedure TireLifeCycleChange(const TireLocation: TTireLocation; const TireLife: Integer);
    procedure TirePresChange(const TireLocation: TTireLocation; const TirePres: Integer; const PresSt: Uint8; const SensorSt: Uint8);
    procedure TireTempChange(const TireLocation: TTireLocation; const TireTemp: Integer; const Tempst: uint8);
    procedure TireWarningColorShowChange;
    procedure TitleWarningShowChange;
    procedure TireLeakWarning;
    procedure MainFormWarningChange(const LocaShowWarningIndex: Integer);
    procedure MainFormWarningUpdate;
    procedure MainFormWarningShow(const WarningType: Byte);
    function WarningTireInfo(const WarningSt: Byte): string;
    procedure MainFormShowChange(const Status: Boolean);
    procedure TireInfoResetWindow(const TireLocation: Byte; const ShowTireLife: double);
    //procedure TireInfoReset(const TireLocation: Byte);
    procedure AllInfoReset;
    procedure StatusUpdate(const BLEMsg: string);
    procedure Simulation;
    //procedure SlowLeakCalStartLogic;
    //procedure SlowLeakCalLogic;
  end;

const
//  ServiceName = 'Basic Text Server';
  ServiceGUI = '{00001101-0000-1000-8000-00805F9B34FB}';
  SigTireInfo = '00000450240';
  CmpTirePresLow = 180;

var
  Form1: TForm1;

var
  MyLayout: TTextLayout;
  //TireWarning
  LFTireShowSt, LRTireShowSt, RFTireShowSt, RRTireShowSt: Byte;        //0--normal, 1--red, 2--yellow
  //TireTitleWarning
  TitleWarningSt: Byte;          //bit0--Tempt, bit1--slow, bit2--fast  fast>slow>normal
  //TemptWarning
  TemptWrongWarningSt: Byte;     //bit0--LF, bit1--LR, bit2--RF, bit3--RR
  TemptWrongWarningLastSt: Byte;     //bit0--LF, bit1--LR, bit2--RF, bit3--RR
  //PresHighWarning
  PresHighWarningSt: Byte;       //bit0--LF, bit1--LR, bit2--RF, bit3--RR
  PresHighWarningLastSt: Byte;       //bit0--LF, bit1--LR, bit2--RF, bit3--RR
  //PresLowWarning
  PresLowWarningSt: Byte;        //bit0--LF, bit1--LR, bit2--RF, bit3--RR
  PresLowWarningLastSt: Byte;        //bit0--LF, bit1--LR, bit2--RF, bit3--RR
  //FastLeakWarning
  FastLeakWarningSt: Byte;       //bit0--LF, bit1--LR, bit2--RF, bit3--RR
  FastLeakWarningLastSt: Byte;   //bit0--LF, bit1--LR, bit2--RF, bit3--RR
  //SlowLeakWarning
  SlowLeakWarningSt: Byte;       //bit0--LF, bit1--LR, bit2--RF, bit3--RR
  SlowLeakWarningLastSt: Byte;   //bit0--LF, bit1--LR, bit2--RF, bit3--RR
  //mainform warningtext 文本显示顺序控制
  //WarningStatus: array[0..4] of Boolean;  //0--FastLeak, 1--SlowLeak, 2--Highpres, 3--LowPres, 4--TempWarong
  //CurrentWarningIndex: Byte;
  WarningShowSt: Byte;           //bit0--FastLeak, bit1--SlowLeak, bit2--Highpres, bit3--LowPres, bit4--TempWarong
  WarningShowLastSt: Byte;       //bit0--FastLeak, bit1--SlowLeak, bit2--Highpres, bit3--LowPres, bit4--TempWarong
  CurrentWarningShowIndex: Byte;     //bit0--FastLeak, bit1--SlowLeak, bit2--Highpres, bit3--LowPres, bit4--TempWarong
  //WarningShowMask: Byte;     //bit0--FastLeak, bit1--SlowLeak, bit2--Highpres, bit3--LowPres, bit4--TempWarong
  //快速漏气处理方式
  strFastLeakTips: string;
  //收发信息
  strGlobalBLEMsg: string;
  //蓝牙连接中断时间记录
  BLEUnconnectTime: Integer;
  BLEUnconnectFlag: Integer;
  //车辆行驶里程记录
  CurrentOdoMeter: Double;
  //各轮胎首次安装时里程记录
  TireOdoMeterStart: array[0..3] of double;
  //时间
  CurrentTime, bf1mTime: Integer;
  //慢漏胎压记录
//  TirePresStart: array[0..3] of Uint16;
//  TirePres1stFlag: Boolean;
//  TireSlowLeakFlag: array[0..3] of Boolean;
//  TireSlowLeakTime: Integer;
//  TireSlowSftyTime: array[0..3] of Integer;
//  strMinSftyTime: string;
  //当前点击轮胎位置
  CurrentClickedTire: Uint8;

var
  BLETireInfo: array[0..3] of TTireInfo;

implementation

{$R *.fmx}

//记录第一次初始的胎压。
//procedure TForm1.SlowLeakCalStartLogic;
//var
//  index: uint8;
//begin
//  if (not TirePres1stFlag) then
//  begin
//    TirePres1stFlag := True;      //设置开始记录标志位
//    Timer1M.Enabled := True;   //开启10s定时器
//    TireSlowLeakTime := 0;     //记录开始时间为0；
//    for index := 0 to 3 do     //将所有压力存储下来
//    begin
//      TirePresStart[index] := BLETireInfo[index].Pres;
//      //TireSlowLeakFlag[index] := False;
//    end;
//  end;
//end;

//记录第一次初始的胎压。
//procedure TForm1.SlowLeakCalLogic;
//var
//  index: uint8;
//  deltaPresto1st: int16;
//  deltaPresRef: int16;
//  minLeftTime: Integer;
//  minLeftHour: Integer;
//begin
//  deltaPresRef := 180;
//  minLeftTime := 24 * 60 * 60;
//  for index := 0 to 3 do
//  begin
//    deltaPresto1st := TirePresStart[index] - BLETireInfo[index].Pres;
//    deltaPresRef := BLETireInfo[index].Pres - 180;
//    if deltaPresto1st > 0 then
//    begin
//      TireSlowSftyTime[index] := integer(Trunc(10 * TireSlowLeakTime * deltaPresRef / deltaPresto1st));
//      if TireSlowSftyTime[index] < 0 then
//        TireSlowSftyTime[index] := 0;
//    end
//    else
//    begin
//      TireSlowSftyTime[index] := minLeftTime;
//    end;
//  end;
//
//  for index := 0 to 3 do
//  begin
//    if BLETireInfo[index].PrsSt = 2 then
//    begin
//      if minLeftTime > TireSlowSftyTime[index] then
//        minLeftTime := TireSlowSftyTime[index];
//    end;
//  end;
//  minLeftHour := integer(Trunc(minLeftTime / 60 / 60));
//  if minLeftHour = 0 then
//    strMinSftyTime := '不足1'
////  else if minLeftHour < 1 then
////    strMinSftyTime := '不足1'
//  else
//    strMinSftyTime := InttoStr(minLeftHour);
//end;


//根据各类警告状态，寻找出现警告的轮胎
function TForm1.WarningTireInfo(const WarningSt: Byte): string;
begin
  case WarningSt of
    1:                                 //0001
      Result := '左前';
    2:
      Result := '左后';                //0010
    3:
      Result := '左前/左后';           //0011
    4:
      Result := '右前';                //0100
    5:
      Result := '左前/右前';           //0101
    6:
      Result := '左后/右前';           //0110
    7:
      Result := '左前/右前/左后';      //0111
    8:
      Result := '右后';                //1000
    9:
      Result := '左前/右后';           //1001
    10:
      Result := '左后/右后';           //1010
    11:
      Result := '左前/左后/右后';      //1011
    12:
      Result := '右前/右后';           //1100
    13:
      Result := '左前/右前/右后';      //1101
    14:
      Result := '右前/左后/右后';      //1110
    15:
      Result := '所有';                //1111
  else
    Result := 'Error'
  end;
end;

//显示当前警告信息，并更新当前显示的警告位置
procedure TForm1.MainFormWarningShow(const WarningType: Byte);
begin
  case WarningType of
    0:    //无警告
      begin
        RectFastLeak.visible := False;
        RectSlowLeak.visible := False;
        RectPresHigh.visible := False;
        RectPresLow.visible := False;
        RectTempWrong.visible := False;
        CBtnWarningComfirm.Visible := False;
        CurrentWarningShowIndex := 0;
      end;
    1:   //快漏警告
      begin
        RectFastLeak.visible := True;
        RectSlowLeak.visible := False;
        RectPresHigh.visible := False;
        RectPresLow.visible := False;
        RectTempWrong.visible := False;
        CBtnWarningComfirm.Visible := False;
        CurrentWarningShowIndex := 1;

      end;
    2:  //慢漏警告
      begin
        RectFastLeak.visible := False;
        RectSlowLeak.visible := True;
        RectPresHigh.visible := False;
        RectPresLow.visible := False;
        RectTempWrong.visible := False;
        CBtnWarningComfirm.Visible := False;
        CurrentWarningShowIndex := 2;

      end;
    4:  //高压警告
      begin

        RectFastLeak.visible := False;
        RectSlowLeak.visible := False;
        RectPresHigh.visible := True;
        RectPresLow.visible := False;
        RectTempWrong.visible := False;
        if (RectYellowWarning.Visible <> True) and (RectRedWarning.Visible <> True) then
          CBtnWarningComfirm.Visible := True
        else
          CBtnWarningComfirm.Visible := False;
        CurrentWarningShowIndex := 4;
      end;
    8:  //低压警告
      begin
        RectFastLeak.visible := False;
        RectSlowLeak.visible := False;
        RectPresHigh.visible := False;
        RectPresLow.visible := True;
        RectTempWrong.visible := False;
        if (RectYellowWarning.Visible <> True) and (RectRedWarning.Visible <> True) then
          CBtnWarningComfirm.Visible := True
        else
          CBtnWarningComfirm.Visible := False;
        CurrentWarningShowIndex := 8;
      end;
    16: //温度错误警告
      begin
        RectFastLeak.visible := False;
        RectSlowLeak.visible := False;
        RectPresHigh.visible := False;
        RectPresLow.visible := False;
        RectTempWrong.visible := True;
        if (RectYellowWarning.Visible <> True) and (RectRedWarning.Visible <> True) then
          CBtnWarningComfirm.Visible := True
        else
          CBtnWarningComfirm.Visible := False;
        CurrentWarningShowIndex := 16;
      end;
  else  //其他类型
    begin
      RectFastLeak.visible := False;
      RectSlowLeak.visible := False;
      RectPresHigh.visible := False;
      RectPresLow.visible := False;
      RectTempWrong.visible := False;
      CBtnWarningComfirm.Visible := False;
      CurrentWarningShowIndex := 0;
    end;

  end;
end;

//点击警告信息时，或当前警告信息消失时，寻找和更换其他警告信息 ，该函数不更新警告状态
procedure TForm1.MainFormWarningChange(const LocaShowWarningIndex: Integer);
var
  index, Warningindextemp: Integer;
  CrtLocalWarningStBit: Byte;
begin
  if (WarningShowSt > 0) and (WarningShowSt < $32) then              // 有合理警告
  begin
    for index := 1 to 4 do                                        //从当前的下一个，遍历剩余4个警告类型，是否有警告显示
    begin
      Warningindextemp := LocaShowWarningIndex + index;
      if (Warningindextemp > 5) then
        Warningindextemp := Warningindextemp - 5;                 // Warningindextemp
      CrtLocalWarningStBit := (WarningShowSt and ($01 shl (Warningindextemp - 1))); //计算当前位警告状态
      if (CrtLocalWarningStBit <> 0) then                                     //找到下一个存在的显示警告
      begin
        MainFormWarningShow(CrtLocalWarningStBit);
        Break;
      end;
    end;
  end
  else
  begin
    MainFormWarningShow(0);                                         //无警告
  end;

end;

//有新消息时，更新当前警告状态，与之前警告状态做对比，更新显示状态
procedure TForm1.MainFormWarningUpdate;
var
  TireinfoTemp: string;
  diffSt, crtStbittemp: Byte;
  index: Integer;
  SlowLeakLeftMinTime: Uint8;
  SlowLeakShowTime: string;
begin
  //index := 0;
  //快速漏气
  if (FastLeakWarningSt <> 0) then
  begin
    TireinfoTemp := WarningTireInfo(FastLeakWarningSt);
    if TireinfoTemp <> 'Error' then
    begin
      //需修改显示文字类型，已修改
      LblFastLeak.Text := TireinfoTemp + strFastLeakTips;
      MyLayout.Text := LblFastLeak.Text;
      MyLayout.Font := LblFastLeak.Font;
      RectFastLeak.Width := MyLayout.TextWidth + 30;
      WarningShowSt := WarningShowSt or $1;                //有快速漏气
    end
    else
    begin
      WarningShowSt := WarningShowSt and $FE;              //无快速漏气
    end;
  end
  else
  begin
    WarningShowSt := WarningShowSt and $FE;              //无快速漏气
  end;

  //慢速漏气
  if (SlowLeakWarningSt <> 0) then
  begin
    TireinfoTemp := WarningTireInfo(SlowLeakWarningSt);
    if TireinfoTemp <> 'Error' then
    begin
      //需要计算慢速漏气时间
      //SlowLeakCalLogic;
      SlowLeakLeftMinTime := 255;
      for index := 0 to 3 do
      begin
        if ((SlowLeakWarningSt and ($01 shl index) <> 0)) then
        begin
          if SlowLeakLeftMinTime > BLETireInfo[index].SlowLeakTime then
            SlowLeakLeftMinTime := BLETireInfo[index].SlowLeakTime;
        end;
      end;

      if (SlowLeakLeftMinTime >= 24) then
        SlowLeakShowTime := inttostr(SlowLeakLeftMinTime div 24) + '天'
      else if (SlowLeakLeftMinTime = 0) then
        SlowLeakShowTime := '30分钟'
      else
        SlowLeakShowTime := inttostr(SlowLeakLeftMinTime) + '小时';

      LblSlowLeak.Text := TireinfoTemp + '轮胎慢漏气，请检查' + TireinfoTemp + '轮，' + #13 + '预计' + SlowLeakShowTime + '内低于安全胎压，请降速至80km/h以内！';
      MyLayout.Text := LblSlowLeak.Text;
      MyLayout.Font := LblSlowLeak.Font;
      RectSlowLeak.Width := MyLayout.TextWidth + 30;
      WarningShowSt := WarningShowSt or $2;                //有慢速漏气
    end
    else
    begin
      WarningShowSt := WarningShowSt and $FD;              //无慢速漏气
    end;
  end
  else
  begin
    WarningShowSt := WarningShowSt and $FD;              //无慢速漏气
  end;

  //胎压过高  显示逻辑，存在过高胎压，且和已知胎压过高不一致
  if (PresHighWarningSt <> 0) and (PresHighWarningLastSt <> PresHighWarningSt) then
  begin
    TireinfoTemp := WarningTireInfo(PresHighWarningSt);
    if TireinfoTemp <> 'Error' then
    begin
      LblPresHigh.Text := TireinfoTemp + '轮胎气压过高！请释放气压到240KPa!';
      MyLayout.Text := LblPresHigh.Text;
      MyLayout.Font := LblPresHigh.Font;
      RectPresHigh.Width := MyLayout.TextWidth + 30;
      WarningShowSt := WarningShowSt or $4;                //胎压过高显示
    end
    else
    begin
      WarningShowSt := WarningShowSt and $FB;              //胎压过高不显示
    end;
  end
  else
  begin
    WarningShowSt := WarningShowSt and $FB;              //胎压过高不显示
  end;

  //胎压过低 显示逻辑，存在过低胎压，且和已知胎压过低不一致
  if (PresLowWarningSt <> 0) and (PresLowWarningSt <> PresLowWarningLastSt) then
  begin
    TireinfoTemp := WarningTireInfo(PresLowWarningSt);
    if TireinfoTemp <> 'Error' then
    begin
      LblPresLow.Text := TireinfoTemp + '轮胎气压过低！请补充气压到240KPa!';
      MyLayout.Text := LblPresLow.Text;
      MyLayout.Font := LblPresLow.Font;
      RectPresLow.Width := MyLayout.TextWidth + 30;
      WarningShowSt := WarningShowSt or $8;                //胎压过低
    end
    else
    begin
      WarningShowSt := WarningShowSt and $F7;              //胎压过低不显示
    end;
  end
  else
  begin
    WarningShowSt := WarningShowSt and $F7;              //胎压过低不显示
  end;

  //胎温异常  存在胎温异常，且和已知胎温异常不一致
  if (TemptWrongWarningSt <> 0) and (TemptWrongWarningSt <> TemptWrongWarningLastSt) then
  begin
    TireinfoTemp := WarningTireInfo(TemptWrongWarningSt);
    if TireinfoTemp <> 'Error' then
    begin
      LblTempWrong.Text := TireinfoTemp + '轮胎温度异常，请检查！';
      MyLayout.Text := LblTempWrong.Text;
      MyLayout.Font := LblTempWrong.Font;
      RectTempWrong.Width := MyLayout.TextWidth + 30;
      WarningShowSt := WarningShowSt or $10;                //胎温异常
    end
    else
    begin
      WarningShowSt := WarningShowSt and $EF;              //胎温正常
    end;
  end
  else
  begin
    WarningShowSt := WarningShowSt and $EF;              //胎温正常w
  end;

  //当前状态和之前不一致
  if WarningShowSt <> WarningShowLastSt then
  begin
    diffSt := WarningShowSt xor WarningShowLastSt;
    for index := 1 to 5 do
    begin
      crtStbittemp := ($01 shl (index - 1));                    //计算第几位
      if (diffSt and crtStbittemp) <> 0 then                      //当前位为状态变化位
      begin
        if (WarningShowSt and crtStbittemp) <> 0 then                    //当前类型警告出现
        begin
          MainFormWarningShow(crtStbittemp);                                     //更新当前位显示为当前显示
          break;                                                                 //跳出当前循环
        end
        else if (CurrentWarningShowIndex and crtStbittemp) <> 0 then     //当前类型警告消失,且当前为显示状态
        begin
          MainFormWarningChange(index);                                         //寻找当前存在的警告，并显示
        end
        else
        begin
                                                                         //当前类型警告消失,且不是当前显示状态，不进行任何处理
        end;

      end;

    end;
    WarningShowLastSt := WarningShowSt;       //设置当前警告状态
  end;

end;

procedure TForm1.Timer1MTimer(Sender: TObject);
begin
//  TireSlowLeakTime := TireSlowLeakTime + 1;
//  SlowLeakCalLogic;
//  CurrentTime := DateTimeToUnix(now());
//  //Edit1.text := inttostr(CurrentTime) + '-' + inttostr(bf1mTime) + '=' + inttostr(CurrentTime - bf1mTime);
//  bf1mTime := CurrentTime;
//  Edit1.text := inttostr(TireSlowLeakTime) + booltostr(TireSlowLeakFlag[3], true) + inttostr(BLETireInfo[3].PrsLeakSt);
end;

procedure TForm1.Timer1Timer(Sender: TObject);
begin
  //LayoutWarningLight.visible := not LayoutWarningLight.visible;
  //左前
  if LFTireShowSt = 1 then
  begin
    RectLFTireRed.Visible := not RectLFTireRed.Visible;
    RectLFTireYellow.Visible := False;
  end
  else if LFTireShowSt = 2 then
  begin
    RectLFTireRed.Visible := False;
    RectLFTireYellow.Visible := not RectLFTireYellow.Visible;
  end
  else
  begin
    RectLFTireRed.Visible := False;
    RectLFTireYellow.Visible := False;
  end;
  //左后
  if LRTireShowSt = 1 then
  begin
    RectLRTireRed.Visible := not RectLRTireRed.Visible;
    RectLRTireYellow.Visible := False;
  end
  else if LRTireShowSt = 2 then
  begin
    RectLRTireRed.Visible := False;
    RectLRTireYellow.Visible := not RectLRTireYellow.Visible;
  end
  else
  begin
    RectLRTireRed.Visible := False;
    RectLRTireYellow.Visible := False;
  end;
  //右前
  if RFTireShowSt = 1 then
  begin
    RectRFTireRed.Visible := not RectRFTireRed.Visible;
    RectRFTireYellow.Visible := False;
  end
  else if RFTireShowSt = 2 then
  begin
    RectRFTireRed.Visible := False;
    RectRFTireYellow.Visible := not RectRFTireYellow.Visible;
  end
  else
  begin
    RectRFTireRed.Visible := False;
    RectRFTireYellow.Visible := False;
  end;

  //右后
  if RRTireShowSt = 1 then
  begin
    RectRRTireRed.Visible := not RectRRTireRed.Visible;
    RectRRTireYellow.Visible := False;
  end
  else if RRTireShowSt = 2 then
  begin
    RectRRTireRed.Visible := False;
    RectRRTireYellow.Visible := not RectRRTireYellow.Visible;
  end
  else
  begin
    RectRRTireRed.Visible := False;
    RectRRTireYellow.Visible := False;
  end;

  //标题栏警告更新
  case TitleWarningSt of
    0:
      begin
        ImageTempRed.Visible := False;
        ImageTireYellow.Visible := False;
        ImageTireRed.Visible := False;
        ImageRedYellow.Visible := False;
        ImageDoubleRed.Visible := False;
      end;
    1:
      begin
        ImageTempRed.Visible := not ImageTempRed.Visible;
        ImageTireYellow.Visible := False;
        ImageTireRed.Visible := False;
        ImageRedYellow.Visible := False;
        ImageDoubleRed.Visible := False;
      end;
    2:
      begin
        ImageTempRed.Visible := False;
        ImageTireYellow.Visible := not ImageTireYellow.Visible;
        ImageTireRed.Visible := False;
        ImageRedYellow.Visible := False;
        ImageDoubleRed.Visible := False;
      end;
    3:
      begin
        ImageTempRed.Visible := False;
        ImageTireYellow.Visible := False;
        ImageTireRed.Visible := False;
        ImageRedYellow.Visible := not ImageRedYellow.Visible;
        ImageDoubleRed.Visible := False;
      end;
    4:
      begin
        ImageTempRed.Visible := False;
        ImageTireYellow.Visible := False;
        ImageTireRed.Visible := not ImageTireRed.Visible;
        ImageRedYellow.Visible := False;
        ImageDoubleRed.Visible := False;
      end;
    5:
      begin
        ImageTempRed.Visible := False;
        ImageTireYellow.Visible := False;
        ImageTireRed.Visible := False;
        ImageRedYellow.Visible := False;
        ImageDoubleRed.Visible := not ImageDoubleRed.Visible;
      end;
  else
    begin
      ImageTempRed.Visible := False;
      ImageTireYellow.Visible := False;
      ImageTireRed.Visible := False;
      ImageRedYellow.Visible := False;
      ImageDoubleRed.Visible := False;
    end;
  end;
  //判断蓝牙是否断开
  if (BLEUnconnectTime > 10) and (BLEUnconnectFlag = 0) then
  begin
    if ServerConnectionTH <> nil then
    begin
      ServerConnectionTH.Terminate;
      ServerConnectionTH.WaitFor;
      FreeAndNil(ServerConnectionTH);
    end;
    if FSocket <> nil then
    begin
      FreeAndNil(FSocket);
    end;
    BLEUnconnectFlag := 1;
    ShowMessage('蓝牙连接断开，请重新连接');
    LblLFTirePres.Text := '--kPa';
    LblLRTirePres.Text := '--kPa';
    LblRFTirePres.Text := '--kPa';
    LblRRTirePres.Text := '--kPa';
    LblLFTireTemp.Text := '--℃';
    LblLRTireTemp.Text := '--℃';
    LblRFTireTemp.Text := '--℃';
    LblRRTireTemp.Text := '--℃';
  end;


//  LayoutLF.visible := not LayoutLF.visible;
//  LayoutLR.visible := not LayoutLR.visible;
//  LayoutRF.visible := not LayoutRF.visible;
//  LayoutRR.visible := not LayoutRR.visible;
end;

//漏气弹出警告
procedure TForm1.TireLeakWarning;
var
  TireinfoTemp: string;
begin
  //快漏气  FastLeakWarningSt: Byte;       //bit0--LF, bit1--LR, bit2--RF, bit3--RR
  if (FastLeakWarningSt <> 0) and (FastLeakWarningSt <> FastLeakWarningLastSt) then
  begin
    TireinfoTemp := WarningTireInfo(FastLeakWarningSt);
    if TireinfoTemp <> 'Error' then
    begin
      LblFastWarning.Text := TireinfoTemp + '轮胎快速漏气，请停车检查！';
      MyLayout.Text := LblFastWarning.Text;
      MyLayout.Font := LblFastWarning.Font;
      RectRedWarningLbl.Width := MyLayout.TextWidth + 30;
      RectRedWarning.Visible := True;
      CBtnWarningComfirm.Visible := False;
      MainFormShowChange(False);
    end;
  end;
  //当前漏气警告消失
  if (FastLeakWarningSt = 0) then
  begin
    FastLeakWarningLastSt := FastLeakWarningSt;
    RectRedWarning.Visible := False;
    if RectYellowWarning.Visible = False then
      MainFormShowChange(True);
  end;



  //满漏气  //SlowLeakWarningSt     //bit0--LF, bit1--LR, bit2--RF, bit3--RR
  if (SlowLeakWarningSt <> 0) and (SlowLeakWarningSt <> SlowLeakWarningLastSt) and (FastLeakWarningSt = FastLeakWarningLastSt) then
  begin
    TireinfoTemp := WarningTireInfo(SlowLeakWarningSt);
    if TireinfoTemp <> 'Error' then
    begin
      LblSlowWarning.Text := TireinfoTemp + '轮胎慢漏气，请停车检查！';
      MyLayout.Text := LblSlowWarning.Text;
      MyLayout.Font := LblSlowWarning.Font;
      RectYellowWarningLbl.Width := MyLayout.TextWidth + 30;

      RectYellowWarning.Visible := True;
      CBtnWarningComfirm.Visible := False;
      MainFormShowChange(False);
    end;
  end;

    //当前漏气警告消失
  if (SlowLeakWarningSt = 0) then
  begin
    SlowLeakWarningLastSt := SlowLeakWarningSt;
    RectYellowWarning.Visible := False;
    if RectRedWarning.Visible = False then
      MainFormShowChange(True);
  end;

end;

//有弹出警告显示状态改变时，调整显示变化
procedure TForm1.MainFormShowChange(const Status: Boolean);
begin
  //  GridPanelLayoutMain.Visible:=True;
  ImageLFTireLife.Visible := Status;
  ImageRFTireLife.Visible := Status;
  ImageLRTireLife.Visible := Status;
  ImageRRTireLife.Visible := Status;
  LayoutVehicle.Visible := Status;
  LayoutWarningLight.Visible := Status;
  Timer1.Enabled := Status;
end;


//轮胎颜色改变
procedure TForm1.TireWarningColorShowChange;
begin
  //TirePresWarning    0--normal, 1--fast, 2--slow
  case LFTireShowSt of
    0:
      begin
        RectLFTireRed.Visible := False;
        RectLFTireYellow.Visible := False;
      end;
    1:
      begin
        RectLFTireRed.Visible := True;
        RectLFTireYellow.Visible := False;
      end;
    2:
      begin
        RectLFTireRed.Visible := False;
        RectLFTireYellow.Visible := True;
      end;
  else
    begin
      RectLFTireRed.Visible := False;
      RectLFTireYellow.Visible := False;
    end;
  end;

  case LRTireShowSt of
    0:
      begin
        RectLRTireRed.Visible := False;
        RectLRTireYellow.Visible := False;
      end;
    1:
      begin
        RectLRTireRed.Visible := True;
        RectLRTireYellow.Visible := False;
      end;
    2:
      begin
        RectLRTireRed.Visible := False;
        RectLRTireYellow.Visible := True;
      end;
  else
    begin
      RectLRTireRed.Visible := False;
      RectLRTireYellow.Visible := False;
    end;
  end;
  case RFTireShowSt of
    0:
      begin
        RectRFTireRed.Visible := False;
        RectRFTireYellow.Visible := False;
      end;
    1:
      begin
        RectRFTireRed.Visible := True;
        RectRFTireYellow.Visible := False;
      end;
    2:
      begin
        RectRFTireRed.Visible := False;
        RectRFTireYellow.Visible := True;
      end;
  else
    begin
      RectRFTireRed.Visible := False;
      RectRFTireYellow.Visible := False;
    end;
  end;
  case RRTireShowSt of
    0:
      begin
        RectRRTireRed.Visible := False;
        RectRRTireYellow.Visible := False;
      end;
    1:
      begin
        RectRRTireRed.Visible := True;
        RectRRTireYellow.Visible := False;
      end;
    2:
      begin
        RectRRTireRed.Visible := False;
        RectRRTireYellow.Visible := True;
      end;
  else
    begin
      RectRRTireRed.Visible := False;
      RectRRTireYellow.Visible := False;
    end;

  end;

end;

procedure TForm1.TitleWarningShowChange;
begin
  //TireTitleWarning      //bit0--Tempt, bit1--slow, bit2--fast  fast>slow>normal
  case TitleWarningSt of
    0:
      begin
        ImageTempRed.Visible := False;
        ImageTireYellow.Visible := False;
        ImageTireRed.Visible := False;
        ImageRedYellow.Visible := False;
        ImageDoubleRed.Visible := False;
      end;
    1:
      begin
        ImageTempRed.Visible := True;
        ImageTireYellow.Visible := False;
        ImageTireRed.Visible := False;
        ImageRedYellow.Visible := False;
        ImageDoubleRed.Visible := False;
      end;
    2:
      begin
        ImageTempRed.Visible := False;
        ImageTireYellow.Visible := True;
        ImageTireRed.Visible := False;
        ImageRedYellow.Visible := False;
        ImageDoubleRed.Visible := False;
      end;
    3:
      begin
        ImageTempRed.Visible := False;
        ImageTireYellow.Visible := False;
        ImageTireRed.Visible := False;
        ImageRedYellow.Visible := True;
        ImageDoubleRed.Visible := False;
      end;
    4:
      begin
        ImageTempRed.Visible := False;
        ImageTireYellow.Visible := False;
        ImageTireRed.Visible := True;
        ImageRedYellow.Visible := False;
        ImageDoubleRed.Visible := False;
      end;
    5:
      begin
        ImageTempRed.Visible := False;
        ImageTireYellow.Visible := False;
        ImageTireRed.Visible := False;
        ImageRedYellow.Visible := False;
        ImageDoubleRed.Visible := True;
      end;
  else
    begin
      ImageTempRed.Visible := False;
      ImageTireYellow.Visible := False;
      ImageTireRed.Visible := False;
      ImageRedYellow.Visible := False;
      ImageDoubleRed.Visible := False;
    end;

  end;

end;
//每次接受到新的数据时，更新警告状态

procedure TForm1.WarningShowUpdate;
begin
  //判断是否漏气，并显示相应选项  //根据漏气情况弹出轮胎类型选择
  TireLeakWarning;
  //更新主界面警告提示语
  MainFormWarningUpdate;
  //更新轮胎颜色
  //TireWarningColorShowChange; （放置在Timer中）
  //更新主界面警告提示图标
  //TitleWarningShowChange;    (放置在Timer中)
  //胎压更新
  TirePresChange(LFTire, BLETireInfo[0].Pres, BLETireInfo[0].PrsSt, BLETireInfo[0].PrsSenLostErr);
  TirePresChange(LRTire, BLETireInfo[1].Pres, BLETireInfo[1].PrsSt, BLETireInfo[1].PrsSenLostErr);
  TirePresChange(RFTire, BLETireInfo[2].Pres, BLETireInfo[2].PrsSt, BLETireInfo[2].PrsSenLostErr);
  TirePresChange(RRTire, BLETireInfo[3].Pres, BLETireInfo[3].PrsSt, BLETireInfo[3].PrsSenLostErr);

  //胎温更新
  TireTempChange(LFTire, BLETireInfo[0].Temp, BLETireInfo[0].TempSt);
  TireTempChange(LRTire, BLETireInfo[1].Temp, BLETireInfo[1].TempSt);
  TireTempChange(RFTire, BLETireInfo[2].Temp, BLETireInfo[2].TempSt);
  TireTempChange(RRTire, BLETireInfo[3].Temp, BLETireInfo[3].TempSt);

  //寿命更新
  TireLifeCycleChange(LFTire, BLETireInfo[0].Life);
  TireLifeCycleChange(LRTire, BLETireInfo[1].Life);
  TireLifeCycleChange(RFTire, BLETireInfo[2].Life);
  TireLifeCycleChange(RRTire, BLETireInfo[3].Life);

end;

procedure TForm1.TirePresChange(const TireLocation: TTireLocation; const TirePres: Integer; const PresSt: Uint8; const SensorSt: Uint8);
begin
  case TireLocation of
    LFTire:
      begin
        if SensorSt = 1 then
        begin
          LblLFTirePres.Text := '---';
          LblLFTirePres.FontColor := claRed;
        end
        else
        begin
          LblLFTirePres.FontColor := clawhite;
          LblLFTirePres.Text := IntToStr(TirePres) + 'kPa';
        end;
        if ((PresSt = 1) or (PresSt = 2)) then
          LblLFTirePres.FontColor := claRed;
      end;
    LRTire:
      begin
        if SensorSt = 1 then
        begin
          LblLRTirePres.Text := '---';
          LblLRTirePres.FontColor := claRed;
        end
        else
        begin
          LblLRTirePres.FontColor := clawhite;
          LblLRTirePres.Text := IntToStr(TirePres) + 'kPa';
        end;
        if ((PresSt = 1) or (PresSt = 2)) then
          LblLRTirePres.FontColor := claRed;
      end;
    RFTire:
      begin
        if SensorSt = 1 then
        begin
          LblRFTirePres.Text := '---';
          LblRFTirePres.FontColor := claRed;
        end
        else
        begin
          LblRFTirePres.FontColor := clawhite;
          LblRFTirePres.Text := IntToStr(TirePres) + 'kPa';
        end;
        if ((PresSt = 1) or (PresSt = 2)) then
          LblRFTirePres.FontColor := claRed;
      end;
    RRTire:
      begin
        if SensorSt = 1 then
        begin
          LblRRTirePres.Text := '---';
          LblRRTirePres.FontColor := claRed;
        end
        else
        begin
          LblRRTirePres.FontColor := clawhite;
          LblRRTirePres.Text := IntToStr(TirePres) + 'kPa';
        end;
        if ((PresSt = 1) or (PresSt = 2)) then
          LblRRTirePres.FontColor := claRed;
      end;
  end;
end;

procedure TForm1.TireTempChange(const TireLocation: TTireLocation; const TireTemp: Integer; const Tempst: uint8);
begin
  case TireLocation of
    LFTire:
      begin
        LblLFTireTemp.Text := IntToStr(TireTemp) + '℃';
        if ((Tempst = 1) or (Tempst = 2)) then
          LblLFTireTemp.FontColor := claRed
        else
          LblLFTireTemp.FontColor := claWhite;
      end;
    LRTire:
      begin
        LblLRTireTemp.Text := IntToStr(TireTemp) + '℃';
        if ((Tempst = 1) or (Tempst = 2)) then
          LblLRTireTemp.FontColor := claRed
        else
          LblLRTireTemp.FontColor := claWhite;
      end;
    RFTire:
      begin
        LblRFTireTemp.Text := IntToStr(TireTemp) + '℃';
        if ((Tempst = 1) or (Tempst = 2)) then
          LblRFTireTemp.FontColor := claRed
        else
          LblRFTireTemp.FontColor := claWhite;
      end;
    RRTire:
      begin
        LblRRTireTemp.Text := IntToStr(TireTemp) + '℃';
        if ((Tempst = 1) or (Tempst = 2)) then
          LblRRTireTemp.FontColor := claRed
        else
          LblRRTireTemp.FontColor := claWhite;
      end;
  end;
end;

procedure TForm1.TireLifeCycleChange(const TireLocation: TTireLocation; const TireLife: Integer);
begin
  case TireLocation of
    LFTire:
      begin
        SeriesLFTireLife.YValue[0] := TireLife;
        SeriesLFTireLife.YValue[1] := 100 - TireLife;
        LblLFTireLife.Text := '寿命' + IntToStr(TireLife) + '%';
        if TireLife >= 20 then
          LblLFTireLife.FontColor := claWhite
        else if TireLife < 10 then
          LblLFTireLife.FontColor := claRed
        else
          LblLFTireLife.FontColor := claYellow;
      end;
    LRTire:
      begin
        SeriesLRTireLife.YValue[0] := TireLife;
        SeriesLRTireLife.YValue[1] := 100 - TireLife;
        LblLRTireLife.Text := '寿命' + IntToStr(TireLife) + '%';
        if TireLife >= 20 then
          LblLRTireLife.FontColor := claWhite
        else if TireLife < 10 then
          LblLRTireLife.FontColor := claRed
        else
          LblLRTireLife.FontColor := claYellow;
      end;
    RFTire:
      begin
        SeriesRFTireLife.YValue[0] := TireLife;
        SeriesRFTireLife.YValue[1] := 100 - TireLife;
        LblRFTireLife.Text := '寿命' + IntToStr(TireLife) + '%';
        if TireLife >= 20 then
          LblRFTireLife.FontColor := claWhite
        else if TireLife < 10 then
          LblRFTireLife.FontColor := claRed
        else
          LblRFTireLife.FontColor := claYellow;
      end;
    RRTire:
      begin
        SeriesRRTireLife.YValue[0] := TireLife;
        SeriesRRTireLife.YValue[1] := 100 - TireLife;
        LblRRTireLife.Text := '寿命' + IntToStr(TireLife) + '%';
        if TireLife >= 20 then
          LblRRTireLife.FontColor := claWhite
        else if TireLife < 10 then
          LblRRTireLife.FontColor := claRed
        else
          LblRRTireLife.FontColor := claYellow;
      end;
  end;
end;

procedure TForm1.FormClose(Sender: TObject; var Action: TCloseAction);
begin
  {退出程序}
  //MainActivity.finish;
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

procedure TForm1.BtnClearMemoClick(Sender: TObject);
begin
  DisplayR.SelectAll;
  DisplayR.DeleteSelection;
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
    //ShowMessage('蓝牙侦听进程已停止');
    DisplayR.Lines.Add('蓝牙侦听进程已停止');
    DisplayR.GoToTextEnd;
  end;
  if FSocket <> nil then
  begin
    FreeAndNil(FSocket);
    ShowMessage('蓝牙收发服务已停止');
    DisplayR.Lines.Add('蓝牙收发服务已停止');
    DisplayR.GoToLineEnd;
  end;

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
  if ComboboxPaired.ItemIndex > -1 then
  begin
    DisplayR.Lines.Add(FPairedDevices[ComboboxPaired.ItemIndex].DeviceName);
    DisplayR.GoToTextEnd;
    if FPairedDevices[ComboboxPaired.ItemIndex].DeviceName = 'HC-02' then
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
    end
    else
    begin
      ShowMessage('请选择"HC-02"设备!');
      DisplayR.Lines.Add('请选择"HC-02"设备!');
      DisplayR.GoToTextEnd;
    end;
  end
  else
  begin
    ShowMessage('请打开手机蓝牙，并连接HC-02设备！');
  end;

end;

procedure TForm1.BtnSenderClick(Sender: TObject);
var
  ToSend: TBytes;
begin
  if (FSocket = nil) or (ItemIndex <> ComboboxPaired.ItemIndex) then
  begin
    ShowMessage('请检查蓝牙连接情况');
  end
  else
  begin
    ToSend := TEncoding.UTF8.GetBytes(EditSender.Text);
    FSocket.SendData(ToSend);
    DisplayR.Lines.Add('Text Sent');
    DisplayR.GoToTextEnd;
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

procedure TForm1.BtnTireTypeCancelClick(Sender: TObject);
begin
//  Edit1.text := inttostr(RBtnTireType.ItemIndex);
//  if (RBtnTireType.ItemIndex = 2) then
  RectTireType.Visible := False;
end;

procedure TForm1.BtnTireTypeComfirmClick(Sender: TObject);
begin
  case RBtnTireType.ItemIndex of
    0:
      begin
        strFastLeakTips := '轮胎快速漏气，请检查轮胎，' + #13 + '并使用补胎胶进行修复，或联系安吉星救助！';
//        FastLeakWarningLastSt := FastLeakWarningSt;
//        RectRedWarning.Visible := False;
//        RectTireType.Visible := False;
      end;

    1:
      begin
        strFastLeakTips := '轮胎快速漏气，请检查轮胎，' + #13 + '并更换备胎或联系安吉星救助！';
//        FastLeakWarningLastSt := FastLeakWarningSt;
//        RectRedWarning.Visible := False;
//        RectTireType.Visible := False;
      end;
    2:
      begin
        strFastLeakTips := '轮胎快速漏气，请降速至80km/h以内，请检查轮胎，' + #13 + '并尽快前往4S店维修或联系安吉星救助！';
//        FastLeakWarningLastSt := FastLeakWarningSt;
//        RectRedWarning.Visible := False;
//        RectTireType.Visible := False;
      end;
    3:
      begin
        strFastLeakTips := '轮胎快速漏气，请检查轮胎，' + #13 + '请尽快联系安吉星救助！';
//        FastLeakWarningLastSt := FastLeakWarningSt;
//        RectRedWarning.Visible := False;
//        RectTireType.Visible := False;
      end;
  else
    begin
      RectTireType.Visible := False;
    end;
  end;

  RectTireType.Visible := False;
  MainFormWarningUpdate
//  //判断是否显示主界面（慢漏气是否检查完）
//  //if (RectYellowWarning.Visible = False) and (SlowLeakWarningLastSt = SlowLeakWarningSt) then
//  if (RectYellowWarning.Visible = False) then
//  begin
//    if (SlowLeakWarningLastSt = SlowLeakWarningSt) then
//    begin
//      MainFormShowChange(True);
//      MainFormWarningUpdate;
//    end
//    else
//    begin
//      RectYellowWarning.Visible := True;
//      MainFormShowChange(False);
//    end;
//  end;

end;

procedure TForm1.Button1Click(Sender: TObject);
begin
  Simulation;
//  RectRedWarning.Visible := True;
//  MainFormShowChange(False);
//  RedShowTireWarning(Edit1.Text);
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
//  ImageLFTireLife.Visible := False;
//  ImageRFTireLife.Visible := False;
//  ImageLRTireLife.Visible := False;
//  ImageRRTireLife.Visible := False;
//  LayoutVehicle.Visible := False;
//  LayoutWarningLight.Visible := False;
end;

procedure TForm1.CBtnRedComfirmClick(Sender: TObject);
begin
//  RectTireType.Visible := True;
  FastLeakWarningLastSt := FastLeakWarningSt;
  RectRedWarning.Visible := False;
  //判断是否显示主界面（慢漏气是否检查完）
  //if (RectYellowWarning.Visible = False) and (SlowLeakWarningLastSt = SlowLeakWarningSt) then
  if (RectYellowWarning.Visible = False) then
  begin
    if (SlowLeakWarningLastSt = SlowLeakWarningSt) then
    begin
      MainFormShowChange(True);
      MainFormWarningUpdate;
    end
    else
    begin
      RectYellowWarning.Visible := True;
      CBtnWarningComfirm.Visible := False;
      MainFormShowChange(False);
    end;
  end;
end;

procedure TForm1.CBtnWarningComfirmClick(Sender: TObject);
begin
  case CurrentWarningShowIndex of
    0, 1, 2:
      begin
        //无操作
      end;
    4:
      begin
        PresHighWarningLastSt := PresHighWarningSt;
      end;
    8:
      begin
        PresLowWarningLastSt := PresLowWarningSt;
      end;
    16:
      begin
        TemptWrongWarningLastSt := TemptWrongWarningSt;
      end;
  else
    begin
        //无操作
    end;
  end;
  MainFormWarningUpdate;
end;

procedure TForm1.CBtnYellowComfirmClick(Sender: TObject);
begin
  SlowLeakWarningLastSt := SlowLeakWarningSt;
  RectYellowWarning.Visible := False;
  //判断是否显示主界面（快漏气是否检查完）
  if (RectRedWarning.Visible = False) and (FastLeakWarningLastSt = FastLeakWarningLastSt) then
  begin
    MainFormWarningUpdate;
    MainFormShowChange(True);
  end;

end;

//点击当前警告

procedure TForm1.RectFastLeakClick(Sender: TObject);
begin
  MainFormWarningChange(1);
end;

procedure TForm1.RectSlowLeakClick(Sender: TObject);
begin
  MainFormWarningChange(2);
end;

procedure TForm1.RectPresHighClick(Sender: TObject);
begin
  MainFormWarningChange(3);
end;

procedure TForm1.RectPresLowClick(Sender: TObject);
begin
  MainFormWarningChange(4);
end;

procedure TForm1.RectTempWrongClick(Sender: TObject);
begin
  MainFormWarningChange(5);
end;

procedure TForm1.ComboboxPairedClick(Sender: TObject);
begin
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
      ShowMessage('请打开蓝牙，并连接HC-02设备');
    end;
  end;
//  if ComboboxPaired.ItemIndex = -1 then
//  begin
//    ShowMessage('请打开蓝牙，并连接HC-02设备');
//  end;

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
      try
        FSocket.Connect;
      except
        on E: Exception do
        begin
          DisplayR.Lines.Add(E.Message);
          DisplayR.GoToTextEnd;
        end;
      end;
      if (FSocket <> nil) and (FSocket.Connected = True) then
      begin
        ItemIndex := ComboboxPaired.ItemIndex;
        //ShowMessage('命令发送已就绪');
        DisplayR.Lines.Add('命令发送已就绪');
        DisplayR.GoToTextEnd;
        ServerConnectionTH := TServerConnectionTH.Create(True);
        ServerConnectionTH.Start;
        //ShowMessage('命令接收已启动');
        ShowMessage('蓝牙设备成功连接');
        DisplayR.Lines.Add('命令接收已启动 ');
        DisplayR.GoToTextEnd;
        BLEUnconnectTime := 0;
        BLEUnconnectFlag := 0;
      end
      else
        ShowMessage('无法连接，请检查HC-02是否连接');
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




//蓝牙连接
function TForm1.ManagerConnected: Boolean;
begin
  if FBluetoothManager.ConnectionState = TBluetoothConnectionState.Connected then
  begin
    DisplayR.Lines.Add('Device discoverable as "' + FBluetoothManager.CurrentAdapter.AdapterName + '"');
    DisplayR.GoToTextEnd;
    Result := True;
  end
  else
  begin
    Result := False;
    DisplayR.Lines.Add('No Bluetooth device Found');
    ShowMessage('No Bluetooth device Found');
    DisplayR.GoToTextEnd;
  end
end;

procedure TForm1.AllInfoReset;
begin
   //全局接收信息
  strGlobalBLEMsg := 'AABBFF' + SigTireInfo + SigTireInfo + SigTireInfo + SigTireInfo + '000' + 'FFBBAA';
    //Tirewarning
  //默认轮胎类型
  strFastLeakTips := '轮胎快速漏气，请检查轮胎，' + #13 + '并使用补胎胶进行修复，或联系安吉星救助！';
  //窗体显示初始化
  RectSoftwareInfo.Visible := false;
  RectBLESetDialog.Visible := False;
  RectAppSet.Visible := false;
  RectDebug.Visible := False;

  RectHide.Visible := False;
  RectHistory.Visible := False;
  RectYellowWarning.Visible := False;
  RectRedWarning.Visible := False;
  //主窗体显示初始化
  ImageDoubleRed.Visible := False;
  ImageRedYellow.Visible := False;
  ImageTireYellow.Visible := False;
  ImageTireRed.Visible := False;

  RectLFTireRed.Visible := False;
  RectLFTireYellow.Visible := False;
  RectRFTireRed.Visible := False;
  RectRFTireYellow.Visible := False;
  RectLRTireRed.Visible := False;
  RectLRTireYellow.Visible := False;
  RectRRTireRed.Visible := False;
  RectRRTireYellow.Visible := False;
  //主窗体数值显示初始化
  BLETireInfo[0].Life := 100;
  BLETireInfo[1].Life := 100;
  BLETireInfo[2].Life := 100;
  BLETireInfo[3].Life := 100;
  TireLifeCycleChange(LFTire, BLETireInfo[0].Life);
  TireLifeCycleChange(RFTire, BLETireInfo[1].Life);
  TireLifeCycleChange(LRTire, BLETireInfo[2].Life);
  TireLifeCycleChange(RRTire, BLETireInfo[3].Life);

  LblLFTirePres.Text := '--kPa';
  LblLRTirePres.Text := '--kPa';
  LblRFTirePres.Text := '--kPa';
  LblRRTirePres.Text := '--kPa';
  LblLFTireTemp.Text := '--℃';
  LblLRTireTemp.Text := '--℃';
  LblRFTireTemp.Text := '--℃';
  LblRRTireTemp.Text := '--℃';
//  TirePresChange(LFTire, 240, 0, 0);
//  TirePresChange(RFTire, 240, 0, 0);
//  TirePresChange(LRTire, 240, 0, 0);
//  TirePresChange(RRTire, 240, 0, 0);
//  TireTempChange(LFTire, 25, 0);
//  TireTempChange(RFTire, 25, 0);
//  TireTempChange(LRTire, 25, 0);
//  TireTempChange(RRTire, 25, 0);
  //状态初始化
  LFTireShowSt := 0;
  LRTireShowSt := 0;
  RFTireShowSt := 0;
  RRTireShowSt := 0;        //0--normal, 1--red, 2--yellow
  //TireTitleWarning
  TitleWarningSt := 0;          //bit0--Tempt, bit1--slow, bit2--fast  fast>slow>normal
  //TemptWarning
  TemptWrongWarningSt := 0;     //bit0--LF, bit1--LR, bit2--RF, bit3--RR
  TemptWrongWarningLastSt := 0;     //bit0--LF, bit1--LR, bit2--RF, bit3--RR
  //PresHighWarning
  PresHighWarningSt := 0;       //bit0--LF, bit1--LR, bit2--RF, bit3--RR
  PresHighWarningLastSt := 0;       //bit0--LF, bit1--LR, bit2--RF, bit3--RR
  //PresLowWarning
  PresLowWarningSt := 0;        //bit0--LF, bit1--LR, bit2--RF, bit3--RR
  PresLowWarningLastSt := 0;        //bit0--LF, bit1--LR, bit2--RF, bit3--RR
  //FastLeakWarning
  FastLeakWarningSt := 0;       //bit0--LF, bit1--LR, bit2--RF, bit3--RR
  FastLeakWarningLastSt := 0;   //bit0--LF, bit1--LR, bit2--RF, bit3--RR
  //SlowLeakWarning
  SlowLeakWarningSt := 0;       //bit0--LF, bit1--LR, bit2--RF, bit3--RR
  SlowLeakWarningLastSt := 0;   //bit0--LF, bit1--LR, bit2--RF, bit3--RR
  //文本警告显示状态
  WarningShowSt := 0;           //bit0--FastLeak, bit1--SlowLeak, bit2--Highpres, bit3--LowPres, bit4--TempWarong
  WarningShowLastSt := 0;       //bit0--FastLeak, bit1--SlowLeak, bit2--Highpres, bit3--LowPres, bit4--TempWarong
  //WarningShowMask := 0;
end;

procedure TForm1.FormShow(Sender: TObject);
begin
  AllInfoReset;
  BLEUnconnectTime := 0;
  BLEUnconnectFlag := 0;
  CurrentClickedTire := 0;
  //strMinSftyTime := '3';
  //TirePres1stFlag := False;
  CurrentTime := DateTimeToUnix(now());
  bf1mTime := DateTimeToUnix(now());
  MyLayout := TTextLayoutManager.DefaultTextLayout.Create;

end;

procedure TForm1.BtnTireInfoCloseClick(Sender: TObject);
begin
  RectTireSetInfo.Visible := False;
end;

procedure TForm1.BtnTireInfoResetClick(Sender: TObject);
var
  BLEMsg: string;
  ChangeFlag: Byte;
begin
  ChangeFlag := 0;
  SeriesTireShowLife.YValue[0] := 100;
  SeriesTireShowLife.YValue[1] := 0;
  LblTireShowLife.Text := '剩余寿命100%';
  //RectTireSetInfo.Visible := False;
  case CurrentClickedTire of
    1:
      begin
        BLEMsg := Copy(strGlobalBLEMsg, 1, 6) + SigTireInfo + Copy(strGlobalBLEMsg, 18, 42);
        TireLifeCycleChange(LFTire, 100);
        ChangeFlag := 1;
      end;
    2:
      begin
        BLEMsg := Copy(strGlobalBLEMsg, 1, 17) + SigTireInfo + Copy(strGlobalBLEMsg, 29, 31);
        TireLifeCycleChange(LRTire, 100);
        ChangeFlag := 1;
      end;
    3:
      begin
        BLEMsg := Copy(strGlobalBLEMsg, 1, 28) + SigTireInfo + Copy(strGlobalBLEMsg, 40, 20);
        TireLifeCycleChange(RFTire, 100);
        ChangeFlag := 1;
      end;
    4:
      begin
        BLEMsg := Copy(strGlobalBLEMsg, 1, 39) + SigTireInfo + Copy(strGlobalBLEMsg, 51, 9);
        TireLifeCycleChange(RRTire, 100);
        ChangeFlag := 1;
      end;
    5:
      begin
//        AllInfoReset;
//        BLEMsg := strGlobalBLEMsg;
//        ChangeFlag := 1;
        ChangeFlag := 0;
      end;
  else
    begin
      //AllInfoReset;
      ChangeFlag := 0;
    end;
  end;
  //TireInfoReset(CmbBoxTire.ItemIndex);
  //状态提取及更新
  if ChangeFlag = 1 then
  begin
    ChangeFlag := 0;
    strGlobalBLEMsg := BLEMsg;
    StatusUpdate(BLEMsg);
  //界面显示更新
    WarningShowUpdate;
  end;

end;

procedure TForm1.ImageLFTireClick(Sender: TObject);
begin
  TireInfoResetWindow(1, SeriesLFTireLife.YValue[0]);
end;

procedure TForm1.ImageLRTireClick(Sender: TObject);
begin
  TireInfoResetWindow(2, SeriesLRTireLife.YValue[0]);
end;

procedure TForm1.ImageRFTireClick(Sender: TObject);
begin
  TireInfoResetWindow(3, SeriesRFTireLife.YValue[0]);
end;

procedure TForm1.ImageRRTireClick(Sender: TObject);
begin
  TireInfoResetWindow(4, SeriesRRTireLife.YValue[0]);
end;

procedure TForm1.LayoutLFClick(Sender: TObject);
begin
  if (FastLeakWarningSt and $01) <> 0 then
    RectTireType.Visible := True;
end;

procedure TForm1.LayoutLRClick(Sender: TObject);
begin
  if (FastLeakWarningSt and $02) <> 0 then
    RectTireType.Visible := True;
end;

procedure TForm1.LayoutRFClick(Sender: TObject);
begin
  if (FastLeakWarningSt and $04) <> 0 then
    RectTireType.Visible := True;
end;

procedure TForm1.LayoutRRClick(Sender: TObject);
begin
  if (FastLeakWarningSt and $08) <> 0 then
    RectTireType.Visible := True;
end;

procedure TForm1.TireInfoResetWindow(const TireLocation: Byte; const ShowTireLife: double);
begin
  RectTireSetInfo.Visible := True;
  CurrentClickedTire := TireLocation;
  SeriesTireShowLife.YValue[0] := ShowTireLife;
  SeriesTireShowLife.YValue[1] := 100 - ShowTireLife;
  LblTireShowLife.Text := '剩余寿命' + floattostr(ShowTireLife) + '%';
  BLETireInfo[TireLocation - 1].Life := 100;

  case TireLocation of
    1:
      begin
        LblTireInfoTitle.Text := '左前轮胎使用大数据';
        LblTireShow.Text := '左前轮胎基本信息';
       //SeriesTireShowLife
      end;
    2:
      begin
        LblTireInfoTitle.Text := '左后轮胎使用大数据';
        LblTireShow.Text := '左后轮胎基本信息';
      end;
    3:
      begin
        LblTireInfoTitle.Text := '右前轮胎使用大数据';
        LblTireShow.Text := '右前轮胎基本信息';
      end;
    4:
      begin
        LblTireInfoTitle.Text := '右后轮胎使用大数据';
        LblTireShow.Text := '右后轮胎基本信息';
      end;
  else
    begin
      RectTireSetInfo.Visible := False;
    end;
  end;

end;
//
//procedure TForm1.TireInfoReset(const TireLocation: Byte);
//begin
//
//  TitleWarningSt := 0;       //bit0--Tempt, bit1--slow, bit2--fast  fast>slow>normal
//  WarningShowSt := 0;           //bit0--FastLeak, bit1--SlowLeak, bit2--Highpres, bit3--LowPres, bit4--TempWarong
//  WarningShowLastSt := 0;       //bit0--FastLeak, bit1--SlowLeak, bit2--Highpres, bit3--LowPres, bit4--TempWarong
//  CurrentWarningShowIndex := 0;
//
//  case TireLocation of
//    0:
//      begin
//        LFTireShowSt := 0;
//        TemptWrongWarningSt := TemptWrongWarningSt and $FE;     //bit0--LF, bit1--LR, bit2--RF, bit3--RR
//        PresHighWarningSt := PresHighWarningSt and $FE;       //bit0--LF, bit1--LR, bit2--RF, bit3--RR
//        PresLowWarningSt := PresLowWarningSt and $FE;        //bit0--LF, bit1--LR, bit2--RF, bit3--RR
//        FastLeakWarningSt := FastLeakWarningSt and $FE;       //bit0--LF, bit1--LR, bit2--RF, bit3--RR
//        FastLeakWarningLastSt := FastLeakWarningLastSt and $FE;   //bit0--LF, bit1--LR, bit2--RF, bit3--RR
//        SlowLeakWarningSt := SlowLeakWarningSt and $FE;       //bit0--LF, bit1--LR, bit2--RF, bit3--RR
//        SlowLeakWarningLastSt := SlowLeakWarningLastSt and $FE;   //bit0--LF, bit1--LR, bit2--RF, bit3--RR
//        TireLifeCycleChange(LFTire, 100);
//        TirePresChange(LFTire, 248, 0, 0);
//        TireTempChange(LFTire, 68, 0);
//      end;
//    1:
//      begin
//        LRTireShowSt := 0;
//        TemptWrongWarningSt := TemptWrongWarningSt and $FD;     //bit0--LF, bit1--LR, bit2--RF, bit3--RR
//        PresHighWarningSt := PresHighWarningSt and $FD;       //bit0--LF, bit1--LR, bit2--RF, bit3--RR
//        PresLowWarningSt := PresLowWarningSt and $FD;        //bit0--LF, bit1--LR, bit2--RF, bit3--RR
//        FastLeakWarningSt := FastLeakWarningSt and $FD;       //bit0--LF, bit1--LR, bit2--RF, bit3--RR
//        FastLeakWarningLastSt := FastLeakWarningLastSt and $FD;   //bit0--LF, bit1--LR, bit2--RF, bit3--RR
//        SlowLeakWarningSt := SlowLeakWarningSt and $FD;       //bit0--LF, bit1--LR, bit2--RF, bit3--RR
//        SlowLeakWarningLastSt := SlowLeakWarningLastSt and $FD;   //bit0--LF, bit1--LR, bit2--RF, bit3--RR
//        TireLifeCycleChange(LRTire, 100);
//        TirePresChange(LRTire, 248, 0, 0);
//        TireTempChange(LRTire, 68, 0);
//      end;
//    2:
//      begin
//        RFTireShowSt := 0;
//        TemptWrongWarningSt := TemptWrongWarningSt and $FB;     //bit0--LF, bit1--LR, bit2--RF, bit3--RR
//        PresHighWarningSt := PresHighWarningSt and $FB;       //bit0--LF, bit1--LR, bit2--RF, bit3--RR
//        PresLowWarningSt := PresLowWarningSt and $FB;        //bit0--LF, bit1--LR, bit2--RF, bit3--RR
//        FastLeakWarningSt := FastLeakWarningSt and $FB;       //bit0--LF, bit1--LR, bit2--RF, bit3--RR
//        FastLeakWarningLastSt := FastLeakWarningLastSt and $FB;   //bit0--LF, bit1--LR, bit2--RF, bit3--RR
//        SlowLeakWarningSt := SlowLeakWarningSt and $FB;       //bit0--LF, bit1--LR, bit2--RF, bit3--RR
//        SlowLeakWarningLastSt := SlowLeakWarningLastSt and $FB;   //bit0--LF, bit1--LR, bit2--RF, bit3--RR
//        TireLifeCycleChange(RFTire, 100);
//        TirePresChange(RFTire, 248, 0, 0);
//        TireTempChange(RFTire, 68, 0);
//      end;
//    3:
//      begin
//        RRTireShowSt := 0;        //0--normal, 1--red, 2--yellow
//        TemptWrongWarningSt := TemptWrongWarningSt and $F7;     //bit0--LF, bit1--LR, bit2--RF, bit3--RR
//        PresHighWarningSt := PresHighWarningSt and $F7;       //bit0--LF, bit1--LR, bit2--RF, bit3--RR
//        PresLowWarningSt := PresLowWarningSt and $F7;        //bit0--LF, bit1--LR, bit2--RF, bit3--RR
//        FastLeakWarningSt := FastLeakWarningSt and $F7;       //bit0--LF, bit1--LR, bit2--RF, bit3--RR
//        FastLeakWarningLastSt := FastLeakWarningLastSt and $F7;   //bit0--LF, bit1--LR, bit2--RF, bit3--RR
//        SlowLeakWarningSt := SlowLeakWarningSt and $F7;       //bit0--LF, bit1--LR, bit2--RF, bit3--RR
//        SlowLeakWarningLastSt := SlowLeakWarningLastSt and $F7;   //bit0--LF, bit1--LR, bit2--RF, bit3--RR
//        TireLifeCycleChange(RRTire, 100);
//        TirePresChange(RRTire, 248, 0, 0);
//        TireTempChange(RRTire, 68, 0);
//      end;
//    4:
//      begin
//        AllInfoReset;
//      end;
//  else
//    begin
//      AllInfoReset;
//    end;
//  end;
//
//end;

procedure TForm1.StatusUpdate(const BLEMsg: string);
var
  iTire: Integer;
  StrMsgTempt: string;
  strTireMsg: array[0..3] of string;
begin
//  strTireMsg[0] := Copy(BLEMsg, 7, 14);   {LF}
//  strTireMsg[1] := Copy(BLEMsg, 21, 14);  {LR}
//  strTireMsg[2] := Copy(BLEMsg, 35, 14);  {RF}
//  strTireMsg[3] := Copy(BLEMsg, 49, 14);  {RR}
  strTireMsg[0] := Copy(BLEMsg, 7, 17);   {LF}
  strTireMsg[1] := Copy(BLEMsg, 24, 17);  {LR}
  strTireMsg[2] := Copy(BLEMsg, 41, 17);  {RF}
  strTireMsg[3] := Copy(BLEMsg, 58, 17);  {RR}
  for iTire := 0 to 3 do
  begin
    StrMsgTempt := Copy(strTireMsg[iTire], 1, 1);  {胎温状态}
    BLETireInfo[iTire].Tempst := StrToUInt(StrMsgTempt);
    StrMsgTempt := Copy(strTireMsg[iTire], 2, 1);  {传感器状态}
    BLETireInfo[iTire].PrsSenLostErr := StrToUInt(StrMsgTempt);
    StrMsgTempt := Copy(strTireMsg[iTire], 3, 1);  {胎压状态}
    BLETireInfo[iTire].PrsSt := StrToUInt(StrMsgTempt);
    StrMsgTempt := Copy(strTireMsg[iTire], 4, 1);  {漏气状态}
    BLETireInfo[iTire].PrsLeakSt := StrToUInt(StrMsgTempt);
    StrMsgTempt := Copy(strTireMsg[iTire], 5, 3);  {胎温}
    BLETireInfo[iTire].Temp := StrToUInt(StrMsgTempt) - 20;
    StrMsgTempt := Copy(strTireMsg[iTire], 8, 4);  {胎压}
    BLETireInfo[iTire].Pres := StrToUInt(StrMsgTempt);
    StrMsgTempt := Copy(strTireMsg[iTire], 12, 3);  {寿命}
    BLETireInfo[iTire].Life := StrToUInt(StrMsgTempt);
    StrMsgTempt := Copy(strTireMsg[iTire], 15, 3);  {慢漏剩余时间}
    BLETireInfo[iTire].SlowLeakTime := StrToUInt(StrMsgTempt);
  end;
//  StrMsgTempt := Copy(BLEMsg, 51, 3);  {总里程}
//  CurrentOdoMeter := StrTofloat(StrMsgTempt) / 10;
  //接收到当前胎压，计算慢漏时间
//  SlowLeakCalStartLogic;          (慢漏时间通过下位机发送)
//
//  //根据上位机慢漏标志位，修改轮胎快漏和慢漏的标志位
//  for iTire := 0 to 3 do
//  begin
//    if (BLETireInfo[iTire].PrsLeakSt = 0) and TireSlowLeakFlag[iTire] then
//      BLETireInfo[iTire].PrsLeakSt := 2;
//  end;
  //寿命，暂无处理
//  BLETireInfo[0].Life := 87;            {寿命}
//  BLETireInfo[1].Life := 88;            {寿命}
//  BLETireInfo[2].Life := 85;            {寿命}
//  BLETireInfo[3].Life := 87;            {寿命}
  //状态值更新获取
                  //轮胎漏气状态
  LFTireShowSt := BLETireInfo[0].PrsLeakSt;      //左前
  LRTireShowSt := BLETireInfo[1].PrsLeakSt;      //左后
  RFTireShowSt := BLETireInfo[2].PrsLeakSt;      //右前
  RRTireShowSt := BLETireInfo[3].PrsLeakSt;      //右后
                  //胎温
  if (BLETireInfo[0].Tempst = 1) or (BLETireInfo[0].Tempst = 2) then
  begin
    TemptWrongWarningSt := TemptWrongWarningSt or $01;   //左前异常
  end
  else
  begin
    TemptWrongWarningSt := TemptWrongWarningSt and $0E;  //左前正常
  end;

  if (BLETireInfo[1].Tempst = 1) or (BLETireInfo[1].Tempst = 2) then
  begin
    TemptWrongWarningSt := TemptWrongWarningSt or $02;   //左后异常
  end
  else
  begin
    TemptWrongWarningSt := TemptWrongWarningSt and $0D;  //左后正常
  end;

  if (BLETireInfo[2].Tempst = 1) or (BLETireInfo[2].Tempst = 2) then
  begin
    TemptWrongWarningSt := TemptWrongWarningSt or $04;   //右前异常
  end
  else
  begin
    TemptWrongWarningSt := TemptWrongWarningSt and $0B;  //右前正常
  end;

  if (BLETireInfo[3].Tempst = 1) or (BLETireInfo[3].Tempst = 2) then
  begin
    TemptWrongWarningSt := TemptWrongWarningSt or $08;   //右后异常
  end
  else
  begin
    TemptWrongWarningSt := TemptWrongWarningSt and $07;  //右后正常
  end;
                  //胎压   左前
  if (BLETireInfo[0].PrsSt = 1) then
  begin
    PresHighWarningSt := PresHighWarningSt or $01;   //胎压过高
    PresLowWarningSt := PresLowWarningSt and $0E;    //正常
  end
  else if (BLETireInfo[0].PrsSt = 2) then
  begin
    PresHighWarningSt := PresHighWarningSt and $0E;  //正常
    PresLowWarningSt := PresLowWarningSt or $01;     //胎压过低                                                //左前胎压过低
  end
  else
  begin
    PresHighWarningSt := PresHighWarningSt and $0E;  //正常
    PresLowWarningSt := PresLowWarningSt and $0E;    //正常
  end;

                  //胎压   左后
  if (BLETireInfo[1].PrsSt = 1) then
  begin
    PresHighWarningSt := PresHighWarningSt or $02;   //胎压过高
    PresLowWarningSt := PresLowWarningSt and $0D;    //左前正常
  end
  else if (BLETireInfo[1].PrsSt = 2) then
  begin
    PresHighWarningSt := PresHighWarningSt and $0D;  //左前正常
    PresLowWarningSt := PresLowWarningSt or $02;     //胎压过低                                                //左前胎压过低
  end
  else
  begin
    PresHighWarningSt := PresHighWarningSt and $0D;  //左前正常
    PresLowWarningSt := PresLowWarningSt and $0D;    //左前正常
  end;

                  //胎压   右前
  if (BLETireInfo[2].PrsSt = 1) then
  begin
    PresHighWarningSt := PresHighWarningSt or $04;   //胎压过高
    PresLowWarningSt := PresLowWarningSt and $0B;    //正常
  end
  else if (BLETireInfo[2].PrsSt = 2) then
  begin
    PresHighWarningSt := PresHighWarningSt and $0B;  //正常
    PresLowWarningSt := PresLowWarningSt or $04;     //胎压过低                                                //左前胎压过低
  end
  else
  begin
    PresHighWarningSt := PresHighWarningSt and $0B;  //正常
    PresLowWarningSt := PresLowWarningSt and $0B;    //正常
  end;

                  //胎压   右后
  if (BLETireInfo[3].PrsSt = 1) then
  begin
    PresHighWarningSt := PresHighWarningSt or $08;   //胎压过高
    PresLowWarningSt := PresLowWarningSt and $07;    //正常
  end
  else if (BLETireInfo[3].PrsSt = 2) then
  begin
    PresHighWarningSt := PresHighWarningSt and $07;  //正常
    PresLowWarningSt := PresLowWarningSt or $08;     //胎压过低                                                //左前胎压过低
  end
  else
  begin
    PresHighWarningSt := PresHighWarningSt and $07;  //正常
    PresLowWarningSt := PresLowWarningSt and $07;    //正常
  end;


                   //漏气   左前
  if (BLETireInfo[0].PrsLeakSt = 1) then
  begin
    FastLeakWarningSt := FastLeakWarningSt or $01;   //胎压过高
    SlowLeakWarningSt := SlowLeakWarningSt and $0E;    //正常
  end
  else if (BLETireInfo[0].PrsLeakSt = 2) then
  begin
    FastLeakWarningSt := FastLeakWarningSt and $0E;  //正常
    SlowLeakWarningSt := SlowLeakWarningSt or $01;     //胎压过低                                                //左前胎压过低
  end
  else
  begin
    FastLeakWarningSt := FastLeakWarningSt and $0E;  //正常
    SlowLeakWarningSt := SlowLeakWarningSt and $0E;    //正常
  end;

                  //漏气   左后
  if (BLETireInfo[1].PrsLeakSt = 1) then
  begin
    FastLeakWarningSt := FastLeakWarningSt or $02;   //胎压过高
    SlowLeakWarningSt := SlowLeakWarningSt and $0D;    //左前正常
  end
  else if (BLETireInfo[1].PrsLeakSt = 2) then
  begin
    FastLeakWarningSt := FastLeakWarningSt and $0D;  //左前正常
    SlowLeakWarningSt := SlowLeakWarningSt or $02;     //胎压过低                                                //左前胎压过低
  end
  else
  begin
    FastLeakWarningSt := FastLeakWarningSt and $0D;  //左前正常
    SlowLeakWarningSt := SlowLeakWarningSt and $0D;    //左前正常
  end;

                  //漏气   右前
  if (BLETireInfo[2].PrsLeakSt = 1) then
  begin
    FastLeakWarningSt := FastLeakWarningSt or $04;   //胎压过高
    SlowLeakWarningSt := SlowLeakWarningSt and $0B;    //正常
  end
  else if (BLETireInfo[2].PrsLeakSt = 2) then
  begin
    FastLeakWarningSt := FastLeakWarningSt and $0B;  //正常
    SlowLeakWarningSt := SlowLeakWarningSt or $04;     //胎压过低                                                //左前胎压过低
  end
  else
  begin
    FastLeakWarningSt := FastLeakWarningSt and $0B;  //正常
    SlowLeakWarningSt := SlowLeakWarningSt and $0B;    //正常
  end;

                  //漏气   右后
  if (BLETireInfo[3].PrsLeakSt = 1) then
  begin
    FastLeakWarningSt := FastLeakWarningSt or $08;   //胎压过高
    SlowLeakWarningSt := SlowLeakWarningSt and $07;    //正常
  end
  else if (BLETireInfo[3].PrsLeakSt = 2) then
  begin
    FastLeakWarningSt := FastLeakWarningSt and $07;  //正常
    SlowLeakWarningSt := SlowLeakWarningSt or $08;     //胎压过低                                                //左前胎压过低
  end
  else
  begin
    FastLeakWarningSt := FastLeakWarningSt and $07;  //正常
    SlowLeakWarningSt := SlowLeakWarningSt and $07;    //正常
  end;
                  //轮胎警告状态
                  //左前
  if ((FastLeakWarningSt or PresHighWarningSt or PresLowWarningSt or TemptWrongWarningSt) and $01) <> 0 then
    LFTireShowSt := 1
  else if (SlowLeakWarningSt and $01) <> 0 then
    LFTireShowSt := 2
  else
    LFTireShowSt := 0;
                  //左后
  if ((FastLeakWarningSt or PresHighWarningSt or PresLowWarningSt or TemptWrongWarningSt) and $02) <> 0 then
    LRTireShowSt := 1
  else if (SlowLeakWarningSt and $02) <> 0 then
    LRTireShowSt := 2
  else
    LRTireShowSt := 0;
                  //右前
  if ((FastLeakWarningSt or PresHighWarningSt or PresLowWarningSt or TemptWrongWarningSt) and $04) <> 0 then
    RFTireShowSt := 1
  else if (SlowLeakWarningSt and $04) <> 0 then
    RFTireShowSt := 2
  else
    RFTireShowSt := 0;
                  //右后
  if ((FastLeakWarningSt or PresHighWarningSt or PresLowWarningSt or TemptWrongWarningSt) and $08) <> 0 then
    RRTireShowSt := 1
  else if (SlowLeakWarningSt and $08) <> 0 then
    RRTireShowSt := 2
  else
    RRTireShowSt := 0;
                  //标题警告状态
  if (TemptWrongWarningSt <> 0) then                                      //胎温异常,温度红色
  begin
    if ((FastLeakWarningSt or PresHighWarningSt or PresLowWarningSt) <> 0) then    //轮胎红色警告
      TitleWarningSt := 5
    else if (SlowLeakWarningSt <> 0) then                                          //轮胎黄色警告
      TitleWarningSt := 3
    else                                                                           //轮胎无警告
      TitleWarningSt := 1;
  end
  else
  begin                                                                   //胎温正常,无温度警告
    if ((FastLeakWarningSt or PresHighWarningSt or PresLowWarningSt) <> 0) then    //轮胎红色警告
      TitleWarningSt := 4
    else if (SlowLeakWarningSt <> 0) then                                          //轮胎黄色警告
      TitleWarningSt := 2
    else                                                                           //轮胎无警告
      TitleWarningSt := 0;
  end;
end;

procedure TForm1.Simulation;
var
  BLEMsg: string;
  StrMsgTempt: string;
  StrLen: Int32;
  strHead: string;
  strEnd: string;
  strTireMsg: array[0..3] of string;
var
  iTire: Integer;
begin
  //BLEMsg := Edit1.Text;
  StrLen := Length(BLEMsg);
  if (StrLen = 59) then
  begin
    strHead := Copy(BLEMsg, 1, 6);
    strEnd := Copy(BLEMsg, 54, 6);
    if SameText(strHead, 'AABBFF') and SameText(strEnd, 'FFBBAA') then
    begin
      strGlobalBLEMsg := BLEMsg;
        //状态提取及更新
      StatusUpdate(BLEMsg);
       //界面显示更新
      WarningShowUpdate;
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
//  FloatMsgTempt: single;
//  FloatMsgTempt1: single;
  StrMsgTempt: string;
//  IntMsgTempt: Int32;
  StrLen: Int32;
  LData: TBytes;
  strHead: string;
  strEnd: string;
  strTireMsg: array[0..3] of string;
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
            var
              iTire: Integer;
            begin
              BLEMsg := TEncoding.UTF8.GetString(LData);
//              Form1.DisplayR.Lines.Add(BLEMsg);
//              Form1.DisplayR.GoToTextEnd;
              StrLen := Length(BLEMsg);
              BLEUnconnectTime := 0;
              //if (StrLen = 68) then
              if (StrLen = 80) then
              begin
                strHead := Copy(BLEMsg, 1, 6);
                strEnd := Copy(BLEMsg, 75, 6);
                //strEnd := Copy(BLEMsg, 63, 6);
                if SameText(strHead, 'AABBFF') and SameText(strEnd, 'FFBBAA') then
                begin
//                  Form1.DisplayR.Lines.Add('OK');
//                  Form1.DisplayR.GoToTextEnd;
                  strGlobalBLEMsg := BLEMsg;
                  //状态更新
                  Form1.StatusUpdate(BLEMsg);
                  //界面显示更新
                  Form1.WarningShowUpdate;

                end;

              end;

            end);
        Sleep(100);
      end;
    end;
  except
    on E: Exception do
    begin
      Msg := E.Message;
      BLEUnconnectTime := BLEUnconnectTime + 1;
      Synchronize(
        procedure
        begin
          Form1.DisplayR.Lines.Add('Server Socket closed: ' + Msg);
          Form1.DisplayR.GoToTextEnd;
        end);
//      if BLEUnconnectTime > 10 then
//      begin
//        //ShowMessage('蓝牙连接断开，请重新连接');
//        Terminate;
//      end;

    end;
  end;
end;

end.

