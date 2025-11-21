#ifndef PLAYERWINDOW_H
#define PLAYERWINDOW_H

#include <QtWidgets/QOpenGLWidget>
#include <mpv/client.h>
#include <mpv/render_gl.h>
#include "../common/qthelper.hpp"

#include <QOpenGLFramebufferObject>

class MpvWidget Q_DECL_FINAL: public QOpenGLWidget
{
    Q_OBJECT
public:
    MpvWidget(QWidget *parent = 0, Qt::WindowFlags f = 0);
    ~MpvWidget();
    void command(const QVariant& params);
    void setProperty(const QString& name, const QVariant& value);
    QVariant getProperty(const QString& name) const;
    QSize sizeHint() const { return QSize(480, 270);}

    void open(QString& file);

    void saveNextFrameAs(const QString &filePath);
    QString m_savePath;
    bool m_saveNextFrame = false;

     static void* getCb(void* ctx, const char* name);

    //bool saveCurrentFrame(mpv_handle* mpv, const QString& filePath);

     void enableTimeWatermark(bool enable);


Q_SIGNALS:
    void durationChanged(int value);
    void positionChanged(int value);
protected:
    void initializeGL() Q_DECL_OVERRIDE;
    void paintGL() Q_DECL_OVERRIDE;
private Q_SLOTS:
    void on_mpv_events();
    void maybeUpdate();
private:
    void handle_mpv_event(mpv_event *event);
    static void on_update(void *ctx);

    mpv_handle *mpv;
    mpv_render_context *mpv_gl;

    QOpenGLFramebufferObject* m_fbo = nullptr;
};



#endif // PLAYERWINDOW_H
