﻿/////////////////////////////////////////////////////////////////////////
// AboutControl.xaml.cs - Control GUI to display message in About tab  //
// ver 1.0                                                             //
// Jim Fawcett, CSE687 - Object Oriented Design, Spring 2018           //
/////////////////////////////////////////////////////////////////////////
/*
 * Package Operations:
 * -------------------
 * This package provides a WPF-based control GUI for Project4Demo.  It's 
 * responsibilities are to:
 * - Provide a display of an "about" message.
 *   
 * Required Files:
 * ---------------
 * AboutControl.xaml, AboutControl.xaml.cs
 * 
 * Maintenance History:
 * --------------------
 * ver 1.0 : 22 Apr 2018
 * - first release
 */
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Threading;
using System.IO;
using MsgPassingCommunication;

namespace WpfApp1
{
  public partial class AboutControl : UserControl
  {
    public AboutControl()
    {
      InitializeComponent();
      showFile("../../../../About.txt");
    }

    /*private void Button_Connect(object sender, RoutedEventArgs e)
        {
            CsEndPoint serverEndPoint = new CsEndPoint();
            serverEndPoint.machineAddress = "localhost";
            serverEndPoint.port = 8080;
            CsMessage msg = new CsMessage();
            msg.add("to", CsEndPoint.toString(serverEndPoint));
            msg.add("from", CsEndPoint.toString(endPoint_));
            msg.add("command", "doConnect");
            msg.add("path", ServerPort.Text);
            translater.postMessage(msg);
        }*/
    //----< show file text >-------------------------------------------

    private void showFile(string fileName)
    {
      Paragraph paragraph = new Paragraph();
      string fileSpec = fileName;
      string fileText = System.IO.File.ReadAllText(fileSpec);
      paragraph.Inlines.Add(new Run(fileText));
      AboutView.Blocks.Add(paragraph);
    }
  }
}
