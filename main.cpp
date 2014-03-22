#include "mainwindow.h"
#include <QApplication>

#include "localrepoparser.h"

using namespace LocalRepoParser;

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    // Test getting a branch from the git folder
    string pathToGitFolder = "/home/krose/Development/GitVisualiztionTool/GitVisualizationTool/.git";
    string branchName = "master";
    LocalRepoParser::getBranch(pathToGitFolder, branchName);

    return a.exec();
}
