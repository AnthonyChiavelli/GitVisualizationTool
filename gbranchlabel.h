#ifndef GBRANCHLABEL_H
#define GBRANCHLABEL_H

#include <QGraphicsItem>

class QGraphicsItem;
class Branch;
class GCommitNode;

using namespace std;

// -- Appearance properties --
#define LABEL_WIDTH 60
#define LABEL_HEIGHT 40

#define BRANCH_LABEL_OFFSET 40
#define BRANCH_LABEL_DISTANCE 75

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
    // Conversion constructor
    GBranchLabel(Branch *branch);

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

    // Establish position
    void establishPosition(int branchNum, int childRanking);

protected:

    // -- Rendering helper methods
    void renderLabelRectangle(QPainter *painter);
    void renderLabelText(QPainter *painter);
    void renderLabelLine(QPainter *painter);

    // -- QT Callbacks --
    // Called when there is some change done to an item
    QVariant itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value);

private:

    // Name of branch
    QString branchName;

    // Commit to which we point
    GCommitNode *associatedCommit;

};

#endif // GBRANCHLABEL_H
