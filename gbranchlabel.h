#ifndef GBRANCHLABEL_H
#define GBRANCHLABEL_H
#include <QGraphicsItem>

#include "gcommitnode.h"

using namespace std;

// -- Appearance properties --
#define LABEL_WIDTH 60
#define LABEL_HEIGHT 40

#define LABEL_BG_COLOR QColor(135, 71, 71)
#define LABEL_TEXT_COLOR QColor(255, 255, 255)

/*
 * Graphical branch label pointing to the commit the branch refers to
 */
class GBranchLabel : public QObject, public QGraphicsItem {
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)

public:

    // -- Constructors --
    explicit GBranchLabel(QGraphicsItem *parent = 0);
    explicit GBranchLabel(QString branchName);

    // -- Graphics methods (required)
    // Returns estimated bounding box
    QRectF boundingRect() const;
    // Performs actual object rendering
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    // -- Getters and setters --
    QString getBranchName() const;
    void setBranchName(const QString &value);

    GCommitNode *getAssociatedCommit() const;
    void setAssociatedCommit(GCommitNode *value);

protected:

    // -- Rendering helper methods
    void renderLabelRectangle(QPainter *painter);
    void renderLabelText(QPainter *painter);

private:

    // Name of branch
    QString branchName;

    // Commit to which we point
    GCommitNode *associatedCommit;

};

#endif // GBRANCHLABEL_H
