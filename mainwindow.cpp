#include "mainwindow.h"
#include "chaya-fft_autogen/include/ui_mainwindow.h"
#include <QFileDialog>

#include <cstdint>
#include <filesystem>
#include <fstream>
#include <string>

#include "libs/AudioFile/AudioFile.h"

#include "src/cli-utils/cli.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(this, "Open a file", "/");

    ui->plainTextEdit->setPlainText(file_name);
}


void MainWindow::on_pushButton_2_clicked()
{
    std::string filename;

    std::string path = ui->plainTextEdit->toPlainText().toStdString();

  auto out = parse(path, filename);
  printf("op done\n");

  int i = 0;
  std::string name;
  for (auto wav : out) {
    name = filename + "-" + std::to_string(i) + ".wav";
    std::cout << "saving file " << name << std::endl;
    wav.save(name);
    i++;
  }

  printf("saved all\n");
}

