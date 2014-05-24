#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->loadButton, SIGNAL(clicked()), this, SLOT(loadPushed()));
    connect(ui->nextButton, SIGNAL(clicked()), this, SLOT(nextPushed()));
    connect(ui->plusButton, SIGNAL(clicked()), this, SLOT(plusPushed()));
    connect(ui->minusButton, SIGNAL(clicked()), this, SLOT(minusPushed()));
    connect(ui->bayanButton, SIGNAL(clicked()), this, SLOT(bayanPushed()));
    ui->quote->setText("Welcome!\nClick 'Load' button to get quotes.");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::loadPushed()
{
    ui->quote->setText("Loading...");
    view = new QWebView();
    view->load(QUrl("http://bash.im/"));
    connect(view, SIGNAL(loadFinished(bool)), this, SLOT(getQuotes()));

}

void Widget::nextPushed()
{
    ui->plusButton->setEnabled(true);
    ui->minusButton->setEnabled(true);
    ui->bayanButton->setEnabled(true);
    if (currQuote >= numberOfQuotes)
        currQuote = 0;
    ui->quote->setText(quotes.at(currQuote).toPlainText() + "\n\n");
    ui->ratingLineEdit->setText(ratings.at(currQuote).toPlainText());
    currQuote++;
}

void Widget::plusPushed()
{
    QString adress = "http://bash.im/quote/" + id.at(currQuote).toPlainText().mid(1);
    QUrl url(adress);
    QNetworkRequest networkRequest(url);
    networkRequest.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    manager->post(networkRequest, "/rulez");
    plusRating();
    ui->plusButton->setEnabled(false);
    ui->minusButton->setEnabled(false);
    ui->bayanButton->setEnabled(false);
}

void Widget::minusPushed()
{
    QString adress = "http://bash.im/quote/" + id.at(currQuote).toPlainText().mid(1);
    QUrl url(adress);
    QNetworkRequest networkRequest(url);
    networkRequest.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    manager->post(networkRequest, "/sux");
    minusRating();
    ui->plusButton->setEnabled(false);
    ui->minusButton->setEnabled(false);
    ui->bayanButton->setEnabled(false);
}

void Widget::bayanPushed()
{
    QString adress = "http://bash.im/quote/" + id.at(currQuote).toPlainText().mid(1);
    QUrl url(adress);
    QNetworkRequest networkRequest(url);
    networkRequest.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    manager->post(networkRequest, "/bayan");
    ui->plusButton->setEnabled(false);
    ui->minusButton->setEnabled(false);
    ui->bayanButton->setEnabled(false);
}

void Widget::getQuotes()
{
    quotes = view->page()->mainFrame()->findAllElements("div[class=text]");
    ratings = view->page()->mainFrame()->findAllElements("span[class=rating]");
    id = view->page()->mainFrame()->findAllElements("a[class=id]");
    currQuote = 0;
    numberOfQuotes = quotes.toList().length();
    nextPushed();
}

void Widget::plusRating()
{
    int rating = ui->ratingLineEdit->text().toInt() + 1;
    ui->ratingLineEdit->setText(QString::number(rating));
}

void Widget::minusRating()
{
    int rating = ui->ratingLineEdit->text().toInt() - 1;
    ui->ratingLineEdit->setText(QString::number(rating));
}
