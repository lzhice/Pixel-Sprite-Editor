#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QWidget>
#include <vector>
#include <QPixmap>
#include <string.h>
#include <QColor>
#include <stdint.h>

namespace ui {
class Model;
}

class Model: public QWidget
{
    Q_OBJECT
public:
    Model(QWidget *parent = 0);
    QSize size;

signals:
    void colorChanged(QColor);
    void frameAdded(std::vector<QImage>);
    void frameRemoved(std::vector<QImage>);
    void updated(QImage);

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;

public slots:
    void setUp(int canvasSize);
    void undoButtonClicked();
    void redoButtonClicked();

    void penButtonClicked();
    void eraserButtonClicked();
    void rectButtonClicked();
    void lineButtonClicked();
    void colorPickerButtonClicked();
    void colorCasterButtonClicked();
    void bucketButtonClicked();
    void mirrorHorizontalButtonToggled(bool checked);
    void mirrorVerticalButtonToggled(bool checked);
    void flipHorizontalButtonClicked();
    void flipVerticalButtonClicked();
    void rotateClockwiseButtonClicked();
    void rotateCounterClockwiseButtonClicked();

    void sliderValueChanged(int change);
    void colorPicked(QColor c);

    void previewButtonClicked();
    void addFrameButtonClicked();
    void duplicateFrameButtonClicked(int i);
    void removeFrameButtonClicked(int i);
    void FPSSpinBoxChanged(int change);

    void saveButtonClicked();

    std::vector<QImage> getFrames();
    void exportSelected(int, std::string, int);

    void addFrame();
    QImage getFrame(int i);
    void changeFrame(int i);

private:
    std::vector<QImage> frames;
    int currentFrame;

    QImage image;
    int scale;

    QColor currentColor;

    void draw(QPoint);
    QPoint lastPoint;
    QPoint mirrorLastPointX;
    QPoint mirrorLastPointY;
    QPoint mirrorLastPointXY;

    int toolSize;

    enum Tool {Pen, Eraser, Line, Caster, Picker, Bucket};
    int currentTool;

    bool mirrorHorizontalActive;
    bool mirrorVerticalActive;

    void convertFrameToArray(uint8_t*, int, int);
};

#endif // MODEL_H
