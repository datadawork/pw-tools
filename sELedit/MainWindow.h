#pragma once

#include "..\COMMON\eListCollection.h"
#include "..\COMMON\eListConversation.h"
#include "..\COMMON\DebugWindow.h"
#include "ReplaceWindow.h"
#include "JoinWindow.h"
#include "ConfigWindow.h"
#include "RulesWindow.h"
#include "ClassMaskWindow.h"
#include "LoseQuestWindow.h"
#include "ReferencesWindow.h"

using namespace System;
using namespace System::IO;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Text;

public ref class MainWindow : public System::Windows::Forms::Form
{
	public:
	MainWindow(void)
	{
		InitializeComponent();
		this->Icon = (Drawing::Icon^)((gcnew Resources::ResourceManager("sTools.icons", Reflection::Assembly::GetExecutingAssembly()))->GetObject("app"));
		mouseMoveCheck = gcnew Point(0,0);
	}

	/// <summary>
	/// Clean up any resources being used.
	/// </summary>
	~MainWindow()
	{
		if (components)
		{
			delete components;
		}
		delete eLC;
	}

	eListCollection^ eLC;
	eListConversation^ conversationList;
	array<array<String^>^>^xrefs;
	private: Point^ mouseMoveCheck;

	public: static System::Windows::Forms::ListBox^  listBox_items;
	public: static System::Windows::Forms::ComboBox^  comboBox_lists;
	private: System::Windows::Forms::DataGridView^  dataGridView_item;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::Button^  button_search;
	private: System::Windows::Forms::TextBox^  textBox_search;
	private: System::Windows::Forms::ProgressBar^  progressBar_progress;
	private: System::Windows::Forms::MenuStrip^  menuStrip_mainMenu;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  loadToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exportContainerToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^  logicReplaceToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem3;
	private: System::Windows::Forms::ToolStripMenuItem^  configEditorToolStripMenuItem;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip_items;
	private: System::Windows::Forms::ToolStripMenuItem^  cloneItemToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  deleteItemToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripMenuItem^  exportItemToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  replaceItemToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  nPCListExportToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  joinToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  nPCAILinkListToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  skillReplaceToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  propertyReplaceToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  tomeReplace136OnlyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  taskOverflowCheck143OnlyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  classMaskGeneratorToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  skillInvalidCheck136OnlyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  tomeInvalidCheck136OnlyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  propertyInvalidChaeck136OnlyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  probabilityVerification136OnlyToolStripMenuItem;
	private: System::Windows::Forms::ToolTip^  toolTip;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox_offset;
	private: System::Windows::Forms::ToolStripMenuItem^  eLVersionToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  elementStructureDiffToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator2;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator3;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator4;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator5;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator6;
	private: System::Windows::Forms::ToolStripMenuItem^  xrefItemToolStripMenuItem;
	private: System::ComponentModel::IContainer^  components;

#pragma region Windows Form Designer generated code
	/// <summary>
	/// Required method for Designer support - do not modify
	/// the contents of this method with the code editor.
	/// </summary>
	void InitializeComponent(void)
	{
		this->components = (gcnew System::ComponentModel::Container());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		this->listBox_items = (gcnew System::Windows::Forms::ListBox());
		this->contextMenuStrip_items = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
		this->cloneItemToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->deleteItemToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
		this->exportItemToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->replaceItemToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->toolStripSeparator6 = (gcnew System::Windows::Forms::ToolStripSeparator());
		this->xrefItemToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->comboBox_lists = (gcnew System::Windows::Forms::ComboBox());
		this->dataGridView_item = (gcnew System::Windows::Forms::DataGridView());
		this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->button_search = (gcnew System::Windows::Forms::Button());
		this->textBox_search = (gcnew System::Windows::Forms::TextBox());
		this->progressBar_progress = (gcnew System::Windows::Forms::ProgressBar());
		this->menuStrip_mainMenu = (gcnew System::Windows::Forms::MenuStrip());
		this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->loadToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->exportContainerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->logicReplaceToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->toolStripSeparator5 = (gcnew System::Windows::Forms::ToolStripSeparator());
		this->skillInvalidCheck136OnlyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->skillReplaceToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->tomeInvalidCheck136OnlyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->tomeReplace136OnlyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->propertyInvalidChaeck136OnlyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->propertyReplaceToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->probabilityVerification136OnlyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->taskOverflowCheck143OnlyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->toolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->eLVersionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->configEditorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->elementStructureDiffToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->toolStripSeparator4 = (gcnew System::Windows::Forms::ToolStripSeparator());
		this->nPCListExportToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->nPCAILinkListToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
		this->joinToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->toolStripSeparator3 = (gcnew System::Windows::Forms::ToolStripSeparator());
		this->classMaskGeneratorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->toolTip = (gcnew System::Windows::Forms::ToolTip(this->components));
		this->label1 = (gcnew System::Windows::Forms::Label());
		this->textBox_offset = (gcnew System::Windows::Forms::TextBox());
		this->contextMenuStrip_items->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_item))->BeginInit();
		this->menuStrip_mainMenu->SuspendLayout();
		this->SuspendLayout();
		// 
		// listBox_items
		// 
		this->listBox_items->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
			| System::Windows::Forms::AnchorStyles::Left));
		this->listBox_items->ContextMenuStrip = this->contextMenuStrip_items;
		this->listBox_items->FormattingEnabled = true;
		this->listBox_items->Location = System::Drawing::Point(3, 57);
		this->listBox_items->Name = L"listBox_items";
		this->listBox_items->Size = System::Drawing::Size(203, 342);
		this->listBox_items->TabIndex = 2;
		this->listBox_items->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWindow::listBox_items_MouseDoubleClick);
		this->listBox_items->SelectedIndexChanged += gcnew System::EventHandler(this, &MainWindow::change_item);
		// 
		// contextMenuStrip_items
		// 
		this->contextMenuStrip_items->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {this->cloneItemToolStripMenuItem, 
			this->deleteItemToolStripMenuItem, this->toolStripSeparator1, this->exportItemToolStripMenuItem, this->replaceItemToolStripMenuItem, 
			this->toolStripSeparator6, this->xrefItemToolStripMenuItem});
		this->contextMenuStrip_items->Name = L"contextMenuStrip_items";
		this->contextMenuStrip_items->RenderMode = System::Windows::Forms::ToolStripRenderMode::System;
		this->contextMenuStrip_items->ShowImageMargin = false;
		this->contextMenuStrip_items->Size = System::Drawing::Size(169, 126);
		// 
		// cloneItemToolStripMenuItem
		// 
		this->cloneItemToolStripMenuItem->Name = L"cloneItemToolStripMenuItem";
		this->cloneItemToolStripMenuItem->Size = System::Drawing::Size(168, 22);
		this->cloneItemToolStripMenuItem->Text = L"Clone Selected Item";
		this->cloneItemToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::click_cloneItem);
		// 
		// deleteItemToolStripMenuItem
		// 
		this->deleteItemToolStripMenuItem->Name = L"deleteItemToolStripMenuItem";
		this->deleteItemToolStripMenuItem->Size = System::Drawing::Size(168, 22);
		this->deleteItemToolStripMenuItem->Text = L"Delete Selected Item";
		this->deleteItemToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::click_deleteItem);
		// 
		// toolStripSeparator1
		// 
		this->toolStripSeparator1->Name = L"toolStripSeparator1";
		this->toolStripSeparator1->Size = System::Drawing::Size(165, 6);
		// 
		// exportItemToolStripMenuItem
		// 
		this->exportItemToolStripMenuItem->Name = L"exportItemToolStripMenuItem";
		this->exportItemToolStripMenuItem->Size = System::Drawing::Size(168, 22);
		this->exportItemToolStripMenuItem->Text = L"Export Selected Item...";
		this->exportItemToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::click_exportItem);
		// 
		// replaceItemToolStripMenuItem
		// 
		this->replaceItemToolStripMenuItem->Name = L"replaceItemToolStripMenuItem";
		this->replaceItemToolStripMenuItem->Size = System::Drawing::Size(168, 22);
		this->replaceItemToolStripMenuItem->Text = L"Replace Selected Item...";
		this->replaceItemToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::click_importItem);
		// 
		// toolStripSeparator6
		// 
		this->toolStripSeparator6->Name = L"toolStripSeparator6";
		this->toolStripSeparator6->Size = System::Drawing::Size(165, 6);
		this->toolStripSeparator6->Visible = false;
		// 
		// xrefItemToolStripMenuItem
		// 
		this->xrefItemToolStripMenuItem->Enabled = false;
		this->xrefItemToolStripMenuItem->Name = L"xrefItemToolStripMenuItem";
		this->xrefItemToolStripMenuItem->Size = System::Drawing::Size(168, 22);
		this->xrefItemToolStripMenuItem->Text = L"Search xrefs to Item...";
		this->xrefItemToolStripMenuItem->Visible = false;
		this->xrefItemToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::click_xrefItem);
		// 
		// comboBox_lists
		// 
		this->comboBox_lists->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
		this->comboBox_lists->FormattingEnabled = true;
		this->comboBox_lists->Location = System::Drawing::Point(3, 30);
		this->comboBox_lists->Name = L"comboBox_lists";
		this->comboBox_lists->Size = System::Drawing::Size(203, 21);
		this->comboBox_lists->TabIndex = 1;
		this->comboBox_lists->SelectedIndexChanged += gcnew System::EventHandler(this, &MainWindow::change_list);
		// 
		// dataGridView_item
		// 
		this->dataGridView_item->AllowUserToAddRows = false;
		this->dataGridView_item->AllowUserToDeleteRows = false;
		this->dataGridView_item->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
			| System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->dataGridView_item->BackgroundColor = System::Drawing::SystemColors::Window;
		this->dataGridView_item->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
		this->dataGridView_item->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
		this->dataGridView_item->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {this->Column1, 
			this->Column2, this->Column3});
		this->dataGridView_item->Location = System::Drawing::Point(212, 57);
		this->dataGridView_item->MultiSelect = false;
		this->dataGridView_item->Name = L"dataGridView_item";
		this->dataGridView_item->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
		dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
		dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
		dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
		dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
		dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
		dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView_item->RowHeadersDefaultCellStyle = dataGridViewCellStyle1;
		this->dataGridView_item->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::AutoSizeToFirstHeader;
		this->dataGridView_item->RowTemplate->Height = 18;
		this->dataGridView_item->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView_item->Size = System::Drawing::Size(417, 371);
		this->dataGridView_item->TabIndex = 3;
		this->dataGridView_item->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::change_value);
		this->dataGridView_item->CellMouseMove += gcnew System::Windows::Forms::DataGridViewCellMouseEventHandler(this, &MainWindow::cellMouseMove_ToolTip);
		// 
		// Column1
		// 
		this->Column1->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		this->Column1->HeaderText = L"Name";
		this->Column1->Name = L"Column1";
		this->Column1->ReadOnly = true;
		this->Column1->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->Column1->Width = 40;
		// 
		// Column2
		// 
		this->Column2->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		this->Column2->HeaderText = L"Type";
		this->Column2->Name = L"Column2";
		this->Column2->ReadOnly = true;
		this->Column2->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->Column2->Width = 36;
		// 
		// Column3
		// 
		this->Column3->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
		this->Column3->HeaderText = L"Value";
		this->Column3->Name = L"Column3";
		this->Column3->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		// 
		// button_search
		// 
		this->button_search->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
		this->button_search->Location = System::Drawing::Point(131, 405);
		this->button_search->Name = L"button_search";
		this->button_search->Size = System::Drawing::Size(75, 23);
		this->button_search->TabIndex = 5;
		this->button_search->Text = L"Find Next";
		this->button_search->UseVisualStyleBackColor = true;
		this->button_search->Click += gcnew System::EventHandler(this, &MainWindow::click_search);
		// 
		// textBox_search
		// 
		this->textBox_search->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
		this->textBox_search->Location = System::Drawing::Point(3, 407);
		this->textBox_search->Name = L"textBox_search";
		this->textBox_search->Size = System::Drawing::Size(122, 20);
		this->textBox_search->TabIndex = 4;
		this->textBox_search->Text = L"ID or NAME";
		this->textBox_search->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		// 
		// progressBar_progress
		// 
		this->progressBar_progress->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->progressBar_progress->Location = System::Drawing::Point(3, 434);
		this->progressBar_progress->Name = L"progressBar_progress";
		this->progressBar_progress->Size = System::Drawing::Size(626, 16);
		this->progressBar_progress->TabIndex = 9;
		// 
		// menuStrip_mainMenu
		// 
		this->menuStrip_mainMenu->BackColor = System::Drawing::SystemColors::Control;
		this->menuStrip_mainMenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->toolStripMenuItem1, 
			this->toolStripMenuItem2, this->toolStripMenuItem3});
		this->menuStrip_mainMenu->Location = System::Drawing::Point(0, 0);
		this->menuStrip_mainMenu->Name = L"menuStrip_mainMenu";
		this->menuStrip_mainMenu->Padding = System::Windows::Forms::Padding(0, 2, 2, 2);
		this->menuStrip_mainMenu->RenderMode = System::Windows::Forms::ToolStripRenderMode::System;
		this->menuStrip_mainMenu->Size = System::Drawing::Size(632, 24);
		this->menuStrip_mainMenu->TabIndex = 0;
		this->menuStrip_mainMenu->Text = L"menuStrip1";
		// 
		// toolStripMenuItem1
		// 
		this->toolStripMenuItem1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
		this->toolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->loadToolStripMenuItem, 
			this->saveToolStripMenuItem, this->exportContainerToolStripMenuItem});
		this->toolStripMenuItem1->ImageScaling = System::Windows::Forms::ToolStripItemImageScaling::None;
		this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
		this->toolStripMenuItem1->Padding = System::Windows::Forms::Padding(0);
		this->toolStripMenuItem1->Size = System::Drawing::Size(27, 20);
		this->toolStripMenuItem1->Text = L"File";
		this->toolStripMenuItem1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
		// 
		// loadToolStripMenuItem
		// 
		this->loadToolStripMenuItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
		this->loadToolStripMenuItem->Name = L"loadToolStripMenuItem";
		this->loadToolStripMenuItem->Size = System::Drawing::Size(125, 22);
		this->loadToolStripMenuItem->Text = L"Load...";
		this->loadToolStripMenuItem->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
		this->loadToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::click_load);
		// 
		// saveToolStripMenuItem
		// 
		this->saveToolStripMenuItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
		this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
		this->saveToolStripMenuItem->Size = System::Drawing::Size(125, 22);
		this->saveToolStripMenuItem->Text = L"Save As...";
		this->saveToolStripMenuItem->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
		this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::click_save);
		// 
		// exportContainerToolStripMenuItem
		// 
		this->exportContainerToolStripMenuItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
		this->exportContainerToolStripMenuItem->Name = L"exportContainerToolStripMenuItem";
		this->exportContainerToolStripMenuItem->Size = System::Drawing::Size(125, 22);
		this->exportContainerToolStripMenuItem->Text = L"Export";
		this->exportContainerToolStripMenuItem->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
		// 
		// toolStripMenuItem2
		// 
		this->toolStripMenuItem2->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
		this->toolStripMenuItem2->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(10) {this->logicReplaceToolStripMenuItem, 
			this->toolStripSeparator5, this->skillInvalidCheck136OnlyToolStripMenuItem, this->skillReplaceToolStripMenuItem, this->tomeInvalidCheck136OnlyToolStripMenuItem, 
			this->tomeReplace136OnlyToolStripMenuItem, this->propertyInvalidChaeck136OnlyToolStripMenuItem, this->propertyReplaceToolStripMenuItem, 
			this->probabilityVerification136OnlyToolStripMenuItem, this->taskOverflowCheck143OnlyToolStripMenuItem});
		this->toolStripMenuItem2->ImageScaling = System::Windows::Forms::ToolStripItemImageScaling::None;
		this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
		this->toolStripMenuItem2->Padding = System::Windows::Forms::Padding(0);
		this->toolStripMenuItem2->Size = System::Drawing::Size(29, 20);
		this->toolStripMenuItem2->Text = L"Edit";
		this->toolStripMenuItem2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
		// 
		// logicReplaceToolStripMenuItem
		// 
		this->logicReplaceToolStripMenuItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
		this->logicReplaceToolStripMenuItem->Name = L"logicReplaceToolStripMenuItem";
		this->logicReplaceToolStripMenuItem->Size = System::Drawing::Size(257, 22);
		this->logicReplaceToolStripMenuItem->Text = L"Logic-Replace...";
		this->logicReplaceToolStripMenuItem->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
		this->logicReplaceToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::click_logicReplace);
		// 
		// toolStripSeparator5
		// 
		this->toolStripSeparator5->Name = L"toolStripSeparator5";
		this->toolStripSeparator5->Size = System::Drawing::Size(254, 6);
		// 
		// skillInvalidCheck136OnlyToolStripMenuItem
		// 
		this->skillInvalidCheck136OnlyToolStripMenuItem->Name = L"skillInvalidCheck136OnlyToolStripMenuItem";
		this->skillInvalidCheck136OnlyToolStripMenuItem->Size = System::Drawing::Size(257, 22);
		this->skillInvalidCheck136OnlyToolStripMenuItem->Text = L"Skill Validation Check (1.3.6 only)";
		this->skillInvalidCheck136OnlyToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::click_skillValidate);
		// 
		// skillReplaceToolStripMenuItem
		// 
		this->skillReplaceToolStripMenuItem->Name = L"skillReplaceToolStripMenuItem";
		this->skillReplaceToolStripMenuItem->Size = System::Drawing::Size(257, 22);
		this->skillReplaceToolStripMenuItem->Text = L"Skill-Replace (1.3.6 only)...";
		this->skillReplaceToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::click_skillReplace);
		// 
		// tomeInvalidCheck136OnlyToolStripMenuItem
		// 
		this->tomeInvalidCheck136OnlyToolStripMenuItem->Name = L"tomeInvalidCheck136OnlyToolStripMenuItem";
		this->tomeInvalidCheck136OnlyToolStripMenuItem->Size = System::Drawing::Size(257, 22);
		this->tomeInvalidCheck136OnlyToolStripMenuItem->Text = L"Tome Validation Check (1.3.6 only)";
		this->tomeInvalidCheck136OnlyToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::click_tomeValidate);
		// 
		// tomeReplace136OnlyToolStripMenuItem
		// 
		this->tomeReplace136OnlyToolStripMenuItem->Name = L"tomeReplace136OnlyToolStripMenuItem";
		this->tomeReplace136OnlyToolStripMenuItem->Size = System::Drawing::Size(257, 22);
		this->tomeReplace136OnlyToolStripMenuItem->Text = L"Tome-Replace (1.3.6 only)...";
		this->tomeReplace136OnlyToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::click_tomeReplace);
		// 
		// propertyInvalidChaeck136OnlyToolStripMenuItem
		// 
		this->propertyInvalidChaeck136OnlyToolStripMenuItem->Name = L"propertyInvalidChaeck136OnlyToolStripMenuItem";
		this->propertyInvalidChaeck136OnlyToolStripMenuItem->Size = System::Drawing::Size(257, 22);
		this->propertyInvalidChaeck136OnlyToolStripMenuItem->Text = L"Property Validation Check (1.3.6 only)";
		this->propertyInvalidChaeck136OnlyToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::click_propertyValidate);
		// 
		// propertyReplaceToolStripMenuItem
		// 
		this->propertyReplaceToolStripMenuItem->Name = L"propertyReplaceToolStripMenuItem";
		this->propertyReplaceToolStripMenuItem->Size = System::Drawing::Size(257, 22);
		this->propertyReplaceToolStripMenuItem->Text = L"Property-Replace (1.3.6 only)...";
		this->propertyReplaceToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::click_propertyReplace);
		// 
		// probabilityVerification136OnlyToolStripMenuItem
		// 
		this->probabilityVerification136OnlyToolStripMenuItem->Name = L"probabilityVerification136OnlyToolStripMenuItem";
		this->probabilityVerification136OnlyToolStripMenuItem->Size = System::Drawing::Size(257, 22);
		this->probabilityVerification136OnlyToolStripMenuItem->Text = L"Probability Verification (1.3.6 only)";
		this->probabilityVerification136OnlyToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::click_probabilityValidate);
		// 
		// taskOverflowCheck143OnlyToolStripMenuItem
		// 
		this->taskOverflowCheck143OnlyToolStripMenuItem->Name = L"taskOverflowCheck143OnlyToolStripMenuItem";
		this->taskOverflowCheck143OnlyToolStripMenuItem->Size = System::Drawing::Size(257, 22);
		this->taskOverflowCheck143OnlyToolStripMenuItem->Text = L"Task Overflow Check (1.4.2+ only)";
		this->taskOverflowCheck143OnlyToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::click_TaskOverflowCheck);
		// 
		// toolStripMenuItem3
		// 
		this->toolStripMenuItem3->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(10) {this->eLVersionToolStripMenuItem, 
			this->configEditorToolStripMenuItem, this->elementStructureDiffToolStripMenuItem, this->toolStripSeparator4, this->nPCListExportToolStripMenuItem, 
			this->nPCAILinkListToolStripMenuItem, this->toolStripSeparator2, this->joinToolStripMenuItem, this->toolStripSeparator3, this->classMaskGeneratorToolStripMenuItem});
		this->toolStripMenuItem3->Name = L"toolStripMenuItem3";
		this->toolStripMenuItem3->Padding = System::Windows::Forms::Padding(0);
		this->toolStripMenuItem3->Size = System::Drawing::Size(36, 20);
		this->toolStripMenuItem3->Text = L"Tools";
		// 
		// eLVersionToolStripMenuItem
		// 
		this->eLVersionToolStripMenuItem->Name = L"eLVersionToolStripMenuItem";
		this->eLVersionToolStripMenuItem->Size = System::Drawing::Size(202, 22);
		this->eLVersionToolStripMenuItem->Text = L"EL Version...";
		this->eLVersionToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::click_version);
		// 
		// configEditorToolStripMenuItem
		// 
		this->configEditorToolStripMenuItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
		this->configEditorToolStripMenuItem->Name = L"configEditorToolStripMenuItem";
		this->configEditorToolStripMenuItem->Size = System::Drawing::Size(202, 22);
		this->configEditorToolStripMenuItem->Text = L"Config Editor...";
		this->configEditorToolStripMenuItem->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
		this->configEditorToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::click_config);
		// 
		// elementStructureDiffToolStripMenuItem
		// 
		this->elementStructureDiffToolStripMenuItem->Name = L"elementStructureDiffToolStripMenuItem";
		this->elementStructureDiffToolStripMenuItem->Size = System::Drawing::Size(202, 22);
		this->elementStructureDiffToolStripMenuItem->Text = L"EL Structure Diff (Rules)...";
		this->elementStructureDiffToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::click_diffEL);
		// 
		// toolStripSeparator4
		// 
		this->toolStripSeparator4->Name = L"toolStripSeparator4";
		this->toolStripSeparator4->Size = System::Drawing::Size(199, 6);
		// 
		// nPCListExportToolStripMenuItem
		// 
		this->nPCListExportToolStripMenuItem->Name = L"nPCListExportToolStripMenuItem";
		this->nPCListExportToolStripMenuItem->Size = System::Drawing::Size(202, 22);
		this->nPCListExportToolStripMenuItem->Text = L"NPC List Export...";
		this->nPCListExportToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::click_npcExport);
		// 
		// nPCAILinkListToolStripMenuItem
		// 
		this->nPCAILinkListToolStripMenuItem->Name = L"nPCAILinkListToolStripMenuItem";
		this->nPCAILinkListToolStripMenuItem->Size = System::Drawing::Size(202, 22);
		this->nPCAILinkListToolStripMenuItem->Text = L"Monster -> AI Link List...";
		this->nPCAILinkListToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::click_npcAIexport);
		// 
		// toolStripSeparator2
		// 
		this->toolStripSeparator2->Name = L"toolStripSeparator2";
		this->toolStripSeparator2->Size = System::Drawing::Size(199, 6);
		// 
		// joinToolStripMenuItem
		// 
		this->joinToolStripMenuItem->Name = L"joinToolStripMenuItem";
		this->joinToolStripMenuItem->Size = System::Drawing::Size(202, 22);
		this->joinToolStripMenuItem->Text = L"Join new Elements";
		this->joinToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::click_joinEL);
		// 
		// toolStripSeparator3
		// 
		this->toolStripSeparator3->Name = L"toolStripSeparator3";
		this->toolStripSeparator3->Size = System::Drawing::Size(199, 6);
		// 
		// classMaskGeneratorToolStripMenuItem
		// 
		this->classMaskGeneratorToolStripMenuItem->Name = L"classMaskGeneratorToolStripMenuItem";
		this->classMaskGeneratorToolStripMenuItem->Size = System::Drawing::Size(202, 22);
		this->classMaskGeneratorToolStripMenuItem->Text = L"Class Mask Generator...";
		this->classMaskGeneratorToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::click_classMask);
		// 
		// toolTip
		// 
		this->toolTip->AutoPopDelay = 5000;
		this->toolTip->InitialDelay = 10;
		this->toolTip->ReshowDelay = 10;
		// 
		// label1
		// 
		this->label1->AutoSize = true;
		this->label1->Location = System::Drawing::Point(209, 34);
		this->label1->Name = L"label1";
		this->label1->Size = System::Drawing::Size(38, 13);
		this->label1->TabIndex = 10;
		this->label1->Text = L"Offset:";
		// 
		// textBox_offset
		// 
		this->textBox_offset->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->textBox_offset->Location = System::Drawing::Point(253, 31);
		this->textBox_offset->Name = L"textBox_offset";
		this->textBox_offset->Size = System::Drawing::Size(376, 20);
		this->textBox_offset->TabIndex = 11;
		this->textBox_offset->Leave += gcnew System::EventHandler(this, &MainWindow::change_offset);
		// 
		// MainWindow
		// 
		this->AcceptButton = this->button_search;
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->ClientSize = System::Drawing::Size(632, 453);
		this->Controls->Add(this->textBox_offset);
		this->Controls->Add(this->label1);
		this->Controls->Add(this->progressBar_progress);
		this->Controls->Add(this->dataGridView_item);
		this->Controls->Add(this->textBox_search);
		this->Controls->Add(this->comboBox_lists);
		this->Controls->Add(this->button_search);
		this->Controls->Add(this->listBox_items);
		this->Controls->Add(this->menuStrip_mainMenu);
		this->MainMenuStrip = this->menuStrip_mainMenu;
		this->MinimumSize = System::Drawing::Size(640, 480);
		this->Name = L"MainWindow";
		this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
		this->Text = L" sELedit";
		this->contextMenuStrip_items->ResumeLayout(false);
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_item))->EndInit();
		this->menuStrip_mainMenu->ResumeLayout(false);
		this->menuStrip_mainMenu->PerformLayout();
		this->ResumeLayout(false);
		this->PerformLayout();

	}

#pragma endregion

	private: System::Void click_load(System::Object^  sender, System::EventArgs^  e)
	{
		OpenFileDialog^ eLoad = gcnew OpenFileDialog();
		eLoad->Filter = "Elements File (*.data)|*.data|All Files (*.*)|*.*";
		if(eLoad->ShowDialog() == Windows::Forms::DialogResult::OK && File::Exists(eLoad->FileName))
		{
			try
			{
				Cursor = Windows::Forms::Cursors::AppStarting;
				progressBar_progress->Style = System::Windows::Forms::ProgressBarStyle::Marquee;

				eLC = gcnew eListCollection(eLoad->FileName);

				this->exportContainerToolStripMenuItem->DropDownItems->Clear();

				// search for available export rules
				if(eLC->ConfigFile)
				{
					this->exportContainerToolStripMenuItem->DropDownItems->Add(gcnew ToolStripLabel("Select a valid Conversation Rules Set"));
					this->exportContainerToolStripMenuItem->DropDownItems[0]->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
					this->exportContainerToolStripMenuItem->DropDownItems->Add(gcnew ToolStripSeparator());
					array<String^>^ files = Directory::GetFiles(Application::StartupPath + "\\rules", "PW_v" + eLC->Version.ToString() + "*.rules");
					for(int i=0; i<files->Length; i++)
					{
						files[i] = files[i]->Replace("=", "=>");
						files[i] = files[i]->Replace(".rules", "");
						files[i] = files[i]->Replace(Application::StartupPath + "\\rules\\", "");
						this->exportContainerToolStripMenuItem->DropDownItems->Add(files[i], nullptr, gcnew System::EventHandler(this, &MainWindow::click_export));
					}
				}
				// load cross references list
				if(eLC->ConfigFile)
				{
					array<String^>^ referencefiles = Directory::GetFiles(Application::StartupPath + "\\configs", "references.txt");
					if (referencefiles->Length>0)
					{
						StreamReader^ sr = gcnew StreamReader(referencefiles[0]);
						array<Char>^chars = {';',','};
						array<String^>^ x;
						xrefs = gcnew array<array<String^>^>(eLC->Lists->Length);
						while(String^line = sr->ReadLine())
						{
							if(!line->StartsWith("#"))
							{
								x = line->Split(chars);
								if(int::Parse(x[0])<eLC->Lists->Length)
								{
									xrefs[int::Parse(x[0])] = x;
								}
							}
						}
						this->toolStripSeparator6->Visible = true;
						this->xrefItemToolStripMenuItem->Visible = true;
					}
				}

				if(eLC->ConversationListIndex > -1 && eLC->Lists->Length > eLC->ConversationListIndex)
				{
					conversationList = gcnew eListConversation((array<unsigned char>^)eLC->Lists[eLC->ConversationListIndex]->elementValues[0][0]);
				}

				dataGridView_item->Rows->Clear();
				listBox_items->Items->Clear();
				comboBox_lists->Items->Clear();
				for(int l=0; l<eLC->Lists->Length; l++)
				{
					comboBox_lists->Items->Add("[" + l + "]: " + eLC->Lists[l]->listName + " (" + eLC->Lists[l]->elementValues->Length + ")");
				}

				this->Text = " sELedit (" + eLoad->FileName + ")";

				progressBar_progress->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
				Cursor = Windows::Forms::Cursors::Default;
			}
			catch(...)
			{
				MessageBox::Show("LOADING ERROR!\nThis error mostly occurs of configuration and elements.data mismatch");
				progressBar_progress->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
				Cursor = Windows::Forms::Cursors::Default;
			}
		}
	}
	private: System::Void click_save(System::Object^  sender, System::EventArgs^  e)
	{

		SaveFileDialog^ eSave = gcnew SaveFileDialog();
		eSave->InitialDirectory = Environment::CurrentDirectory;
		eSave->Filter = "Elements File (*.data)|*.data|All Files (*.*)|*.*";
		if(eSave->ShowDialog() == Windows::Forms::DialogResult::OK && eSave->FileName != "")
		{
			try
			{
				Cursor = Windows::Forms::Cursors::AppStarting;
				progressBar_progress->Style = System::Windows::Forms::ProgressBarStyle::Marquee;
				if(eLC->ConversationListIndex > -1 && eLC->Lists->Length > eLC->ConversationListIndex)
				{
					eLC->Lists[eLC->ConversationListIndex]->elementValues[0][0] = conversationList->GetBytes();
				}
				eLC->Save(eSave->FileName);
				progressBar_progress->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
				Cursor = Windows::Forms::Cursors::Default;
			}
			catch(...)
			{
				MessageBox::Show("SAVING ERROR!\nThis error mostly occurs of configuration and elements.data mismatch");
				progressBar_progress->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
				Cursor = Windows::Forms::Cursors::Default;
			}
		}
	}
	private: System::Void click_export(System::Object^  sender, System::EventArgs^  e)
	{
		SaveFileDialog^ eSave = gcnew SaveFileDialog();
		eSave->Filter = "Elements File (*.data)|*.data|All Files (*.*)|*.*";
		if(eSave->ShowDialog() == Windows::Forms::DialogResult::OK && eSave->FileName != "")
		{
			try
			{
				int start = ((ToolStripMenuItem^)sender)->Text->IndexOf(" ==> ")+5;

				Cursor = Windows::Forms::Cursors::WaitCursor;
				progressBar_progress->Style = System::Windows::Forms::ProgressBarStyle::Marquee;
				String^ rulesFile = Application::StartupPath + "\\rules\\" + ((ToolStripMenuItem^)sender)->Text->Replace("=>", "=") + ".rules";
				eLC->Export(rulesFile, eSave->FileName);
				progressBar_progress->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
				Cursor = Windows::Forms::Cursors::Default;
			}
			catch(...)
			{
				MessageBox::Show("EXPORTING ERROR!\nThis error mostly occurs if selected rules fileset is invalid");
				progressBar_progress->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
				Cursor = Windows::Forms::Cursors::Default;
			}
		}
	}

	private: System::Void change_list(System::Object^  sender, System::EventArgs^  ea)
	{
		if(comboBox_lists->SelectedIndex > -1)
		{
			int l = comboBox_lists->SelectedIndex;
			listBox_items->Items->Clear();
			textBox_offset->Text = eLC->GetOffset(l);
			dataGridView_item->Rows->Clear();
			this->xrefItemToolStripMenuItem->Enabled = true;
			try
			{
				int ajk = xrefs[l]->Length;
			}
			catch(...)
			{
				this->xrefItemToolStripMenuItem->Enabled = false;
			}

			if(l != eLC->ConversationListIndex)
			{
				for(int e=0; e<eLC->Lists[l]->elementValues->Length; e++)
				{
					// Find Position for Name
					int pos = -1;
					for(int i=0; i<eLC->Lists[l]->elementFields->Length; i++)
					{
						if(eLC->Lists[l]->elementFields[i] == "Name")
						{
							pos = i;
							break;
						}
					}

					if(eLC->Lists[l]->elementFields[0] == "ID")
					{
						listBox_items->Items->Add("[" + e + "]: " + eLC->GetValue(l,e,0) + " - " + eLC->GetValue(l,e,pos));
					}
					else
					{
						listBox_items->Items->Add("[" + e + "]: " + eLC->GetValue(l,e,pos));
					}
				}
			}
			else
			{
				for(int e=0; e<conversationList->DialogCount; e++)
				{
					listBox_items->Items->Add("[" + e + "]: " + conversationList->Dialogs[e]->DialogID + " - Dialog");
				}

			}
		}
	}

	private: System::Void change_item(System::Object^  sender, System::EventArgs^  ea)
	{
		int l = comboBox_lists->SelectedIndex;
		int e = listBox_items->SelectedIndex;
		int scroll = dataGridView_item->FirstDisplayedScrollingRowIndex;
		dataGridView_item->Rows->Clear();
		if(l != eLC->ConversationListIndex)
		{
			if(e > -1)
			{
				for(int f=0; f<eLC->Lists[l]->elementValues[e]->Length; f++)
				{
					dataGridView_item->Rows->Add(gcnew array<String^>{eLC->Lists[l]->elementFields[f], eLC->Lists[l]->elementTypes[f], eLC->GetValue(l,e,f)});
					dataGridView_item->Rows[f]->HeaderCell->Value = f.ToString();
				}
			}
		}
		else
		{
			if(e > -1)
			{
				dataGridView_item->Rows->Add(gcnew array<String^>{"Dialog ID", "int32", conversationList->Dialogs[e]->DialogID.ToString()});
				dataGridView_item->Rows->Add(gcnew array<String^>{"Dialog Name", "wstring:128", conversationList->Dialogs[e]->GetText()});
				for(int q=0; q<conversationList->Dialogs[e]->QuestionCount; q++)
				{
					dataGridView_item->Rows->Add(gcnew array<String^>{"Question_" + q + " - ID", "int32", conversationList->Dialogs[e]->Questions[q]->QuestionID.ToString()});
					dataGridView_item->Rows->Add(gcnew array<String^>{"Question_" + q + " - Control", "int32", conversationList->Dialogs[e]->Questions[q]->Control.ToString()});
					dataGridView_item->Rows->Add(gcnew array<String^>{"Question_" + q + " - Text", "wstring:" + conversationList->Dialogs[e]->Questions[q]->QuestionTextLength, conversationList->Dialogs[e]->Questions[q]->GetText()});
					for(int c=0; c<conversationList->Dialogs[e]->Questions[q]->ChoiceQount; c++)
					{
						dataGridView_item->Rows->Add(gcnew array<String^>{"Question_" + q + " - Choice_" + c + " - Control", "int32", conversationList->Dialogs[e]->Questions[q]->Choices[c]->Control.ToString()});
						dataGridView_item->Rows->Add(gcnew array<String^>{"Question_" + q + " - Choice_" + c + " - Text", "wstring:132", conversationList->Dialogs[e]->Questions[q]->Choices[c]->GetText()});
					}
				}
			}

		}
		if(scroll > -1)
		{
			dataGridView_item->FirstDisplayedScrollingRowIndex = scroll;
		}
	}
	private: System::Void change_offset(System::Object^  sender, System::EventArgs^  e)
	{
		eLC->SetOffset(comboBox_lists->SelectedIndex, textBox_offset->Text);
	}
	private: System::Void change_value(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ ea)
	{
		try
		{
			if(eLC && ea->ColumnIndex > -1)
			{
				int l = comboBox_lists->SelectedIndex;
				int e = listBox_items->SelectedIndex;
				if(l != eLC->ConversationListIndex)
				{
					eLC->SetValue(l, e, ea->RowIndex, Convert::ToString(dataGridView_item->CurrentCell->Value));

					if(ea->RowIndex == 0 || dataGridView_item->Rows[ea->RowIndex]->Cells[0]->Value->ToString() == "Name")
					{
						// change the values in the listbox depending on new name & id

						// Find Position for Name
						int pos = -1;
						for(int i=0; i<eLC->Lists[l]->elementFields->Length; i++)
						{
							if(eLC->Lists[l]->elementFields[i] == "Name")
							{
								pos = i;
								break;
							}
						}

						this->listBox_items->SelectedIndexChanged -= gcnew System::EventHandler(this, &MainWindow::change_item);
						listBox_items->Items[e] = "[" + e + "]: " + eLC->GetValue(l,e,0) + " - " + eLC->GetValue(l,e,pos);
						this->listBox_items->SelectedIndexChanged += gcnew System::EventHandler(this, &MainWindow::change_item);
					}
				}
				else
				{
					//check which item was changed (by field name)
					String^ fieldName = dataGridView_item[0, ea->RowIndex]->Value->ToString();

					if(fieldName == "Dialog ID")
					{
						conversationList->Dialogs[listBox_items->SelectedIndex]->DialogID = Convert::ToInt32(dataGridView_item->CurrentCell->Value);
						return;
					}
					if(fieldName == "Dialog Name")
					{
						conversationList->Dialogs[listBox_items->SelectedIndex]->SetText(dataGridView_item->CurrentCell->Value->ToString());
						return;
					}
					if(fieldName->StartsWith("Question_") && fieldName->EndsWith(" - ID"))
					{
						int q = Convert::ToInt32(fieldName->Replace("Question_", "")->Replace(" - ID", ""));
						conversationList->Dialogs[listBox_items->SelectedIndex]->Questions[q]->QuestionID = Convert::ToInt32(dataGridView_item->CurrentCell->Value);
						return;
					}
					if(fieldName->StartsWith("Question_") && fieldName->Contains("Choice_") && fieldName->EndsWith(" - Control"))
					{
						array<String^>^ s = fieldName->Replace("Question_", "")->Replace(" - Choice_", ";")->Replace(" - Control", "")->Split(gcnew array<wchar_t>{';'});
						int q = Convert::ToInt32(s[0]);
						int c = Convert::ToInt32(s[1]);
						conversationList->Dialogs[listBox_items->SelectedIndex]->Questions[q]->Choices[c]->Control = Convert::ToInt32(dataGridView_item->CurrentCell->Value);
						return;
					}
					if(fieldName->StartsWith("Question_") && fieldName->Contains("Choice_") && fieldName->EndsWith(" - Text"))
					{
						array<String^>^ s = fieldName->Replace("Question_", "")->Replace(" - Choice_", ";")->Replace(" - Text", "")->Split(gcnew array<wchar_t>{';'});
						int q = Convert::ToInt32(s[0]);
						int c = Convert::ToInt32(s[1]);
						conversationList->Dialogs[listBox_items->SelectedIndex]->Questions[q]->Choices[c]->SetText(dataGridView_item->CurrentCell->Value->ToString());
						return;
					}
					if(fieldName->StartsWith("Question_") && fieldName->EndsWith(" - Control"))
					{
						int q = Convert::ToInt32(fieldName->Replace("Question_", "")->Replace(" - Control", ""));
						conversationList->Dialogs[listBox_items->SelectedIndex]->Questions[q]->Control = Convert::ToInt32(dataGridView_item->CurrentCell->Value);
						return;
					}
					if(fieldName->StartsWith("Question_") && fieldName->EndsWith(" - Text"))
					{
						int q = Convert::ToInt32(fieldName->Replace("Question_", "")->Replace(" - Text", ""));
						conversationList->Dialogs[listBox_items->SelectedIndex]->Questions[q]->SetText(dataGridView_item->CurrentCell->Value->ToString());
						dataGridView_item[1, ea->RowIndex]->Value = "wstring:" + conversationList->Dialogs[listBox_items->SelectedIndex]->Questions[q]->QuestionTextLength;
						return;
					}
				}
			}
		}
		catch(...)
		{
			MessageBox::Show("CHANGING ERROR!\nFailed changing value, this value seems to be invalid.");
		}
	}
	private: System::Void click_search(System::Object^  sender, System::EventArgs^  ea)
	{
		String^ id = textBox_search->Text;
		int l = comboBox_lists->SelectedIndex;
		if(l<0){l=0;}
		int e = listBox_items->SelectedIndex+1;
		if(e<0){e=0;}
		if(eLC && eLC->Lists)
		{
			for(l; l<eLC->Lists->Length; l++)
			{
				int pos = 0;
				for(int i=0; i<eLC->Lists[l]->elementFields->Length; i++)
				{
					if(eLC->Lists[l]->elementFields[i] == "Name")
					{
						pos = i;
						break;
					}
				}
				for(e; e<eLC->Lists[l]->elementValues->Length; e++)
				{
					if(id == eLC->GetValue(l,e,0) || eLC->GetValue(l,e,pos)->Contains(id))
					{
						comboBox_lists->SelectedIndex = l;
						listBox_items->SelectedIndex = e;
						return;
					}
				}
				e = 0;
			}
			MessageBox::Show("Search reached End without Result!");
		}
	}
	private: System::Void click_deleteItem(System::Object^  sender, System::EventArgs^  ea)
	{
		int l = comboBox_lists->SelectedIndex;
		int e = listBox_items->SelectedIndex;
		if(l != eLC->ConversationListIndex)
		{
			if(l>-1 && e>-1)
			{
				eLC->Lists[l]->RemoveItem(e);
				dataGridView_item->Rows->Clear();
				listBox_items->Items->RemoveAt(e);
				comboBox_lists->Items[l] = "[" + l + "]: " + eLC->Lists[l]->listName + " (" + eLC->Lists[l]->elementValues->Length + ")";
				if(e<listBox_items->Items->Count)
				{
					listBox_items->SelectedIndex = e;
				}
				else
				{
					if(listBox_items->Items->Count>-1)
					{
						listBox_items->SelectedIndex = listBox_items->Items->Count-1;
					}
				}
			}
		}
		else
		{
			MessageBox::Show("Operation not supported in List " + eLC->ConversationListIndex.ToString());
		}
	}
	private: System::Void click_cloneItem(System::Object^  sender, System::EventArgs^  ea)
	{
		int l = comboBox_lists->SelectedIndex;
		int e = listBox_items->SelectedIndex;
		if(l != eLC->ConversationListIndex)
		{
			if(l>-1 && e>-1)
			{
				array<Object^>^ o = gcnew array<Object^>(eLC->Lists[l]->elementValues[e]->Length);
				eLC->Lists[l]->elementValues[e]->CopyTo(o,0);
				eLC->Lists[l]->AddItem(o);
				listBox_items->Items->Add(listBox_items->Items[e]);
				comboBox_lists->Items[l] = "[" + l + "]: " + eLC->Lists[l]->listName + " (" + eLC->Lists[l]->elementValues->Length + ")";
				listBox_items->SelectedIndex = listBox_items->Items->Count-1;
			}
		}
		else
		{
			MessageBox::Show("Operation not supported in List " + eLC->ConversationListIndex.ToString());
		}
	}
	private: System::Void click_logicReplace(System::Object^  sender, System::EventArgs^  e)
	{
		if(eLC)
		{
			(gcnew ReplaceWindow(eLC))->ShowDialog();
			int itemIndex = listBox_items->SelectedIndex;
			change_list(nullptr, nullptr);
			listBox_items->SelectedIndex = itemIndex;
		}
		else
		{
			MessageBox::Show("No File Loaded!");
		}
	}
	private: System::Void click_info(System::Object^  sender, System::EventArgs^  e)
	{
		if(eLC)
		{
			//(gcnew InfoWindow(eLC))->ShowDialog();
		}
		else
		{
			MessageBox::Show("No File Loaded!");
		}
	}
	private: System::Void click_version(System::Object^  sender, System::EventArgs^  e)
	{
		OpenFileDialog^ eLoad = gcnew OpenFileDialog();
		eLoad->Filter = "Elements File (*.data)|*.data|All Files (*.*)|*.*";
		if(eLoad->ShowDialog() == Windows::Forms::DialogResult::OK && File::Exists(eLoad->FileName))
		{
			FileStream^ fs =File::OpenRead(eLoad->FileName);
			BinaryReader^ br = gcnew BinaryReader(fs);
			short version = br->ReadInt16();
			short signature = br->ReadInt16();
			br->Close();
			fs->Close();

			MessageBox::Show("File: " + eLoad->FileName + "\n\nVersion: " + version.ToString() + "\nSignature: " + signature.ToString());
		}
		else
		{
			//MessageBox::Show("No File!");
		}
	}
	private: System::Void click_config(System::Object^  sender, System::EventArgs^  e)
	{
		(gcnew ConfigWindow())->Show();
	}
	private: System::Void click_exportItem(System::Object^  sender, System::EventArgs^  ea)
	{
		int l = comboBox_lists->SelectedIndex;
		int e = listBox_items->SelectedIndex;
		if(l != eLC->ConversationListIndex)
		{
			if(l>-1 && e>-1)
			{
				SaveFileDialog^ eSave = gcnew SaveFileDialog();
				eSave->Filter = "Unicode Text File (*.txt)|*.txt|All Files (*.*)|*.*";
				if(eSave->ShowDialog() == Windows::Forms::DialogResult::OK && eSave->FileName != "")
				{
					try
					{
						Cursor = Windows::Forms::Cursors::AppStarting;
						eLC->Lists[l]->ExportItem(eSave->FileName, e);
						Cursor = Windows::Forms::Cursors::Default;
					}
					catch(...)
					{
						MessageBox::Show("EXPORT ERROR!\nExporting item to unicode text file failed!");
						Cursor = Windows::Forms::Cursors::Default;
					}
				}
			}
		}
		else
		{
			MessageBox::Show("Operation not supported in List " + eLC->ConversationListIndex.ToString());
		}
	}
	private: System::Void click_importItem(System::Object^  sender, System::EventArgs^  ea)
	{
		int l = comboBox_lists->SelectedIndex;
		int e = listBox_items->SelectedIndex;
		if(l != eLC->ConversationListIndex)
		{
			if(l>-1 && e>-1)
			{
				OpenFileDialog^ eLoad = gcnew OpenFileDialog();
				eLoad->Filter = "Unicode Text File (*.txt)|*.txt|All Files (*.*)|*.*";
				if(eLoad->ShowDialog() == Windows::Forms::DialogResult::OK && File::Exists(eLoad->FileName))
				{
					try
					{
						Cursor = Windows::Forms::Cursors::AppStarting;
						eLC->Lists[l]->ImportItem(eLoad->FileName, e);
						change_list(nullptr, nullptr);
						listBox_items->SelectedIndex = e;
						Cursor = Windows::Forms::Cursors::Default;
					}
					catch(...)
					{
						MessageBox::Show("IMPORT ERROR!\nCheck if the item version matches the elements.data version and is imported to the correct list!");
						Cursor = Windows::Forms::Cursors::Default;
					}
				}
			}
		}
		else
		{
			MessageBox::Show("Operation not supported in List " + eLC->ConversationListIndex.ToString());
		}
	}

	private: System::Void click_npcExport(System::Object^  sender, System::EventArgs^  e)
	{
		SaveFileDialog^ save = gcnew SaveFileDialog();
		save->InitialDirectory = Environment::CurrentDirectory;
		save->Filter = "Text File (*.txt)|*.txt|All Files (*.*)|*.*";
		if(save->ShowDialog() == Windows::Forms::DialogResult::OK && save->FileName != "")
		{
			try
			{
				Cursor = Windows::Forms::Cursors::AppStarting;
				progressBar_progress->Style = System::Windows::Forms::ProgressBarStyle::Marquee;

				StreamWriter^ sw = gcnew StreamWriter(save->FileName, false, Encoding::Unicode);

				for(int i=0; i<eLC->Lists[38]->elementValues->Length; i++)
				{
					sw->WriteLine(eLC->GetValue(38, i, 0) + "\t" + eLC->GetValue(38, i, 2));
				}

				for(int i=0; i<eLC->Lists[57]->elementValues->Length; i++)
				{
					sw->WriteLine(eLC->GetValue(57, i, 0) + "\t" + eLC->GetValue(57, i, 1));
				}

				sw->Close();

				progressBar_progress->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
				Cursor = Windows::Forms::Cursors::Default;
			}
			catch(...)
			{
				MessageBox::Show("SAVING ERROR!");
				progressBar_progress->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
				Cursor = Windows::Forms::Cursors::Default;
			}
		}
	}
	private: System::Void click_joinEL(System::Object^  sender, System::EventArgs^  e)
	{
		JoinWindow^ eJoin = gcnew JoinWindow();
		if(eJoin->ShowDialog() == Windows::Forms::DialogResult::OK)
		{
			if(File::Exists(eJoin->FileName))
			{
				if(eJoin->LogDirectory == "" || !Directory::Exists(eJoin->LogDirectory))
				{
					eJoin->LogDirectory = eJoin->FileName + ".JOIN";
					Directory::CreateDirectory(eJoin->LogDirectory);
				}

				if(eJoin->BackupNew)
				{
					Directory::CreateDirectory(eJoin->LogDirectory + "\\added.backup");
				}
				if(eJoin->BackupChanged)
				{
					Directory::CreateDirectory(eJoin->LogDirectory + "\\replaced.backup");
				}
				if(eJoin->BackupMissing)
				{
					Directory::CreateDirectory(eJoin->LogDirectory + "\\removed.backup");
				}

				try
				{
					Cursor = Windows::Forms::Cursors::WaitCursor;
					progressBar_progress->Style = System::Windows::Forms::ProgressBarStyle::Marquee;
					eListCollection^ neLC = gcnew eListCollection(eJoin->FileName);
					if(eLC->ConfigFile != neLC->ConfigFile)
					{
						MessageBox::Show("You're going to join two different element.data versions. The merged file will become invalid!", " WARNING");
					}
					if(eLC->ConversationListIndex > -1 && neLC->Lists->Length > eLC->ConversationListIndex)
					{
						conversationList = gcnew eListConversation((array<unsigned char>^)neLC->Lists[eLC->ConversationListIndex]->elementValues[0][0]);
					}
					StreamWriter^ sw = gcnew StreamWriter(eJoin->LogDirectory + "\\LOG.TXT", false, Encoding::Unicode);

					ArrayList^ report;

					for(int l=0; l<eLC->Lists->Length; l++)
					{
						if(l != eLC->ConversationListIndex)
						{
							report = eLC->Lists[l]->JoinElements(neLC->Lists[l], l, eJoin->AddNew, eJoin->BackupNew, eJoin->ReplaceChanged, eJoin->BackupChanged, eJoin->RemoveMissing, eJoin->BackupMissing, eJoin->LogDirectory+"\\added.backup", eJoin->LogDirectory+"\\replaced.backup", eJoin->LogDirectory+"\\removed.backup");
							report->Sort();
							if(report->Count > 0)
							{
								sw->WriteLine("List " + l + ": " + report->Count + " Item(s) Affected");
								sw->WriteLine();

								for(int n=0; n<report->Count; n++)
								{
									sw->WriteLine((String^)report[n]);
								}

								sw->WriteLine();
							}

							comboBox_lists->Items[l] = "[" + l + "]: " + eLC->Lists[l]->listName + " (" + eLC->Lists[l]->elementValues->Length + ")";
						}
					}

					sw->Close();

					if(comboBox_lists->SelectedIndex>-1)
					{
						change_list(nullptr, nullptr);
					}

					progressBar_progress->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
					Cursor = Windows::Forms::Cursors::Default;
				}
				catch(...)
				{
					MessageBox::Show("LOADING ERROR!\nThis error mostly occurs of configuration and elements.data mismatch");
					progressBar_progress->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
					Cursor = Windows::Forms::Cursors::Default;
				}
			}
		}
	}
	private: System::Void click_npcAIexport(System::Object^  sender, System::EventArgs^  e)
	{
		SaveFileDialog^ save = gcnew SaveFileDialog();
		save->InitialDirectory = Environment::CurrentDirectory;
		save->Filter = "Text File (*.txt)|*.txt|All Files (*.*)|*.*";
		if(save->ShowDialog() == Windows::Forms::DialogResult::OK && save->FileName != "")
		{
			try
			{
				Cursor = Windows::Forms::Cursors::AppStarting;
				progressBar_progress->Style = System::Windows::Forms::ProgressBarStyle::Marquee;

				StreamWriter^ sw = gcnew StreamWriter(save->FileName, false, Encoding::Unicode);

				for(int i=0; i<eLC->Lists[38]->elementValues->Length; i++)
				{
					sw->WriteLine(eLC->GetValue(38, i, 0) + "\t" + eLC->GetValue(38, i, 2) + "\t" + eLC->GetValue(38, i, 64));
				}

				sw->Close();

				progressBar_progress->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
				Cursor = Windows::Forms::Cursors::Default;
			}
			catch(...)
			{
				MessageBox::Show("SAVING ERROR!");
				progressBar_progress->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
				Cursor = Windows::Forms::Cursors::Default;
			}
		}
	}
	private: System::Void click_skillValidate(System::Object^  sender, System::EventArgs^  e)
	{
		if(eLC)
		{
			ArrayList^ mobSkills = gcnew ArrayList();

			String^ skill;

			// check all monster skills (list 38 fields 119, 121, 123, 125, 127, 129)
			for(int n=0; n<eLC->Lists[38]->elementValues->Length; n++)
			{
				for(int f=119; f<130; f+=2)
				{
					skill = eLC->GetValue(38, n, f);

					if(Convert::ToInt32(skill) > 846)
					{
						mobSkills->Add("Invalid Skill: " + skill + " (Monster: " + eLC->GetValue(38, n, 0) + ")");
					}
				}
			}

			if(mobSkills->Count == 0)
			{
				MessageBox::Show("OK, no invalid skills found!");
			}
			else
			{
				String^ message = "";
				for(int i=0; i<mobSkills->Count; i++)
				{
					message += (String^)mobSkills[i] + "\r\n";
				}
				gcnew DebugWindow("Invalid Skills", message);
			}
		}
	}

	private: System::Void click_propertyValidate(System::Object^  sender, System::EventArgs^  e)
	{
		if(eLC)
		{
			ArrayList^ properties = gcnew ArrayList();

			String^ attribute;

			// weapons (list 3, fields 43-201, +=2)
			for(int n=0; n<eLC->Lists[3]->elementValues->Length; n++)
			{
				for(int f=43; f<202; f+=2)
				{
					attribute = eLC->GetValue(3, n, f);

					if(Convert::ToInt32(attribute) > 1909)
					{
						properties->Add("Invalid Property: " + attribute + " (Weapon: " + eLC->GetValue(3, n, 0) + ")");
					}
				}
			}

			// armors (list 6, fields 55-179, +=2)
			for(int n=0; n<eLC->Lists[6]->elementValues->Length; n++)
			{
				for(int f=55; f<180; f+=2)
				{
					attribute = eLC->GetValue(6, n, f);

					if(Convert::ToInt32(attribute) > 1909)
					{
						properties->Add("Invalid Property: " + attribute + " (Armor: " + eLC->GetValue(6, n, 0) + ")");
					}
				}
			}

			// ornaments (list 9, fields 44-160, +=2)
			for(int n=0; n<eLC->Lists[9]->elementValues->Length; n++)
			{
				for(int f=44; f<161; f+=2)
				{
					attribute = eLC->GetValue(9, n, f);

					if(Convert::ToInt32(attribute) > 1909)
					{
						properties->Add("Invalid Property: " + attribute + " (Ornament: " + eLC->GetValue(9, n, 0) + ")");
					}
				}
			}

			// soulgems (list 35, fields 11-12, +=1)
			for(int n=0; n<eLC->Lists[35]->elementValues->Length; n++)
			{
				for(int f=11; f<13; f++)
				{
					attribute = eLC->GetValue(35, n, f);

					if(Convert::ToInt32(attribute) > 1909)
					{
						properties->Add("Invalid Property: " + attribute + " (Soulgem: " + eLC->GetValue(35, n, 0) + ")");
					}
				}
			}

			// complect boni (list 90, fields 15-19, +=1)
			for(int n=0; n<eLC->Lists[90]->elementValues->Length; n++)
			{
				for(int f=15; f<20; f++)
				{
					attribute = eLC->GetValue(90, n, f);

					if(Convert::ToInt32(attribute) > 1909)
					{
						properties->Add("Invalid Property: " + attribute + " (Complect Bonus: " + eLC->GetValue(90, n, 0) + ")");
					}
				}
			}

			if(properties->Count == 0)
			{
				MessageBox::Show("OK, no invalid properties found!");
			}
			else
			{
				String^ message = "";
				for(int i=0; i<properties->Count; i++)
				{
					message += (String^)properties[i] + "\r\n";
				}
				gcnew DebugWindow("Invalid Properties", message);
			}
		}
	}
	private: System::Void click_tomeValidate(System::Object^  sender, System::EventArgs^  e)
	{
		if(eLC)
		{
			ArrayList^ properties = gcnew ArrayList();

			String^ attribute;

			for(int n=0; n<eLC->Lists[112]->elementValues->Length; n++)
			{
				for(int f=4; f<14; f++)
				{
					attribute = eLC->GetValue(112, n, f);

					if(Convert::ToInt32(attribute) > 1909)
					{
						properties->Add("Invalid Property: " + attribute + " (Tome: " + eLC->GetValue(112, n, 0) + ")");
					}
				}
			}

			if(properties->Count == 0)
			{
				MessageBox::Show("OK, no invalid tome properties found!");
			}
			else
			{
				String^ message = "";
				for(int i=0; i<properties->Count; i++)
				{
					message += (String^)properties[i] + "\r\n";
				}
				gcnew DebugWindow("Invalid Tome Properties", message);
			}
		}
	}

	private: System::Void click_skillReplace(System::Object^  sender, System::EventArgs^  e)
	{
		if(eLC)
		{
			OpenFileDialog^ load = gcnew OpenFileDialog();
			load->InitialDirectory = Application::StartupPath + "\\replace";
			load->Filter = "Skill Replace File (*.txt)|*.txt|All Files (*.*)|*.*";
			if(load->ShowDialog() == Windows::Forms::DialogResult::OK && File::Exists(load->FileName))
			{
				Collections::SortedList^ skillTable = gcnew Collections::SortedList();

				StreamReader^ sr = gcnew StreamReader(load->FileName);

				String^ line;
				array<String^>^ pair;
				array<String^>^ seperator = gcnew array<String^>{"="};
				while(!sr->EndOfStream)
				{
					line = sr->ReadLine();
					if(!line->StartsWith("#") && line->Contains("="))
					{
						pair = line->Split(seperator, StringSplitOptions::RemoveEmptyEntries);
						if(pair->Length == 2)
						{
							skillTable->Add(pair[0], pair[1]);
						}
					}
				}

				sr->Close();
/*
ArrayList^ mobSkills = gcnew ArrayList();
*/
				String^ skill;

				// change all monster skills (list 38 fields 119, 121, 123, 125, 127, 129)
				for(int n=0; n<eLC->Lists[38]->elementValues->Length; n++)
				{
					for(int f=119; f<130; f+=2)
					{
						skill = eLC->GetValue(38, n, f);
/*
if(!mobSkills->Contains(skill))
{
	mobSkills->Add(skill);
}
*/
						if(skillTable->ContainsKey(skill))
						{
							eLC->SetValue(38, n, f, (String^)skillTable[skill]);
						}
					}
				}
/*
int debug = 1;
*/
			}
		}
	}
	private: System::Void click_propertyReplace(System::Object^  sender, System::EventArgs^  e)
	{
		if(eLC)
		{
			OpenFileDialog^ load = gcnew OpenFileDialog();
			load->InitialDirectory = Application::StartupPath + "\\replace";
			load->Filter = "Property Replace File (*.txt)|*.txt|All Files (*.*)|*.*";
			if(load->ShowDialog() == Windows::Forms::DialogResult::OK && File::Exists(load->FileName))
			{
				Collections::SortedList^ propertyTable = gcnew Collections::SortedList();

				StreamReader^ sr = gcnew StreamReader(load->FileName);

				String^ line;
				array<String^>^ pair;
				array<String^>^ seperator = gcnew array<String^>{"="};
				while(!sr->EndOfStream)
				{
					line = sr->ReadLine();
					if(!line->StartsWith("#") && line->Contains("="))
					{
						pair = line->Split(seperator, StringSplitOptions::RemoveEmptyEntries);
						if(pair->Length == 2)
						{
							propertyTable->Add(pair[0], pair[1]);
						}
					}
				}

				sr->Close();
/*
ArrayList^ weaponProps = gcnew ArrayList();
ArrayList^ armorProps = gcnew ArrayList();
ArrayList^ ornamentProps = gcnew ArrayList();
ArrayList^ gemProps = gcnew ArrayList();
ArrayList^ complectProps = gcnew ArrayList();
*/

				String^ attribute;

				// weapons (list 3, fields 43-201, +=2)
				for(int n=0; n<eLC->Lists[3]->elementValues->Length; n++)
				{
					for(int f=43; f<202; f+=2)
					{
						attribute = eLC->GetValue(3, n, f);
/*
if(!weaponProps->Contains(attribute))
{
	weaponProps->Add(attribute);
}
*/
						if(propertyTable->ContainsKey(attribute))
						{
							eLC->SetValue(3, n, f, (String^)propertyTable[attribute]);
						}
					}
				}

				// armors (list 6, fields 55-179, +=2)
				for(int n=0; n<eLC->Lists[6]->elementValues->Length; n++)
				{
					for(int f=55; f<180; f+=2)
					{
						attribute = eLC->GetValue(6, n, f);
/*
if(!armorProps->Contains(attribute))
{
	armorProps->Add(attribute);
}
*/
						if(propertyTable->ContainsKey(attribute))
						{
							eLC->SetValue(6, n, f, (String^)propertyTable[attribute]);
						}
					}
				}

				// ornaments (list 9, fields 44-160, +=2)
				for(int n=0; n<eLC->Lists[9]->elementValues->Length; n++)
				{
					for(int f=44; f<161; f+=2)
					{
						attribute = eLC->GetValue(9, n, f);
/*
if(!ornamentProps->Contains(attribute))
{
	ornamentProps->Add(attribute);
}
*/
						if(propertyTable->ContainsKey(attribute))
						{
							eLC->SetValue(9, n, f, (String^)propertyTable[attribute]);
						}
					}
				}

				// soulgems (list 35, fields 11-12, +=1)
				for(int n=0; n<eLC->Lists[35]->elementValues->Length; n++)
				{
					for(int f=11; f<13; f++)
					{
						attribute = eLC->GetValue(35, n, f);
/*
if(!gemProps->Contains(attribute))
{
	gemProps->Add(attribute);
}
*/
						if(propertyTable->ContainsKey(attribute))
						{
							eLC->SetValue(35, n, f, (String^)propertyTable[attribute]);

							if((String^)propertyTable[attribute] == "1515")
							{
								eLC->SetValue(35, n, f+2, "Vit. +20");
							}
							if((String^)propertyTable[attribute] == "1517")
							{
								eLC->SetValue(35, n, f+2, "Critical +2%");
							}
							if((String^)propertyTable[attribute] == "1518")
							{
								eLC->SetValue(35, n, f+2, "Channel -6%");
							}
						}
					}
				}

				// complect boni (list 90, fields 15-19, +=1)
				for(int n=0; n<eLC->Lists[90]->elementValues->Length; n++)
				{
					for(int f=15; f<20; f++)
					{
						attribute = eLC->GetValue(90, n, f);
/*
if(!complectProps->Contains(attribute))
{
	complectProps->Add(attribute);
}
*/
						if(propertyTable->ContainsKey(attribute))
						{
							eLC->SetValue(90, n, f, (String^)propertyTable[attribute]);
						}
					}
				}
/*
int debug = 1;
*/
			}
		}
	}
	private: System::Void click_tomeReplace(System::Object^  sender, System::EventArgs^  e)
	{
		if(eLC)
		{
			OpenFileDialog^ load = gcnew OpenFileDialog();
			load->InitialDirectory = Application::StartupPath + "\\replace";
			load->Filter = "Tome Replace File (*.txt)|*.txt|All Files (*.*)|*.*";
			if(load->ShowDialog() == Windows::Forms::DialogResult::OK && File::Exists(load->FileName))
			{
				Collections::SortedList^ propertyTable = gcnew Collections::SortedList();

				StreamReader^ sr = gcnew StreamReader(load->FileName);

				String^ line;
				array<String^>^ pair;
				array<String^>^ seperator = gcnew array<String^>{"="};
				array<String^>^ divider = gcnew array<String^>{","};
				while(!sr->EndOfStream)
				{
					line = sr->ReadLine();
					if(!line->StartsWith("#") && line->Contains("="))
					{
						pair = line->Split(seperator, StringSplitOptions::RemoveEmptyEntries);
						if(pair->Length == 2)
						{
							propertyTable->Add(pair[0], pair[1]->Split(divider, StringSplitOptions::RemoveEmptyEntries));
						}
					}
				}

				sr->Close();
/*
ArrayList^ tomeProps = gcnew ArrayList();
*/
				String^ attribute;
				array<String^>^ attributes;
				ArrayList^ attributesOrgiginal = gcnew ArrayList();
				ArrayList^ attributesReplaced = gcnew ArrayList();

				// weapons (list 3, fields 43-201, +=2)
				for(int n=0; n<eLC->Lists[112]->elementValues->Length; n++)
				{
					attributesOrgiginal->Clear();
					attributesReplaced->Clear();

					for(int f=4; f<14; f++)
					{
						attribute = eLC->GetValue(112, n, f);
/*
if(!tomeProps->Contains(attribute))
{
	tomeProps->Add(attribute);
}
*/
						if(attribute != "0")
						{
							if(propertyTable->ContainsKey(attribute))
							{
								attributes = (array<String^>^)propertyTable[attribute];
								for(int a=0; a<attributes->Length; a++)
								{
									attributesReplaced->Add(attributes[a]);
								}
							}
							else
							{
								// add the attribute without changes
								attributesReplaced->Add(attribute);
							}
						}
					}

					if(attributesReplaced->Count > 10)
					{
						MessageBox::Show("Tome Attribute Overflow: " + n + "\nAttributes Truncated");
					}

					// add the new attribute list to the current tome
					for(int f=4; f<14; f++)
					{
						if(f-4 < attributesReplaced->Count)
						{
							// add the replaced attribute
							attribute = (String^)attributesReplaced[f-4];
							eLC->SetValue(112, n, f, attribute);
						}
						else
						{
							eLC->SetValue(112, n, f, "0");
						}
					}
				}
/*
int debug = 1;
*/
			}
		}
	}
	private: System::Void click_probabilityValidate(System::Object^  sender, System::EventArgs^  e)
	{
		if(eLC)
		{
			ArrayList^ probabilities = gcnew ArrayList();
			double attribute;

			// weapons (list 3)
			for(int n=0; n<eLC->Lists[3]->elementValues->Length; n++)
			{
				// weapon drop sockets count(fields 32-34, +=1)

				attribute = 0;

				for(int f=32; f<35; f++)
				{
					attribute += Convert::ToDouble(eLC->GetValue(3, n, f));
				}

				if(Math::Round(attribute, 6) != 1)
				{
					probabilities->Add("Suspicious Socket Drop Probability (sum != 1.0): " + attribute.ToString() + " (Weapon: " + eLC->GetValue(3, n, 0) + ")");
				}

				// weapon craft sockets count(fields 35-37, +=1)

				attribute = 0;

				for(int f=35; f<38; f++)
				{
					attribute += Convert::ToDouble(eLC->GetValue(3, n, f));
				}

				if(Math::Round(attribute, 6) != 1)
				{
					probabilities->Add("Suspicious Socket Craft Probability (sum != 1.0): " + attribute.ToString() + " (Weapon: " + eLC->GetValue(3, n, 0) + ")");
				}

				// weapon addons count(fields 38-41, +=1)

				attribute = 0;

				for(int f=38; f<42; f++)
				{
					attribute += Convert::ToDouble(eLC->GetValue(3, n, f));
				}

				if(Math::Round(attribute, 6) != 1)
				{
					probabilities->Add("Suspicious Addon Count Probability (sum != 1.0): " + attribute.ToString() + " (Weapon: " + eLC->GetValue(3, n, 0) + ")");
				}

				// weapon drop (fields 44-106, +=2)

				attribute = 0;

				for(int f=44; f<107; f+=2)
				{
					attribute += Convert::ToDouble(eLC->GetValue(3, n, f));
				}

				if(Math::Round(attribute, 6) != 1)
				{
					probabilities->Add("Suspicious Drop Attriutes Probability (sum != 1.0): " + attribute.ToString() + " (Weapon: " + eLC->GetValue(3, n, 0) + ")");
				}

				// weapon craft (fields 108-170, +=2)

				attribute = 0;

				for(int f=108; f<171; f+=2)
				{
					attribute += Convert::ToDouble(eLC->GetValue(3, n, f));
				}

				if(Math::Round(attribute, 6) != 1)
				{
					probabilities->Add("Suspicious Craft Attributes Probability (sum != 1.0): " + attribute.ToString() + " (Weapon: " + eLC->GetValue(3, n, 0) + ")");
				}

				// weapons unique (fields 172-202, +=2)

				attribute = 0;

				for(int f=172; f<203; f+=2)
				{
					attribute += Convert::ToDouble(eLC->GetValue(3, n, f));
				}

				if(Math::Round(attribute, 6) != 1)
				{
					probabilities->Add("Suspicious Unique Attributes Probability (sum != 1.0): " + attribute.ToString() + " (Weapon: " + eLC->GetValue(3, n, 0) + ")");
				}
			}

			// armors (list 6)
			for(int n=0; n<eLC->Lists[6]->elementValues->Length; n++)
			{
				// armor drop sockets count(fields 41-45, +=1)

				attribute = 0;

				for(int f=41; f<46; f++)
				{
					attribute += Convert::ToDouble(eLC->GetValue(6, n, f));
				}

				if(Math::Round(attribute, 6) != 1)
				{
					probabilities->Add("Suspicious Socket Drop Probability (sum != 1.0): " + attribute.ToString() + " (Armor: " + eLC->GetValue(6, n, 0) + ")");
				}

				// armor craft sockets count(fields 46-50, +=1)

				attribute = 0;

				for(int f=46; f<51; f++)
				{
					attribute += Convert::ToDouble(eLC->GetValue(6, n, f));
				}

				if(Math::Round(attribute, 6) != 1)
				{
					probabilities->Add("Suspicious Socket Craft Probability (sum != 1.0): " + attribute.ToString() + " (Armor: " + eLC->GetValue(6, n, 0) + ")");
				}

				// armor addons count(fields 51-54, +=1)

				attribute = 0;

				for(int f=51; f<55; f++)
				{
					attribute += Convert::ToDouble(eLC->GetValue(6, n, f));
				}

				if(Math::Round(attribute, 6) != 1)
				{
					probabilities->Add("Suspicious Addon Count Probability (sum != 1.0): " + attribute.ToString() + " (Armor: " + eLC->GetValue(6, n, 0) + ")");
				}

				// armor drop (fields 56-118, +=2)

				attribute = 0;

				for(int f=56; f<119; f+=2)
				{
					attribute += Convert::ToDouble(eLC->GetValue(6, n, f));
				}

				if(Math::Round(attribute, 6) != 1)
				{
					probabilities->Add("Suspicious Drop Attriutes Probability (sum != 1.0): " + attribute.ToString() + " (Armor: " + eLC->GetValue(6, n, 0) + ")");
				}

				// armor craft (fields 120-180, +=2)

				attribute = 0;

				for(int f=120; f<181; f+=2)
				{
					attribute += Convert::ToDouble(eLC->GetValue(6, n, f));
				}

				if(Math::Round(attribute, 6) != 1)
				{
					probabilities->Add("Suspicious Craft Attributes Probability (sum != 1.0): " + attribute.ToString() + " (Armor: " + eLC->GetValue(6, n, 0) + ")");
				}
			}

			// ornaments (list 9)
			for(int n=0; n<eLC->Lists[9]->elementValues->Length; n++)
			{
				// ornament addons count(fields 40-43, +=1)

				attribute = 0;

				for(int f=40; f<44; f++)
				{
					attribute += Convert::ToDouble(eLC->GetValue(9, n, f));
				}

				if(Math::Round(attribute, 6) != 1)
				{
					probabilities->Add("Suspicious Addon Count Probability (sum != 1.0): " + attribute.ToString() + " (Ornament: " + eLC->GetValue(9, n, 0) + ")");
				}

				// ornament drop (fields 45-107, +=2)

				attribute = 0;

				for(int f=45; f<108; f+=2)
				{
					attribute += Convert::ToDouble(eLC->GetValue(9, n, f));
				}

				if(Math::Round(attribute, 6) != 1)
				{
					probabilities->Add("Suspicious Drop Attriutes Probability (sum != 1.0): " + attribute.ToString() + " (Ornament: " + eLC->GetValue(9, n, 0) + ")");
				}

				// ornament craft (fields 109-161, +=2)

				attribute = 0;

				for(int f=109; f<162; f+=2)
				{
					attribute += Convert::ToDouble(eLC->GetValue(9, n, f));
				}

				if(Math::Round(attribute, 6) != 1)
				{
					probabilities->Add("Suspicious Craft Attributes Probability (sum != 1.0): " + attribute.ToString() + " (Ornament: " + eLC->GetValue(9, n, 0) + ")");
				}
			}

			if(probabilities->Count == 0)
			{
				MessageBox::Show("OK, no invalid probabilities found!");
			}
			else
			{
				String^ message = "";
				for(int i=0; i<probabilities->Count; i++)
				{
					message += (String^)probabilities[i] + "\r\n";
				}
				gcnew DebugWindow("Invalid Probabilities", message);
			}
		}
	}
	private: System::Void click_TaskOverflowCheck(System::Object^  sender, System::EventArgs^  e)
	{
		if(eLC)
		{
			String^ value;
			bool isAddedElement;

			LoseQuestWindow^ questWindow = gcnew LoseQuestWindow();



			// list 45 recive quests
			for(int n=0; n<eLC->Lists[45]->elementValues->Length; n++)
			{
				isAddedElement = false;
				for(int f=34; f<eLC->Lists[45]->elementFields->Length; f++)
				{
					value = eLC->GetValue(45, n, f);
					if(value != "0")
					{
						if(!isAddedElement)
						{
							questWindow->listBox_Receive->Items->Add("+++++ " + eLC->GetValue(45, n, 0) + " - " + eLC->GetValue(45, n, 1) + " +++++");
							isAddedElement = true;
						}
						questWindow->listBox_Receive->Items->Add(value);
					}
				}
			}

			// list 46 activate quests
			for(int n=0; n<eLC->Lists[46]->elementValues->Length; n++)
			{
				isAddedElement = false;
				for(int f=34; f<eLC->Lists[46]->elementFields->Length; f++)
				{
					value = eLC->GetValue(46, n, f);
					if(value != "0")
					{
						if(!isAddedElement)
						{
							questWindow->listBox_Activate->Items->Add("+++++ " + eLC->GetValue(46, n, 0) + " - " + eLC->GetValue(46, n, 1) + " +++++");
							isAddedElement = true;
						}
						questWindow->listBox_Activate->Items->Add(value);
					}
				}
			}

			questWindow->Show();
		}
	}
	private: System::Void click_classMask(System::Object^  sender, System::EventArgs^  e)
	{
		ClassMaskWindow^ eClassMask = gcnew ClassMaskWindow();
		eClassMask->Show();
	}
	private: System::Void cellMouseMove_ToolTip(System::Object^  sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^  e)
	{
		if(comboBox_lists->SelectedIndex == 0 && listBox_items->SelectedIndex != -1 && e->ColumnIndex == 2 && e->RowIndex > 2 && e->RowIndex < 6)
		{
			String^ text = "Float: " + (BitConverter::ToSingle(BitConverter::GetBytes( (int)(eLC->Lists[0]->elementValues[listBox_items->SelectedIndex][e->RowIndex]) ), 0)).ToString("F6");

			// not working on first mouse over (still shows previous value on first mouse over)
			//dataGridView_item->Rows[e->RowIndex]->Cells[e->ColumnIndex]->ToolTipText = text;

			// only draw on real move to prevent flickering in windows 7
			if(mouseMoveCheck->X != e->X || mouseMoveCheck->Y != e->Y)
			{
				toolTip->SetToolTip((Control^)sender, text);
				mouseMoveCheck->X = e->X;
				mouseMoveCheck->Y = e->Y;
			}
		}
		else
		{
			toolTip->Hide((Control^)sender);;
		}
	}
	private: System::Void click_diffEL(System::Object^  sender, System::EventArgs^  e)
	{
		RulesWindow^ eRules = gcnew RulesWindow();
		eRules->Show();
	}
	private: System::Void listBox_items_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
		int l = comboBox_lists->SelectedIndex;
		int k = listBox_items->SelectedIndex;
		if(l != eLC->ConversationListIndex)
		{
			if(l>-1 && k>-1)
			{
				int pos = -1;
				for(int i=0; i<eLC->Lists[l]->elementFields->Length; i++)
				{
					if(eLC->Lists[l]->elementFields[i] == "Name")
					{
						pos = i;
						break;
					}
				}
				if(pos > -1)
				{
					Clipboard::SetDataObject(eLC->GetValue(l,k,0) + "	" + eLC->GetValue(l,k,pos), true);
				}
				else
				{
					MessageBox::Show("Config Error: cannot find Name field");
				}
			}
			else
			{
				MessageBox::Show("Invalid List");
			}
		}
		else
		{
			MessageBox::Show("Operation not supported in List " + eLC->ConversationListIndex.ToString());
		}
	}
	private: System::Void click_xrefItem(System::Object^  sender, System::EventArgs^  ea)
	{
		int l = comboBox_lists->SelectedIndex;
		int e = listBox_items->SelectedIndex;
		if(l != eLC->ConversationListIndex)
		{
			if(l>-1 && e>-1)
			{
				ReferencesWindow^ eXRef = gcnew ReferencesWindow();
				array<Char>^chars = {'-'};
				int results = 0;

				for(int j=1; j<xrefs[l]->Length; j++)
				{
					array<String^>^x = xrefs[l][j]->Split(chars);
					for(int m=1; m<eLC->Lists[int::Parse(x[0])]->elementValues->Length; m++)
					{
						for(int k=1; k<x->Length; k++)
						{
							if(eLC->GetValue(int::Parse(x[0]),m,int::Parse(x[k])) == eLC->GetValue(l,e,0))
							{
								results++;
								int pos = -1;
								for(int i=0; i<eLC->Lists[l]->elementFields->Length; i++)
								{
									if(eLC->Lists[int::Parse(x[0])]->elementFields[i] == "Name")
									{
										pos = i;
										break;
									}
								}
								eXRef->dataGridView->Rows->Add(gcnew array<String^>{x[0],eLC->Lists[int::Parse(x[0])]->listName,eLC->GetValue(int::Parse(x[0]),m,0),eLC->GetValue(int::Parse(x[0]),m,pos),x[k] + " - " + eLC->Lists[int::Parse(x[0])]->elementFields[int::Parse(x[k])]});
							}
						}
					}
				}
				if(results > 0)
				{
					eXRef->Show();
				}
				else
				{
					eXRef->Close();
					MessageBox::Show("No results found");
				}
			}
		}
		else
		{
			MessageBox::Show("Operation not supported in List " + eLC->ConversationListIndex.ToString());
		}
	}
};
