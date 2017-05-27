#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <opencv2/video/tracking.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/videoio/videoio.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>
#include <ctype.h>

#include <QMainWindow>
#include <QTimer>

using namespace cv;
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Point2f point;
    bool addRemovePt = false;
    void onMouse( int event, int x, int y, int /*flags*/, void* /*param*/ )
    {
        if( event == EVENT_LBUTTONDOWN )
        {
            point = Point2f((float)x, (float)y);
            addRemovePt = true;
        }
    }
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QTimer *timer;
    Ui::MainWindow *ui;

public slots:
    void updatePicture();
};

#endif // MAINWINDOW_H
