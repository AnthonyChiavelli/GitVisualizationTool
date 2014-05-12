#ifndef GBRANCHLABEL_H
#define GBRANCHLABEL_H
#include <QGraphicsItem>

using namespace std;

// -- Appearance properties --
#define LABEL_WIDTH 50
#define LABEL_HEIGHT 30

#define LABEL_BG_COLOR QColor()

/*
 * Graphical branch label pointing to the commit the branch refers to
 */
class GBranchLabel : public QObject, public QGraphicsItem {
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)

public:

    // -- Constructors --
    explicit GBranchLabel(QGraphicsItem *parent = 0);

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

    void renderLabelText();
    void renderLabelRectangle();
private:

    // Name of branch
    QString branchName;

    // Commit to which we point
    GCommitNode *associatedCommit;

};

#endif // GBRANCHLABEL_H
