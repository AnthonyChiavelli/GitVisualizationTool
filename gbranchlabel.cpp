#include "gbranchlabel.h"

GBranchLabel::GBranchLabel(QGraphicsItem *parent) : QGraphicsItem(parent) {
}

GBranchLabel::GBranchLabel(QString branchName){

    // Allow the object to be dragged around
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);

    this->branchName = branchName;
}

QRectF GBranchLabel::boundingRect() const {
    return QRect(0,0, LABEL_WIDTH, LABEL_HEIGHT);
}

void GBranchLabel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {

    // Render the rectangle
    renderLabelRectangle(painter);

    // Render the text
    renderLabelText(painter);
}

void GBranchLabel::renderLabelRectangle(QPainter *painter) {

    // Paint a rectangle
    painter->setBrush(LABEL_BG_COLOR);
    QRect rect = QRect(0, 0, LABEL_WIDTH, LABEL_HEIGHT);
    painter->drawRect(rect);
}

void GBranchLabel::renderLabelText(QPainter *painter) {

    // Set up font
    QFont font;
    font.setPointSize(10);

    // Branch name label metrics
    QFontMetrics fontMetrics(font);
    int labelTextWidth = fontMetrics.width(this->branchName);
    int labelTextHeight = fontMetrics.height();

    // Calculate margins necessary to center text in label
    int labelTextTopMargin = ((LABEL_HEIGHT - labelTextHeight) / 2) + 13;
    int labelTextLeftMargin = (LABEL_WIDTH - labelTextWidth) / 2;

    // Render the label
    painter->setBrush(LABEL_TEXT_COLOR);
    painter->setPen(LABEL_TEXT_COLOR);
    painter->setFont(font);
    QPointF labelTextPosition = QPointF(labelTextLeftMargin, labelTextTopMargin);
    painter->drawText(labelTextPosition, this->branchName);

}

QString GBranchLabel::getBranchName() const { return branchName; }
void GBranchLabel::setBranchName(const QString &value) { branchName = value; }

GCommitNode *GBranchLabel::getAssociatedCommit() const { return associatedCommit; }
void GBranchLabel::setAssociatedCommit(GCommitNode *value) { associatedCommit = value; }
