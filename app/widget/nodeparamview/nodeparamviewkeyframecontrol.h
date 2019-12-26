#ifndef NODEPARAMVIEWKEYFRAMECONTROL_H
#define NODEPARAMVIEWKEYFRAMECONTROL_H

#include <QPushButton>
#include <QWidget>

#include "node/input.h"

class NodeParamViewKeyframeControl : public QWidget
{
  Q_OBJECT
public:
  NodeParamViewKeyframeControl(NodeInput* input, QWidget* parent = nullptr);

  NodeInput* GetConnectedInput() const;

  void SetPreviousButtonEnabled(bool enabled);
  void SetNextButtonEnabled(bool enabled);
  void SetToggleButtonChecked(bool checked);

public slots:
  void SetKeyframeEnabled(bool e);

signals:
  void KeyframeEnableChanged(bool);

  void GoToPreviousKey();
  void GoToNextKey();

  void KeyframeToggled(bool);

private:
  QPushButton* CreateNewToolButton(const QIcon &icon) const;

  QPushButton* prev_key_btn_;
  QPushButton* toggle_key_btn_;
  QPushButton* next_key_btn_;
  QPushButton* enable_key_btn_;

  NodeInput* input_;

private slots:
  void ShowButtonsFromKeyframeEnable(bool e);
};

#endif // NODEPARAMVIEWKEYFRAMECONTROL_H
