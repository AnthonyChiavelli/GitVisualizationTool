#ifndef GGRAPHICSSCENE_H
#define GGRAPHICSSCENE_H

#include <QGraphicsScene>

class GRepoScene : public QGraphicsScene {
    Q_OBJECT
public:
    explicit GRepoScene(QObject *parent = 0);

    // Attach a commit node as the root commit node
    void attachRootCommitNode(int rootNode);

    // Draw the scene
    void renderScene();

signals:

public slots:

};

#endif // GGRAPHICSSCENE_H
