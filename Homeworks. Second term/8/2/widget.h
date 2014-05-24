#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QTextCodec>
#include <QtWebKit/QWebElement>
#include <QWebFrame>
#include <QWebPage>
#include <QWebView>
#include <QDomDocument>
#include <QWebView>

namespace Ui {
class Widget;
}

///Class for working with bash.im
class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void plusPushed();
    void minusPushed();
    void bayanPushed();
    void loadPushed();
    void nextPushed();
    void getQuotes();

private:
    Ui::Widget *ui;
    ///Contains quotes from bash.im
    QWebElementCollection quotes;
    ///Contains ratings of quotes from bash.im
    QWebElementCollection ratings;
    QWebElementCollection id;
    ///Method for plus button
    void plusRating();
    ///Method for minus button
    void minusRating();
    ///Index of current quote
    int currQuote;
    int numberOfQuotes;
    QWebView *view;
};

#endif // WIDGET_H
