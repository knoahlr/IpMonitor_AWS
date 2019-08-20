#pragma once


#include <QtWidgets/QMainWindow>
#include <QtGui>
#include <QtWidgets>
#include <QHBoxLayout>
#include <string.h>
#include <boost/thread.hpp>
#include <map>
#include <prDefault.h>



using namespace std;

class ipMonitor: public QMainWindow
{
	Q_OBJECT

public:
	Archiver(QWidget *parent = Q_NULLPTR);

	// Fields and Main Window variables
	QWidget *centralWidget;
	QVBoxLayout *centralLayout;
	QIcon *Icon;
	int simulationSize;
	boost::thread* thr;
	DefaultStatusBar *statusBar;

	QString rootFilePath;
	QString archiveFilePath;
	QString rootDirName;

	//GroupBoxes 
	QGroupBox *rootFolderGroupBox;
	QGroupBox  *archiveFolderGroupBox;
	QGroupBox *archiveButtonGroupBox;
	QFormLayout *rootFolderGroupBoxLayout;
	QFormLayout *archiveFolderGroupBoxLayout;
	QVBoxLayout *archiveButtonLayout;


	//Push buttons and LineEdits
	QLineEdit *rootFolderLineEdit;
	QLineEdit *archiveFolderLineEdit;
	QPushButton *rootBrowseButton;
	QPushButton *archiveBrowseButton;
	QPushButton *archiveButton;



	map<boost::thread::id, int> threadMap;
	void dirCopier(void);

	//Member Functions
public slots:

	void handleRootBrowse(void);
	void handleArchiveBrowse(void);
	void handleArchive(void);


};
