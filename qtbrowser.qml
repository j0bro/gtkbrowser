import QtQuick 2.0
import QtWebKit 3.0

Rectangle {
   id: root
   width:800
   height:600

   WebView {
       id: webView
       clip: false
       anchors {
           top: parent.top
           left: parent.left
           right: parent.right
           bottom: parent.bottom
       }
   }

   Component.onCompleted: {
     webView.url = "http://www.html5test.com/"
   }
}
