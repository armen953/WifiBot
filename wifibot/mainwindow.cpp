#include "mainwindow.h"
#include "ui_mainwindow.h"

/**
 * @brief Constructor of the class
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QMainWindow::setFocus();
    this->ui->setupUi(this);
    this->ui->haut->setArrowType(Qt::UpArrow);
    this->ui->bas->setArrowType(Qt::DownArrow);
    this->ui->droite->setArrowType(Qt::RightArrow);
    this->ui->gauche->setArrowType(Qt::LeftArrow);

    // init label with slider value
    this->ui->labelVitesse->setText(QString::number(this->ui->vitesse->value()));

    // chnage the color of batterie indicotor to green
    ui->batterie->setStyleSheet(this->battrieSafeColor);


    this->setWindowTitle("WIFIBOT MAHMEDOV PATRU");

    //center the window on the screen ceneter
    QRect position = frameGeometry();
    move(position.center());

    this->wifibotcontroller = new WifiBotController(this);
    this->cameraControl = new QNetworkAccessManager();
    connect(this->ui->vitesse, SIGNAL(valueChanged(int)), SLOT(setValueToTheLabel(int)));
    disableInterface();
}

/**
 * @brief Destructor (free the memory alocated)
 */
MainWindow::~MainWindow()
{
    delete this->ui;
    delete wifibotcontroller;
    delete cameraControl;
}

/**
 * @brief Event when a key is pressed
 * @param event the event
 */
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Z: // move forward
        //this->wifibotcontroller->moveWifibot(Direction::up,240,240);
        //this->wifibotcontroller->setIsMovingForward(true);

        this->ui->z->animateClick();  // call the function
        // FAIRE ANIMATE CLICK OU APPELER LA FNC POUR PASSER A TRUE

        // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! FAIRE PAREIL QU'ICI POUR LES AUTRES

        //qDebug() << this->wifibotcontroller->getIsMovingForward();
        break;

    case Qt::Key_Q:  // go left
        this->wifibotcontroller->setIsGoingLeft(true);
//        this->wifibotcontroller->moveWifibot(Direction::left,240,240);
        break;

    case Qt::Key_S: // go back
        this->wifibotcontroller->setIsMovingBack(true);
        break;

    case Qt::Key_D: //go right
        this->wifibotcontroller->setIsGoingRight(true);
        break;

    case Qt::Key_Up: // up camezra
        this->ui->haut->animateClick();
        break;

    case Qt::Key_Down: // down camera
        this->ui->bas->animateClick();
        break;

    case Qt::Key_Left: // move left camera
        this->ui->gauche->animateClick();
        break;

    case Qt::Key_Right: // move right camera
        this->ui->droite->animateClick();
        break;
    }
}

/**
 * @brief Event when a key is released
 * @param event the event
 */
void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    switch(event->key()){
    case Qt::Key_Z:
        this->wifibotcontroller->setIsMovingForward(false);
        //qDebug() << this->wifibotcontroller->getIsMovingForward();
        break;
    case Qt::Key_Q:
        this->wifibotcontroller->setIsGoingLeft(false);
        break;
    case Qt::Key_S:
        this->wifibotcontroller->setIsMovingBack(false);
        break;
    case Qt::Key_D:
        this->wifibotcontroller->setIsGoingRight(false);
        break;
    }
}

/**
 * @brief disable interface
 * disable interface when client is not conectd whith wifibot
 * And enable the hostname, port and connec button
 */
void MainWindow::disableInterface()
{
    QMainWindow::setFocus();
    // disable controll interface
    this->ui->z->setEnabled(false);
    this->ui->q->setEnabled(false);
    this->ui->s->setEnabled(false);
    this->ui->d->setEnabled(false);
    this->ui->vitesse->setEnabled(false);
    this->ui->haut->setEnabled(false);
    this->ui->bas->setEnabled(false);
    this->ui->gauche->setEnabled(false);
    this->ui->droite->setEnabled(false);
    // enable connection info interface
    this->ui->btnDeconnect->setEnabled(false);
    this->ui->hostname->setEnabled(true);
    this->ui->port->setEnabled(true);
    this->ui->btnConnect->setEnabled(true);
}

/**
 * @brief enable interface
 * enable interface when successfuly connected with the wifibot
 * And disable the hostname, port and connec button
 */
void MainWindow::enableInterface()
{
    QMainWindow::setFocus();
    // enable controll interface
    this->ui->z->setEnabled(true);
    this->ui->q->setEnabled(true);
    this->ui->s->setEnabled(true);
    this->ui->d->setEnabled(true);
    this->ui->vitesse->setEnabled(true);
    this->ui->haut->setEnabled(true);
    this->ui->bas->setEnabled(true);
    this->ui->gauche->setEnabled(true);
    this->ui->droite->setEnabled(true);
    // disable connection info interface
    this->ui->btnDeconnect->setEnabled(true);
    this->ui->hostname->setEnabled(false);
    this->ui->port->setEnabled(false);
    this->ui->btnConnect->setEnabled(false);
}

//void MainWindow::displayWarningOnScreen(QString title, QString mgs)
//{
//     QMessageBox::warning(this, title, mgs, QMessageBox::Ok);
//}

/**
 * @brief Event when the connecion button is pressed
 * Connection
 */
void MainWindow::on_btnConnect_clicked()
{
    this->hostname = ui->hostname->text();
    this->port = ui->port->text().toInt();
    this->wifibotcontroller->hello();

    qDebug() << this->wifibotcontroller->attemptConnection(this->hostname, this->port);
    // stocker le retour de attemptConnection dans un bool et faire le reste quand le boot = true
    QString source = "http://" + ui->hostname->text() + ":8080/javascript_simple.html";  // ou /?action=stream
    qDebug() << source;
    this->ui->camera->load(QUrl(source));
    this->ui->camera->setZoomFactor(1.4);
    this->ui->camera->setStyleSheet("background-color:#ffffff;");
    this->ui->camera->setZoomFactor(1.8);
    this->ui->camera->show();
    enableInterface();
}

/**
 * @brief Event when deconnect button is pressed
 * Deconnection
 */
void MainWindow::on_btnDeconnect_clicked()
{
    this->wifibotcontroller->endConnection();
    this->ui->camera->stop();
    disableInterface();
}

/**
 * @brief MainWindow::setValueToTheLabel
 * @param value
 */
void MainWindow::setValueToTheLabel(int value)
{
     this->ui->labelVitesse->setText(QString::number(value));
}

/**
 * @brief MainWindow::on_z_pressed
 */
void MainWindow::on_z_pressed()
{
    this->wifibotcontroller->setIsMovingForward(true);
}

/**
 * @brief MainWindow::on_q_pressed
 */
void MainWindow::on_q_pressed()
{
    this->wifibotcontroller->setIsGoingLeft(true);
}

/**
 * @brief MainWindow::on_s_pressed
 */
void MainWindow::on_s_pressed()
{
    this->wifibotcontroller->setIsMovingBack(true);
}

/**
 * @brief MainWindow::on_d_pressed
 */
void MainWindow::on_d_pressed()
{
    this->wifibotcontroller->setIsGoingRight(true);
}

/**
 * @brief MainWindow::on_z_released
 */
void MainWindow::on_z_released()
{
    this->wifibotcontroller->setIsMovingForward(false);
}

/**
 * @brief MainWindow::on_q_released
 */
void MainWindow::on_q_released()
{
    this->wifibotcontroller->setIsGoingLeft(false);
}

/**
 * @brief MainWindow::on_s_released
 */
void MainWindow::on_s_released()
{
    this->wifibotcontroller->setIsMovingBack(false);
}

/**
 * @brief MainWindow::on_d_released
 */
void MainWindow::on_d_released()
{
    this->wifibotcontroller->setIsGoingRight(false);
}

/*=================================
*       MOVE CAMERA EVENTS
=================================*/
/**
 * @brief MainWindow::on_haut_clicked
 */
void MainWindow::on_haut_clicked()
{
    QUrl url("http://" + ui->hostname->text() + ":8080" + CameraDirection::up);
    this->cameraControl->get(QNetworkRequest(url));
}

/**
 * @brief MainWindow::on_gauche_clicked
 */
void MainWindow::on_gauche_clicked()
{
    QUrl url("http://" + ui->hostname->text()+ ":8080" + CameraDirection::left);
    this->cameraControl->get(QNetworkRequest(url));
}

/**
 * @brief MainWindow::on_bas_clicked
 */
void MainWindow::on_bas_clicked()
{
    QUrl url("http://" + ui->hostname->text() + ":8080" + CameraDirection::down);
    this->cameraControl->get(QNetworkRequest(url));
}

/**
 * @brief MainWindow::on_droite_clicked
 */
void MainWindow::on_droite_clicked()
{
    QUrl url("http://" + ui->hostname->text()+":8080" + CameraDirection::right);
    this->cameraControl->get(QNetworkRequest(url));
}
