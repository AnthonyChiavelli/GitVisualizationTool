#include "mainwindow.h"

#include <QApplication>
#include <QtGui>
#include <QtCore>


#include "localrepoparser.h"

using namespace LocalRepoParser;

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    MainWindow window;
    window.setWindowTitle("Gitty Up!");

    // Test getting a branch from the git folder
    string pathToGitFolder = "/home/krose/Development/GitVisualiztionTool/GitVisualizationTool";
    string branchName = "master";
    LocalRepoParser::getBranch(pathToGitFolder, branchName);

    // Test getting a git tree
    LocalRepoParser::getGitTree(pathToGitFolder);

    window.show();
    return a.exec();
}


//void test_GIT_API(){

//    std::string path = "/home";
//    gitAPI::gitInit(path);

//}
