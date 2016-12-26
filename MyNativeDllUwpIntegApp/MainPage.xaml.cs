using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Runtime.InteropServices.WindowsRuntime;
using System.Text;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Popups;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

namespace MyNativeDllUwpIntegApp
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class MainPage : Page
    {
        public MainPage()
        {
            this.InitializeComponent();
        }

        protected override async void OnNavigatedTo(NavigationEventArgs e)
        {
            base.OnNavigatedTo(e);

            MyRegisterLogFunc(log => 
            {
                Debug.WriteLine(log);
            });

            var result = Add(1, 2);
            this.TbLog.Text += $"result : {result}\n";

            var result2 = GetStr();

            var sb = new StringBuilder();
            MyStrCpy(sb, "abc");

            var buf = new byte[] { 0x30, 0x31, 0x32, 0x33, 0x34 };

            for (int i = 0; i < 10; i++)
            {
                var result3 = MyPassByteArray(buf, i);
            }

            var result4 = MyStrConcat("aa", "bb");
        }

        [DllImport("MySimpleNativeDll")]
        static extern int Add(int x, int y);

        [DllImport("MySimpleNativeDll")]
        [return: MarshalAs(unmanagedType:UnmanagedType.LPWStr)]
        static extern string GetStr();

        //MYSIMPLENATIVEDLL_API void MyStrCpy(LPWSTR wStr, LPCWSTR wStr2)
        [DllImport("MySimpleNativeDll")]
        static extern void MyStrCpy(StringBuilder wStr, string wStr2);

        //MYSIMPLENATIVEDLL_API LPCWSTR MyPassByteArray(unsigned char* pBuf, int iIdx)
        [DllImport("MySimpleNativeDll")]
        [return: MarshalAs(unmanagedType: UnmanagedType.LPWStr)]
        static extern string MyPassByteArray(byte[] pBuf, int iIdx);

        //MYSIMPLENATIVEDLL_API LPCWSTR MyStrConcat(LPCSTR szStr, LPCSTR szStr2)
        [DllImport("MySimpleNativeDll")]
        [return: MarshalAs(unmanagedType: UnmanagedType.LPWStr)]
        static extern string MyStrConcat(string szStr, string szStr2);

        //MYSIMPLENATIVEDLL_API void MyRegisterLogFunc(PFUNC_MYCALLBACK pFuncLog);
        [DllImport("MySimpleNativeDll")]
        static extern void MyRegisterLogFunc(PFUNC_MYCALLBACK pFuncLog);

        public delegate void PFUNC_MYCALLBACK([MarshalAs(unmanagedType:UnmanagedType.LPWStr)]string log);
    }
}
