#pragma once

#include "..\COMMON\task.h"
#include "..\COMMON\DebugWindow.h"

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
		comboBox_search->SelectedIndex = 0;

		for(int i=0; i<versions->Count-1; i++)
		{
			this->exportToolStripMenuItem->DropDownItems->Add("v" + ((int)versions[i]).ToString());
			this->exportToolStripMenuItem->DropDownItems[i]->Click += gcnew System::EventHandler(this, &MainWindow::click_save);
		}
	}

	protected:
	/// <summary>
	/// Clean up any resources being used.
	/// </summary>
	~MainWindow()
	{
		if (components)
		{
			delete components;
		}
	}

	static ArrayList^ versions = gcnew ArrayList(gcnew array<int>{55, 56, 89, 90, 92, 93, 100, 102, 103, 105, 108, 9999});
	array<Task^>^ Tasks;
	Task^ SelectedTask;
	Reward^ SelectedReward;

	private: System::Windows::Forms::MenuStrip^  menuStrip_mainMenu;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  loadToolStripMenuItem;
	private: System::Windows::Forms::ProgressBar^  progressBar_progress;
	private: System::Windows::Forms::TextBox^  textBox_search;
	private: System::Windows::Forms::Button^  button_search;
	private: System::Windows::Forms::TreeView^  treeView_tasks;
	private: System::Windows::Forms::DataGridView^  dataGridView_date_spans;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^  taskSplitToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^  groupBox_reward;
	private: System::Windows::Forms::DataGridView^  dataGridView_reward_item_group_items;
	private: System::Windows::Forms::TextBox^  textBox_reward_reputation;
	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::TextBox^  textBox_reward_spirit;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::TextBox^  textBox_reward_experience;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::TextBox^  textBox_reward_coins;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::TextBox^  textBox_reward_vigor;
	private: System::Windows::Forms::Label^  label21;
	private: System::Windows::Forms::TextBox^  textBox_reward_cultivation;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::TextBox^  textBox_reward_new_quest;
	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::TextBox^  textBox_reward_petbag_slots;
	private: System::Windows::Forms::Label^  label23;
	private: System::Windows::Forms::TextBox^  textBox_reward_inventory_slots;
	private: System::Windows::Forms::Label^  label24;
	private: System::Windows::Forms::TextBox^  textBox_reward_storage_slots;
	private: System::Windows::Forms::Label^  label25;
	private: System::Windows::Forms::TextBox^  textBox_conversation_prompt_text;
	private: System::Windows::Forms::TextBox^  textBox_reward_teleport_map_id;
	private: System::Windows::Forms::TextBox^  textBox_reward_teleport_z;
	private: System::Windows::Forms::TextBox^  textBox_reward_teleport_x;
	private: System::Windows::Forms::TextBox^  textBox_reward_teleport_altitude;
	private: System::Windows::Forms::Label^  label26;
	private: System::Windows::Forms::Label^  label37;
	private: System::Windows::Forms::ToolStripMenuItem^  exportToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^  groupBox_answers;
	private: System::Windows::Forms::GroupBox^  groupBox_dialogs;
	private: System::Windows::Forms::GroupBox^  groupBox_conversation;
	private: System::Windows::Forms::Label^  label40;
	private: System::Windows::Forms::TextBox^  textBox_conversation_general_text;
	private: System::Windows::Forms::Label^  label42;
	private: System::Windows::Forms::ListBox^  listBox_conversation_dialogs;
	private: System::Windows::Forms::Label^  label43;
	private: System::Windows::Forms::TextBox^  textBox_conversation_dialog_unknown;
	private: System::Windows::Forms::TextBox^  textBox_conversation_answer_task_link;
	private: System::Windows::Forms::Label^  label46;
	private: System::Windows::Forms::TextBox^  textBox_conversation_answer_question_link;
	private: System::Windows::Forms::Label^  label47;
	private: System::Windows::Forms::ListBox^  listBox_conversation_answers;
	private: System::Windows::Forms::GroupBox^  groupBox_questions;
	private: System::Windows::Forms::TextBox^  textBox_conversation_question_previous;
	private: System::Windows::Forms::Label^  label45;
	private: System::Windows::Forms::TextBox^  textBox_conversation_question_id;
	private: System::Windows::Forms::Label^  label44;
	private: System::Windows::Forms::ListBox^  listBox_conversation_questions;
	private: System::Windows::Forms::TextBox^  textBox_conversation_answer_text;
	private: System::Windows::Forms::TextBox^  textBox_conversation_question_text;
	private: System::Windows::Forms::TextBox^  textBox_conversation_dialog_text;
	private: System::Windows::Forms::GroupBox^  groupBox_reward_selector;
	private: System::Windows::Forms::ListBox^  listBox_reward_timed;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown_time_factor;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::RadioButton^  radioButton_timed;
	private: System::Windows::Forms::RadioButton^  radioButton_failed;
	private: System::Windows::Forms::RadioButton^  radioButton_success;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip_date_spans;
	private: System::Windows::Forms::ToolStripMenuItem^  addRowToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  deleteRowToolStripMenuItem;
	private: System::Windows::Forms::TextBox^  textBox_time_limit;
	private: System::Windows::Forms::Label^  label32;
	private: System::Windows::Forms::TextBox^  textBox_author_text;
	private: System::Windows::Forms::TextBox^  textBox_name;
	private: System::Windows::Forms::Label^  label29;
	private: System::Windows::Forms::TextBox^  textBox_id;
	private: System::Windows::Forms::Label^  label28;
	private: System::Windows::Forms::CheckBox^  checkBox_author_mode;
	private: System::Windows::Forms::ToolTip^  toolTip;
	private: System::Windows::Forms::ComboBox^  comboBox_type;
	private: System::Windows::Forms::Label^  label55;
	private: System::Windows::Forms::Label^  label57;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown_reward_item_groups_count;
	private: System::Windows::Forms::Label^  label56;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip_task;
	private: System::Windows::Forms::ToolStripMenuItem^  cloneSelectedToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  deleteSelectedToolStripMenuItem;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip_conversation_question;
	private: System::Windows::Forms::ToolStripMenuItem^  addToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  removeToolStripMenuItem;
	private: System::Windows::Forms::TextBox^  textBox_reward_unknown_2b;
	private: System::Windows::Forms::Label^  label61;
	private: System::Windows::Forms::TextBox^  textBox_reward_unknown_2a;
	private: System::Windows::Forms::Label^  label60;
	private: System::Windows::Forms::TextBox^  textBox_reward_ai_trigger;
	private: System::Windows::Forms::Label^  label63;
	private: System::Windows::Forms::TextBox^  textBox_unknown_07;
	private: System::Windows::Forms::Label^  label76;
	private: System::Windows::Forms::ToolStripMenuItem^  creatureBuilderListToolStripMenuItem;
	private: System::Windows::Forms::ComboBox^  comboBox_search;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripMenuItem^  exportSelectedItemToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  replaceSelectedItemToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^  groupBox_general;
	private: System::Windows::Forms::TextBox^  textBox_unknown_01;
	private: System::Windows::Forms::Label^  label81;
	private: System::Windows::Forms::CheckBox^  checkBox_has_date_fail;
	private: System::Windows::Forms::CheckBox^  checkBox_has_date_spans;
	private: System::Windows::Forms::TextBox^  textBox_unknown_05;
	private: System::Windows::Forms::Label^  label84;
	private: System::Windows::Forms::TextBox^  textBox_unknown_04;
	private: System::Windows::Forms::Label^  label31;
	private: System::Windows::Forms::TextBox^  textBox_unknown_06;
	private: System::Windows::Forms::Label^  label85;
	private: System::Windows::Forms::GroupBox^  groupBox_requirements;
	private: System::Windows::Forms::Label^  label35;
	private: System::Windows::Forms::TextBox^  textBox_level_min;
	private: System::Windows::Forms::Label^  label36;
	private: System::Windows::Forms::TextBox^  textBox_level_max;
	private: System::Windows::Forms::TextBox^  textBox_instant_pay_coins;
	private: System::Windows::Forms::Label^  label65;
	private: System::Windows::Forms::TextBox^  textBox_sub_quest_first;
	private: System::Windows::Forms::Label^  label52;
	private: System::Windows::Forms::TextBox^  textBox_next_quest;
	private: System::Windows::Forms::Label^  label51;
	private: System::Windows::Forms::TextBox^  textBox_previous_quest;
	private: System::Windows::Forms::Label^  label50;
	private: System::Windows::Forms::TextBox^  textBox_parent_quest;
	private: System::Windows::Forms::Label^  label49;
	private: System::Windows::Forms::CheckBox^  checkBox_unknown_02;
	private: System::Windows::Forms::CheckBox^  checkBox_unknown_03;
	private: System::Windows::Forms::Label^  label82;
	private: System::Windows::Forms::Label^  label86;
	private: System::Windows::Forms::Label^  label83;
	private: System::Windows::Forms::Label^  label87;
	private: System::Windows::Forms::Label^  label88;
	private: System::Windows::Forms::DataGridView^  dataGridView_date_fail;
	private: System::Windows::Forms::TextBox^  textBox_unknown_08;
	private: System::Windows::Forms::Label^  label89;
	private: System::Windows::Forms::TextBox^  textBox_unknown_09;
	private: System::Windows::Forms::Label^  label90;
	private: System::Windows::Forms::GroupBox^  groupBox_flags;
	private: System::Windows::Forms::Label^  label91;
	private: System::Windows::Forms::CheckBox^  checkBox_activate_first_subquest;
	private: System::Windows::Forms::Label^  label100;
	private: System::Windows::Forms::CheckBox^  checkBox_on_fail_parent_fail;
	private: System::Windows::Forms::Label^  label99;
	private: System::Windows::Forms::CheckBox^  checkBox_fail_on_death;
	private: System::Windows::Forms::Label^  label98;
	private: System::Windows::Forms::CheckBox^  checkBox_repeatable_after_failure;
	private: System::Windows::Forms::Label^  label97;
	private: System::Windows::Forms::CheckBox^  checkBox_repeatable;
	private: System::Windows::Forms::Label^  label96;
	private: System::Windows::Forms::CheckBox^  checkBox_can_give_up;
	private: System::Windows::Forms::Label^  label95;
	private: System::Windows::Forms::CheckBox^  checkBox_on_success_parent_success;
	private: System::Windows::Forms::Label^  label94;
	private: System::Windows::Forms::CheckBox^  checkBox_on_give_up_parent_fails;
	private: System::Windows::Forms::Label^  label93;
	private: System::Windows::Forms::CheckBox^  checkBox_activate_next_subquest;
	private: System::Windows::Forms::Label^  label92;
	private: System::Windows::Forms::CheckBox^  checkBox_activate_random_subquest;
	private: System::Windows::Forms::Label^  label101;
	private: System::Windows::Forms::CheckBox^  checkBox_unknown_10;
	private: System::Windows::Forms::Label^  label102;
	private: System::Windows::Forms::DataGridView^  dataGridView_trigger_location_spans;
	private: System::Windows::Forms::CheckBox^  checkBox_trigger_locations_has_spans;
	private: System::Windows::Forms::Label^  label106;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn37;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn38;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn39;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn40;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn41;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn42;
	private: System::Windows::Forms::Label^  label107;
	private: System::Windows::Forms::TextBox^  textBox_trigger_locations_map_id;
	private: System::Windows::Forms::GroupBox^  groupBox_trigger_location;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip_trigger_location;
	private: System::Windows::Forms::ToolStripMenuItem^  addToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  removeToolStripMenuItem1;
	private: System::Windows::Forms::GroupBox^  groupBox_fail_location;
	private: System::Windows::Forms::TextBox^  textBox_fail_locations_unknown_1;
	private: System::Windows::Forms::DataGridView^  dataGridView_fail_location_spans;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn43;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn44;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn45;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn46;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn47;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn48;
	private: System::Windows::Forms::TextBox^  textBox_fail_locations_map_id;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::GroupBox^  groupBox_valid_location;
	private: System::Windows::Forms::TextBox^  textBox_valid_locations_unknown_1;
	private: System::Windows::Forms::DataGridView^  dataGridView_valid_location_spans;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn49;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn50;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn51;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn52;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn53;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn54;
	private: System::Windows::Forms::TextBox^  textBox_valid_locations_map_id;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column5;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^  Column6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column8;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column9;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column10;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column11;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column12;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^  Column13;
	private: System::Windows::Forms::TextBox^  textBox_trigger_locations_unknown_1;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::CheckBox^  checkBox_fail_locations_has_spans;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::CheckBox^  checkBox_valid_locations_has_spans;
	private: System::Windows::Forms::Label^  label53;
	private: System::Windows::Forms::CheckBox^  checkBox_unknown_17;
	private: System::Windows::Forms::Label^  label108;
	private: System::Windows::Forms::CheckBox^  checkBox_has_instant_teleport;
	private: System::Windows::Forms::Label^  label109;
	private: System::Windows::Forms::Label^  label48;
	private: System::Windows::Forms::TextBox^  textBox_required_quests_undone_1;
	private: System::Windows::Forms::TextBox^  textBox_required_quests_undone_2;
	private: System::Windows::Forms::TextBox^  textBox_required_quests_undone_3;
	private: System::Windows::Forms::TextBox^  textBox_required_quests_undone_5;
	private: System::Windows::Forms::TextBox^  textBox_required_quests_undone_4;
	private: System::Windows::Forms::CheckBox^  checkBox_unknown_18;
	private: System::Windows::Forms::Label^  label110;
	private: System::Windows::Forms::CheckBox^  checkBox_unknown_20;
	private: System::Windows::Forms::Label^  label112;
	private: System::Windows::Forms::CheckBox^  checkBox_unknown_19;
	private: System::Windows::Forms::Label^  label111;
	private: System::Windows::Forms::TextBox^  textBox_ai_trigger;
	private: System::Windows::Forms::Label^  label113;
	private: System::Windows::Forms::GroupBox^  groupBox_basic_1;
	private: System::Windows::Forms::CheckBox^  checkBox_unknown_23;
	private: System::Windows::Forms::Label^  label116;
	private: System::Windows::Forms::CheckBox^  checkBox_unknown_22;
	private: System::Windows::Forms::Label^  label115;
	private: System::Windows::Forms::CheckBox^  checkBox_unknown_21;
	private: System::Windows::Forms::Label^  label114;
	private: System::Windows::Forms::TextBox^  textBox_unknown_level;
	private: System::Windows::Forms::Label^  label117;
	private: System::Windows::Forms::TextBox^  textBox_instant_teleport_location_z;
	private: System::Windows::Forms::Label^  label121;
	private: System::Windows::Forms::TextBox^  textBox_instant_teleport_location_alt;
	private: System::Windows::Forms::Label^  label120;
	private: System::Windows::Forms::TextBox^  textBox_instant_teleport_location_x;
	private: System::Windows::Forms::Label^  label119;
	private: System::Windows::Forms::TextBox^  textBox_instant_teleport_location_map_id;
	private: System::Windows::Forms::Label^  label118;
	private: System::Windows::Forms::Label^  label123;
	private: System::Windows::Forms::CheckBox^  checkBox_mark_available_point;
	private: System::Windows::Forms::Label^  label122;
	private: System::Windows::Forms::CheckBox^  checkBox_mark_available_icon;
	private: System::Windows::Forms::Label^  label33;
	private: System::Windows::Forms::TextBox^  textBox_quest_npc;
	private: System::Windows::Forms::Label^  label34;
	private: System::Windows::Forms::TextBox^  textBox_reward_npc;
	private: System::Windows::Forms::CheckBox^  checkBox_unknown_24;
	private: System::Windows::Forms::Label^  label124;
	private: System::Windows::Forms::CheckBox^  checkBox_unknown_26;
	private: System::Windows::Forms::Label^  label126;
	private: System::Windows::Forms::CheckBox^  checkBox_unknown_25;
	private: System::Windows::Forms::Label^  label125;
	private: System::Windows::Forms::CheckBox^  checkBox_craft_skill;
	private: System::Windows::Forms::Label^  label127;
	private: System::Windows::Forms::Label^  label128;
	private: System::Windows::Forms::TextBox^  textBox_unknown_26_01;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip_valid_location;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem5;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem6;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip_fail_location;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem3;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem4;
	private: System::Windows::Forms::CheckBox^  checkBox_unknown_28;
	private: System::Windows::Forms::CheckBox^  checkBox_unknown_27;
	private: System::Windows::Forms::Label^  label64;
	private: System::Windows::Forms::Label^  label62;
	private: System::Windows::Forms::TextBox^  textBox_required_items_unknown;
	private: System::Windows::Forms::Label^  label70;
	private: System::Windows::Forms::CheckBox^  checkBox_unknown_28_01;
	private: System::Windows::Forms::Label^  label71;
	private: System::Windows::Forms::TextBox^  textBox_unknown_30;
	private: System::Windows::Forms::Label^  label73;
	private: System::Windows::Forms::TextBox^  textBox_unknown_29;
	private: System::Windows::Forms::Label^  label72;
	private: System::Windows::Forms::TextBox^  textBox_given_items_unknown;
	private: System::Windows::Forms::Label^  label129;
	private: System::Windows::Forms::CheckBox^  checkBox_unknown_31;
	private: System::Windows::Forms::Label^  label130;
	private: System::Windows::Forms::TextBox^  textBox_unknown_32;
	private: System::Windows::Forms::Label^  label131;
	private: System::Windows::Forms::TextBox^  textBox_required_reputation;
	private: System::Windows::Forms::Label^  label38;
	private: System::Windows::Forms::CheckBox^  checkBox_unknown_33;
	private: System::Windows::Forms::Label^  label132;
	private: System::Windows::Forms::Label^  label41;
	private: System::Windows::Forms::TextBox^  textBox_required_quests_done_1;
	private: System::Windows::Forms::TextBox^  textBox_required_quests_done_2;
	private: System::Windows::Forms::TextBox^  textBox_required_quests_done_3;
	private: System::Windows::Forms::TextBox^  textBox_required_quests_done_4;
	private: System::Windows::Forms::TextBox^  textBox_required_quests_done_5;
	private: System::Windows::Forms::CheckBox^  checkBox_unknown_35;
	private: System::Windows::Forms::Label^  label133;
	private: System::Windows::Forms::TextBox^  textBox_unknown_34;
	private: System::Windows::Forms::Label^  label134;
	private: System::Windows::Forms::TextBox^  textBox_unknown_38;
	private: System::Windows::Forms::Label^  label137;
	private: System::Windows::Forms::TextBox^  textBox_unknown_37;
	private: System::Windows::Forms::Label^  label136;
	private: System::Windows::Forms::TextBox^  textBox_unknown_36;
	private: System::Windows::Forms::Label^  label135;
	private: System::Windows::Forms::CheckBox^  checkBox_unknown_39;
	private: System::Windows::Forms::Label^  label138;
	private: System::Windows::Forms::ComboBox^  comboBox_required_gender;
	private: System::Windows::Forms::Label^  label58;
	private: System::Windows::Forms::CheckBox^  checkBox_unknown_40;
	private: System::Windows::Forms::Label^  label30;
	private: System::Windows::Forms::CheckBox^  checkBox_unknown_43;
	private: System::Windows::Forms::Label^  label143;
	private: System::Windows::Forms::CheckBox^  checkBox_required_be_gm;
	private: System::Windows::Forms::Label^  label142;
	private: System::Windows::Forms::CheckBox^  checkBox_unknown_42;
	private: System::Windows::Forms::Label^  label141;
	private: System::Windows::Forms::CheckBox^  checkBox_required_be_married;
	private: System::Windows::Forms::Label^  label140;
	private: System::Windows::Forms::CheckBox^  checkBox_unknown_41;
	private: System::Windows::Forms::Label^  label139;
	private: System::Windows::Forms::CheckBox^  checkBox_occupation_seeker;
	private: System::Windows::Forms::CheckBox^  checkBox_occupation_mystic;
	private: System::Windows::Forms::CheckBox^  checkBox_occupation_cleric;
	private: System::Windows::Forms::CheckBox^  checkBox_occupation_archer;
	private: System::Windows::Forms::CheckBox^  checkBox_occupation_psychic;
	private: System::Windows::Forms::CheckBox^  checkBox_occupation_barbarian;
	private: System::Windows::Forms::CheckBox^  checkBox_occupation_venomancer;
	private: System::Windows::Forms::CheckBox^  checkBox_occupation_assassin;
	private: System::Windows::Forms::CheckBox^  checkBox_occupation_wizard;
	private: System::Windows::Forms::CheckBox^  checkBox_occupation_blademaster;
	private: System::Windows::Forms::TextBox^  textBox_unknown_44;
	private: System::Windows::Forms::Label^  label144;
	private: System::Windows::Forms::DataGridView^  dataGridView_date_unknown;
	private: System::Windows::Forms::Label^  label145;
	private: System::Windows::Forms::TextBox^  textBox_unknown_45;
	private: System::Windows::Forms::Label^  label146;
	private: System::Windows::Forms::CheckBox^  checkBox_unknown_46;
	private: System::Windows::Forms::Label^  label147;
	private: System::Windows::Forms::TextBox^  textBox_unknown_47;
	private: System::Windows::Forms::Label^  label148;
	private: System::Windows::Forms::TextBox^  textBox_required_apothecary_level;
	private: System::Windows::Forms::Label^  label80;
	private: System::Windows::Forms::TextBox^  textBox_required_craftsman_level;
	private: System::Windows::Forms::Label^  label79;
	private: System::Windows::Forms::TextBox^  textBox_required_tailor_level;
	private: System::Windows::Forms::Label^  label78;
	private: System::Windows::Forms::TextBox^  textBox_required_blacksmith_level;
	private: System::Windows::Forms::Label^  label77;
	private: System::Windows::Forms::TextBox^  textBox_unknown_49;
	private: System::Windows::Forms::Label^  label150;
	private: System::Windows::Forms::TextBox^  textBox_unknown_48;
	private: System::Windows::Forms::Label^  label149;
	private: System::Windows::Forms::CheckBox^  checkBox_unknown_51;
	private: System::Windows::Forms::Label^  label152;
	private: System::Windows::Forms::TextBox^  textBox_unknown_50;
	private: System::Windows::Forms::Label^  label151;
	private: System::Windows::Forms::TextBox^  textBox_resource_pq_audit_id;
	private: System::Windows::Forms::Label^  label154;
	private: System::Windows::Forms::TextBox^  textBox_unknown_52;
	private: System::Windows::Forms::Label^  label153;
	private: System::Windows::Forms::TextBox^  textBox_unknown_55;
	private: System::Windows::Forms::Label^  label158;
	private: System::Windows::Forms::TextBox^  textBox_required_pq_contribution;
	private: System::Windows::Forms::Label^  label157;
	private: System::Windows::Forms::TextBox^  textBox_unknown_54;
	private: System::Windows::Forms::Label^  label156;
	private: System::Windows::Forms::TextBox^  textBox_unknown_53;
	private: System::Windows::Forms::Label^  label155;
	private: System::Windows::Forms::TextBox^  textBox_unknown_55_02_01;
	private: System::Windows::Forms::Label^  label159;
	private: System::Windows::Forms::TextBox^  textBox_required_npc_type;
	private: System::Windows::Forms::Label^  label161;
	private: System::Windows::Forms::TextBox^  textBox_required_success_type;
	private: System::Windows::Forms::Label^  label160;
	private: System::Windows::Forms::TextBox^  textBox_required_get_items_unknown;
	private: System::Windows::Forms::Label^  label67;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::DataGridView^  dataGridView_required_get_items;
	private: System::Windows::Forms::TextBox^  textBox_required_chases_unknown;
	private: System::Windows::Forms::Label^  label66;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::DataGridView^  dataGridView_required_chases;
	private: System::Windows::Forms::Label^  label27;
	private: System::Windows::Forms::TextBox^  textBox_required_wait_time;
	private: System::Windows::Forms::TextBox^  textBox_required_coins;
	private: System::Windows::Forms::Label^  label39;
	private: System::Windows::Forms::TextBox^  textBox_unknown_57;
	private: System::Windows::Forms::Label^  label162;
	private: System::Windows::Forms::TextBox^  textBox_unknown_56;
	private: System::Windows::Forms::Label^  label163;
	private: System::Windows::Forms::TextBox^  textBox_unknown_57_01;
	private: System::Windows::Forms::Label^  label165;
	private: System::Windows::Forms::GroupBox^  groupBox_basic_2;
	private: System::Windows::Forms::GroupBox^  groupBox_pq_exit_area;
	private: System::Windows::Forms::Label^  label69;
	private: System::Windows::Forms::DataGridView^  dataGridView_required_items;
	private: System::Windows::Forms::Label^  label68;
	private: System::Windows::Forms::DataGridView^  dataGridView_given_items;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip_required_items;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem7;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem8;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip_given_items;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem9;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem10;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip_required_get_items;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem11;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem12;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn55;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn56;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn57;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn58;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn59;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^  Column_date_unknown_weekday;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn32;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn33;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn34;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn35;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn36;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^  Column_date_fail_weekday;
	private: System::Windows::Forms::DataGridView^  dataGridView_team_members;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip_team_members;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem13;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem14;
	private: System::Windows::Forms::Label^  label74;
	private: System::Windows::Forms::GroupBox^  groupBox_reach_location;
	private: System::Windows::Forms::CheckBox^  checkBox_reach_locations_has_spans;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox_reach_locations_unknown_1;
	private: System::Windows::Forms::DataGridView^  dataGridView_reach_location_spans;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn60;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn61;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn62;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn63;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn64;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn65;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip_reach_location;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem15;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem16;
	private: System::Windows::Forms::TextBox^  textBox_reach_locations_map_id;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::DataGridView^  dataGridView_pq_script_infos;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn66;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn67;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn69;
	private: System::Windows::Forms::Label^  label75;
	private: System::Windows::Forms::DataGridView^  dataGridView_pq_scripts;
	private: System::Windows::Forms::TextBox^  textBox_pq_unknown_2;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  textBox_pq_unknown_1;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label54;
	private: System::Windows::Forms::TextBox^  textBox_pq_unknown_3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn68;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn70;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn71;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column19;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column20;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column21;
	private: System::Windows::Forms::Label^  label167;
	private: System::Windows::Forms::TextBox^  textBox_pq_unknown_6;
	private: System::Windows::Forms::Label^  label166;
	private: System::Windows::Forms::TextBox^  textBox_pq_unknown_5;
	private: System::Windows::Forms::Label^  label164;
	private: System::Windows::Forms::TextBox^  textBox_pq_unknown_4;
	private: System::Windows::Forms::Label^  label168;
	private: System::Windows::Forms::DataGridView^  dataGridView_pq_chases;
	private: System::Windows::Forms::Label^  label173;
	private: System::Windows::Forms::TextBox^  textBox_pq_unknown_11;
	private: System::Windows::Forms::Label^  label174;
	private: System::Windows::Forms::TextBox^  textBox_pq_unknown_10;
	private: System::Windows::Forms::Label^  label169;
	private: System::Windows::Forms::TextBox^  textBox_pq_unknown_9;
	private: System::Windows::Forms::Label^  label170;
	private: System::Windows::Forms::TextBox^  textBox_pq_unknown_8;
	private: System::Windows::Forms::Label^  label171;
	private: System::Windows::Forms::TextBox^  textBox_pq_unknown_7;
	private: System::Windows::Forms::GroupBox^  groupBox_pq_location;
	private: System::Windows::Forms::CheckBox^  checkBox_pq_location_has_spans;
	private: System::Windows::Forms::Label^  label172;
	private: System::Windows::Forms::TextBox^  textBox_pq_location_unknown_1;
	private: System::Windows::Forms::DataGridView^  dataGridView_pq_location_spans;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn75;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn76;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn77;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn78;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn79;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn80;
	private: System::Windows::Forms::TextBox^  textBox_pq_location_map_id;
	private: System::Windows::Forms::Label^  label175;
	private: System::Windows::Forms::Label^  label176;
	private: System::Windows::Forms::Label^  label182;
	private: System::Windows::Forms::TextBox^  textBox_pq_unknown_16;
	private: System::Windows::Forms::Label^  label181;
	private: System::Windows::Forms::TextBox^  textBox_pq_unknown_15;
	private: System::Windows::Forms::Label^  label180;
	private: System::Windows::Forms::TextBox^  textBox_pq_unknown_14;
	private: System::Windows::Forms::Label^  label179;
	private: System::Windows::Forms::TextBox^  textBox_pq_id_script;
	private: System::Windows::Forms::Label^  label178;
	private: System::Windows::Forms::TextBox^  textBox_pq_unknown_13;
	private: System::Windows::Forms::Label^  label177;
	private: System::Windows::Forms::TextBox^  textBox_pq_unknown_12;
	private: System::Windows::Forms::Label^  label183;
	private: System::Windows::Forms::TextBox^  textBox_pq_unknown_17;
	private: System::Windows::Forms::Label^  label184;
	private: System::Windows::Forms::DataGridView^  dataGridView_pq_special_scripts;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn81;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn82;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn83;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn84;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn85;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn86;
	private: System::Windows::Forms::DataGridView^  dataGridView_pq_messages;
	private: System::Windows::Forms::Label^  label188;
	private: System::Windows::Forms::Label^  label187;
	private: System::Windows::Forms::TextBox^  textBox_pq_unknown_20;
	private: System::Windows::Forms::Label^  label186;
	private: System::Windows::Forms::TextBox^  textBox_pq_unknown_19;
	private: System::Windows::Forms::Label^  label185;
	private: System::Windows::Forms::TextBox^  textBox_pq_unknown_18;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn87;









	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn72;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn73;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column22;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn74;
	private: System::Windows::Forms::TextBox^  textBox_player_limit;
	private: System::Windows::Forms::ToolStripMenuItem^  developerToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  developerSearchToolStripMenuItem;
	private: System::Windows::Forms::ToolStripComboBox^  toolStripComboBox_developer_search;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator2;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem17;
	private: System::Windows::Forms::ToolStripMenuItem^  changeConfirmationToolStripMenuItem;
	private: System::Windows::Forms::TextBox^  textBox_receive_quest_probability;
	private: System::Windows::Forms::Label^  label105;
	private: System::Windows::Forms::TextBox^  textBox_unknown_59;
	private: System::Windows::Forms::Label^  label104;
	private: System::Windows::Forms::TextBox^  textBox_unknown_58;
	private: System::Windows::Forms::Label^  label103;
	private: System::Windows::Forms::CheckBox^  checkBox_unknown_60_01;
	private: System::Windows::Forms::Label^  label190;
	private: System::Windows::Forms::CheckBox^  checkBox_unknown_60;
	private: System::Windows::Forms::Label^  label189;
	private: System::Windows::Forms::TextBox^  textBox_unknown_61;
	private: System::Windows::Forms::Label^  label191;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::TabPage^  tabPage4;
	private: System::Windows::Forms::TabPage^  tabPage5;
	private: System::Windows::Forms::TabPage^  tabPage6;
	private: System::Windows::Forms::TabPage^  tabPage7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn24;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  dataGridViewTextBoxColumn25;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn26;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn27;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn4;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  dataGridViewTextBoxColumn5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn16;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  dataGridViewTextBoxColumn17;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn18;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn19;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column17;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn20;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn21;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn22;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn23;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column14;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column15;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column16;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::GroupBox^  groupBox_reward_items;
	private: System::Windows::Forms::GroupBox^  groupBox_reward_pq;
	private: System::Windows::Forms::TextBox^  textBox_reward_new_waypoint;
	private: System::Windows::Forms::Label^  label192;
	private: System::Windows::Forms::TextBox^  textBox_reward_account_stash_slots;
	private: System::Windows::Forms::Label^  label195;
	private: System::Windows::Forms::TextBox^  textBox_reward_wardrobe_slots;
	private: System::Windows::Forms::Label^  label194;
	private: System::Windows::Forms::TextBox^  textBox_reward_cupboard_slots;
	private: System::Windows::Forms::Label^  label193;
	private: System::Windows::Forms::Label^  label196;
	private: System::Windows::Forms::Label^  label198;
	private: System::Windows::Forms::Label^  label197;
	private: System::Windows::Forms::TextBox^  textBox_reward_unknown_6;
	private: System::Windows::Forms::Label^  label200;
	private: System::Windows::Forms::Label^  label201;
	private: System::Windows::Forms::TextBox^  textBox_reward_influence;
	private: System::Windows::Forms::TextBox^  textBox_reward_unknown_5;
	private: System::Windows::Forms::Label^  label202;
	private: System::Windows::Forms::TextBox^  textBox_reward_prestige;
	private: System::Windows::Forms::Label^  label203;
	private: System::Windows::Forms::TextBox^  textBox_reward_seperator;
	private: System::Windows::Forms::Label^  label199;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^  Column_reward_item_groups;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn28;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  dataGridViewTextBoxColumn29;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn30;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn31;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column23;
	private: System::Windows::Forms::CheckedListBox^  checkedListBox_reward_item_groups_flag;
	private: System::Windows::Forms::TextBox^  textBox_reward_pq_unknown_0;
	private: System::Windows::Forms::Label^  label59;
	private: System::Windows::Forms::TextBox^  textBox_reward_pq_unknown_level;
	private: System::Windows::Forms::Label^  label208;
	private: System::Windows::Forms::TextBox^  textBox_reward_pq_unknown_2;
	private: System::Windows::Forms::Label^  label207;
	private: System::Windows::Forms::TextBox^  textBox_reward_pq_unknown_quest;
	private: System::Windows::Forms::Label^  label206;
	private: System::Windows::Forms::TextBox^  textBox_reward_pq_unknown_1;
	private: System::Windows::Forms::Label^  label205;
	private: System::Windows::Forms::TextBox^  textBox_reward_pq_event_gold;
	private: System::Windows::Forms::Label^  label204;
	private: System::Windows::Forms::TextBox^  textBox_reward_pq_contribution_required;
	private: System::Windows::Forms::Label^  label211;
	private: System::Windows::Forms::TextBox^  textBox_reward_pq_contribution_random_max;
	private: System::Windows::Forms::Label^  label210;
	private: System::Windows::Forms::TextBox^  textBox_reward_pq_contribution_random_min;
	private: System::Windows::Forms::Label^  label209;
	private: System::Windows::Forms::TextBox^  textBox_reward_pq_unknown_3;
	private: System::Windows::Forms::Label^  label212;
	private: System::Windows::Forms::TextBox^  textBox_reward_pq_unknown_7;
	private: System::Windows::Forms::Label^  label216;
	private: System::Windows::Forms::TextBox^  textBox_reward_pq_unknown_6;
	private: System::Windows::Forms::Label^  label215;
	private: System::Windows::Forms::TextBox^  textBox_reward_pq_unknown_5;
	private: System::Windows::Forms::Label^  label214;
	private: System::Windows::Forms::TextBox^  textBox_reward_pq_unknown_4;
	private: System::Windows::Forms::Label^  label213;
	private: System::Windows::Forms::Label^  label219;
	private: System::Windows::Forms::DataGridView^  dataGridView_reward_pq_chases;
	private: System::Windows::Forms::DataGridView^  dataGridView_reward_pq_messages;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn89;
	private: System::Windows::Forms::Label^  label218;
	private: System::Windows::Forms::DataGridView^  dataGridView_reward_pq_scripts;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn88;
	private: System::Windows::Forms::Label^  label217;
	private: System::Windows::Forms::Label^  label220;
	private: System::Windows::Forms::DataGridView^  dataGridView_reward_pq_items;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column24;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column25;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  Column26;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn94;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn95;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn96;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn90;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn91;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn92;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn93;
	private: System::Windows::Forms::Label^  label221;
	private: System::Windows::Forms::DataGridView^  dataGridView_reward_pq_specials;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn97;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn98;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn100;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip_reward_items;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem18;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem19;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip_reward_pq_chases;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem20;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem21;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip_reward_pq_items;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem22;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem23;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip_pq_chases;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem24;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem25;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip_chases;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem26;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem27;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip_pq_location;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem28;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem29;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip_pq_script_infos;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem30;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem31;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip_pq_scripts;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem32;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem33;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip_pq_special_scripts;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem34;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem35;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip_pq_messages;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem36;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem37;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip_reward_timed;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem38;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem39;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip_reward_pq_scripts;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem40;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem41;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip_reward_pq_specials;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem42;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem43;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip_reward_pq_messages;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem44;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem45;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip_conversation_answer;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem46;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem47;

	private: System::Windows::Forms::Label^  label222;
	private: System::Windows::Forms::TextBox^  textBox_unknown_55_06;
	private: System::Windows::Forms::Label^  label227;
	private: System::Windows::Forms::TextBox^  textBox_unknown_55_05;
	private: System::Windows::Forms::Label^  label228;
	private: System::Windows::Forms::TextBox^  textBox_unknown_55_04;
	private: System::Windows::Forms::Label^  label229;
	private: System::Windows::Forms::TextBox^  textBox_required_influence_fee;
	private: System::Windows::Forms::Label^  label224;
	private: System::Windows::Forms::TextBox^  textBox_unknown_55_03;
	private: System::Windows::Forms::Label^  label225;
	private: System::Windows::Forms::TextBox^  textBox_required_prestige;
	private: System::Windows::Forms::Label^  label223;
	private: System::Windows::Forms::TextBox^  textBox_unknown_55_02_02;
	private: System::Windows::Forms::Label^  label226;
	private: System::Windows::Forms::ComboBox^  comboBox_required_force;
	private: System::Windows::Forms::Label^  label230;
	private: System::Windows::Forms::Label^  label231;
	private: System::Windows::Forms::TextBox^  textBox_pq_required_quests_completed;
	private: System::Windows::Forms::CheckBox^  checkBox_unknown_42_2;
	private: System::Windows::Forms::Label^  label233;
	private: System::Windows::Forms::CheckBox^  checkBox_unknown_42_1;
	private: System::Windows::Forms::Label^  label232;
	private: System::Windows::Forms::TextBox^  textBox_reward_quest_slot_expansion;
	private: System::Windows::Forms::Label^  label234;
	private: System::Windows::Forms::Label^  label235;
	private: System::Windows::Forms::ComboBox^  comboBox_required_cultivation;
private: System::Windows::Forms::TextBox^  textBox_required_morai_pk_unknown;

private: System::Windows::Forms::Label^  label236;
private: System::Windows::Forms::Label^  label237;
private: System::Windows::Forms::DataGridView^  dataGridView_required_morai_pk;










private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn8;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn9;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn10;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn11;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn12;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn13;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn14;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn15;
private: System::Windows::Forms::DataGridViewComboBoxColumn^  Column18;










private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip_morai_pk;
private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem48;
private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem49;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn99;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn101;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn102;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn103;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn104;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  DataGridViewTextBoxColumn281;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn106;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn107;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column27;
private: System::Windows::Forms::DataGridViewComboBoxColumn^  Column28;









































































































	private: System::ComponentModel::IContainer^  components;

	private:
	/// <summary>
	/// Required designer variable.
	/// </summary>


#pragma region Windows Form Designer generated code
	/// <summary>
	/// Required method for Designer support - do not modify
	/// the contents of this method with the code editor.
	/// </summary>
	void InitializeComponent(void)
	{
		this->components = (gcnew System::ComponentModel::Container());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle14 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle5 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle6 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle7 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle8 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle9 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle10 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle11 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle12 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle13 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle20 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle15 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle16 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle17 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle18 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle19 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle22 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle21 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle25 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle23 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle24 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle28 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle26 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle27 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle31 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle29 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle30 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle34 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle32 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle33 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle41 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle35 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle36 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle37 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle38 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle39 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle40 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle48 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle42 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle43 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle44 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle45 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle46 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle47 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle55 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle49 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle50 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle51 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle52 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle53 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle54 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle62 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle56 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle57 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle58 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle59 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle60 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle61 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle73 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle83 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle74 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle75 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle76 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle77 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle78 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle79 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle80 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle81 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle82 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle88 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle84 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle85 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle86 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle87 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle93 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle89 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle90 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle91 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle92 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle98 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle94 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle95 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle96 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle97 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle104 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle99 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle100 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle101 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle102 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle103 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle111 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle105 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle106 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle107 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle108 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle109 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle110 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle118 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle112 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle113 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle114 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle115 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle116 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle117 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle125 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle119 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle120 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle121 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle122 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle123 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle124 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle128 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle126 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle127 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle131 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle129 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle130 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle134 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle132 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle133 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle136 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle135 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle138 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle137 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle63 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle64 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle65 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle66 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle67 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle68 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle69 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle70 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle71 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle72 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		this->menuStrip_mainMenu = (gcnew System::Windows::Forms::MenuStrip());
		this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->loadToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->exportToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->taskSplitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->creatureBuilderListToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->developerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->changeConfirmationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->developerSearchToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->toolStripComboBox_developer_search = (gcnew System::Windows::Forms::ToolStripComboBox());
		this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
		this->toolStripMenuItem17 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->contextMenuStrip_date_spans = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
		this->addRowToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->deleteRowToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->progressBar_progress = (gcnew System::Windows::Forms::ProgressBar());
		this->textBox_search = (gcnew System::Windows::Forms::TextBox());
		this->button_search = (gcnew System::Windows::Forms::Button());
		this->treeView_tasks = (gcnew System::Windows::Forms::TreeView());
		this->contextMenuStrip_task = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
		this->cloneSelectedToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->deleteSelectedToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
		this->exportSelectedItemToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->replaceSelectedItemToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->comboBox_type = (gcnew System::Windows::Forms::ComboBox());
		this->label55 = (gcnew System::Windows::Forms::Label());
		this->checkBox_author_mode = (gcnew System::Windows::Forms::CheckBox());
		this->textBox_time_limit = (gcnew System::Windows::Forms::TextBox());
		this->label32 = (gcnew System::Windows::Forms::Label());
		this->textBox_author_text = (gcnew System::Windows::Forms::TextBox());
		this->textBox_name = (gcnew System::Windows::Forms::TextBox());
		this->label29 = (gcnew System::Windows::Forms::Label());
		this->textBox_id = (gcnew System::Windows::Forms::TextBox());
		this->label28 = (gcnew System::Windows::Forms::Label());
		this->textBox_unknown_07 = (gcnew System::Windows::Forms::TextBox());
		this->label76 = (gcnew System::Windows::Forms::Label());
		this->dataGridView_date_spans = (gcnew System::Windows::Forms::DataGridView());
		this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Column6 = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
		this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Column8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Column9 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Column10 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Column11 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Column12 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Column13 = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
		this->dataGridView_reward_item_group_items = (gcnew System::Windows::Forms::DataGridView());
		this->Column_reward_item_groups = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
		this->dataGridViewTextBoxColumn28 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn29 = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
		this->dataGridViewTextBoxColumn30 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn31 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Column23 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->contextMenuStrip_reward_items = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
		this->toolStripMenuItem18 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->toolStripMenuItem19 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->groupBox_reward_selector = (gcnew System::Windows::Forms::GroupBox());
		this->numericUpDown_time_factor = (gcnew System::Windows::Forms::NumericUpDown());
		this->label3 = (gcnew System::Windows::Forms::Label());
		this->radioButton_timed = (gcnew System::Windows::Forms::RadioButton());
		this->radioButton_failed = (gcnew System::Windows::Forms::RadioButton());
		this->radioButton_success = (gcnew System::Windows::Forms::RadioButton());
		this->listBox_reward_timed = (gcnew System::Windows::Forms::ListBox());
		this->contextMenuStrip_reward_timed = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
		this->toolStripMenuItem38 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->toolStripMenuItem39 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->groupBox_reward = (gcnew System::Windows::Forms::GroupBox());
		this->textBox_reward_quest_slot_expansion = (gcnew System::Windows::Forms::TextBox());
		this->label234 = (gcnew System::Windows::Forms::Label());
		this->textBox_reward_unknown_6 = (gcnew System::Windows::Forms::TextBox());
		this->label200 = (gcnew System::Windows::Forms::Label());
		this->label201 = (gcnew System::Windows::Forms::Label());
		this->textBox_reward_influence = (gcnew System::Windows::Forms::TextBox());
		this->textBox_reward_unknown_5 = (gcnew System::Windows::Forms::TextBox());
		this->label202 = (gcnew System::Windows::Forms::Label());
		this->textBox_reward_prestige = (gcnew System::Windows::Forms::TextBox());
		this->label203 = (gcnew System::Windows::Forms::Label());
		this->textBox_reward_seperator = (gcnew System::Windows::Forms::TextBox());
		this->label199 = (gcnew System::Windows::Forms::Label());
		this->label198 = (gcnew System::Windows::Forms::Label());
		this->label197 = (gcnew System::Windows::Forms::Label());
		this->label196 = (gcnew System::Windows::Forms::Label());
		this->textBox_reward_account_stash_slots = (gcnew System::Windows::Forms::TextBox());
		this->label195 = (gcnew System::Windows::Forms::Label());
		this->textBox_reward_wardrobe_slots = (gcnew System::Windows::Forms::TextBox());
		this->label194 = (gcnew System::Windows::Forms::Label());
		this->textBox_reward_cupboard_slots = (gcnew System::Windows::Forms::TextBox());
		this->label193 = (gcnew System::Windows::Forms::Label());
		this->textBox_reward_new_waypoint = (gcnew System::Windows::Forms::TextBox());
		this->label192 = (gcnew System::Windows::Forms::Label());
		this->label63 = (gcnew System::Windows::Forms::Label());
		this->textBox_reward_ai_trigger = (gcnew System::Windows::Forms::TextBox());
		this->textBox_reward_unknown_2b = (gcnew System::Windows::Forms::TextBox());
		this->label61 = (gcnew System::Windows::Forms::Label());
		this->textBox_reward_unknown_2a = (gcnew System::Windows::Forms::TextBox());
		this->label60 = (gcnew System::Windows::Forms::Label());
		this->textBox_reward_teleport_map_id = (gcnew System::Windows::Forms::TextBox());
		this->textBox_reward_teleport_z = (gcnew System::Windows::Forms::TextBox());
		this->textBox_reward_teleport_x = (gcnew System::Windows::Forms::TextBox());
		this->textBox_reward_teleport_altitude = (gcnew System::Windows::Forms::TextBox());
		this->label26 = (gcnew System::Windows::Forms::Label());
		this->textBox_reward_petbag_slots = (gcnew System::Windows::Forms::TextBox());
		this->label23 = (gcnew System::Windows::Forms::Label());
		this->textBox_reward_inventory_slots = (gcnew System::Windows::Forms::TextBox());
		this->label24 = (gcnew System::Windows::Forms::Label());
		this->textBox_reward_storage_slots = (gcnew System::Windows::Forms::TextBox());
		this->label25 = (gcnew System::Windows::Forms::Label());
		this->textBox_reward_new_quest = (gcnew System::Windows::Forms::TextBox());
		this->label22 = (gcnew System::Windows::Forms::Label());
		this->textBox_reward_vigor = (gcnew System::Windows::Forms::TextBox());
		this->label21 = (gcnew System::Windows::Forms::Label());
		this->textBox_reward_cultivation = (gcnew System::Windows::Forms::TextBox());
		this->label20 = (gcnew System::Windows::Forms::Label());
		this->textBox_reward_reputation = (gcnew System::Windows::Forms::TextBox());
		this->label19 = (gcnew System::Windows::Forms::Label());
		this->textBox_reward_spirit = (gcnew System::Windows::Forms::TextBox());
		this->label18 = (gcnew System::Windows::Forms::Label());
		this->textBox_reward_experience = (gcnew System::Windows::Forms::TextBox());
		this->label17 = (gcnew System::Windows::Forms::Label());
		this->textBox_reward_coins = (gcnew System::Windows::Forms::TextBox());
		this->label16 = (gcnew System::Windows::Forms::Label());
		this->label57 = (gcnew System::Windows::Forms::Label());
		this->numericUpDown_reward_item_groups_count = (gcnew System::Windows::Forms::NumericUpDown());
		this->label56 = (gcnew System::Windows::Forms::Label());
		this->label37 = (gcnew System::Windows::Forms::Label());
		this->groupBox_conversation = (gcnew System::Windows::Forms::GroupBox());
		this->textBox_conversation_general_text = (gcnew System::Windows::Forms::TextBox());
		this->label42 = (gcnew System::Windows::Forms::Label());
		this->label40 = (gcnew System::Windows::Forms::Label());
		this->textBox_conversation_prompt_text = (gcnew System::Windows::Forms::TextBox());
		this->groupBox_answers = (gcnew System::Windows::Forms::GroupBox());
		this->textBox_conversation_answer_text = (gcnew System::Windows::Forms::TextBox());
		this->textBox_conversation_answer_task_link = (gcnew System::Windows::Forms::TextBox());
		this->label46 = (gcnew System::Windows::Forms::Label());
		this->textBox_conversation_answer_question_link = (gcnew System::Windows::Forms::TextBox());
		this->label47 = (gcnew System::Windows::Forms::Label());
		this->listBox_conversation_answers = (gcnew System::Windows::Forms::ListBox());
		this->contextMenuStrip_conversation_answer = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
		this->toolStripMenuItem46 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->toolStripMenuItem47 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->contextMenuStrip_conversation_question = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
		this->addToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->removeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->groupBox_questions = (gcnew System::Windows::Forms::GroupBox());
		this->textBox_conversation_question_text = (gcnew System::Windows::Forms::TextBox());
		this->textBox_conversation_question_previous = (gcnew System::Windows::Forms::TextBox());
		this->label45 = (gcnew System::Windows::Forms::Label());
		this->textBox_conversation_question_id = (gcnew System::Windows::Forms::TextBox());
		this->label44 = (gcnew System::Windows::Forms::Label());
		this->listBox_conversation_questions = (gcnew System::Windows::Forms::ListBox());
		this->groupBox_dialogs = (gcnew System::Windows::Forms::GroupBox());
		this->textBox_conversation_dialog_text = (gcnew System::Windows::Forms::TextBox());
		this->textBox_conversation_dialog_unknown = (gcnew System::Windows::Forms::TextBox());
		this->label43 = (gcnew System::Windows::Forms::Label());
		this->listBox_conversation_dialogs = (gcnew System::Windows::Forms::ListBox());
		this->toolTip = (gcnew System::Windows::Forms::ToolTip(this->components));
		this->label106 = (gcnew System::Windows::Forms::Label());
		this->label107 = (gcnew System::Windows::Forms::Label());
		this->label10 = (gcnew System::Windows::Forms::Label());
		this->label11 = (gcnew System::Windows::Forms::Label());
		this->label12 = (gcnew System::Windows::Forms::Label());
		this->label13 = (gcnew System::Windows::Forms::Label());
		this->label14 = (gcnew System::Windows::Forms::Label());
		this->label15 = (gcnew System::Windows::Forms::Label());
		this->label53 = (gcnew System::Windows::Forms::Label());
		this->label48 = (gcnew System::Windows::Forms::Label());
		this->label41 = (gcnew System::Windows::Forms::Label());
		this->label4 = (gcnew System::Windows::Forms::Label());
		this->label5 = (gcnew System::Windows::Forms::Label());
		this->label6 = (gcnew System::Windows::Forms::Label());
		this->label172 = (gcnew System::Windows::Forms::Label());
		this->label175 = (gcnew System::Windows::Forms::Label());
		this->label176 = (gcnew System::Windows::Forms::Label());
		this->comboBox_search = (gcnew System::Windows::Forms::ComboBox());
		this->textBox_unknown_61 = (gcnew System::Windows::Forms::TextBox());
		this->label191 = (gcnew System::Windows::Forms::Label());
		this->groupBox_basic_2 = (gcnew System::Windows::Forms::GroupBox());
		this->checkBox_unknown_60_01 = (gcnew System::Windows::Forms::CheckBox());
		this->label190 = (gcnew System::Windows::Forms::Label());
		this->checkBox_unknown_60 = (gcnew System::Windows::Forms::CheckBox());
		this->label189 = (gcnew System::Windows::Forms::Label());
		this->textBox_receive_quest_probability = (gcnew System::Windows::Forms::TextBox());
		this->label105 = (gcnew System::Windows::Forms::Label());
		this->textBox_unknown_59 = (gcnew System::Windows::Forms::TextBox());
		this->label104 = (gcnew System::Windows::Forms::Label());
		this->textBox_unknown_58 = (gcnew System::Windows::Forms::TextBox());
		this->label103 = (gcnew System::Windows::Forms::Label());
		this->textBox_parent_quest = (gcnew System::Windows::Forms::TextBox());
		this->textBox_sub_quest_first = (gcnew System::Windows::Forms::TextBox());
		this->label52 = (gcnew System::Windows::Forms::Label());
		this->label51 = (gcnew System::Windows::Forms::Label());
		this->textBox_previous_quest = (gcnew System::Windows::Forms::TextBox());
		this->label50 = (gcnew System::Windows::Forms::Label());
		this->label49 = (gcnew System::Windows::Forms::Label());
		this->textBox_next_quest = (gcnew System::Windows::Forms::TextBox());
		this->groupBox_pq_exit_area = (gcnew System::Windows::Forms::GroupBox());
		this->textBox_pq_required_quests_completed = (gcnew System::Windows::Forms::TextBox());
		this->label231 = (gcnew System::Windows::Forms::Label());
		this->dataGridView_pq_messages = (gcnew System::Windows::Forms::DataGridView());
		this->dataGridViewTextBoxColumn87 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->contextMenuStrip_pq_messages = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
		this->toolStripMenuItem36 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->toolStripMenuItem37 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->label188 = (gcnew System::Windows::Forms::Label());
		this->label187 = (gcnew System::Windows::Forms::Label());
		this->textBox_pq_unknown_20 = (gcnew System::Windows::Forms::TextBox());
		this->label186 = (gcnew System::Windows::Forms::Label());
		this->textBox_pq_unknown_19 = (gcnew System::Windows::Forms::TextBox());
		this->label185 = (gcnew System::Windows::Forms::Label());
		this->textBox_pq_unknown_18 = (gcnew System::Windows::Forms::TextBox());
		this->label184 = (gcnew System::Windows::Forms::Label());
		this->dataGridView_pq_special_scripts = (gcnew System::Windows::Forms::DataGridView());
		this->dataGridViewTextBoxColumn81 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn82 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn83 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn84 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn85 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn86 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->contextMenuStrip_pq_special_scripts = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
		this->toolStripMenuItem34 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->toolStripMenuItem35 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->label183 = (gcnew System::Windows::Forms::Label());
		this->label182 = (gcnew System::Windows::Forms::Label());
		this->textBox_pq_unknown_16 = (gcnew System::Windows::Forms::TextBox());
		this->textBox_pq_unknown_17 = (gcnew System::Windows::Forms::TextBox());
		this->label181 = (gcnew System::Windows::Forms::Label());
		this->textBox_pq_unknown_15 = (gcnew System::Windows::Forms::TextBox());
		this->label180 = (gcnew System::Windows::Forms::Label());
		this->textBox_pq_unknown_14 = (gcnew System::Windows::Forms::TextBox());
		this->label179 = (gcnew System::Windows::Forms::Label());
		this->textBox_pq_id_script = (gcnew System::Windows::Forms::TextBox());
		this->label178 = (gcnew System::Windows::Forms::Label());
		this->textBox_pq_unknown_13 = (gcnew System::Windows::Forms::TextBox());
		this->label177 = (gcnew System::Windows::Forms::Label());
		this->textBox_pq_unknown_12 = (gcnew System::Windows::Forms::TextBox());
		this->label173 = (gcnew System::Windows::Forms::Label());
		this->textBox_pq_unknown_11 = (gcnew System::Windows::Forms::TextBox());
		this->label174 = (gcnew System::Windows::Forms::Label());
		this->textBox_pq_unknown_10 = (gcnew System::Windows::Forms::TextBox());
		this->label169 = (gcnew System::Windows::Forms::Label());
		this->textBox_pq_unknown_9 = (gcnew System::Windows::Forms::TextBox());
		this->label170 = (gcnew System::Windows::Forms::Label());
		this->textBox_pq_unknown_8 = (gcnew System::Windows::Forms::TextBox());
		this->label171 = (gcnew System::Windows::Forms::Label());
		this->textBox_pq_unknown_7 = (gcnew System::Windows::Forms::TextBox());
		this->label168 = (gcnew System::Windows::Forms::Label());
		this->dataGridView_pq_chases = (gcnew System::Windows::Forms::DataGridView());
		this->dataGridViewTextBoxColumn72 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn73 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Column22 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn74 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->contextMenuStrip_pq_chases = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
		this->toolStripMenuItem24 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->toolStripMenuItem25 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->label167 = (gcnew System::Windows::Forms::Label());
		this->textBox_pq_unknown_6 = (gcnew System::Windows::Forms::TextBox());
		this->label166 = (gcnew System::Windows::Forms::Label());
		this->textBox_pq_unknown_5 = (gcnew System::Windows::Forms::TextBox());
		this->label164 = (gcnew System::Windows::Forms::Label());
		this->textBox_pq_unknown_4 = (gcnew System::Windows::Forms::TextBox());
		this->label75 = (gcnew System::Windows::Forms::Label());
		this->dataGridView_pq_scripts = (gcnew System::Windows::Forms::DataGridView());
		this->dataGridViewTextBoxColumn68 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn70 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn71 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Column19 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Column20 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Column21 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->contextMenuStrip_pq_script_infos = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
		this->toolStripMenuItem30 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->toolStripMenuItem31 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->textBox_pq_unknown_2 = (gcnew System::Windows::Forms::TextBox());
		this->label8 = (gcnew System::Windows::Forms::Label());
		this->textBox_pq_unknown_1 = (gcnew System::Windows::Forms::TextBox());
		this->label9 = (gcnew System::Windows::Forms::Label());
		this->label54 = (gcnew System::Windows::Forms::Label());
		this->textBox_pq_unknown_3 = (gcnew System::Windows::Forms::TextBox());
		this->label7 = (gcnew System::Windows::Forms::Label());
		this->dataGridView_pq_script_infos = (gcnew System::Windows::Forms::DataGridView());
		this->dataGridViewTextBoxColumn66 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn67 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn69 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->groupBox_pq_location = (gcnew System::Windows::Forms::GroupBox());
		this->checkBox_pq_location_has_spans = (gcnew System::Windows::Forms::CheckBox());
		this->textBox_pq_location_unknown_1 = (gcnew System::Windows::Forms::TextBox());
		this->dataGridView_pq_location_spans = (gcnew System::Windows::Forms::DataGridView());
		this->dataGridViewTextBoxColumn75 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn76 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn77 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn78 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn79 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn80 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->contextMenuStrip_pq_location = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
		this->toolStripMenuItem28 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->toolStripMenuItem29 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->textBox_pq_location_map_id = (gcnew System::Windows::Forms::TextBox());
		this->groupBox_basic_1 = (gcnew System::Windows::Forms::GroupBox());
		this->label35 = (gcnew System::Windows::Forms::Label());
		this->label128 = (gcnew System::Windows::Forms::Label());
		this->textBox_level_min = (gcnew System::Windows::Forms::TextBox());
		this->label36 = (gcnew System::Windows::Forms::Label());
		this->textBox_unknown_26_01 = (gcnew System::Windows::Forms::TextBox());
		this->textBox_level_max = (gcnew System::Windows::Forms::TextBox());
		this->checkBox_craft_skill = (gcnew System::Windows::Forms::CheckBox());
		this->label127 = (gcnew System::Windows::Forms::Label());
		this->checkBox_unknown_26 = (gcnew System::Windows::Forms::CheckBox());
		this->label126 = (gcnew System::Windows::Forms::Label());
		this->checkBox_unknown_25 = (gcnew System::Windows::Forms::CheckBox());
		this->label125 = (gcnew System::Windows::Forms::Label());
		this->checkBox_unknown_24 = (gcnew System::Windows::Forms::CheckBox());
		this->label124 = (gcnew System::Windows::Forms::Label());
		this->label33 = (gcnew System::Windows::Forms::Label());
		this->textBox_quest_npc = (gcnew System::Windows::Forms::TextBox());
		this->label34 = (gcnew System::Windows::Forms::Label());
		this->textBox_reward_npc = (gcnew System::Windows::Forms::TextBox());
		this->label123 = (gcnew System::Windows::Forms::Label());
		this->checkBox_mark_available_point = (gcnew System::Windows::Forms::CheckBox());
		this->label122 = (gcnew System::Windows::Forms::Label());
		this->checkBox_mark_available_icon = (gcnew System::Windows::Forms::CheckBox());
		this->textBox_instant_teleport_location_z = (gcnew System::Windows::Forms::TextBox());
		this->label121 = (gcnew System::Windows::Forms::Label());
		this->textBox_instant_teleport_location_alt = (gcnew System::Windows::Forms::TextBox());
		this->label120 = (gcnew System::Windows::Forms::Label());
		this->textBox_instant_teleport_location_x = (gcnew System::Windows::Forms::TextBox());
		this->label119 = (gcnew System::Windows::Forms::Label());
		this->textBox_instant_teleport_location_map_id = (gcnew System::Windows::Forms::TextBox());
		this->label118 = (gcnew System::Windows::Forms::Label());
		this->textBox_unknown_level = (gcnew System::Windows::Forms::TextBox());
		this->label117 = (gcnew System::Windows::Forms::Label());
		this->label108 = (gcnew System::Windows::Forms::Label());
		this->checkBox_unknown_23 = (gcnew System::Windows::Forms::CheckBox());
		this->checkBox_unknown_17 = (gcnew System::Windows::Forms::CheckBox());
		this->label116 = (gcnew System::Windows::Forms::Label());
		this->label109 = (gcnew System::Windows::Forms::Label());
		this->checkBox_unknown_22 = (gcnew System::Windows::Forms::CheckBox());
		this->checkBox_has_instant_teleport = (gcnew System::Windows::Forms::CheckBox());
		this->label115 = (gcnew System::Windows::Forms::Label());
		this->label110 = (gcnew System::Windows::Forms::Label());
		this->checkBox_unknown_21 = (gcnew System::Windows::Forms::CheckBox());
		this->checkBox_unknown_18 = (gcnew System::Windows::Forms::CheckBox());
		this->label114 = (gcnew System::Windows::Forms::Label());
		this->label111 = (gcnew System::Windows::Forms::Label());
		this->textBox_ai_trigger = (gcnew System::Windows::Forms::TextBox());
		this->checkBox_unknown_19 = (gcnew System::Windows::Forms::CheckBox());
		this->label113 = (gcnew System::Windows::Forms::Label());
		this->label112 = (gcnew System::Windows::Forms::Label());
		this->checkBox_unknown_20 = (gcnew System::Windows::Forms::CheckBox());
		this->groupBox_valid_location = (gcnew System::Windows::Forms::GroupBox());
		this->checkBox_valid_locations_has_spans = (gcnew System::Windows::Forms::CheckBox());
		this->textBox_valid_locations_unknown_1 = (gcnew System::Windows::Forms::TextBox());
		this->dataGridView_valid_location_spans = (gcnew System::Windows::Forms::DataGridView());
		this->dataGridViewTextBoxColumn49 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn50 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn51 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn52 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn53 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn54 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->contextMenuStrip_valid_location = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
		this->toolStripMenuItem5 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->toolStripMenuItem6 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->textBox_valid_locations_map_id = (gcnew System::Windows::Forms::TextBox());
		this->groupBox_fail_location = (gcnew System::Windows::Forms::GroupBox());
		this->checkBox_fail_locations_has_spans = (gcnew System::Windows::Forms::CheckBox());
		this->textBox_fail_locations_unknown_1 = (gcnew System::Windows::Forms::TextBox());
		this->dataGridView_fail_location_spans = (gcnew System::Windows::Forms::DataGridView());
		this->dataGridViewTextBoxColumn43 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn44 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn45 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn46 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn47 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn48 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->contextMenuStrip_fail_location = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
		this->toolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->toolStripMenuItem4 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->textBox_fail_locations_map_id = (gcnew System::Windows::Forms::TextBox());
		this->groupBox_trigger_location = (gcnew System::Windows::Forms::GroupBox());
		this->textBox_trigger_locations_unknown_1 = (gcnew System::Windows::Forms::TextBox());
		this->dataGridView_trigger_location_spans = (gcnew System::Windows::Forms::DataGridView());
		this->dataGridViewTextBoxColumn37 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn38 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn39 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn40 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn41 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn42 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->contextMenuStrip_trigger_location = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
		this->addToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->removeToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->checkBox_trigger_locations_has_spans = (gcnew System::Windows::Forms::CheckBox());
		this->textBox_trigger_locations_map_id = (gcnew System::Windows::Forms::TextBox());
		this->groupBox_flags = (gcnew System::Windows::Forms::GroupBox());
		this->textBox_player_limit = (gcnew System::Windows::Forms::TextBox());
		this->label102 = (gcnew System::Windows::Forms::Label());
		this->label101 = (gcnew System::Windows::Forms::Label());
		this->checkBox_unknown_10 = (gcnew System::Windows::Forms::CheckBox());
		this->label100 = (gcnew System::Windows::Forms::Label());
		this->checkBox_on_fail_parent_fail = (gcnew System::Windows::Forms::CheckBox());
		this->label99 = (gcnew System::Windows::Forms::Label());
		this->checkBox_fail_on_death = (gcnew System::Windows::Forms::CheckBox());
		this->label98 = (gcnew System::Windows::Forms::Label());
		this->checkBox_repeatable_after_failure = (gcnew System::Windows::Forms::CheckBox());
		this->label97 = (gcnew System::Windows::Forms::Label());
		this->checkBox_repeatable = (gcnew System::Windows::Forms::CheckBox());
		this->label96 = (gcnew System::Windows::Forms::Label());
		this->checkBox_can_give_up = (gcnew System::Windows::Forms::CheckBox());
		this->label95 = (gcnew System::Windows::Forms::Label());
		this->checkBox_on_success_parent_success = (gcnew System::Windows::Forms::CheckBox());
		this->label94 = (gcnew System::Windows::Forms::Label());
		this->checkBox_on_give_up_parent_fails = (gcnew System::Windows::Forms::CheckBox());
		this->label93 = (gcnew System::Windows::Forms::Label());
		this->checkBox_activate_next_subquest = (gcnew System::Windows::Forms::CheckBox());
		this->label92 = (gcnew System::Windows::Forms::Label());
		this->checkBox_activate_random_subquest = (gcnew System::Windows::Forms::CheckBox());
		this->label91 = (gcnew System::Windows::Forms::Label());
		this->checkBox_activate_first_subquest = (gcnew System::Windows::Forms::CheckBox());
		this->groupBox_requirements = (gcnew System::Windows::Forms::GroupBox());
		this->textBox_required_morai_pk_unknown = (gcnew System::Windows::Forms::TextBox());
		this->label236 = (gcnew System::Windows::Forms::Label());
		this->label237 = (gcnew System::Windows::Forms::Label());
		this->dataGridView_required_morai_pk = (gcnew System::Windows::Forms::DataGridView());
		this->contextMenuStrip_morai_pk = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
		this->toolStripMenuItem48 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->toolStripMenuItem49 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->label235 = (gcnew System::Windows::Forms::Label());
		this->comboBox_required_cultivation = (gcnew System::Windows::Forms::ComboBox());
		this->checkBox_unknown_42_2 = (gcnew System::Windows::Forms::CheckBox());
		this->label233 = (gcnew System::Windows::Forms::Label());
		this->checkBox_unknown_42_1 = (gcnew System::Windows::Forms::CheckBox());
		this->label232 = (gcnew System::Windows::Forms::Label());
		this->comboBox_required_force = (gcnew System::Windows::Forms::ComboBox());
		this->label230 = (gcnew System::Windows::Forms::Label());
		this->textBox_unknown_55_02_02 = (gcnew System::Windows::Forms::TextBox());
		this->label226 = (gcnew System::Windows::Forms::Label());
		this->textBox_unknown_55_06 = (gcnew System::Windows::Forms::TextBox());
		this->label227 = (gcnew System::Windows::Forms::Label());
		this->textBox_unknown_55_05 = (gcnew System::Windows::Forms::TextBox());
		this->label228 = (gcnew System::Windows::Forms::Label());
		this->textBox_unknown_55_04 = (gcnew System::Windows::Forms::TextBox());
		this->label229 = (gcnew System::Windows::Forms::Label());
		this->textBox_required_influence_fee = (gcnew System::Windows::Forms::TextBox());
		this->label224 = (gcnew System::Windows::Forms::Label());
		this->textBox_unknown_55_03 = (gcnew System::Windows::Forms::TextBox());
		this->label225 = (gcnew System::Windows::Forms::Label());
		this->textBox_required_prestige = (gcnew System::Windows::Forms::TextBox());
		this->label223 = (gcnew System::Windows::Forms::Label());
		this->label222 = (gcnew System::Windows::Forms::Label());
		this->label74 = (gcnew System::Windows::Forms::Label());
		this->dataGridView_team_members = (gcnew System::Windows::Forms::DataGridView());
		this->dataGridViewTextBoxColumn8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn9 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn10 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn11 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn12 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn13 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn14 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn15 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Column18 = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
		this->contextMenuStrip_team_members = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
		this->toolStripMenuItem13 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->toolStripMenuItem14 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->label68 = (gcnew System::Windows::Forms::Label());
		this->dataGridView_given_items = (gcnew System::Windows::Forms::DataGridView());
		this->dataGridViewTextBoxColumn24 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn25 = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
		this->dataGridViewTextBoxColumn26 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn27 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->contextMenuStrip_given_items = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
		this->toolStripMenuItem9 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->toolStripMenuItem10 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->label69 = (gcnew System::Windows::Forms::Label());
		this->dataGridView_required_items = (gcnew System::Windows::Forms::DataGridView());
		this->dataGridViewTextBoxColumn4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn5 = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
		this->dataGridViewTextBoxColumn6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->contextMenuStrip_required_items = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
		this->toolStripMenuItem7 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->toolStripMenuItem8 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->textBox_unknown_57_01 = (gcnew System::Windows::Forms::TextBox());
		this->label165 = (gcnew System::Windows::Forms::Label());
		this->textBox_unknown_57 = (gcnew System::Windows::Forms::TextBox());
		this->label162 = (gcnew System::Windows::Forms::Label());
		this->textBox_unknown_56 = (gcnew System::Windows::Forms::TextBox());
		this->label163 = (gcnew System::Windows::Forms::Label());
		this->label27 = (gcnew System::Windows::Forms::Label());
		this->textBox_required_wait_time = (gcnew System::Windows::Forms::TextBox());
		this->textBox_required_coins = (gcnew System::Windows::Forms::TextBox());
		this->label39 = (gcnew System::Windows::Forms::Label());
		this->textBox_required_get_items_unknown = (gcnew System::Windows::Forms::TextBox());
		this->label67 = (gcnew System::Windows::Forms::Label());
		this->label2 = (gcnew System::Windows::Forms::Label());
		this->dataGridView_required_get_items = (gcnew System::Windows::Forms::DataGridView());
		this->dataGridViewTextBoxColumn16 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn17 = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
		this->dataGridViewTextBoxColumn18 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn19 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Column17 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->contextMenuStrip_required_get_items = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
		this->toolStripMenuItem11 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->toolStripMenuItem12 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->textBox_required_chases_unknown = (gcnew System::Windows::Forms::TextBox());
		this->label66 = (gcnew System::Windows::Forms::Label());
		this->label1 = (gcnew System::Windows::Forms::Label());
		this->dataGridView_required_chases = (gcnew System::Windows::Forms::DataGridView());
		this->dataGridViewTextBoxColumn20 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn21 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn22 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn23 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Column14 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Column15 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Column16 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->contextMenuStrip_chases = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
		this->toolStripMenuItem26 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->toolStripMenuItem27 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->textBox_required_npc_type = (gcnew System::Windows::Forms::TextBox());
		this->label161 = (gcnew System::Windows::Forms::Label());
		this->textBox_required_success_type = (gcnew System::Windows::Forms::TextBox());
		this->label160 = (gcnew System::Windows::Forms::Label());
		this->textBox_unknown_55_02_01 = (gcnew System::Windows::Forms::TextBox());
		this->label159 = (gcnew System::Windows::Forms::Label());
		this->textBox_unknown_55 = (gcnew System::Windows::Forms::TextBox());
		this->label158 = (gcnew System::Windows::Forms::Label());
		this->textBox_required_pq_contribution = (gcnew System::Windows::Forms::TextBox());
		this->label157 = (gcnew System::Windows::Forms::Label());
		this->textBox_unknown_54 = (gcnew System::Windows::Forms::TextBox());
		this->label156 = (gcnew System::Windows::Forms::Label());
		this->textBox_unknown_53 = (gcnew System::Windows::Forms::TextBox());
		this->label155 = (gcnew System::Windows::Forms::Label());
		this->textBox_resource_pq_audit_id = (gcnew System::Windows::Forms::TextBox());
		this->label154 = (gcnew System::Windows::Forms::Label());
		this->textBox_unknown_52 = (gcnew System::Windows::Forms::TextBox());
		this->label153 = (gcnew System::Windows::Forms::Label());
		this->checkBox_unknown_51 = (gcnew System::Windows::Forms::CheckBox());
		this->label152 = (gcnew System::Windows::Forms::Label());
		this->textBox_unknown_50 = (gcnew System::Windows::Forms::TextBox());
		this->label151 = (gcnew System::Windows::Forms::Label());
		this->textBox_unknown_49 = (gcnew System::Windows::Forms::TextBox());
		this->label150 = (gcnew System::Windows::Forms::Label());
		this->textBox_unknown_48 = (gcnew System::Windows::Forms::TextBox());
		this->label149 = (gcnew System::Windows::Forms::Label());
		this->textBox_required_apothecary_level = (gcnew System::Windows::Forms::TextBox());
		this->label80 = (gcnew System::Windows::Forms::Label());
		this->textBox_required_craftsman_level = (gcnew System::Windows::Forms::TextBox());
		this->label79 = (gcnew System::Windows::Forms::Label());
		this->textBox_required_tailor_level = (gcnew System::Windows::Forms::TextBox());
		this->label78 = (gcnew System::Windows::Forms::Label());
		this->textBox_required_blacksmith_level = (gcnew System::Windows::Forms::TextBox());
		this->label77 = (gcnew System::Windows::Forms::Label());
		this->textBox_required_quests_undone_1 = (gcnew System::Windows::Forms::TextBox());
		this->textBox_unknown_47 = (gcnew System::Windows::Forms::TextBox());
		this->textBox_required_quests_undone_2 = (gcnew System::Windows::Forms::TextBox());
		this->label148 = (gcnew System::Windows::Forms::Label());
		this->textBox_required_quests_undone_3 = (gcnew System::Windows::Forms::TextBox());
		this->checkBox_unknown_46 = (gcnew System::Windows::Forms::CheckBox());
		this->textBox_required_quests_undone_5 = (gcnew System::Windows::Forms::TextBox());
		this->textBox_required_quests_undone_4 = (gcnew System::Windows::Forms::TextBox());
		this->label147 = (gcnew System::Windows::Forms::Label());
		this->textBox_unknown_45 = (gcnew System::Windows::Forms::TextBox());
		this->label146 = (gcnew System::Windows::Forms::Label());
		this->dataGridView_date_unknown = (gcnew System::Windows::Forms::DataGridView());
		this->dataGridViewTextBoxColumn55 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn56 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn57 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn58 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn59 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Column_date_unknown_weekday = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
		this->label145 = (gcnew System::Windows::Forms::Label());
		this->textBox_unknown_44 = (gcnew System::Windows::Forms::TextBox());
		this->label144 = (gcnew System::Windows::Forms::Label());
		this->checkBox_occupation_seeker = (gcnew System::Windows::Forms::CheckBox());
		this->checkBox_occupation_mystic = (gcnew System::Windows::Forms::CheckBox());
		this->checkBox_occupation_cleric = (gcnew System::Windows::Forms::CheckBox());
		this->checkBox_occupation_archer = (gcnew System::Windows::Forms::CheckBox());
		this->checkBox_occupation_psychic = (gcnew System::Windows::Forms::CheckBox());
		this->checkBox_occupation_barbarian = (gcnew System::Windows::Forms::CheckBox());
		this->checkBox_occupation_venomancer = (gcnew System::Windows::Forms::CheckBox());
		this->checkBox_occupation_assassin = (gcnew System::Windows::Forms::CheckBox());
		this->checkBox_occupation_wizard = (gcnew System::Windows::Forms::CheckBox());
		this->checkBox_occupation_blademaster = (gcnew System::Windows::Forms::CheckBox());
		this->checkBox_unknown_43 = (gcnew System::Windows::Forms::CheckBox());
		this->label143 = (gcnew System::Windows::Forms::Label());
		this->checkBox_required_be_gm = (gcnew System::Windows::Forms::CheckBox());
		this->label142 = (gcnew System::Windows::Forms::Label());
		this->checkBox_unknown_42 = (gcnew System::Windows::Forms::CheckBox());
		this->label141 = (gcnew System::Windows::Forms::Label());
		this->checkBox_required_be_married = (gcnew System::Windows::Forms::CheckBox());
		this->label140 = (gcnew System::Windows::Forms::Label());
		this->checkBox_unknown_41 = (gcnew System::Windows::Forms::CheckBox());
		this->label139 = (gcnew System::Windows::Forms::Label());
		this->checkBox_unknown_40 = (gcnew System::Windows::Forms::CheckBox());
		this->label30 = (gcnew System::Windows::Forms::Label());
		this->comboBox_required_gender = (gcnew System::Windows::Forms::ComboBox());
		this->label58 = (gcnew System::Windows::Forms::Label());
		this->checkBox_unknown_39 = (gcnew System::Windows::Forms::CheckBox());
		this->label138 = (gcnew System::Windows::Forms::Label());
		this->textBox_unknown_38 = (gcnew System::Windows::Forms::TextBox());
		this->label137 = (gcnew System::Windows::Forms::Label());
		this->textBox_unknown_37 = (gcnew System::Windows::Forms::TextBox());
		this->label136 = (gcnew System::Windows::Forms::Label());
		this->textBox_unknown_36 = (gcnew System::Windows::Forms::TextBox());
		this->label135 = (gcnew System::Windows::Forms::Label());
		this->checkBox_unknown_35 = (gcnew System::Windows::Forms::CheckBox());
		this->label133 = (gcnew System::Windows::Forms::Label());
		this->textBox_unknown_34 = (gcnew System::Windows::Forms::TextBox());
		this->label134 = (gcnew System::Windows::Forms::Label());
		this->textBox_required_quests_done_1 = (gcnew System::Windows::Forms::TextBox());
		this->textBox_required_quests_done_2 = (gcnew System::Windows::Forms::TextBox());
		this->textBox_required_quests_done_3 = (gcnew System::Windows::Forms::TextBox());
		this->textBox_required_quests_done_4 = (gcnew System::Windows::Forms::TextBox());
		this->textBox_required_quests_done_5 = (gcnew System::Windows::Forms::TextBox());
		this->checkBox_unknown_33 = (gcnew System::Windows::Forms::CheckBox());
		this->label132 = (gcnew System::Windows::Forms::Label());
		this->textBox_unknown_32 = (gcnew System::Windows::Forms::TextBox());
		this->label131 = (gcnew System::Windows::Forms::Label());
		this->textBox_required_reputation = (gcnew System::Windows::Forms::TextBox());
		this->label38 = (gcnew System::Windows::Forms::Label());
		this->checkBox_unknown_31 = (gcnew System::Windows::Forms::CheckBox());
		this->label130 = (gcnew System::Windows::Forms::Label());
		this->textBox_given_items_unknown = (gcnew System::Windows::Forms::TextBox());
		this->label129 = (gcnew System::Windows::Forms::Label());
		this->textBox_unknown_30 = (gcnew System::Windows::Forms::TextBox());
		this->label73 = (gcnew System::Windows::Forms::Label());
		this->textBox_unknown_29 = (gcnew System::Windows::Forms::TextBox());
		this->label72 = (gcnew System::Windows::Forms::Label());
		this->checkBox_unknown_28_01 = (gcnew System::Windows::Forms::CheckBox());
		this->label71 = (gcnew System::Windows::Forms::Label());
		this->textBox_required_items_unknown = (gcnew System::Windows::Forms::TextBox());
		this->label70 = (gcnew System::Windows::Forms::Label());
		this->checkBox_unknown_28 = (gcnew System::Windows::Forms::CheckBox());
		this->checkBox_unknown_27 = (gcnew System::Windows::Forms::CheckBox());
		this->label64 = (gcnew System::Windows::Forms::Label());
		this->label62 = (gcnew System::Windows::Forms::Label());
		this->textBox_instant_pay_coins = (gcnew System::Windows::Forms::TextBox());
		this->label65 = (gcnew System::Windows::Forms::Label());
		this->groupBox_general = (gcnew System::Windows::Forms::GroupBox());
		this->textBox_unknown_09 = (gcnew System::Windows::Forms::TextBox());
		this->label90 = (gcnew System::Windows::Forms::Label());
		this->textBox_unknown_08 = (gcnew System::Windows::Forms::TextBox());
		this->label89 = (gcnew System::Windows::Forms::Label());
		this->dataGridView_date_fail = (gcnew System::Windows::Forms::DataGridView());
		this->dataGridViewTextBoxColumn32 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn33 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn34 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn35 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn36 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Column_date_fail_weekday = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
		this->label88 = (gcnew System::Windows::Forms::Label());
		this->label87 = (gcnew System::Windows::Forms::Label());
		this->label86 = (gcnew System::Windows::Forms::Label());
		this->label83 = (gcnew System::Windows::Forms::Label());
		this->label82 = (gcnew System::Windows::Forms::Label());
		this->checkBox_unknown_03 = (gcnew System::Windows::Forms::CheckBox());
		this->checkBox_unknown_02 = (gcnew System::Windows::Forms::CheckBox());
		this->textBox_unknown_06 = (gcnew System::Windows::Forms::TextBox());
		this->label85 = (gcnew System::Windows::Forms::Label());
		this->textBox_unknown_05 = (gcnew System::Windows::Forms::TextBox());
		this->label84 = (gcnew System::Windows::Forms::Label());
		this->textBox_unknown_04 = (gcnew System::Windows::Forms::TextBox());
		this->label31 = (gcnew System::Windows::Forms::Label());
		this->checkBox_has_date_spans = (gcnew System::Windows::Forms::CheckBox());
		this->checkBox_has_date_fail = (gcnew System::Windows::Forms::CheckBox());
		this->textBox_unknown_01 = (gcnew System::Windows::Forms::TextBox());
		this->label81 = (gcnew System::Windows::Forms::Label());
		this->groupBox_reach_location = (gcnew System::Windows::Forms::GroupBox());
		this->checkBox_reach_locations_has_spans = (gcnew System::Windows::Forms::CheckBox());
		this->textBox_reach_locations_unknown_1 = (gcnew System::Windows::Forms::TextBox());
		this->dataGridView_reach_location_spans = (gcnew System::Windows::Forms::DataGridView());
		this->dataGridViewTextBoxColumn60 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn61 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn62 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn63 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn64 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn65 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->contextMenuStrip_reach_location = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
		this->toolStripMenuItem15 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->toolStripMenuItem16 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->textBox_reach_locations_map_id = (gcnew System::Windows::Forms::TextBox());
		this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
		this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
		this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
		this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
		this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
		this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
		this->tabPage6 = (gcnew System::Windows::Forms::TabPage());
		this->groupBox_reward_pq = (gcnew System::Windows::Forms::GroupBox());
		this->label221 = (gcnew System::Windows::Forms::Label());
		this->dataGridView_reward_pq_specials = (gcnew System::Windows::Forms::DataGridView());
		this->dataGridViewTextBoxColumn97 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn98 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn100 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->contextMenuStrip_reward_pq_specials = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
		this->toolStripMenuItem42 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->toolStripMenuItem43 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->label220 = (gcnew System::Windows::Forms::Label());
		this->dataGridView_reward_pq_items = (gcnew System::Windows::Forms::DataGridView());
		this->Column24 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Column25 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Column26 = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
		this->dataGridViewTextBoxColumn94 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn95 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn96 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->contextMenuStrip_reward_pq_items = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
		this->toolStripMenuItem22 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->toolStripMenuItem23 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->label219 = (gcnew System::Windows::Forms::Label());
		this->dataGridView_reward_pq_chases = (gcnew System::Windows::Forms::DataGridView());
		this->dataGridViewTextBoxColumn90 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn91 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn92 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn93 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->contextMenuStrip_reward_pq_chases = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
		this->toolStripMenuItem20 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->toolStripMenuItem21 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->dataGridView_reward_pq_messages = (gcnew System::Windows::Forms::DataGridView());
		this->dataGridViewTextBoxColumn89 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->contextMenuStrip_reward_pq_messages = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
		this->toolStripMenuItem44 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->toolStripMenuItem45 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->label218 = (gcnew System::Windows::Forms::Label());
		this->dataGridView_reward_pq_scripts = (gcnew System::Windows::Forms::DataGridView());
		this->dataGridViewTextBoxColumn88 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->contextMenuStrip_reward_pq_scripts = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
		this->toolStripMenuItem40 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->toolStripMenuItem41 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->label217 = (gcnew System::Windows::Forms::Label());
		this->textBox_reward_pq_unknown_7 = (gcnew System::Windows::Forms::TextBox());
		this->label216 = (gcnew System::Windows::Forms::Label());
		this->textBox_reward_pq_unknown_6 = (gcnew System::Windows::Forms::TextBox());
		this->label215 = (gcnew System::Windows::Forms::Label());
		this->textBox_reward_pq_unknown_5 = (gcnew System::Windows::Forms::TextBox());
		this->label214 = (gcnew System::Windows::Forms::Label());
		this->textBox_reward_pq_unknown_4 = (gcnew System::Windows::Forms::TextBox());
		this->label213 = (gcnew System::Windows::Forms::Label());
		this->textBox_reward_pq_unknown_3 = (gcnew System::Windows::Forms::TextBox());
		this->label212 = (gcnew System::Windows::Forms::Label());
		this->textBox_reward_pq_contribution_required = (gcnew System::Windows::Forms::TextBox());
		this->label211 = (gcnew System::Windows::Forms::Label());
		this->textBox_reward_pq_contribution_random_max = (gcnew System::Windows::Forms::TextBox());
		this->label210 = (gcnew System::Windows::Forms::Label());
		this->textBox_reward_pq_contribution_random_min = (gcnew System::Windows::Forms::TextBox());
		this->label209 = (gcnew System::Windows::Forms::Label());
		this->textBox_reward_pq_unknown_level = (gcnew System::Windows::Forms::TextBox());
		this->label208 = (gcnew System::Windows::Forms::Label());
		this->textBox_reward_pq_unknown_2 = (gcnew System::Windows::Forms::TextBox());
		this->label207 = (gcnew System::Windows::Forms::Label());
		this->textBox_reward_pq_unknown_quest = (gcnew System::Windows::Forms::TextBox());
		this->label206 = (gcnew System::Windows::Forms::Label());
		this->textBox_reward_pq_unknown_1 = (gcnew System::Windows::Forms::TextBox());
		this->label205 = (gcnew System::Windows::Forms::Label());
		this->textBox_reward_pq_event_gold = (gcnew System::Windows::Forms::TextBox());
		this->label204 = (gcnew System::Windows::Forms::Label());
		this->textBox_reward_pq_unknown_0 = (gcnew System::Windows::Forms::TextBox());
		this->label59 = (gcnew System::Windows::Forms::Label());
		this->groupBox_reward_items = (gcnew System::Windows::Forms::GroupBox());
		this->checkedListBox_reward_item_groups_flag = (gcnew System::Windows::Forms::CheckedListBox());
		this->tabPage7 = (gcnew System::Windows::Forms::TabPage());
		this->contextMenuStrip_pq_scripts = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
		this->toolStripMenuItem32 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->toolStripMenuItem33 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->dataGridViewTextBoxColumn99 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn101 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn102 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn103 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn104 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->DataGridViewTextBoxColumn281 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn106 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn107 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Column27 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Column28 = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
		this->menuStrip_mainMenu->SuspendLayout();
		this->contextMenuStrip_date_spans->SuspendLayout();
		this->contextMenuStrip_task->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_date_spans))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_reward_item_group_items))->BeginInit();
		this->contextMenuStrip_reward_items->SuspendLayout();
		this->groupBox_reward_selector->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown_time_factor))->BeginInit();
		this->contextMenuStrip_reward_timed->SuspendLayout();
		this->groupBox_reward->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown_reward_item_groups_count))->BeginInit();
		this->groupBox_conversation->SuspendLayout();
		this->groupBox_answers->SuspendLayout();
		this->contextMenuStrip_conversation_answer->SuspendLayout();
		this->contextMenuStrip_conversation_question->SuspendLayout();
		this->groupBox_questions->SuspendLayout();
		this->groupBox_dialogs->SuspendLayout();
		this->groupBox_basic_2->SuspendLayout();
		this->groupBox_pq_exit_area->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_pq_messages))->BeginInit();
		this->contextMenuStrip_pq_messages->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_pq_special_scripts))->BeginInit();
		this->contextMenuStrip_pq_special_scripts->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_pq_chases))->BeginInit();
		this->contextMenuStrip_pq_chases->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_pq_scripts))->BeginInit();
		this->contextMenuStrip_pq_script_infos->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_pq_script_infos))->BeginInit();
		this->groupBox_pq_location->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_pq_location_spans))->BeginInit();
		this->contextMenuStrip_pq_location->SuspendLayout();
		this->groupBox_basic_1->SuspendLayout();
		this->groupBox_valid_location->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_valid_location_spans))->BeginInit();
		this->contextMenuStrip_valid_location->SuspendLayout();
		this->groupBox_fail_location->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_fail_location_spans))->BeginInit();
		this->contextMenuStrip_fail_location->SuspendLayout();
		this->groupBox_trigger_location->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_trigger_location_spans))->BeginInit();
		this->contextMenuStrip_trigger_location->SuspendLayout();
		this->groupBox_flags->SuspendLayout();
		this->groupBox_requirements->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_required_morai_pk))->BeginInit();
		this->contextMenuStrip_morai_pk->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_team_members))->BeginInit();
		this->contextMenuStrip_team_members->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_given_items))->BeginInit();
		this->contextMenuStrip_given_items->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_required_items))->BeginInit();
		this->contextMenuStrip_required_items->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_required_get_items))->BeginInit();
		this->contextMenuStrip_required_get_items->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_required_chases))->BeginInit();
		this->contextMenuStrip_chases->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_date_unknown))->BeginInit();
		this->groupBox_general->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_date_fail))->BeginInit();
		this->groupBox_reach_location->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_reach_location_spans))->BeginInit();
		this->contextMenuStrip_reach_location->SuspendLayout();
		this->tabControl1->SuspendLayout();
		this->tabPage1->SuspendLayout();
		this->tabPage2->SuspendLayout();
		this->tabPage3->SuspendLayout();
		this->tabPage4->SuspendLayout();
		this->tabPage5->SuspendLayout();
		this->tabPage6->SuspendLayout();
		this->groupBox_reward_pq->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_reward_pq_specials))->BeginInit();
		this->contextMenuStrip_reward_pq_specials->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_reward_pq_items))->BeginInit();
		this->contextMenuStrip_reward_pq_items->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_reward_pq_chases))->BeginInit();
		this->contextMenuStrip_reward_pq_chases->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_reward_pq_messages))->BeginInit();
		this->contextMenuStrip_reward_pq_messages->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_reward_pq_scripts))->BeginInit();
		this->contextMenuStrip_reward_pq_scripts->SuspendLayout();
		this->groupBox_reward_items->SuspendLayout();
		this->tabPage7->SuspendLayout();
		this->contextMenuStrip_pq_scripts->SuspendLayout();
		this->SuspendLayout();
		// 
		// menuStrip_mainMenu
		// 
		this->menuStrip_mainMenu->BackColor = System::Drawing::SystemColors::Control;
		this->menuStrip_mainMenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->toolStripMenuItem1, 
			this->toolStripMenuItem2, this->developerToolStripMenuItem});
		this->menuStrip_mainMenu->Location = System::Drawing::Point(0, 0);
		this->menuStrip_mainMenu->Name = L"menuStrip_mainMenu";
		this->menuStrip_mainMenu->Padding = System::Windows::Forms::Padding(0, 2, 2, 2);
		this->menuStrip_mainMenu->RenderMode = System::Windows::Forms::ToolStripRenderMode::System;
		this->menuStrip_mainMenu->Size = System::Drawing::Size(912, 24);
		this->menuStrip_mainMenu->TabIndex = 0;
		this->menuStrip_mainMenu->Text = L"menuStrip1";
		// 
		// toolStripMenuItem1
		// 
		this->toolStripMenuItem1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
		this->toolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->loadToolStripMenuItem, 
			this->exportToolStripMenuItem});
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
		this->loadToolStripMenuItem->Size = System::Drawing::Size(109, 22);
		this->loadToolStripMenuItem->Text = L"Load...";
		this->loadToolStripMenuItem->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
		this->loadToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::click_load);
		// 
		// exportToolStripMenuItem
		// 
		this->exportToolStripMenuItem->Name = L"exportToolStripMenuItem";
		this->exportToolStripMenuItem->Size = System::Drawing::Size(109, 22);
		this->exportToolStripMenuItem->Text = L"Export";
		// 
		// toolStripMenuItem2
		// 
		this->toolStripMenuItem2->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
		this->toolStripMenuItem2->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->taskSplitToolStripMenuItem, 
			this->creatureBuilderListToolStripMenuItem});
		this->toolStripMenuItem2->ImageScaling = System::Windows::Forms::ToolStripItemImageScaling::None;
		this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
		this->toolStripMenuItem2->Padding = System::Windows::Forms::Padding(0);
		this->toolStripMenuItem2->Size = System::Drawing::Size(36, 20);
		this->toolStripMenuItem2->Text = L"Tools";
		this->toolStripMenuItem2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
		// 
		// taskSplitToolStripMenuItem
		// 
		this->taskSplitToolStripMenuItem->Name = L"taskSplitToolStripMenuItem";
		this->taskSplitToolStripMenuItem->Size = System::Drawing::Size(183, 22);
		this->taskSplitToolStripMenuItem->Text = L"Task Split...";
		this->taskSplitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::click_split);
		// 
		// creatureBuilderListToolStripMenuItem
		// 
		this->creatureBuilderListToolStripMenuItem->Name = L"creatureBuilderListToolStripMenuItem";
		this->creatureBuilderListToolStripMenuItem->Size = System::Drawing::Size(183, 22);
		this->creatureBuilderListToolStripMenuItem->Text = L"Creature Builder List...";
		this->creatureBuilderListToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::click_creatureBuilder);
		// 
		// developerToolStripMenuItem
		// 
		this->developerToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->changeConfirmationToolStripMenuItem, 
			this->developerSearchToolStripMenuItem});
		this->developerToolStripMenuItem->Name = L"developerToolStripMenuItem";
		this->developerToolStripMenuItem->Size = System::Drawing::Size(68, 20);
		this->developerToolStripMenuItem->Text = L"Developer";
		// 
		// changeConfirmationToolStripMenuItem
		// 
		this->changeConfirmationToolStripMenuItem->CheckOnClick = true;
		this->changeConfirmationToolStripMenuItem->Name = L"changeConfirmationToolStripMenuItem";
		this->changeConfirmationToolStripMenuItem->Size = System::Drawing::Size(175, 22);
		this->changeConfirmationToolStripMenuItem->Text = L"Change Confirmation";
		// 
		// developerSearchToolStripMenuItem
		// 
		this->developerSearchToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->toolStripComboBox_developer_search, 
			this->toolStripSeparator2, this->toolStripMenuItem17});
		this->developerSearchToolStripMenuItem->Name = L"developerSearchToolStripMenuItem";
		this->developerSearchToolStripMenuItem->Size = System::Drawing::Size(175, 22);
		this->developerSearchToolStripMenuItem->Text = L"Search !NULL Fields";
		// 
		// toolStripComboBox_developer_search
		// 
		this->toolStripComboBox_developer_search->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
		this->toolStripComboBox_developer_search->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->toolStripComboBox_developer_search->Items->AddRange(gcnew cli::array< System::Object^  >(12) {L"Required be GM", L"UNKNOWN_43", 
			L"Prestige", L"Influence", L"Event Gold", L"Reward PQ Chases", L"Reward PQ Items", L"Reward PQ Scripts", L"Reward PQ Messages", 
			L"Reward Unknown 5", L"Reward Unknown 6", L"Reward Timed"});
		this->toolStripComboBox_developer_search->Name = L"toolStripComboBox_developer_search";
		this->toolStripComboBox_developer_search->Size = System::Drawing::Size(121, 21);
		// 
		// toolStripSeparator2
		// 
		this->toolStripSeparator2->Name = L"toolStripSeparator2";
		this->toolStripSeparator2->Size = System::Drawing::Size(178, 6);
		// 
		// toolStripMenuItem17
		// 
		this->toolStripMenuItem17->Name = L"toolStripMenuItem17";
		this->toolStripMenuItem17->Size = System::Drawing::Size(181, 22);
		this->toolStripMenuItem17->Text = L"Start Search";
		this->toolStripMenuItem17->Click += gcnew System::EventHandler(this, &MainWindow::click_developer_search);
		// 
		// contextMenuStrip_date_spans
		// 
		this->contextMenuStrip_date_spans->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->addRowToolStripMenuItem, 
			this->deleteRowToolStripMenuItem});
		this->contextMenuStrip_date_spans->Name = L"contextMenuStrip_dataGrid";
		this->contextMenuStrip_date_spans->RenderMode = System::Windows::Forms::ToolStripRenderMode::System;
		this->contextMenuStrip_date_spans->ShowImageMargin = false;
		this->contextMenuStrip_date_spans->Size = System::Drawing::Size(134, 48);
		// 
		// addRowToolStripMenuItem
		// 
		this->addRowToolStripMenuItem->Name = L"addRowToolStripMenuItem";
		this->addRowToolStripMenuItem->Size = System::Drawing::Size(133, 22);
		this->addRowToolStripMenuItem->Text = L"Add Date Span";
		this->addRowToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::add_date_span);
		// 
		// deleteRowToolStripMenuItem
		// 
		this->deleteRowToolStripMenuItem->Name = L"deleteRowToolStripMenuItem";
		this->deleteRowToolStripMenuItem->Size = System::Drawing::Size(133, 22);
		this->deleteRowToolStripMenuItem->Text = L"Delete Date Span";
		this->deleteRowToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::remove_date_span);
		// 
		// progressBar_progress
		// 
		this->progressBar_progress->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->progressBar_progress->Location = System::Drawing::Point(0, 636);
		this->progressBar_progress->Name = L"progressBar_progress";
		this->progressBar_progress->Size = System::Drawing::Size(912, 16);
		this->progressBar_progress->TabIndex = 7;
		// 
		// textBox_search
		// 
		this->textBox_search->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
		this->textBox_search->Location = System::Drawing::Point(0, 583);
		this->textBox_search->Name = L"textBox_search";
		this->textBox_search->Size = System::Drawing::Size(222, 20);
		this->textBox_search->TabIndex = 2;
		this->textBox_search->Text = L"ID or NAME";
		this->textBox_search->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->textBox_search->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainWindow::keyPress_search);
		// 
		// button_search
		// 
		this->button_search->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
		this->button_search->Location = System::Drawing::Point(143, 609);
		this->button_search->Name = L"button_search";
		this->button_search->Size = System::Drawing::Size(79, 21);
		this->button_search->TabIndex = 4;
		this->button_search->Text = L"Find Next";
		this->button_search->UseVisualStyleBackColor = true;
		this->button_search->Click += gcnew System::EventHandler(this, &MainWindow::click_search);
		// 
		// treeView_tasks
		// 
		this->treeView_tasks->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
			| System::Windows::Forms::AnchorStyles::Left));
		this->treeView_tasks->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(32)), 
			static_cast<System::Int32>(static_cast<System::Byte>(32)));
		this->treeView_tasks->ContextMenuStrip = this->contextMenuStrip_task;
		this->treeView_tasks->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(0)));
		this->treeView_tasks->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)), 
			static_cast<System::Int32>(static_cast<System::Byte>(64)));
		this->treeView_tasks->HideSelection = false;
		this->treeView_tasks->Indent = 16;
		this->treeView_tasks->LineColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)), 
			static_cast<System::Int32>(static_cast<System::Byte>(64)));
		this->treeView_tasks->Location = System::Drawing::Point(0, 27);
		this->treeView_tasks->Name = L"treeView_tasks";
		this->treeView_tasks->ShowLines = false;
		this->treeView_tasks->Size = System::Drawing::Size(222, 550);
		this->treeView_tasks->TabIndex = 1;
		this->treeView_tasks->AfterSelect += gcnew System::Windows::Forms::TreeViewEventHandler(this, &MainWindow::select_task);
		// 
		// contextMenuStrip_task
		// 
		this->contextMenuStrip_task->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {this->cloneSelectedToolStripMenuItem, 
			this->deleteSelectedToolStripMenuItem, this->toolStripSeparator1, this->exportSelectedItemToolStripMenuItem, this->replaceSelectedItemToolStripMenuItem});
		this->contextMenuStrip_task->Name = L"contextMenuStrip_task";
		this->contextMenuStrip_task->RenderMode = System::Windows::Forms::ToolStripRenderMode::System;
		this->contextMenuStrip_task->ShowImageMargin = false;
		this->contextMenuStrip_task->Size = System::Drawing::Size(163, 98);
		// 
		// cloneSelectedToolStripMenuItem
		// 
		this->cloneSelectedToolStripMenuItem->Name = L"cloneSelectedToolStripMenuItem";
		this->cloneSelectedToolStripMenuItem->Size = System::Drawing::Size(162, 22);
		this->cloneSelectedToolStripMenuItem->Text = L"Clone Selected";
		this->cloneSelectedToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::click_cloneTask);
		// 
		// deleteSelectedToolStripMenuItem
		// 
		this->deleteSelectedToolStripMenuItem->Name = L"deleteSelectedToolStripMenuItem";
		this->deleteSelectedToolStripMenuItem->Size = System::Drawing::Size(162, 22);
		this->deleteSelectedToolStripMenuItem->Text = L"Delete Selected";
		this->deleteSelectedToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::click_deleteTask);
		// 
		// toolStripSeparator1
		// 
		this->toolStripSeparator1->Name = L"toolStripSeparator1";
		this->toolStripSeparator1->Size = System::Drawing::Size(159, 6);
		// 
		// exportSelectedItemToolStripMenuItem
		// 
		this->exportSelectedItemToolStripMenuItem->Name = L"exportSelectedItemToolStripMenuItem";
		this->exportSelectedItemToolStripMenuItem->Size = System::Drawing::Size(162, 22);
		this->exportSelectedItemToolStripMenuItem->Text = L"Export Selected Task...";
		this->exportSelectedItemToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::click_ExportTask);
		// 
		// replaceSelectedItemToolStripMenuItem
		// 
		this->replaceSelectedItemToolStripMenuItem->Name = L"replaceSelectedItemToolStripMenuItem";
		this->replaceSelectedItemToolStripMenuItem->Size = System::Drawing::Size(162, 22);
		this->replaceSelectedItemToolStripMenuItem->Text = L"Import New Task...";
		this->replaceSelectedItemToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::click_ImportTask);
		// 
		// comboBox_type
		// 
		this->comboBox_type->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
		this->comboBox_type->FormattingEnabled = true;
		this->comboBox_type->Items->AddRange(gcnew cli::array< System::Object^  >(13) {L"[0] Normal", L"[1] Cycle", L"[2] Spiritual Cultivation", 
			L"[3] Hero", L"[4] Challenge", L"[5] Adventure", L"[6] Errand", L"[7] Legendary", L"[8] Battle", L"[9] Public", L"[10] Divine Order\?", 
			L"[11] Guild Base\?", L"[12] \?"});
		this->comboBox_type->Location = System::Drawing::Point(256, 18);
		this->comboBox_type->Name = L"comboBox_type";
		this->comboBox_type->Size = System::Drawing::Size(115, 21);
		this->comboBox_type->TabIndex = 3;
		this->comboBox_type->SelectedIndexChanged += gcnew System::EventHandler(this, &MainWindow::change_type);
		// 
		// label55
		// 
		this->label55->AutoSize = true;
		this->label55->Location = System::Drawing::Point(216, 22);
		this->label55->Name = L"label55";
		this->label55->Size = System::Drawing::Size(34, 13);
		this->label55->TabIndex = 2;
		this->label55->Text = L"Type:";
		// 
		// checkBox_author_mode
		// 
		this->checkBox_author_mode->AutoSize = true;
		this->checkBox_author_mode->Enabled = false;
		this->checkBox_author_mode->Location = System::Drawing::Point(95, 74);
		this->checkBox_author_mode->Name = L"checkBox_author_mode";
		this->checkBox_author_mode->RightToLeft = System::Windows::Forms::RightToLeft::No;
		this->checkBox_author_mode->Size = System::Drawing::Size(15, 14);
		this->checkBox_author_mode->TabIndex = 8;
		this->checkBox_author_mode->UseVisualStyleBackColor = true;
		// 
		// textBox_time_limit
		// 
		this->textBox_time_limit->Location = System::Drawing::Point(466, 19);
		this->textBox_time_limit->Name = L"textBox_time_limit";
		this->textBox_time_limit->Size = System::Drawing::Size(115, 20);
		this->textBox_time_limit->TabIndex = 10;
		this->textBox_time_limit->Leave += gcnew System::EventHandler(this, &MainWindow::change_time_limit);
		// 
		// label32
		// 
		this->label32->AutoSize = true;
		this->label32->Location = System::Drawing::Point(377, 22);
		this->label32->Name = L"label32";
		this->label32->Size = System::Drawing::Size(83, 13);
		this->label32->TabIndex = 9;
		this->label32->Text = L"Time Limit [sec]:";
		// 
		// textBox_author_text
		// 
		this->textBox_author_text->Location = System::Drawing::Point(116, 71);
		this->textBox_author_text->MaxLength = 28;
		this->textBox_author_text->Name = L"textBox_author_text";
		this->textBox_author_text->Size = System::Drawing::Size(400, 20);
		this->textBox_author_text->TabIndex = 7;
		this->textBox_author_text->Leave += gcnew System::EventHandler(this, &MainWindow::change_author_text);
		// 
		// textBox_name
		// 
		this->textBox_name->Location = System::Drawing::Point(95, 45);
		this->textBox_name->MaxLength = 28;
		this->textBox_name->Name = L"textBox_name";
		this->textBox_name->Size = System::Drawing::Size(421, 20);
		this->textBox_name->TabIndex = 5;
		this->textBox_name->Leave += gcnew System::EventHandler(this, &MainWindow::change_name);
		// 
		// label29
		// 
		this->label29->AutoSize = true;
		this->label29->Location = System::Drawing::Point(6, 48);
		this->label29->Name = L"label29";
		this->label29->Size = System::Drawing::Size(38, 13);
		this->label29->TabIndex = 4;
		this->label29->Text = L"Name:";
		// 
		// textBox_id
		// 
		this->textBox_id->Location = System::Drawing::Point(95, 19);
		this->textBox_id->Name = L"textBox_id";
		this->textBox_id->Size = System::Drawing::Size(115, 20);
		this->textBox_id->TabIndex = 1;
		this->textBox_id->Leave += gcnew System::EventHandler(this, &MainWindow::change_id);
		// 
		// label28
		// 
		this->label28->AutoSize = true;
		this->label28->Location = System::Drawing::Point(6, 22);
		this->label28->Name = L"label28";
		this->label28->Size = System::Drawing::Size(21, 13);
		this->label28->TabIndex = 0;
		this->label28->Text = L"ID:";
		// 
		// textBox_unknown_07
		// 
		this->textBox_unknown_07->Location = System::Drawing::Point(446, 260);
		this->textBox_unknown_07->Name = L"textBox_unknown_07";
		this->textBox_unknown_07->Size = System::Drawing::Size(219, 20);
		this->textBox_unknown_07->TabIndex = 25;
		this->textBox_unknown_07->Leave += gcnew System::EventHandler(this, &MainWindow::change_unknown_07);
		// 
		// label76
		// 
		this->label76->AutoSize = true;
		this->label76->Location = System::Drawing::Point(358, 263);
		this->label76->Name = L"label76";
		this->label76->Size = System::Drawing::Size(71, 13);
		this->label76->TabIndex = 24;
		this->label76->Text = L"Unknown 07:";
		// 
		// dataGridView_date_spans
		// 
		this->dataGridView_date_spans->AllowUserToAddRows = false;
		this->dataGridView_date_spans->AllowUserToDeleteRows = false;
		this->dataGridView_date_spans->BackgroundColor = System::Drawing::SystemColors::Window;
		this->dataGridView_date_spans->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
		this->dataGridView_date_spans->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
		this->dataGridView_date_spans->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(13) {this->dataGridViewTextBoxColumn1, 
			this->dataGridViewTextBoxColumn2, this->dataGridViewTextBoxColumn3, this->Column4, this->Column5, this->Column6, this->Column7, 
			this->Column8, this->Column9, this->Column10, this->Column11, this->Column12, this->Column13});
		this->dataGridView_date_spans->ContextMenuStrip = this->contextMenuStrip_date_spans;
		this->dataGridView_date_spans->Location = System::Drawing::Point(116, 172);
		this->dataGridView_date_spans->MultiSelect = false;
		this->dataGridView_date_spans->Name = L"dataGridView_date_spans";
		this->dataGridView_date_spans->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
		dataGridViewCellStyle14->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
		dataGridViewCellStyle14->BackColor = System::Drawing::SystemColors::Control;
		dataGridViewCellStyle14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		dataGridViewCellStyle14->ForeColor = System::Drawing::SystemColors::WindowText;
		dataGridViewCellStyle14->SelectionBackColor = System::Drawing::SystemColors::Highlight;
		dataGridViewCellStyle14->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
		dataGridViewCellStyle14->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView_date_spans->RowHeadersDefaultCellStyle = dataGridViewCellStyle14;
		this->dataGridView_date_spans->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::AutoSizeToFirstHeader;
		this->dataGridView_date_spans->RowTemplate->Height = 18;
		this->dataGridView_date_spans->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView_date_spans->Size = System::Drawing::Size(549, 82);
		this->dataGridView_date_spans->TabIndex = 0;
		this->dataGridView_date_spans->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::change_date_span);
		// 
		// dataGridViewTextBoxColumn1
		// 
		this->dataGridViewTextBoxColumn1->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn1->DefaultCellStyle = dataGridViewCellStyle1;
		this->dataGridViewTextBoxColumn1->HeaderText = L"Y";
		this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
		this->dataGridViewTextBoxColumn1->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn1->Width = 19;
		// 
		// dataGridViewTextBoxColumn2
		// 
		this->dataGridViewTextBoxColumn2->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn2->DefaultCellStyle = dataGridViewCellStyle2;
		this->dataGridViewTextBoxColumn2->HeaderText = L"M";
		this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
		this->dataGridViewTextBoxColumn2->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn2->Width = 21;
		// 
		// dataGridViewTextBoxColumn3
		// 
		this->dataGridViewTextBoxColumn3->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn3->DefaultCellStyle = dataGridViewCellStyle3;
		this->dataGridViewTextBoxColumn3->HeaderText = L"D";
		this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
		this->dataGridViewTextBoxColumn3->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn3->Width = 20;
		// 
		// Column4
		// 
		this->Column4->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->Column4->DefaultCellStyle = dataGridViewCellStyle4;
		this->Column4->HeaderText = L"H";
		this->Column4->Name = L"Column4";
		this->Column4->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->Column4->Width = 20;
		// 
		// Column5
		// 
		this->Column5->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle5->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->Column5->DefaultCellStyle = dataGridViewCellStyle5;
		this->Column5->HeaderText = L"M";
		this->Column5->Name = L"Column5";
		this->Column5->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->Column5->Width = 21;
		// 
		// Column6
		// 
		this->Column6->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle6->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->Column6->DefaultCellStyle = dataGridViewCellStyle6;
		this->Column6->HeaderText = L"d";
		this->Column6->Items->AddRange(gcnew cli::array< System::Object^  >(8) {L"ALL", L"Mon", L"Tue", L"Wed", L"Thu", L"Fri", L"Sat", 
			L"Sun"});
		this->Column6->Name = L"Column6";
		this->Column6->Resizable = System::Windows::Forms::DataGridViewTriState::True;
		this->Column6->Width = 18;
		// 
		// Column7
		// 
		this->Column7->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
		dataGridViewCellStyle7->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		dataGridViewCellStyle7->BackColor = System::Drawing::SystemColors::InactiveCaptionText;
		this->Column7->DefaultCellStyle = dataGridViewCellStyle7;
		this->Column7->HeaderText = L"";
		this->Column7->Name = L"Column7";
		this->Column7->ReadOnly = true;
		this->Column7->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		// 
		// Column8
		// 
		this->Column8->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle8->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->Column8->DefaultCellStyle = dataGridViewCellStyle8;
		this->Column8->HeaderText = L"Y";
		this->Column8->Name = L"Column8";
		this->Column8->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->Column8->Width = 19;
		// 
		// Column9
		// 
		this->Column9->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle9->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->Column9->DefaultCellStyle = dataGridViewCellStyle9;
		this->Column9->HeaderText = L"M";
		this->Column9->Name = L"Column9";
		this->Column9->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->Column9->Width = 21;
		// 
		// Column10
		// 
		this->Column10->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle10->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->Column10->DefaultCellStyle = dataGridViewCellStyle10;
		this->Column10->HeaderText = L"D";
		this->Column10->Name = L"Column10";
		this->Column10->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->Column10->Width = 20;
		// 
		// Column11
		// 
		this->Column11->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle11->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->Column11->DefaultCellStyle = dataGridViewCellStyle11;
		this->Column11->HeaderText = L"H";
		this->Column11->Name = L"Column11";
		this->Column11->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->Column11->Width = 20;
		// 
		// Column12
		// 
		this->Column12->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle12->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->Column12->DefaultCellStyle = dataGridViewCellStyle12;
		this->Column12->HeaderText = L"M";
		this->Column12->Name = L"Column12";
		this->Column12->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->Column12->Width = 21;
		// 
		// Column13
		// 
		this->Column13->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle13->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->Column13->DefaultCellStyle = dataGridViewCellStyle13;
		this->Column13->HeaderText = L"d";
		this->Column13->Items->AddRange(gcnew cli::array< System::Object^  >(8) {L"ALL", L"Mon", L"Tue", L"Wed", L"Thu", L"Fri", 
			L"Sat", L"Sun"});
		this->Column13->Name = L"Column13";
		this->Column13->Resizable = System::Windows::Forms::DataGridViewTriState::True;
		this->Column13->Width = 18;
		// 
		// dataGridView_reward_item_group_items
		// 
		this->dataGridView_reward_item_group_items->AllowUserToAddRows = false;
		this->dataGridView_reward_item_group_items->AllowUserToDeleteRows = false;
		this->dataGridView_reward_item_group_items->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
			| System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->dataGridView_reward_item_group_items->BackgroundColor = System::Drawing::SystemColors::Window;
		this->dataGridView_reward_item_group_items->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
		this->dataGridView_reward_item_group_items->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
		this->dataGridView_reward_item_group_items->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {this->Column_reward_item_groups, 
			this->dataGridViewTextBoxColumn28, this->dataGridViewTextBoxColumn29, this->dataGridViewTextBoxColumn30, this->dataGridViewTextBoxColumn31, 
			this->Column23});
		this->dataGridView_reward_item_group_items->ContextMenuStrip = this->contextMenuStrip_reward_items;
		this->dataGridView_reward_item_group_items->Location = System::Drawing::Point(113, 37);
		this->dataGridView_reward_item_group_items->MultiSelect = false;
		this->dataGridView_reward_item_group_items->Name = L"dataGridView_reward_item_group_items";
		this->dataGridView_reward_item_group_items->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
		dataGridViewCellStyle20->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
		dataGridViewCellStyle20->BackColor = System::Drawing::SystemColors::Control;
		dataGridViewCellStyle20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		dataGridViewCellStyle20->ForeColor = System::Drawing::SystemColors::WindowText;
		dataGridViewCellStyle20->SelectionBackColor = System::Drawing::SystemColors::Highlight;
		dataGridViewCellStyle20->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
		dataGridViewCellStyle20->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView_reward_item_group_items->RowHeadersDefaultCellStyle = dataGridViewCellStyle20;
		this->dataGridView_reward_item_group_items->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::AutoSizeToFirstHeader;
		this->dataGridView_reward_item_group_items->RowTemplate->Height = 18;
		this->dataGridView_reward_item_group_items->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView_reward_item_group_items->Size = System::Drawing::Size(536, 148);
		this->dataGridView_reward_item_group_items->TabIndex = 38;
		this->dataGridView_reward_item_group_items->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::change_reward_items);
		// 
		// Column_reward_item_groups
		// 
		this->Column_reward_item_groups->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle15->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->Column_reward_item_groups->DefaultCellStyle = dataGridViewCellStyle15;
		this->Column_reward_item_groups->DisplayStyle = System::Windows::Forms::DataGridViewComboBoxDisplayStyle::ComboBox;
		this->Column_reward_item_groups->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->Column_reward_item_groups->HeaderText = L"Group";
		this->Column_reward_item_groups->Name = L"Column_reward_item_groups";
		this->Column_reward_item_groups->Width = 41;
		// 
		// dataGridViewTextBoxColumn28
		// 
		this->dataGridViewTextBoxColumn28->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle16->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn28->DefaultCellStyle = dataGridViewCellStyle16;
		this->dataGridViewTextBoxColumn28->HeaderText = L"ID";
		this->dataGridViewTextBoxColumn28->Name = L"dataGridViewTextBoxColumn28";
		this->dataGridViewTextBoxColumn28->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn28->Width = 23;
		// 
		// dataGridViewTextBoxColumn29
		// 
		this->dataGridViewTextBoxColumn29->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		this->dataGridViewTextBoxColumn29->HeaderText = L"\?";
		this->dataGridViewTextBoxColumn29->Name = L"dataGridViewTextBoxColumn29";
		this->dataGridViewTextBoxColumn29->Resizable = System::Windows::Forms::DataGridViewTriState::True;
		this->dataGridViewTextBoxColumn29->Width = 18;
		// 
		// dataGridViewTextBoxColumn30
		// 
		this->dataGridViewTextBoxColumn30->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle17->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn30->DefaultCellStyle = dataGridViewCellStyle17;
		this->dataGridViewTextBoxColumn30->HeaderText = L"#";
		this->dataGridViewTextBoxColumn30->Name = L"dataGridViewTextBoxColumn30";
		this->dataGridViewTextBoxColumn30->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn30->Width = 19;
		// 
		// dataGridViewTextBoxColumn31
		// 
		this->dataGridViewTextBoxColumn31->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle18->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn31->DefaultCellStyle = dataGridViewCellStyle18;
		this->dataGridViewTextBoxColumn31->HeaderText = L"%";
		this->dataGridViewTextBoxColumn31->Name = L"dataGridViewTextBoxColumn31";
		this->dataGridViewTextBoxColumn31->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn31->Width = 20;
		// 
		// Column23
		// 
		this->Column23->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
		dataGridViewCellStyle19->ForeColor = System::Drawing::Color::Gray;
		this->Column23->DefaultCellStyle = dataGridViewCellStyle19;
		this->Column23->HeaderText = L"Expiration";
		this->Column23->Name = L"Column23";
		this->Column23->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		// 
		// contextMenuStrip_reward_items
		// 
		this->contextMenuStrip_reward_items->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->toolStripMenuItem18, 
			this->toolStripMenuItem19});
		this->contextMenuStrip_reward_items->Name = L"contextMenuStrip1";
		this->contextMenuStrip_reward_items->Size = System::Drawing::Size(139, 48);
		// 
		// toolStripMenuItem18
		// 
		this->toolStripMenuItem18->Name = L"toolStripMenuItem18";
		this->toolStripMenuItem18->Size = System::Drawing::Size(138, 22);
		this->toolStripMenuItem18->Text = L"Add Item";
		this->toolStripMenuItem18->Click += gcnew System::EventHandler(this, &MainWindow::add_reward_item);
		// 
		// toolStripMenuItem19
		// 
		this->toolStripMenuItem19->Name = L"toolStripMenuItem19";
		this->toolStripMenuItem19->Size = System::Drawing::Size(138, 22);
		this->toolStripMenuItem19->Text = L"Remove Item";
		this->toolStripMenuItem19->Click += gcnew System::EventHandler(this, &MainWindow::remove_reward_item);
		// 
		// groupBox_reward_selector
		// 
		this->groupBox_reward_selector->Controls->Add(this->numericUpDown_time_factor);
		this->groupBox_reward_selector->Controls->Add(this->label3);
		this->groupBox_reward_selector->Controls->Add(this->radioButton_timed);
		this->groupBox_reward_selector->Controls->Add(this->radioButton_failed);
		this->groupBox_reward_selector->Controls->Add(this->radioButton_success);
		this->groupBox_reward_selector->Controls->Add(this->listBox_reward_timed);
		this->groupBox_reward_selector->Location = System::Drawing::Point(3, 3);
		this->groupBox_reward_selector->Name = L"groupBox_reward_selector";
		this->groupBox_reward_selector->Size = System::Drawing::Size(655, 120);
		this->groupBox_reward_selector->TabIndex = 0;
		this->groupBox_reward_selector->TabStop = false;
		this->groupBox_reward_selector->Text = L"REWARD SELECTOR";
		// 
		// numericUpDown_time_factor
		// 
		this->numericUpDown_time_factor->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
		this->numericUpDown_time_factor->DecimalPlaces = 3;
		this->numericUpDown_time_factor->Enabled = false;
		this->numericUpDown_time_factor->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 131072});
		this->numericUpDown_time_factor->Location = System::Drawing::Point(576, 94);
		this->numericUpDown_time_factor->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
		this->numericUpDown_time_factor->Name = L"numericUpDown_time_factor";
		this->numericUpDown_time_factor->Size = System::Drawing::Size(73, 20);
		this->numericUpDown_time_factor->TabIndex = 5;
		this->numericUpDown_time_factor->ValueChanged += gcnew System::EventHandler(this, &MainWindow::change_reward_time_factor);
		// 
		// label3
		// 
		this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
		this->label3->AutoSize = true;
		this->label3->Location = System::Drawing::Point(504, 96);
		this->label3->Name = L"label3";
		this->label3->Size = System::Drawing::Size(66, 13);
		this->label3->TabIndex = 4;
		this->label3->Text = L"Time Factor:";
		// 
		// radioButton_timed
		// 
		this->radioButton_timed->AutoSize = true;
		this->radioButton_timed->Location = System::Drawing::Point(6, 65);
		this->radioButton_timed->Name = L"radioButton_timed";
		this->radioButton_timed->Size = System::Drawing::Size(81, 17);
		this->radioButton_timed->TabIndex = 2;
		this->radioButton_timed->Text = L"Time Based";
		this->radioButton_timed->UseVisualStyleBackColor = true;
		this->radioButton_timed->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::select_reward);
		// 
		// radioButton_failed
		// 
		this->radioButton_failed->AutoSize = true;
		this->radioButton_failed->Location = System::Drawing::Point(6, 42);
		this->radioButton_failed->Name = L"radioButton_failed";
		this->radioButton_failed->Size = System::Drawing::Size(53, 17);
		this->radioButton_failed->TabIndex = 1;
		this->radioButton_failed->Text = L"Failed";
		this->radioButton_failed->UseVisualStyleBackColor = true;
		this->radioButton_failed->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::select_reward);
		// 
		// radioButton_success
		// 
		this->radioButton_success->AutoSize = true;
		this->radioButton_success->Checked = true;
		this->radioButton_success->Location = System::Drawing::Point(6, 19);
		this->radioButton_success->Name = L"radioButton_success";
		this->radioButton_success->Size = System::Drawing::Size(66, 17);
		this->radioButton_success->TabIndex = 0;
		this->radioButton_success->TabStop = true;
		this->radioButton_success->Text = L"Success";
		this->radioButton_success->UseVisualStyleBackColor = true;
		this->radioButton_success->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::select_reward);
		// 
		// listBox_reward_timed
		// 
		this->listBox_reward_timed->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
			| System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->listBox_reward_timed->ContextMenuStrip = this->contextMenuStrip_reward_timed;
		this->listBox_reward_timed->Enabled = false;
		this->listBox_reward_timed->FormattingEnabled = true;
		this->listBox_reward_timed->Location = System::Drawing::Point(93, 19);
		this->listBox_reward_timed->Name = L"listBox_reward_timed";
		this->listBox_reward_timed->Size = System::Drawing::Size(556, 69);
		this->listBox_reward_timed->TabIndex = 3;
		this->listBox_reward_timed->SelectedIndexChanged += gcnew System::EventHandler(this, &MainWindow::select_reward);
		// 
		// contextMenuStrip_reward_timed
		// 
		this->contextMenuStrip_reward_timed->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->toolStripMenuItem38, 
			this->toolStripMenuItem39});
		this->contextMenuStrip_reward_timed->Name = L"contextMenuStrip1";
		this->contextMenuStrip_reward_timed->Size = System::Drawing::Size(154, 48);
		// 
		// toolStripMenuItem38
		// 
		this->toolStripMenuItem38->Name = L"toolStripMenuItem38";
		this->toolStripMenuItem38->Size = System::Drawing::Size(153, 22);
		this->toolStripMenuItem38->Text = L"Add Reward";
		this->toolStripMenuItem38->Click += gcnew System::EventHandler(this, &MainWindow::add_reward_timed);
		// 
		// toolStripMenuItem39
		// 
		this->toolStripMenuItem39->Name = L"toolStripMenuItem39";
		this->toolStripMenuItem39->Size = System::Drawing::Size(153, 22);
		this->toolStripMenuItem39->Text = L"Remove Reward";
		this->toolStripMenuItem39->Click += gcnew System::EventHandler(this, &MainWindow::remove_reward_timed);
		// 
		// groupBox_reward
		// 
		this->groupBox_reward->Controls->Add(this->textBox_reward_quest_slot_expansion);
		this->groupBox_reward->Controls->Add(this->label234);
		this->groupBox_reward->Controls->Add(this->textBox_reward_unknown_6);
		this->groupBox_reward->Controls->Add(this->label200);
		this->groupBox_reward->Controls->Add(this->label201);
		this->groupBox_reward->Controls->Add(this->textBox_reward_influence);
		this->groupBox_reward->Controls->Add(this->textBox_reward_unknown_5);
		this->groupBox_reward->Controls->Add(this->label202);
		this->groupBox_reward->Controls->Add(this->textBox_reward_prestige);
		this->groupBox_reward->Controls->Add(this->label203);
		this->groupBox_reward->Controls->Add(this->textBox_reward_seperator);
		this->groupBox_reward->Controls->Add(this->label199);
		this->groupBox_reward->Controls->Add(this->label198);
		this->groupBox_reward->Controls->Add(this->label197);
		this->groupBox_reward->Controls->Add(this->label196);
		this->groupBox_reward->Controls->Add(this->textBox_reward_account_stash_slots);
		this->groupBox_reward->Controls->Add(this->label195);
		this->groupBox_reward->Controls->Add(this->textBox_reward_wardrobe_slots);
		this->groupBox_reward->Controls->Add(this->label194);
		this->groupBox_reward->Controls->Add(this->textBox_reward_cupboard_slots);
		this->groupBox_reward->Controls->Add(this->label193);
		this->groupBox_reward->Controls->Add(this->textBox_reward_new_waypoint);
		this->groupBox_reward->Controls->Add(this->label192);
		this->groupBox_reward->Controls->Add(this->label63);
		this->groupBox_reward->Controls->Add(this->textBox_reward_ai_trigger);
		this->groupBox_reward->Controls->Add(this->textBox_reward_unknown_2b);
		this->groupBox_reward->Controls->Add(this->label61);
		this->groupBox_reward->Controls->Add(this->textBox_reward_unknown_2a);
		this->groupBox_reward->Controls->Add(this->label60);
		this->groupBox_reward->Controls->Add(this->textBox_reward_teleport_map_id);
		this->groupBox_reward->Controls->Add(this->textBox_reward_teleport_z);
		this->groupBox_reward->Controls->Add(this->textBox_reward_teleport_x);
		this->groupBox_reward->Controls->Add(this->textBox_reward_teleport_altitude);
		this->groupBox_reward->Controls->Add(this->label26);
		this->groupBox_reward->Controls->Add(this->textBox_reward_petbag_slots);
		this->groupBox_reward->Controls->Add(this->label23);
		this->groupBox_reward->Controls->Add(this->textBox_reward_inventory_slots);
		this->groupBox_reward->Controls->Add(this->label24);
		this->groupBox_reward->Controls->Add(this->textBox_reward_storage_slots);
		this->groupBox_reward->Controls->Add(this->label25);
		this->groupBox_reward->Controls->Add(this->textBox_reward_new_quest);
		this->groupBox_reward->Controls->Add(this->label22);
		this->groupBox_reward->Controls->Add(this->textBox_reward_vigor);
		this->groupBox_reward->Controls->Add(this->label21);
		this->groupBox_reward->Controls->Add(this->textBox_reward_cultivation);
		this->groupBox_reward->Controls->Add(this->label20);
		this->groupBox_reward->Controls->Add(this->textBox_reward_reputation);
		this->groupBox_reward->Controls->Add(this->label19);
		this->groupBox_reward->Controls->Add(this->textBox_reward_spirit);
		this->groupBox_reward->Controls->Add(this->label18);
		this->groupBox_reward->Controls->Add(this->textBox_reward_experience);
		this->groupBox_reward->Controls->Add(this->label17);
		this->groupBox_reward->Controls->Add(this->textBox_reward_coins);
		this->groupBox_reward->Controls->Add(this->label16);
		this->groupBox_reward->Location = System::Drawing::Point(3, 129);
		this->groupBox_reward->Name = L"groupBox_reward";
		this->groupBox_reward->Size = System::Drawing::Size(655, 383);
		this->groupBox_reward->TabIndex = 2;
		this->groupBox_reward->TabStop = false;
		this->groupBox_reward->Text = L"GENERAL";
		// 
		// textBox_reward_quest_slot_expansion
		// 
		this->textBox_reward_quest_slot_expansion->Location = System::Drawing::Point(397, 331);
		this->textBox_reward_quest_slot_expansion->Name = L"textBox_reward_quest_slot_expansion";
		this->textBox_reward_quest_slot_expansion->Size = System::Drawing::Size(100, 20);
		this->textBox_reward_quest_slot_expansion->TabIndex = 55;
		this->textBox_reward_quest_slot_expansion->Leave += gcnew System::EventHandler(this, &MainWindow::change_reward_quest_slot_expansion);
		// 
		// label234
		// 
		this->label234->AutoSize = true;
		this->label234->ForeColor = System::Drawing::Color::Red;
		this->label234->Location = System::Drawing::Point(274, 334);
		this->label234->Name = L"label234";
		this->label234->Size = System::Drawing::Size(111, 13);
		this->label234->TabIndex = 54;
		this->label234->Text = L"Quest Slot Expansion:";
		// 
		// textBox_reward_unknown_6
		// 
		this->textBox_reward_unknown_6->Location = System::Drawing::Point(397, 305);
		this->textBox_reward_unknown_6->Name = L"textBox_reward_unknown_6";
		this->textBox_reward_unknown_6->Size = System::Drawing::Size(100, 20);
		this->textBox_reward_unknown_6->TabIndex = 53;
		this->textBox_reward_unknown_6->Leave += gcnew System::EventHandler(this, &MainWindow::change_reward_unknown_6);
		// 
		// label200
		// 
		this->label200->AutoSize = true;
		this->label200->ForeColor = System::Drawing::Color::Red;
		this->label200->Location = System::Drawing::Point(274, 308);
		this->label200->Name = L"label200";
		this->label200->Size = System::Drawing::Size(65, 13);
		this->label200->TabIndex = 52;
		this->label200->Text = L"Unknown 6:";
		// 
		// label201
		// 
		this->label201->AutoSize = true;
		this->label201->ForeColor = System::Drawing::Color::Red;
		this->label201->Location = System::Drawing::Point(274, 230);
		this->label201->Name = L"label201";
		this->label201->Size = System::Drawing::Size(54, 13);
		this->label201->TabIndex = 46;
		this->label201->Text = L"Influence:";
		// 
		// textBox_reward_influence
		// 
		this->textBox_reward_influence->Location = System::Drawing::Point(397, 227);
		this->textBox_reward_influence->Name = L"textBox_reward_influence";
		this->textBox_reward_influence->Size = System::Drawing::Size(100, 20);
		this->textBox_reward_influence->TabIndex = 47;
		this->textBox_reward_influence->Leave += gcnew System::EventHandler(this, &MainWindow::change_reward_influence);
		// 
		// textBox_reward_unknown_5
		// 
		this->textBox_reward_unknown_5->Location = System::Drawing::Point(397, 279);
		this->textBox_reward_unknown_5->Name = L"textBox_reward_unknown_5";
		this->textBox_reward_unknown_5->Size = System::Drawing::Size(100, 20);
		this->textBox_reward_unknown_5->TabIndex = 51;
		this->textBox_reward_unknown_5->Leave += gcnew System::EventHandler(this, &MainWindow::change_reward_unknown_5);
		// 
		// label202
		// 
		this->label202->AutoSize = true;
		this->label202->ForeColor = System::Drawing::Color::Red;
		this->label202->Location = System::Drawing::Point(274, 282);
		this->label202->Name = L"label202";
		this->label202->Size = System::Drawing::Size(65, 13);
		this->label202->TabIndex = 50;
		this->label202->Text = L"Unknown 5:";
		// 
		// textBox_reward_prestige
		// 
		this->textBox_reward_prestige->Location = System::Drawing::Point(397, 253);
		this->textBox_reward_prestige->Name = L"textBox_reward_prestige";
		this->textBox_reward_prestige->Size = System::Drawing::Size(100, 20);
		this->textBox_reward_prestige->TabIndex = 49;
		this->textBox_reward_prestige->Leave += gcnew System::EventHandler(this, &MainWindow::change_reward_prestige);
		// 
		// label203
		// 
		this->label203->AutoSize = true;
		this->label203->ForeColor = System::Drawing::Color::Red;
		this->label203->Location = System::Drawing::Point(274, 256);
		this->label203->Name = L"label203";
		this->label203->Size = System::Drawing::Size(48, 13);
		this->label203->TabIndex = 48;
		this->label203->Text = L"Prestige:";
		// 
		// textBox_reward_seperator
		// 
		this->textBox_reward_seperator->Location = System::Drawing::Point(397, 201);
		this->textBox_reward_seperator->Name = L"textBox_reward_seperator";
		this->textBox_reward_seperator->Size = System::Drawing::Size(100, 20);
		this->textBox_reward_seperator->TabIndex = 45;
		this->textBox_reward_seperator->Leave += gcnew System::EventHandler(this, &MainWindow::change_reward_seperator);
		// 
		// label199
		// 
		this->label199->AutoSize = true;
		this->label199->Location = System::Drawing::Point(274, 204);
		this->label199->Name = L"label199";
		this->label199->Size = System::Drawing::Size(56, 13);
		this->label199->TabIndex = 44;
		this->label199->Text = L"Seperator:";
		// 
		// label198
		// 
		this->label198->AutoSize = true;
		this->label198->Location = System::Drawing::Point(344, 100);
		this->label198->Name = L"label198";
		this->label198->Size = System::Drawing::Size(17, 13);
		this->label198->TabIndex = 43;
		this->label198->Text = L"Z:";
		// 
		// label197
		// 
		this->label197->AutoSize = true;
		this->label197->Location = System::Drawing::Point(316, 74);
		this->label197->Name = L"label197";
		this->label197->Size = System::Drawing::Size(45, 13);
		this->label197->TabIndex = 42;
		this->label197->Text = L"Altitude:";
		// 
		// label196
		// 
		this->label196->AutoSize = true;
		this->label196->Location = System::Drawing::Point(344, 48);
		this->label196->Name = L"label196";
		this->label196->Size = System::Drawing::Size(17, 13);
		this->label196->TabIndex = 41;
		this->label196->Text = L"X:";
		// 
		// textBox_reward_account_stash_slots
		// 
		this->textBox_reward_account_stash_slots->Location = System::Drawing::Point(129, 305);
		this->textBox_reward_account_stash_slots->Name = L"textBox_reward_account_stash_slots";
		this->textBox_reward_account_stash_slots->Size = System::Drawing::Size(100, 20);
		this->textBox_reward_account_stash_slots->TabIndex = 40;
		this->textBox_reward_account_stash_slots->Leave += gcnew System::EventHandler(this, &MainWindow::change_reward_account_stash_slots);
		// 
		// label195
		// 
		this->label195->AutoSize = true;
		this->label195->ForeColor = System::Drawing::Color::Gray;
		this->label195->Location = System::Drawing::Point(6, 308);
		this->label195->Name = L"label195";
		this->label195->Size = System::Drawing::Size(106, 13);
		this->label195->TabIndex = 39;
		this->label195->Text = L"Account Stash Slots:";
		// 
		// textBox_reward_wardrobe_slots
		// 
		this->textBox_reward_wardrobe_slots->Location = System::Drawing::Point(129, 279);
		this->textBox_reward_wardrobe_slots->Name = L"textBox_reward_wardrobe_slots";
		this->textBox_reward_wardrobe_slots->Size = System::Drawing::Size(100, 20);
		this->textBox_reward_wardrobe_slots->TabIndex = 38;
		this->textBox_reward_wardrobe_slots->Leave += gcnew System::EventHandler(this, &MainWindow::change_reward_wardrobe_slots);
		// 
		// label194
		// 
		this->label194->AutoSize = true;
		this->label194->ForeColor = System::Drawing::Color::Gray;
		this->label194->Location = System::Drawing::Point(6, 282);
		this->label194->Name = L"label194";
		this->label194->Size = System::Drawing::Size(83, 13);
		this->label194->TabIndex = 37;
		this->label194->Text = L"Wardrobe Slots:";
		// 
		// textBox_reward_cupboard_slots
		// 
		this->textBox_reward_cupboard_slots->Location = System::Drawing::Point(129, 253);
		this->textBox_reward_cupboard_slots->Name = L"textBox_reward_cupboard_slots";
		this->textBox_reward_cupboard_slots->Size = System::Drawing::Size(100, 20);
		this->textBox_reward_cupboard_slots->TabIndex = 36;
		this->textBox_reward_cupboard_slots->Leave += gcnew System::EventHandler(this, &MainWindow::change_reward_cupboard_slots);
		// 
		// label193
		// 
		this->label193->AutoSize = true;
		this->label193->ForeColor = System::Drawing::Color::Gray;
		this->label193->Location = System::Drawing::Point(6, 256);
		this->label193->Name = L"label193";
		this->label193->Size = System::Drawing::Size(82, 13);
		this->label193->TabIndex = 35;
		this->label193->Text = L"Cupboard Slots:";
		// 
		// textBox_reward_new_waypoint
		// 
		this->textBox_reward_new_waypoint->Location = System::Drawing::Point(129, 175);
		this->textBox_reward_new_waypoint->Name = L"textBox_reward_new_waypoint";
		this->textBox_reward_new_waypoint->Size = System::Drawing::Size(100, 20);
		this->textBox_reward_new_waypoint->TabIndex = 34;
		this->textBox_reward_new_waypoint->Leave += gcnew System::EventHandler(this, &MainWindow::change_reward_new_waypoint);
		// 
		// label192
		// 
		this->label192->AutoSize = true;
		this->label192->Location = System::Drawing::Point(6, 178);
		this->label192->Name = L"label192";
		this->label192->Size = System::Drawing::Size(100, 13);
		this->label192->TabIndex = 33;
		this->label192->Text = L"New Waypoint (ID):";
		// 
		// label63
		// 
		this->label63->AutoSize = true;
		this->label63->Location = System::Drawing::Point(274, 126);
		this->label63->Name = L"label63";
		this->label63->Size = System::Drawing::Size(85, 13);
		this->label63->TabIndex = 22;
		this->label63->Text = L"Creature Builder:";
		// 
		// textBox_reward_ai_trigger
		// 
		this->textBox_reward_ai_trigger->Location = System::Drawing::Point(397, 123);
		this->textBox_reward_ai_trigger->Name = L"textBox_reward_ai_trigger";
		this->textBox_reward_ai_trigger->Size = System::Drawing::Size(100, 20);
		this->textBox_reward_ai_trigger->TabIndex = 23;
		this->textBox_reward_ai_trigger->Leave += gcnew System::EventHandler(this, &MainWindow::change_reward_ai_trigger);
		// 
		// textBox_reward_unknown_2b
		// 
		this->textBox_reward_unknown_2b->Location = System::Drawing::Point(397, 175);
		this->textBox_reward_unknown_2b->Name = L"textBox_reward_unknown_2b";
		this->textBox_reward_unknown_2b->Size = System::Drawing::Size(100, 20);
		this->textBox_reward_unknown_2b->TabIndex = 27;
		this->textBox_reward_unknown_2b->Leave += gcnew System::EventHandler(this, &MainWindow::change_reward_unknown_2b);
		// 
		// label61
		// 
		this->label61->AutoSize = true;
		this->label61->ForeColor = System::Drawing::Color::Gray;
		this->label61->Location = System::Drawing::Point(274, 178);
		this->label61->Name = L"label61";
		this->label61->Size = System::Drawing::Size(71, 13);
		this->label61->TabIndex = 26;
		this->label61->Text = L"Unknown 2b:";
		// 
		// textBox_reward_unknown_2a
		// 
		this->textBox_reward_unknown_2a->Location = System::Drawing::Point(397, 149);
		this->textBox_reward_unknown_2a->Name = L"textBox_reward_unknown_2a";
		this->textBox_reward_unknown_2a->Size = System::Drawing::Size(100, 20);
		this->textBox_reward_unknown_2a->TabIndex = 25;
		this->textBox_reward_unknown_2a->Leave += gcnew System::EventHandler(this, &MainWindow::change_reward_unknown_2a);
		// 
		// label60
		// 
		this->label60->AutoSize = true;
		this->label60->Location = System::Drawing::Point(274, 152);
		this->label60->Name = L"label60";
		this->label60->Size = System::Drawing::Size(71, 13);
		this->label60->TabIndex = 24;
		this->label60->Text = L"Unknown 2a:";
		// 
		// textBox_reward_teleport_map_id
		// 
		this->textBox_reward_teleport_map_id->Location = System::Drawing::Point(397, 19);
		this->textBox_reward_teleport_map_id->Name = L"textBox_reward_teleport_map_id";
		this->textBox_reward_teleport_map_id->Size = System::Drawing::Size(60, 20);
		this->textBox_reward_teleport_map_id->TabIndex = 29;
		this->textBox_reward_teleport_map_id->Leave += gcnew System::EventHandler(this, &MainWindow::change_reward_teleport_map_id);
		// 
		// textBox_reward_teleport_z
		// 
		this->textBox_reward_teleport_z->Location = System::Drawing::Point(397, 97);
		this->textBox_reward_teleport_z->Name = L"textBox_reward_teleport_z";
		this->textBox_reward_teleport_z->Size = System::Drawing::Size(60, 20);
		this->textBox_reward_teleport_z->TabIndex = 32;
		this->textBox_reward_teleport_z->Leave += gcnew System::EventHandler(this, &MainWindow::change_reward_teleport_z);
		// 
		// textBox_reward_teleport_x
		// 
		this->textBox_reward_teleport_x->Location = System::Drawing::Point(397, 45);
		this->textBox_reward_teleport_x->Name = L"textBox_reward_teleport_x";
		this->textBox_reward_teleport_x->Size = System::Drawing::Size(60, 20);
		this->textBox_reward_teleport_x->TabIndex = 30;
		this->textBox_reward_teleport_x->Leave += gcnew System::EventHandler(this, &MainWindow::change_reward_teleport_x);
		// 
		// textBox_reward_teleport_altitude
		// 
		this->textBox_reward_teleport_altitude->Location = System::Drawing::Point(397, 71);
		this->textBox_reward_teleport_altitude->Name = L"textBox_reward_teleport_altitude";
		this->textBox_reward_teleport_altitude->Size = System::Drawing::Size(60, 20);
		this->textBox_reward_teleport_altitude->TabIndex = 31;
		this->textBox_reward_teleport_altitude->Leave += gcnew System::EventHandler(this, &MainWindow::change_reward_teleport_altitude);
		// 
		// label26
		// 
		this->label26->AutoSize = true;
		this->label26->Location = System::Drawing::Point(274, 22);
		this->label26->Name = L"label26";
		this->label26->Size = System::Drawing::Size(87, 13);
		this->label26->TabIndex = 28;
		this->label26->Text = L"Teleport Map ID:";
		// 
		// textBox_reward_petbag_slots
		// 
		this->textBox_reward_petbag_slots->Location = System::Drawing::Point(129, 357);
		this->textBox_reward_petbag_slots->Name = L"textBox_reward_petbag_slots";
		this->textBox_reward_petbag_slots->Size = System::Drawing::Size(100, 20);
		this->textBox_reward_petbag_slots->TabIndex = 19;
		this->textBox_reward_petbag_slots->Leave += gcnew System::EventHandler(this, &MainWindow::change_reward_petbag_slots);
		// 
		// label23
		// 
		this->label23->AutoSize = true;
		this->label23->Location = System::Drawing::Point(6, 360);
		this->label23->Name = L"label23";
		this->label23->Size = System::Drawing::Size(70, 13);
		this->label23->TabIndex = 18;
		this->label23->Text = L"Petbag Slots:";
		// 
		// textBox_reward_inventory_slots
		// 
		this->textBox_reward_inventory_slots->Location = System::Drawing::Point(129, 331);
		this->textBox_reward_inventory_slots->Name = L"textBox_reward_inventory_slots";
		this->textBox_reward_inventory_slots->Size = System::Drawing::Size(100, 20);
		this->textBox_reward_inventory_slots->TabIndex = 17;
		this->textBox_reward_inventory_slots->Leave += gcnew System::EventHandler(this, &MainWindow::change_reward_inventory_slots);
		// 
		// label24
		// 
		this->label24->AutoSize = true;
		this->label24->Location = System::Drawing::Point(6, 334);
		this->label24->Name = L"label24";
		this->label24->Size = System::Drawing::Size(80, 13);
		this->label24->TabIndex = 16;
		this->label24->Text = L"Inventory Slots:";
		// 
		// textBox_reward_storage_slots
		// 
		this->textBox_reward_storage_slots->Location = System::Drawing::Point(129, 227);
		this->textBox_reward_storage_slots->Name = L"textBox_reward_storage_slots";
		this->textBox_reward_storage_slots->Size = System::Drawing::Size(100, 20);
		this->textBox_reward_storage_slots->TabIndex = 15;
		this->textBox_reward_storage_slots->Leave += gcnew System::EventHandler(this, &MainWindow::change_reward_storage_slots);
		// 
		// label25
		// 
		this->label25->AutoSize = true;
		this->label25->Location = System::Drawing::Point(6, 230);
		this->label25->Name = L"label25";
		this->label25->Size = System::Drawing::Size(73, 13);
		this->label25->TabIndex = 14;
		this->label25->Text = L"Storage Slots:";
		// 
		// textBox_reward_new_quest
		// 
		this->textBox_reward_new_quest->Location = System::Drawing::Point(129, 201);
		this->textBox_reward_new_quest->Name = L"textBox_reward_new_quest";
		this->textBox_reward_new_quest->Size = System::Drawing::Size(100, 20);
		this->textBox_reward_new_quest->TabIndex = 21;
		this->textBox_reward_new_quest->Leave += gcnew System::EventHandler(this, &MainWindow::change_reward_new_quest);
		// 
		// label22
		// 
		this->label22->AutoSize = true;
		this->label22->Location = System::Drawing::Point(6, 204);
		this->label22->Name = L"label22";
		this->label22->Size = System::Drawing::Size(109, 13);
		this->label22->TabIndex = 20;
		this->label22->Text = L"New Quest Available:";
		// 
		// textBox_reward_vigor
		// 
		this->textBox_reward_vigor->Location = System::Drawing::Point(129, 149);
		this->textBox_reward_vigor->Name = L"textBox_reward_vigor";
		this->textBox_reward_vigor->Size = System::Drawing::Size(100, 20);
		this->textBox_reward_vigor->TabIndex = 13;
		this->textBox_reward_vigor->Leave += gcnew System::EventHandler(this, &MainWindow::change_reward_vigor);
		// 
		// label21
		// 
		this->label21->AutoSize = true;
		this->label21->Location = System::Drawing::Point(6, 152);
		this->label21->Name = L"label21";
		this->label21->Size = System::Drawing::Size(60, 13);
		this->label21->TabIndex = 12;
		this->label21->Text = L"Vigor / Chi:";
		// 
		// textBox_reward_cultivation
		// 
		this->textBox_reward_cultivation->Location = System::Drawing::Point(129, 123);
		this->textBox_reward_cultivation->Name = L"textBox_reward_cultivation";
		this->textBox_reward_cultivation->Size = System::Drawing::Size(100, 20);
		this->textBox_reward_cultivation->TabIndex = 11;
		this->textBox_reward_cultivation->Leave += gcnew System::EventHandler(this, &MainWindow::change_reward_cultivation);
		// 
		// label20
		// 
		this->label20->AutoSize = true;
		this->label20->Location = System::Drawing::Point(6, 126);
		this->label20->Name = L"label20";
		this->label20->Size = System::Drawing::Size(88, 13);
		this->label20->TabIndex = 10;
		this->label20->Text = L"Cultivation Level:";
		// 
		// textBox_reward_reputation
		// 
		this->textBox_reward_reputation->Location = System::Drawing::Point(129, 97);
		this->textBox_reward_reputation->Name = L"textBox_reward_reputation";
		this->textBox_reward_reputation->Size = System::Drawing::Size(100, 20);
		this->textBox_reward_reputation->TabIndex = 7;
		this->textBox_reward_reputation->Leave += gcnew System::EventHandler(this, &MainWindow::change_reward_reputation);
		// 
		// label19
		// 
		this->label19->AutoSize = true;
		this->label19->Location = System::Drawing::Point(6, 100);
		this->label19->Name = L"label19";
		this->label19->Size = System::Drawing::Size(62, 13);
		this->label19->TabIndex = 6;
		this->label19->Text = L"Reputation:";
		// 
		// textBox_reward_spirit
		// 
		this->textBox_reward_spirit->Location = System::Drawing::Point(129, 71);
		this->textBox_reward_spirit->Name = L"textBox_reward_spirit";
		this->textBox_reward_spirit->Size = System::Drawing::Size(100, 20);
		this->textBox_reward_spirit->TabIndex = 5;
		this->textBox_reward_spirit->Leave += gcnew System::EventHandler(this, &MainWindow::change_reward_spirit);
		// 
		// label18
		// 
		this->label18->AutoSize = true;
		this->label18->Location = System::Drawing::Point(6, 74);
		this->label18->Name = L"label18";
		this->label18->Size = System::Drawing::Size(33, 13);
		this->label18->TabIndex = 4;
		this->label18->Text = L"Spirit:";
		// 
		// textBox_reward_experience
		// 
		this->textBox_reward_experience->Location = System::Drawing::Point(129, 45);
		this->textBox_reward_experience->Name = L"textBox_reward_experience";
		this->textBox_reward_experience->Size = System::Drawing::Size(100, 20);
		this->textBox_reward_experience->TabIndex = 3;
		this->textBox_reward_experience->Leave += gcnew System::EventHandler(this, &MainWindow::change_reward_experience);
		// 
		// label17
		// 
		this->label17->AutoSize = true;
		this->label17->Location = System::Drawing::Point(6, 48);
		this->label17->Name = L"label17";
		this->label17->Size = System::Drawing::Size(63, 13);
		this->label17->TabIndex = 2;
		this->label17->Text = L"Experience:";
		// 
		// textBox_reward_coins
		// 
		this->textBox_reward_coins->Location = System::Drawing::Point(129, 19);
		this->textBox_reward_coins->Name = L"textBox_reward_coins";
		this->textBox_reward_coins->Size = System::Drawing::Size(100, 20);
		this->textBox_reward_coins->TabIndex = 1;
		this->textBox_reward_coins->Leave += gcnew System::EventHandler(this, &MainWindow::change_reward_coins);
		// 
		// label16
		// 
		this->label16->AutoSize = true;
		this->label16->Location = System::Drawing::Point(6, 22);
		this->label16->Name = L"label16";
		this->label16->Size = System::Drawing::Size(36, 13);
		this->label16->TabIndex = 0;
		this->label16->Text = L"Coins:";
		// 
		// label57
		// 
		this->label57->AutoSize = true;
		this->label57->Location = System::Drawing::Point(3, 60);
		this->label57->Name = L"label57";
		this->label57->Size = System::Drawing::Size(67, 13);
		this->label57->TabIndex = 35;
		this->label57->Text = L"Group Flags:";
		// 
		// numericUpDown_reward_item_groups_count
		// 
		this->numericUpDown_reward_item_groups_count->Location = System::Drawing::Point(6, 37);
		this->numericUpDown_reward_item_groups_count->Name = L"numericUpDown_reward_item_groups_count";
		this->numericUpDown_reward_item_groups_count->Size = System::Drawing::Size(101, 20);
		this->numericUpDown_reward_item_groups_count->TabIndex = 34;
		this->numericUpDown_reward_item_groups_count->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->numericUpDown_reward_item_groups_count->ValueChanged += gcnew System::EventHandler(this, &MainWindow::change_reward_item_groups_count);
		// 
		// label56
		// 
		this->label56->AutoSize = true;
		this->label56->Location = System::Drawing::Point(3, 21);
		this->label56->Name = L"label56";
		this->label56->Size = System::Drawing::Size(77, 13);
		this->label56->TabIndex = 33;
		this->label56->Text = L"# Item Groups:";
		// 
		// label37
		// 
		this->label37->AutoSize = true;
		this->label37->Location = System::Drawing::Point(110, 21);
		this->label37->Name = L"label37";
		this->label37->Size = System::Drawing::Size(35, 13);
		this->label37->TabIndex = 37;
		this->label37->Text = L"Items:";
		// 
		// groupBox_conversation
		// 
		this->groupBox_conversation->Controls->Add(this->textBox_conversation_general_text);
		this->groupBox_conversation->Controls->Add(this->label42);
		this->groupBox_conversation->Controls->Add(this->label40);
		this->groupBox_conversation->Controls->Add(this->textBox_conversation_prompt_text);
		this->groupBox_conversation->Location = System::Drawing::Point(3, 3);
		this->groupBox_conversation->Name = L"groupBox_conversation";
		this->groupBox_conversation->Size = System::Drawing::Size(671, 159);
		this->groupBox_conversation->TabIndex = 0;
		this->groupBox_conversation->TabStop = false;
		this->groupBox_conversation->Text = L"CONVERSATION";
		// 
		// textBox_conversation_general_text
		// 
		this->textBox_conversation_general_text->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
			| System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->textBox_conversation_general_text->Location = System::Drawing::Point(317, 35);
		this->textBox_conversation_general_text->Multiline = true;
		this->textBox_conversation_general_text->Name = L"textBox_conversation_general_text";
		this->textBox_conversation_general_text->ScrollBars = System::Windows::Forms::ScrollBars::Both;
		this->textBox_conversation_general_text->Size = System::Drawing::Size(348, 119);
		this->textBox_conversation_general_text->TabIndex = 3;
		this->textBox_conversation_general_text->Leave += gcnew System::EventHandler(this, &MainWindow::change_conversation_general_text);
		// 
		// label42
		// 
		this->label42->AutoSize = true;
		this->label42->Location = System::Drawing::Point(314, 19);
		this->label42->Name = L"label42";
		this->label42->Size = System::Drawing::Size(31, 13);
		this->label42->TabIndex = 2;
		this->label42->Text = L"Text:";
		// 
		// label40
		// 
		this->label40->AutoSize = true;
		this->label40->Location = System::Drawing::Point(3, 19);
		this->label40->Name = L"label40";
		this->label40->Size = System::Drawing::Size(43, 13);
		this->label40->TabIndex = 0;
		this->label40->Text = L"Prompt:";
		// 
		// textBox_conversation_prompt_text
		// 
		this->textBox_conversation_prompt_text->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
			| System::Windows::Forms::AnchorStyles::Left));
		this->textBox_conversation_prompt_text->Location = System::Drawing::Point(6, 35);
		this->textBox_conversation_prompt_text->Multiline = true;
		this->textBox_conversation_prompt_text->Name = L"textBox_conversation_prompt_text";
		this->textBox_conversation_prompt_text->ScrollBars = System::Windows::Forms::ScrollBars::Both;
		this->textBox_conversation_prompt_text->Size = System::Drawing::Size(305, 119);
		this->textBox_conversation_prompt_text->TabIndex = 1;
		this->textBox_conversation_prompt_text->Leave += gcnew System::EventHandler(this, &MainWindow::change_conversation_prompt_text);
		// 
		// groupBox_answers
		// 
		this->groupBox_answers->Controls->Add(this->textBox_conversation_answer_text);
		this->groupBox_answers->Controls->Add(this->textBox_conversation_answer_task_link);
		this->groupBox_answers->Controls->Add(this->label46);
		this->groupBox_answers->Controls->Add(this->textBox_conversation_answer_question_link);
		this->groupBox_answers->Controls->Add(this->label47);
		this->groupBox_answers->Controls->Add(this->listBox_conversation_answers);
		this->groupBox_answers->Location = System::Drawing::Point(3, 431);
		this->groupBox_answers->Name = L"groupBox_answers";
		this->groupBox_answers->Size = System::Drawing::Size(671, 132);
		this->groupBox_answers->TabIndex = 3;
		this->groupBox_answers->TabStop = false;
		this->groupBox_answers->Text = L"ANSWERS";
		// 
		// textBox_conversation_answer_text
		// 
		this->textBox_conversation_answer_text->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
			| System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->textBox_conversation_answer_text->Location = System::Drawing::Point(178, 19);
		this->textBox_conversation_answer_text->MaxLength = 63;
		this->textBox_conversation_answer_text->Multiline = true;
		this->textBox_conversation_answer_text->Name = L"textBox_conversation_answer_text";
		this->textBox_conversation_answer_text->ScrollBars = System::Windows::Forms::ScrollBars::Both;
		this->textBox_conversation_answer_text->Size = System::Drawing::Size(487, 107);
		this->textBox_conversation_answer_text->TabIndex = 5;
		this->textBox_conversation_answer_text->Leave += gcnew System::EventHandler(this, &MainWindow::change_conversation_answer_text);
		// 
		// textBox_conversation_answer_task_link
		// 
		this->textBox_conversation_answer_task_link->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
		this->textBox_conversation_answer_task_link->Location = System::Drawing::Point(84, 106);
		this->textBox_conversation_answer_task_link->Name = L"textBox_conversation_answer_task_link";
		this->textBox_conversation_answer_task_link->Size = System::Drawing::Size(88, 20);
		this->textBox_conversation_answer_task_link->TabIndex = 4;
		this->textBox_conversation_answer_task_link->Leave += gcnew System::EventHandler(this, &MainWindow::change_conversation_answer_task_link);
		// 
		// label46
		// 
		this->label46->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
		this->label46->AutoSize = true;
		this->label46->Location = System::Drawing::Point(3, 109);
		this->label46->Name = L"label46";
		this->label46->Size = System::Drawing::Size(57, 13);
		this->label46->TabIndex = 3;
		this->label46->Text = L"Task Link:";
		// 
		// textBox_conversation_answer_question_link
		// 
		this->textBox_conversation_answer_question_link->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
		this->textBox_conversation_answer_question_link->Location = System::Drawing::Point(84, 80);
		this->textBox_conversation_answer_question_link->Name = L"textBox_conversation_answer_question_link";
		this->textBox_conversation_answer_question_link->Size = System::Drawing::Size(88, 20);
		this->textBox_conversation_answer_question_link->TabIndex = 2;
		this->textBox_conversation_answer_question_link->Leave += gcnew System::EventHandler(this, &MainWindow::change_conversation_answer_question_link);
		// 
		// label47
		// 
		this->label47->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
		this->label47->AutoSize = true;
		this->label47->Location = System::Drawing::Point(3, 83);
		this->label47->Name = L"label47";
		this->label47->Size = System::Drawing::Size(75, 13);
		this->label47->TabIndex = 1;
		this->label47->Text = L"Question Link:";
		// 
		// listBox_conversation_answers
		// 
		this->listBox_conversation_answers->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
			| System::Windows::Forms::AnchorStyles::Left));
		this->listBox_conversation_answers->ContextMenuStrip = this->contextMenuStrip_conversation_answer;
		this->listBox_conversation_answers->FormattingEnabled = true;
		this->listBox_conversation_answers->Location = System::Drawing::Point(6, 19);
		this->listBox_conversation_answers->Name = L"listBox_conversation_answers";
		this->listBox_conversation_answers->Size = System::Drawing::Size(166, 56);
		this->listBox_conversation_answers->TabIndex = 0;
		this->listBox_conversation_answers->SelectedIndexChanged += gcnew System::EventHandler(this, &MainWindow::select_answer);
		// 
		// contextMenuStrip_conversation_answer
		// 
		this->contextMenuStrip_conversation_answer->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->toolStripMenuItem46, 
			this->toolStripMenuItem47});
		this->contextMenuStrip_conversation_answer->Name = L"contextMenuStrip_conversation";
		this->contextMenuStrip_conversation_answer->RenderMode = System::Windows::Forms::ToolStripRenderMode::System;
		this->contextMenuStrip_conversation_answer->ShowImageMargin = false;
		this->contextMenuStrip_conversation_answer->Size = System::Drawing::Size(120, 48);
		// 
		// toolStripMenuItem46
		// 
		this->toolStripMenuItem46->Name = L"toolStripMenuItem46";
		this->toolStripMenuItem46->Size = System::Drawing::Size(119, 22);
		this->toolStripMenuItem46->Text = L"Add Answer";
		this->toolStripMenuItem46->Click += gcnew System::EventHandler(this, &MainWindow::add_answer);
		// 
		// toolStripMenuItem47
		// 
		this->toolStripMenuItem47->Name = L"toolStripMenuItem47";
		this->toolStripMenuItem47->Size = System::Drawing::Size(119, 22);
		this->toolStripMenuItem47->Text = L"Delete Answer";
		this->toolStripMenuItem47->Click += gcnew System::EventHandler(this, &MainWindow::remove_answer);
		// 
		// contextMenuStrip_conversation_question
		// 
		this->contextMenuStrip_conversation_question->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->addToolStripMenuItem, 
			this->removeToolStripMenuItem});
		this->contextMenuStrip_conversation_question->Name = L"contextMenuStrip_conversation";
		this->contextMenuStrip_conversation_question->RenderMode = System::Windows::Forms::ToolStripRenderMode::System;
		this->contextMenuStrip_conversation_question->ShowImageMargin = false;
		this->contextMenuStrip_conversation_question->Size = System::Drawing::Size(127, 48);
		// 
		// addToolStripMenuItem
		// 
		this->addToolStripMenuItem->Name = L"addToolStripMenuItem";
		this->addToolStripMenuItem->Size = System::Drawing::Size(126, 22);
		this->addToolStripMenuItem->Text = L"Add Question";
		this->addToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::add_question);
		// 
		// removeToolStripMenuItem
		// 
		this->removeToolStripMenuItem->Name = L"removeToolStripMenuItem";
		this->removeToolStripMenuItem->Size = System::Drawing::Size(126, 22);
		this->removeToolStripMenuItem->Text = L"Delete Question";
		this->removeToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::remove_question);
		// 
		// groupBox_questions
		// 
		this->groupBox_questions->Controls->Add(this->textBox_conversation_question_text);
		this->groupBox_questions->Controls->Add(this->textBox_conversation_question_previous);
		this->groupBox_questions->Controls->Add(this->label45);
		this->groupBox_questions->Controls->Add(this->textBox_conversation_question_id);
		this->groupBox_questions->Controls->Add(this->label44);
		this->groupBox_questions->Controls->Add(this->listBox_conversation_questions);
		this->groupBox_questions->Location = System::Drawing::Point(3, 293);
		this->groupBox_questions->Name = L"groupBox_questions";
		this->groupBox_questions->Size = System::Drawing::Size(671, 132);
		this->groupBox_questions->TabIndex = 2;
		this->groupBox_questions->TabStop = false;
		this->groupBox_questions->Text = L"QUESTIONS";
		// 
		// textBox_conversation_question_text
		// 
		this->textBox_conversation_question_text->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
			| System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->textBox_conversation_question_text->Location = System::Drawing::Point(178, 19);
		this->textBox_conversation_question_text->Multiline = true;
		this->textBox_conversation_question_text->Name = L"textBox_conversation_question_text";
		this->textBox_conversation_question_text->ScrollBars = System::Windows::Forms::ScrollBars::Both;
		this->textBox_conversation_question_text->Size = System::Drawing::Size(487, 107);
		this->textBox_conversation_question_text->TabIndex = 5;
		this->textBox_conversation_question_text->Leave += gcnew System::EventHandler(this, &MainWindow::change_conversation_question_text);
		// 
		// textBox_conversation_question_previous
		// 
		this->textBox_conversation_question_previous->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
		this->textBox_conversation_question_previous->Location = System::Drawing::Point(84, 106);
		this->textBox_conversation_question_previous->Name = L"textBox_conversation_question_previous";
		this->textBox_conversation_question_previous->Size = System::Drawing::Size(88, 20);
		this->textBox_conversation_question_previous->TabIndex = 4;
		this->textBox_conversation_question_previous->Leave += gcnew System::EventHandler(this, &MainWindow::change_conversation_question_previous);
		// 
		// label45
		// 
		this->label45->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
		this->label45->AutoSize = true;
		this->label45->Location = System::Drawing::Point(3, 109);
		this->label45->Name = L"label45";
		this->label45->Size = System::Drawing::Size(51, 13);
		this->label45->TabIndex = 3;
		this->label45->Text = L"Previous:";
		// 
		// textBox_conversation_question_id
		// 
		this->textBox_conversation_question_id->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
		this->textBox_conversation_question_id->Location = System::Drawing::Point(84, 80);
		this->textBox_conversation_question_id->Name = L"textBox_conversation_question_id";
		this->textBox_conversation_question_id->Size = System::Drawing::Size(88, 20);
		this->textBox_conversation_question_id->TabIndex = 2;
		this->textBox_conversation_question_id->Leave += gcnew System::EventHandler(this, &MainWindow::change_conversation_question_id);
		// 
		// label44
		// 
		this->label44->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
		this->label44->AutoSize = true;
		this->label44->Location = System::Drawing::Point(3, 83);
		this->label44->Name = L"label44";
		this->label44->Size = System::Drawing::Size(21, 13);
		this->label44->TabIndex = 1;
		this->label44->Text = L"ID:";
		// 
		// listBox_conversation_questions
		// 
		this->listBox_conversation_questions->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
			| System::Windows::Forms::AnchorStyles::Left));
		this->listBox_conversation_questions->ContextMenuStrip = this->contextMenuStrip_conversation_question;
		this->listBox_conversation_questions->FormattingEnabled = true;
		this->listBox_conversation_questions->Location = System::Drawing::Point(6, 19);
		this->listBox_conversation_questions->Name = L"listBox_conversation_questions";
		this->listBox_conversation_questions->Size = System::Drawing::Size(166, 56);
		this->listBox_conversation_questions->TabIndex = 0;
		this->listBox_conversation_questions->SelectedIndexChanged += gcnew System::EventHandler(this, &MainWindow::select_question);
		// 
		// groupBox_dialogs
		// 
		this->groupBox_dialogs->Controls->Add(this->textBox_conversation_dialog_text);
		this->groupBox_dialogs->Controls->Add(this->textBox_conversation_dialog_unknown);
		this->groupBox_dialogs->Controls->Add(this->label43);
		this->groupBox_dialogs->Controls->Add(this->listBox_conversation_dialogs);
		this->groupBox_dialogs->Location = System::Drawing::Point(3, 168);
		this->groupBox_dialogs->Name = L"groupBox_dialogs";
		this->groupBox_dialogs->Size = System::Drawing::Size(671, 119);
		this->groupBox_dialogs->TabIndex = 1;
		this->groupBox_dialogs->TabStop = false;
		this->groupBox_dialogs->Text = L"DIALOGS";
		// 
		// textBox_conversation_dialog_text
		// 
		this->textBox_conversation_dialog_text->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
			| System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->textBox_conversation_dialog_text->Location = System::Drawing::Point(178, 19);
		this->textBox_conversation_dialog_text->MaxLength = 63;
		this->textBox_conversation_dialog_text->Multiline = true;
		this->textBox_conversation_dialog_text->Name = L"textBox_conversation_dialog_text";
		this->textBox_conversation_dialog_text->ScrollBars = System::Windows::Forms::ScrollBars::Both;
		this->textBox_conversation_dialog_text->Size = System::Drawing::Size(487, 94);
		this->textBox_conversation_dialog_text->TabIndex = 3;
		this->textBox_conversation_dialog_text->Leave += gcnew System::EventHandler(this, &MainWindow::change_conversation_dialog_text);
		// 
		// textBox_conversation_dialog_unknown
		// 
		this->textBox_conversation_dialog_unknown->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
		this->textBox_conversation_dialog_unknown->Location = System::Drawing::Point(84, 93);
		this->textBox_conversation_dialog_unknown->Name = L"textBox_conversation_dialog_unknown";
		this->textBox_conversation_dialog_unknown->Size = System::Drawing::Size(88, 20);
		this->textBox_conversation_dialog_unknown->TabIndex = 2;
		this->textBox_conversation_dialog_unknown->Leave += gcnew System::EventHandler(this, &MainWindow::change_conversation_dialog_unknown);
		// 
		// label43
		// 
		this->label43->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
		this->label43->AutoSize = true;
		this->label43->Location = System::Drawing::Point(3, 96);
		this->label43->Name = L"label43";
		this->label43->Size = System::Drawing::Size(56, 13);
		this->label43->TabIndex = 1;
		this->label43->Text = L"Unknown:";
		// 
		// listBox_conversation_dialogs
		// 
		this->listBox_conversation_dialogs->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
			| System::Windows::Forms::AnchorStyles::Left));
		this->listBox_conversation_dialogs->FormattingEnabled = true;
		this->listBox_conversation_dialogs->Items->AddRange(gcnew cli::array< System::Object^  >(5) {L"[1] Dialog", L"[2] Dialog", 
			L"[3] Dialog", L"[4] Dialog", L"[5] Dialog"});
		this->listBox_conversation_dialogs->Location = System::Drawing::Point(6, 19);
		this->listBox_conversation_dialogs->Name = L"listBox_conversation_dialogs";
		this->listBox_conversation_dialogs->Size = System::Drawing::Size(166, 69);
		this->listBox_conversation_dialogs->TabIndex = 0;
		this->listBox_conversation_dialogs->SelectedIndexChanged += gcnew System::EventHandler(this, &MainWindow::select_dialog);
		// 
		// toolTip
		// 
		this->toolTip->AutomaticDelay = 0;
		this->toolTip->AutoPopDelay = 10000;
		this->toolTip->InitialDelay = 0;
		this->toolTip->ReshowDelay = 0;
		// 
		// label106
		// 
		this->label106->AutoSize = true;
		this->label106->Location = System::Drawing::Point(6, 19);
		this->label106->Name = L"label106";
		this->label106->Size = System::Drawing::Size(62, 13);
		this->label106->TabIndex = 89;
		this->label106->Text = L"Has Spans:";
		this->toolTip->SetToolTip(this->label106, L"If version < 89 there must be exactly one location span!");
		// 
		// label107
		// 
		this->label107->AutoSize = true;
		this->label107->Location = System::Drawing::Point(6, 42);
		this->label107->Name = L"label107";
		this->label107->Size = System::Drawing::Size(45, 13);
		this->label107->TabIndex = 93;
		this->label107->Text = L"Map ID:";
		this->toolTip->SetToolTip(this->label107, L"If version < 89 there must be exactly one location span!");
		// 
		// label10
		// 
		this->label10->AutoSize = true;
		this->label10->Location = System::Drawing::Point(6, 68);
		this->label10->Name = L"label10";
		this->label10->Size = System::Drawing::Size(65, 13);
		this->label10->TabIndex = 89;
		this->label10->Text = L"Unknown 1:";
		this->toolTip->SetToolTip(this->label10, L"If version < 89 there must be exactly one location span!");
		// 
		// label11
		// 
		this->label11->AutoSize = true;
		this->label11->Location = System::Drawing::Point(6, 42);
		this->label11->Name = L"label11";
		this->label11->Size = System::Drawing::Size(45, 13);
		this->label11->TabIndex = 93;
		this->label11->Text = L"Map ID:";
		this->toolTip->SetToolTip(this->label11, L"If version < 89 there must be exactly one location span!");
		// 
		// label12
		// 
		this->label12->AutoSize = true;
		this->label12->Location = System::Drawing::Point(6, 68);
		this->label12->Name = L"label12";
		this->label12->Size = System::Drawing::Size(65, 13);
		this->label12->TabIndex = 89;
		this->label12->Text = L"Unknown 1:";
		this->toolTip->SetToolTip(this->label12, L"If version < 89 there must be exactly one location span!");
		// 
		// label13
		// 
		this->label13->AutoSize = true;
		this->label13->Location = System::Drawing::Point(6, 42);
		this->label13->Name = L"label13";
		this->label13->Size = System::Drawing::Size(45, 13);
		this->label13->TabIndex = 93;
		this->label13->Text = L"Map ID:";
		this->toolTip->SetToolTip(this->label13, L"If version < 89 there must be exactly one location span!");
		// 
		// label14
		// 
		this->label14->AutoSize = true;
		this->label14->Location = System::Drawing::Point(6, 68);
		this->label14->Name = L"label14";
		this->label14->Size = System::Drawing::Size(65, 13);
		this->label14->TabIndex = 95;
		this->label14->Text = L"Unknown 1:";
		this->toolTip->SetToolTip(this->label14, L"If version < 89 there must be exactly one location span!");
		// 
		// label15
		// 
		this->label15->AutoSize = true;
		this->label15->Location = System::Drawing::Point(6, 19);
		this->label15->Name = L"label15";
		this->label15->Size = System::Drawing::Size(62, 13);
		this->label15->TabIndex = 95;
		this->label15->Text = L"Has Spans:";
		this->toolTip->SetToolTip(this->label15, L"If version < 89 there must be exactly one location span!");
		// 
		// label53
		// 
		this->label53->AutoSize = true;
		this->label53->Location = System::Drawing::Point(6, 19);
		this->label53->Name = L"label53";
		this->label53->Size = System::Drawing::Size(62, 13);
		this->label53->TabIndex = 95;
		this->label53->Text = L"Has Spans:";
		this->toolTip->SetToolTip(this->label53, L"If version < 89 there must be exactly one location span!");
		// 
		// label48
		// 
		this->label48->AutoSize = true;
		this->label48->Cursor = System::Windows::Forms::Cursors::Help;
		this->label48->Location = System::Drawing::Point(366, 263);
		this->label48->Name = L"label48";
		this->label48->Size = System::Drawing::Size(104, 13);
		this->label48->TabIndex = 10;
		this->label48->Text = L"Unactivated Quests:";
		this->toolTip->SetToolTip(this->label48, L"The Quest can only be activated if the following Quests are not in your Quest Log" 
			L"");
		// 
		// label41
		// 
		this->label41->AutoSize = true;
		this->label41->Cursor = System::Windows::Forms::Cursors::Help;
		this->label41->Location = System::Drawing::Point(257, 263);
		this->label41->Name = L"label41";
		this->label41->Size = System::Drawing::Size(85, 13);
		this->label41->TabIndex = 164;
		this->label41->Text = L"Finished Quests:";
		this->toolTip->SetToolTip(this->label41, L"The Quest can only be activated if the following quests are completed");
		// 
		// label4
		// 
		this->label4->AutoSize = true;
		this->label4->Location = System::Drawing::Point(6, 19);
		this->label4->Name = L"label4";
		this->label4->Size = System::Drawing::Size(62, 13);
		this->label4->TabIndex = 95;
		this->label4->Text = L"Has Spans:";
		this->toolTip->SetToolTip(this->label4, L"If version < 89 there must be exactly one location span!");
		// 
		// label5
		// 
		this->label5->AutoSize = true;
		this->label5->Location = System::Drawing::Point(6, 68);
		this->label5->Name = L"label5";
		this->label5->Size = System::Drawing::Size(65, 13);
		this->label5->TabIndex = 89;
		this->label5->Text = L"Unknown 1:";
		this->toolTip->SetToolTip(this->label5, L"If version < 89 there must be exactly one location span!");
		// 
		// label6
		// 
		this->label6->AutoSize = true;
		this->label6->Location = System::Drawing::Point(6, 42);
		this->label6->Name = L"label6";
		this->label6->Size = System::Drawing::Size(45, 13);
		this->label6->TabIndex = 93;
		this->label6->Text = L"Map ID:";
		this->toolTip->SetToolTip(this->label6, L"If version < 89 there must be exactly one location span!");
		// 
		// label172
		// 
		this->label172->AutoSize = true;
		this->label172->Location = System::Drawing::Point(6, 19);
		this->label172->Name = L"label172";
		this->label172->Size = System::Drawing::Size(62, 13);
		this->label172->TabIndex = 95;
		this->label172->Text = L"Has Spans:";
		this->toolTip->SetToolTip(this->label172, L"If version < 89 there must be exactly one location span!");
		// 
		// label175
		// 
		this->label175->AutoSize = true;
		this->label175->Location = System::Drawing::Point(6, 68);
		this->label175->Name = L"label175";
		this->label175->Size = System::Drawing::Size(65, 13);
		this->label175->TabIndex = 89;
		this->label175->Text = L"Unknown 1:";
		this->toolTip->SetToolTip(this->label175, L"If version < 89 there must be exactly one location span!");
		// 
		// label176
		// 
		this->label176->AutoSize = true;
		this->label176->Location = System::Drawing::Point(6, 42);
		this->label176->Name = L"label176";
		this->label176->Size = System::Drawing::Size(45, 13);
		this->label176->TabIndex = 93;
		this->label176->Text = L"Map ID:";
		this->toolTip->SetToolTip(this->label176, L"If version < 89 there must be exactly one location span!");
		// 
		// comboBox_search
		// 
		this->comboBox_search->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
		this->comboBox_search->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
		this->comboBox_search->FormattingEnabled = true;
		this->comboBox_search->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"ID", L"Name", L"Creature Builder ID"});
		this->comboBox_search->Location = System::Drawing::Point(0, 609);
		this->comboBox_search->Name = L"comboBox_search";
		this->comboBox_search->Size = System::Drawing::Size(137, 21);
		this->comboBox_search->TabIndex = 3;
		// 
		// textBox_unknown_61
		// 
		this->textBox_unknown_61->Location = System::Drawing::Point(113, 143);
		this->textBox_unknown_61->Name = L"textBox_unknown_61";
		this->textBox_unknown_61->Size = System::Drawing::Size(552, 20);
		this->textBox_unknown_61->TabIndex = 274;
		this->textBox_unknown_61->Leave += gcnew System::EventHandler(this, &MainWindow::change_unknown_61);
		// 
		// label191
		// 
		this->label191->AutoSize = true;
		this->label191->Location = System::Drawing::Point(6, 146);
		this->label191->Name = L"label191";
		this->label191->Size = System::Drawing::Size(71, 13);
		this->label191->TabIndex = 273;
		this->label191->Text = L"Unknown 61:";
		// 
		// groupBox_basic_2
		// 
		this->groupBox_basic_2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->groupBox_basic_2->Controls->Add(this->textBox_unknown_61);
		this->groupBox_basic_2->Controls->Add(this->label191);
		this->groupBox_basic_2->Controls->Add(this->checkBox_unknown_60_01);
		this->groupBox_basic_2->Controls->Add(this->label190);
		this->groupBox_basic_2->Controls->Add(this->checkBox_unknown_60);
		this->groupBox_basic_2->Controls->Add(this->label189);
		this->groupBox_basic_2->Controls->Add(this->textBox_receive_quest_probability);
		this->groupBox_basic_2->Controls->Add(this->label105);
		this->groupBox_basic_2->Controls->Add(this->textBox_unknown_59);
		this->groupBox_basic_2->Controls->Add(this->label104);
		this->groupBox_basic_2->Controls->Add(this->textBox_unknown_58);
		this->groupBox_basic_2->Controls->Add(this->label103);
		this->groupBox_basic_2->Controls->Add(this->textBox_parent_quest);
		this->groupBox_basic_2->Controls->Add(this->textBox_sub_quest_first);
		this->groupBox_basic_2->Controls->Add(this->label52);
		this->groupBox_basic_2->Controls->Add(this->label51);
		this->groupBox_basic_2->Controls->Add(this->textBox_previous_quest);
		this->groupBox_basic_2->Controls->Add(this->label50);
		this->groupBox_basic_2->Controls->Add(this->label49);
		this->groupBox_basic_2->Controls->Add(this->textBox_next_quest);
		this->groupBox_basic_2->Location = System::Drawing::Point(3, 238);
		this->groupBox_basic_2->Name = L"groupBox_basic_2";
		this->groupBox_basic_2->Size = System::Drawing::Size(671, 168);
		this->groupBox_basic_2->TabIndex = 135;
		this->groupBox_basic_2->TabStop = false;
		this->groupBox_basic_2->Text = L"BASIC PROPERTIES II";
		// 
		// checkBox_unknown_60_01
		// 
		this->checkBox_unknown_60_01->AutoSize = true;
		this->checkBox_unknown_60_01->Location = System::Drawing::Point(229, 123);
		this->checkBox_unknown_60_01->Name = L"checkBox_unknown_60_01";
		this->checkBox_unknown_60_01->Size = System::Drawing::Size(15, 14);
		this->checkBox_unknown_60_01->TabIndex = 276;
		this->checkBox_unknown_60_01->UseVisualStyleBackColor = true;
		this->checkBox_unknown_60_01->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_unknown_60_01);
		// 
		// label190
		// 
		this->label190->AutoSize = true;
		this->label190->ForeColor = System::Drawing::Color::Red;
		this->label190->Location = System::Drawing::Point(134, 123);
		this->label190->Name = L"label190";
		this->label190->Size = System::Drawing::Size(89, 13);
		this->label190->TabIndex = 275;
		this->label190->Text = L"Unknown 60_01:";
		// 
		// checkBox_unknown_60
		// 
		this->checkBox_unknown_60->AutoSize = true;
		this->checkBox_unknown_60->Location = System::Drawing::Point(113, 123);
		this->checkBox_unknown_60->Name = L"checkBox_unknown_60";
		this->checkBox_unknown_60->Size = System::Drawing::Size(15, 14);
		this->checkBox_unknown_60->TabIndex = 274;
		this->checkBox_unknown_60->UseVisualStyleBackColor = true;
		this->checkBox_unknown_60->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_unknown_60);
		// 
		// label189
		// 
		this->label189->AutoSize = true;
		this->label189->ForeColor = System::Drawing::Color::Gray;
		this->label189->Location = System::Drawing::Point(6, 123);
		this->label189->Name = L"label189";
		this->label189->Size = System::Drawing::Size(71, 13);
		this->label189->TabIndex = 273;
		this->label189->Text = L"Unknown 60:";
		// 
		// textBox_receive_quest_probability
		// 
		this->textBox_receive_quest_probability->Location = System::Drawing::Point(113, 97);
		this->textBox_receive_quest_probability->Name = L"textBox_receive_quest_probability";
		this->textBox_receive_quest_probability->Size = System::Drawing::Size(90, 20);
		this->textBox_receive_quest_probability->TabIndex = 272;
		this->textBox_receive_quest_probability->Leave += gcnew System::EventHandler(this, &MainWindow::change_receive_quest_probability);
		// 
		// label105
		// 
		this->label105->AutoSize = true;
		this->label105->ForeColor = System::Drawing::Color::Gray;
		this->label105->Location = System::Drawing::Point(6, 100);
		this->label105->Name = L"label105";
		this->label105->Size = System::Drawing::Size(101, 13);
		this->label105->TabIndex = 271;
		this->label105->Text = L"Receive Probability:";
		// 
		// textBox_unknown_59
		// 
		this->textBox_unknown_59->Location = System::Drawing::Point(113, 45);
		this->textBox_unknown_59->Name = L"textBox_unknown_59";
		this->textBox_unknown_59->Size = System::Drawing::Size(552, 20);
		this->textBox_unknown_59->TabIndex = 270;
		this->textBox_unknown_59->Leave += gcnew System::EventHandler(this, &MainWindow::change_unknown_59);
		// 
		// label104
		// 
		this->label104->AutoSize = true;
		this->label104->Location = System::Drawing::Point(6, 48);
		this->label104->Name = L"label104";
		this->label104->Size = System::Drawing::Size(71, 13);
		this->label104->TabIndex = 269;
		this->label104->Text = L"Unknown 59:";
		// 
		// textBox_unknown_58
		// 
		this->textBox_unknown_58->Location = System::Drawing::Point(113, 19);
		this->textBox_unknown_58->Name = L"textBox_unknown_58";
		this->textBox_unknown_58->Size = System::Drawing::Size(159, 20);
		this->textBox_unknown_58->TabIndex = 268;
		this->textBox_unknown_58->Leave += gcnew System::EventHandler(this, &MainWindow::change_unknown_58);
		// 
		// label103
		// 
		this->label103->AutoSize = true;
		this->label103->Location = System::Drawing::Point(6, 22);
		this->label103->Name = L"label103";
		this->label103->Size = System::Drawing::Size(71, 13);
		this->label103->TabIndex = 267;
		this->label103->Text = L"Unknown 58:";
		// 
		// textBox_parent_quest
		// 
		this->textBox_parent_quest->Location = System::Drawing::Point(113, 71);
		this->textBox_parent_quest->Name = L"textBox_parent_quest";
		this->textBox_parent_quest->Size = System::Drawing::Size(60, 20);
		this->textBox_parent_quest->TabIndex = 60;
		this->textBox_parent_quest->Leave += gcnew System::EventHandler(this, &MainWindow::change_parent_quest);
		// 
		// textBox_sub_quest_first
		// 
		this->textBox_sub_quest_first->Location = System::Drawing::Point(559, 71);
		this->textBox_sub_quest_first->Name = L"textBox_sub_quest_first";
		this->textBox_sub_quest_first->Size = System::Drawing::Size(60, 20);
		this->textBox_sub_quest_first->TabIndex = 64;
		this->textBox_sub_quest_first->Leave += gcnew System::EventHandler(this, &MainWindow::change_sub_quest_first);
		// 
		// label52
		// 
		this->label52->AutoSize = true;
		this->label52->Location = System::Drawing::Point(468, 74);
		this->label52->Name = L"label52";
		this->label52->Size = System::Drawing::Size(85, 13);
		this->label52->TabIndex = 63;
		this->label52->Text = L"SubQuest (First):";
		// 
		// label51
		// 
		this->label51->AutoSize = true;
		this->label51->Location = System::Drawing::Point(333, 74);
		this->label51->Name = L"label51";
		this->label51->Size = System::Drawing::Size(63, 13);
		this->label51->TabIndex = 65;
		this->label51->Text = L"Next Quest:";
		// 
		// textBox_previous_quest
		// 
		this->textBox_previous_quest->Location = System::Drawing::Point(267, 71);
		this->textBox_previous_quest->Name = L"textBox_previous_quest";
		this->textBox_previous_quest->Size = System::Drawing::Size(60, 20);
		this->textBox_previous_quest->TabIndex = 62;
		this->textBox_previous_quest->Leave += gcnew System::EventHandler(this, &MainWindow::change_previous_quest);
		// 
		// label50
		// 
		this->label50->AutoSize = true;
		this->label50->Location = System::Drawing::Point(179, 74);
		this->label50->Name = L"label50";
		this->label50->Size = System::Drawing::Size(82, 13);
		this->label50->TabIndex = 61;
		this->label50->Text = L"Previous Quest:";
		// 
		// label49
		// 
		this->label49->AutoSize = true;
		this->label49->Location = System::Drawing::Point(6, 74);
		this->label49->Name = L"label49";
		this->label49->Size = System::Drawing::Size(72, 13);
		this->label49->TabIndex = 59;
		this->label49->Text = L"Parent Quest:";
		// 
		// textBox_next_quest
		// 
		this->textBox_next_quest->Location = System::Drawing::Point(402, 71);
		this->textBox_next_quest->Name = L"textBox_next_quest";
		this->textBox_next_quest->Size = System::Drawing::Size(60, 20);
		this->textBox_next_quest->TabIndex = 66;
		this->textBox_next_quest->Leave += gcnew System::EventHandler(this, &MainWindow::change_next_quest);
		// 
		// groupBox_pq_exit_area
		// 
		this->groupBox_pq_exit_area->Controls->Add(this->textBox_pq_required_quests_completed);
		this->groupBox_pq_exit_area->Controls->Add(this->label231);
		this->groupBox_pq_exit_area->Controls->Add(this->dataGridView_pq_messages);
		this->groupBox_pq_exit_area->Controls->Add(this->label188);
		this->groupBox_pq_exit_area->Controls->Add(this->label187);
		this->groupBox_pq_exit_area->Controls->Add(this->textBox_pq_unknown_20);
		this->groupBox_pq_exit_area->Controls->Add(this->label186);
		this->groupBox_pq_exit_area->Controls->Add(this->textBox_pq_unknown_19);
		this->groupBox_pq_exit_area->Controls->Add(this->label185);
		this->groupBox_pq_exit_area->Controls->Add(this->textBox_pq_unknown_18);
		this->groupBox_pq_exit_area->Controls->Add(this->label184);
		this->groupBox_pq_exit_area->Controls->Add(this->dataGridView_pq_special_scripts);
		this->groupBox_pq_exit_area->Controls->Add(this->label183);
		this->groupBox_pq_exit_area->Controls->Add(this->label182);
		this->groupBox_pq_exit_area->Controls->Add(this->textBox_pq_unknown_16);
		this->groupBox_pq_exit_area->Controls->Add(this->textBox_pq_unknown_17);
		this->groupBox_pq_exit_area->Controls->Add(this->label181);
		this->groupBox_pq_exit_area->Controls->Add(this->textBox_pq_unknown_15);
		this->groupBox_pq_exit_area->Controls->Add(this->label180);
		this->groupBox_pq_exit_area->Controls->Add(this->textBox_pq_unknown_14);
		this->groupBox_pq_exit_area->Controls->Add(this->label179);
		this->groupBox_pq_exit_area->Controls->Add(this->textBox_pq_id_script);
		this->groupBox_pq_exit_area->Controls->Add(this->label178);
		this->groupBox_pq_exit_area->Controls->Add(this->textBox_pq_unknown_13);
		this->groupBox_pq_exit_area->Controls->Add(this->label177);
		this->groupBox_pq_exit_area->Controls->Add(this->textBox_pq_unknown_12);
		this->groupBox_pq_exit_area->Controls->Add(this->label173);
		this->groupBox_pq_exit_area->Controls->Add(this->textBox_pq_unknown_11);
		this->groupBox_pq_exit_area->Controls->Add(this->label174);
		this->groupBox_pq_exit_area->Controls->Add(this->textBox_pq_unknown_10);
		this->groupBox_pq_exit_area->Controls->Add(this->label169);
		this->groupBox_pq_exit_area->Controls->Add(this->textBox_pq_unknown_9);
		this->groupBox_pq_exit_area->Controls->Add(this->label170);
		this->groupBox_pq_exit_area->Controls->Add(this->textBox_pq_unknown_8);
		this->groupBox_pq_exit_area->Controls->Add(this->label171);
		this->groupBox_pq_exit_area->Controls->Add(this->textBox_pq_unknown_7);
		this->groupBox_pq_exit_area->Controls->Add(this->label168);
		this->groupBox_pq_exit_area->Controls->Add(this->dataGridView_pq_chases);
		this->groupBox_pq_exit_area->Controls->Add(this->label167);
		this->groupBox_pq_exit_area->Controls->Add(this->textBox_pq_unknown_6);
		this->groupBox_pq_exit_area->Controls->Add(this->label166);
		this->groupBox_pq_exit_area->Controls->Add(this->textBox_pq_unknown_5);
		this->groupBox_pq_exit_area->Controls->Add(this->label164);
		this->groupBox_pq_exit_area->Controls->Add(this->textBox_pq_unknown_4);
		this->groupBox_pq_exit_area->Controls->Add(this->label75);
		this->groupBox_pq_exit_area->Controls->Add(this->dataGridView_pq_scripts);
		this->groupBox_pq_exit_area->Controls->Add(this->textBox_pq_unknown_2);
		this->groupBox_pq_exit_area->Controls->Add(this->label8);
		this->groupBox_pq_exit_area->Controls->Add(this->textBox_pq_unknown_1);
		this->groupBox_pq_exit_area->Controls->Add(this->label9);
		this->groupBox_pq_exit_area->Controls->Add(this->label54);
		this->groupBox_pq_exit_area->Controls->Add(this->textBox_pq_unknown_3);
		this->groupBox_pq_exit_area->Controls->Add(this->label7);
		this->groupBox_pq_exit_area->Controls->Add(this->dataGridView_pq_script_infos);
		this->groupBox_pq_exit_area->ForeColor = System::Drawing::Color::Gray;
		this->groupBox_pq_exit_area->Location = System::Drawing::Point(3, 3);
		this->groupBox_pq_exit_area->Name = L"groupBox_pq_exit_area";
		this->groupBox_pq_exit_area->Size = System::Drawing::Size(655, 836);
		this->groupBox_pq_exit_area->TabIndex = 134;
		this->groupBox_pq_exit_area->TabStop = false;
		this->groupBox_pq_exit_area->Text = L"AUDIT";
		// 
		// textBox_pq_required_quests_completed
		// 
		this->textBox_pq_required_quests_completed->Location = System::Drawing::Point(573, 276);
		this->textBox_pq_required_quests_completed->Name = L"textBox_pq_required_quests_completed";
		this->textBox_pq_required_quests_completed->Size = System::Drawing::Size(63, 20);
		this->textBox_pq_required_quests_completed->TabIndex = 319;
		this->textBox_pq_required_quests_completed->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->textBox_pq_required_quests_completed->Leave += gcnew System::EventHandler(this, &MainWindow::change_pq_required_quests_completed);
		// 
		// label231
		// 
		this->label231->AutoSize = true;
		this->label231->Location = System::Drawing::Point(428, 279);
		this->label231->Name = L"label231";
		this->label231->Size = System::Drawing::Size(142, 13);
		this->label231->TabIndex = 318;
		this->label231->Text = L"Required Quests Completed:";
		// 
		// dataGridView_pq_messages
		// 
		this->dataGridView_pq_messages->AllowUserToAddRows = false;
		this->dataGridView_pq_messages->AllowUserToDeleteRows = false;
		this->dataGridView_pq_messages->BackgroundColor = System::Drawing::SystemColors::Window;
		this->dataGridView_pq_messages->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
		this->dataGridView_pq_messages->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
		this->dataGridView_pq_messages->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) {this->dataGridViewTextBoxColumn87});
		this->dataGridView_pq_messages->ContextMenuStrip = this->contextMenuStrip_pq_messages;
		this->dataGridView_pq_messages->Location = System::Drawing::Point(98, 702);
		this->dataGridView_pq_messages->MultiSelect = false;
		this->dataGridView_pq_messages->Name = L"dataGridView_pq_messages";
		this->dataGridView_pq_messages->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
		dataGridViewCellStyle22->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
		dataGridViewCellStyle22->BackColor = System::Drawing::SystemColors::Control;
		dataGridViewCellStyle22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		dataGridViewCellStyle22->ForeColor = System::Drawing::SystemColors::WindowText;
		dataGridViewCellStyle22->SelectionBackColor = System::Drawing::SystemColors::Highlight;
		dataGridViewCellStyle22->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
		dataGridViewCellStyle22->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView_pq_messages->RowHeadersDefaultCellStyle = dataGridViewCellStyle22;
		this->dataGridView_pq_messages->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::AutoSizeToFirstHeader;
		this->dataGridView_pq_messages->RowTemplate->Height = 18;
		this->dataGridView_pq_messages->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView_pq_messages->Size = System::Drawing::Size(492, 98);
		this->dataGridView_pq_messages->TabIndex = 317;
		this->dataGridView_pq_messages->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::change_pq_messages);
		// 
		// dataGridViewTextBoxColumn87
		// 
		this->dataGridViewTextBoxColumn87->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
		dataGridViewCellStyle21->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
		this->dataGridViewTextBoxColumn87->DefaultCellStyle = dataGridViewCellStyle21;
		this->dataGridViewTextBoxColumn87->HeaderText = L"Text";
		this->dataGridViewTextBoxColumn87->Name = L"dataGridViewTextBoxColumn87";
		this->dataGridViewTextBoxColumn87->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		// 
		// contextMenuStrip_pq_messages
		// 
		this->contextMenuStrip_pq_messages->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->toolStripMenuItem36, 
			this->toolStripMenuItem37});
		this->contextMenuStrip_pq_messages->Name = L"contextMenuStrip1";
		this->contextMenuStrip_pq_messages->Size = System::Drawing::Size(159, 48);
		// 
		// toolStripMenuItem36
		// 
		this->toolStripMenuItem36->Name = L"toolStripMenuItem36";
		this->toolStripMenuItem36->Size = System::Drawing::Size(158, 22);
		this->toolStripMenuItem36->Text = L"Add Message";
		this->toolStripMenuItem36->Click += gcnew System::EventHandler(this, &MainWindow::add_pq_message);
		// 
		// toolStripMenuItem37
		// 
		this->toolStripMenuItem37->Name = L"toolStripMenuItem37";
		this->toolStripMenuItem37->Size = System::Drawing::Size(158, 22);
		this->toolStripMenuItem37->Text = L"Remove Message";
		this->toolStripMenuItem37->Click += gcnew System::EventHandler(this, &MainWindow::remove_pq_message);
		// 
		// label188
		// 
		this->label188->AutoSize = true;
		this->label188->Location = System::Drawing::Point(10, 705);
		this->label188->Name = L"label188";
		this->label188->Size = System::Drawing::Size(58, 13);
		this->label188->TabIndex = 316;
		this->label188->Text = L"Messages:";
		// 
		// label187
		// 
		this->label187->AutoSize = true;
		this->label187->Location = System::Drawing::Point(-1, 810);
		this->label187->Name = L"label187";
		this->label187->Size = System::Drawing::Size(71, 13);
		this->label187->TabIndex = 314;
		this->label187->Text = L"Unknown 20:";
		// 
		// textBox_pq_unknown_20
		// 
		this->textBox_pq_unknown_20->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
		this->textBox_pq_unknown_20->Location = System::Drawing::Point(144, 807);
		this->textBox_pq_unknown_20->Name = L"textBox_pq_unknown_20";
		this->textBox_pq_unknown_20->Size = System::Drawing::Size(112, 20);
		this->textBox_pq_unknown_20->TabIndex = 315;
		this->textBox_pq_unknown_20->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->textBox_pq_unknown_20->Leave += gcnew System::EventHandler(this, &MainWindow::change_pq_unknown_20);
		// 
		// label186
		// 
		this->label186->AutoSize = true;
		this->label186->Location = System::Drawing::Point(9, 674);
		this->label186->Name = L"label186";
		this->label186->Size = System::Drawing::Size(71, 13);
		this->label186->TabIndex = 312;
		this->label186->Text = L"Unknown 19:";
		// 
		// textBox_pq_unknown_19
		// 
		this->textBox_pq_unknown_19->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
		this->textBox_pq_unknown_19->Location = System::Drawing::Point(154, 671);
		this->textBox_pq_unknown_19->Name = L"textBox_pq_unknown_19";
		this->textBox_pq_unknown_19->Size = System::Drawing::Size(112, 20);
		this->textBox_pq_unknown_19->TabIndex = 313;
		this->textBox_pq_unknown_19->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->textBox_pq_unknown_19->Leave += gcnew System::EventHandler(this, &MainWindow::change_pq_unknown_19);
		// 
		// label185
		// 
		this->label185->AutoSize = true;
		this->label185->Location = System::Drawing::Point(13, 648);
		this->label185->Name = L"label185";
		this->label185->Size = System::Drawing::Size(71, 13);
		this->label185->TabIndex = 310;
		this->label185->Text = L"Unknown 18:";
		// 
		// textBox_pq_unknown_18
		// 
		this->textBox_pq_unknown_18->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
		this->textBox_pq_unknown_18->Location = System::Drawing::Point(158, 645);
		this->textBox_pq_unknown_18->Name = L"textBox_pq_unknown_18";
		this->textBox_pq_unknown_18->Size = System::Drawing::Size(112, 20);
		this->textBox_pq_unknown_18->TabIndex = 311;
		this->textBox_pq_unknown_18->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->textBox_pq_unknown_18->Leave += gcnew System::EventHandler(this, &MainWindow::change_pq_unknown_18);
		// 
		// label184
		// 
		this->label184->AutoSize = true;
		this->label184->Location = System::Drawing::Point(20, 534);
		this->label184->Name = L"label184";
		this->label184->Size = System::Drawing::Size(80, 13);
		this->label184->TabIndex = 308;
		this->label184->Text = L"Special Scripts:";
		// 
		// dataGridView_pq_special_scripts
		// 
		this->dataGridView_pq_special_scripts->AllowUserToAddRows = false;
		this->dataGridView_pq_special_scripts->AllowUserToDeleteRows = false;
		this->dataGridView_pq_special_scripts->BackgroundColor = System::Drawing::SystemColors::Window;
		this->dataGridView_pq_special_scripts->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
		this->dataGridView_pq_special_scripts->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
		this->dataGridView_pq_special_scripts->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {this->dataGridViewTextBoxColumn81, 
			this->dataGridViewTextBoxColumn82, this->dataGridViewTextBoxColumn83, this->dataGridViewTextBoxColumn84, this->dataGridViewTextBoxColumn85, 
			this->dataGridViewTextBoxColumn86});
		this->dataGridView_pq_special_scripts->ContextMenuStrip = this->contextMenuStrip_pq_special_scripts;
		this->dataGridView_pq_special_scripts->Location = System::Drawing::Point(107, 529);
		this->dataGridView_pq_special_scripts->MultiSelect = false;
		this->dataGridView_pq_special_scripts->Name = L"dataGridView_pq_special_scripts";
		this->dataGridView_pq_special_scripts->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
		dataGridViewCellStyle25->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
		dataGridViewCellStyle25->BackColor = System::Drawing::SystemColors::Control;
		dataGridViewCellStyle25->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		dataGridViewCellStyle25->ForeColor = System::Drawing::SystemColors::WindowText;
		dataGridViewCellStyle25->SelectionBackColor = System::Drawing::SystemColors::Highlight;
		dataGridViewCellStyle25->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
		dataGridViewCellStyle25->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView_pq_special_scripts->RowHeadersDefaultCellStyle = dataGridViewCellStyle25;
		this->dataGridView_pq_special_scripts->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::AutoSizeToFirstHeader;
		this->dataGridView_pq_special_scripts->RowTemplate->Height = 18;
		this->dataGridView_pq_special_scripts->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView_pq_special_scripts->Size = System::Drawing::Size(497, 110);
		this->dataGridView_pq_special_scripts->TabIndex = 309;
		this->dataGridView_pq_special_scripts->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::change_pq_special_scripts);
		// 
		// dataGridViewTextBoxColumn81
		// 
		this->dataGridViewTextBoxColumn81->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle23->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn81->DefaultCellStyle = dataGridViewCellStyle23;
		this->dataGridViewTextBoxColumn81->HeaderText = L"Name";
		this->dataGridViewTextBoxColumn81->Name = L"dataGridViewTextBoxColumn81";
		this->dataGridViewTextBoxColumn81->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn81->Width = 40;
		// 
		// dataGridViewTextBoxColumn82
		// 
		this->dataGridViewTextBoxColumn82->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle24->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn82->DefaultCellStyle = dataGridViewCellStyle24;
		this->dataGridViewTextBoxColumn82->HeaderText = L"Count";
		this->dataGridViewTextBoxColumn82->Name = L"dataGridViewTextBoxColumn82";
		this->dataGridViewTextBoxColumn82->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn82->Width = 40;
		// 
		// dataGridViewTextBoxColumn83
		// 
		this->dataGridViewTextBoxColumn83->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		this->dataGridViewTextBoxColumn83->HeaderText = L"ID";
		this->dataGridViewTextBoxColumn83->Name = L"dataGridViewTextBoxColumn83";
		this->dataGridViewTextBoxColumn83->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn83->Width = 23;
		// 
		// dataGridViewTextBoxColumn84
		// 
		this->dataGridViewTextBoxColumn84->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		this->dataGridViewTextBoxColumn84->HeaderText = L"Seperator";
		this->dataGridViewTextBoxColumn84->Name = L"dataGridViewTextBoxColumn84";
		this->dataGridViewTextBoxColumn84->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn84->Width = 58;
		// 
		// dataGridViewTextBoxColumn85
		// 
		this->dataGridViewTextBoxColumn85->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		this->dataGridViewTextBoxColumn85->HeaderText = L"Ref. ID";
		this->dataGridViewTextBoxColumn85->Name = L"dataGridViewTextBoxColumn85";
		this->dataGridViewTextBoxColumn85->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn85->Width = 46;
		// 
		// dataGridViewTextBoxColumn86
		// 
		this->dataGridViewTextBoxColumn86->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
		this->dataGridViewTextBoxColumn86->HeaderText = L"Source Code";
		this->dataGridViewTextBoxColumn86->Name = L"dataGridViewTextBoxColumn86";
		this->dataGridViewTextBoxColumn86->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		// 
		// contextMenuStrip_pq_special_scripts
		// 
		this->contextMenuStrip_pq_special_scripts->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->toolStripMenuItem34, 
			this->toolStripMenuItem35});
		this->contextMenuStrip_pq_special_scripts->Name = L"contextMenuStrip1";
		this->contextMenuStrip_pq_special_scripts->Size = System::Drawing::Size(144, 48);
		// 
		// toolStripMenuItem34
		// 
		this->toolStripMenuItem34->Name = L"toolStripMenuItem34";
		this->toolStripMenuItem34->Size = System::Drawing::Size(143, 22);
		this->toolStripMenuItem34->Text = L"Add Script";
		this->toolStripMenuItem34->Click += gcnew System::EventHandler(this, &MainWindow::add_pq_special_script);
		// 
		// toolStripMenuItem35
		// 
		this->toolStripMenuItem35->Name = L"toolStripMenuItem35";
		this->toolStripMenuItem35->Size = System::Drawing::Size(143, 22);
		this->toolStripMenuItem35->Text = L"Remove Script";
		this->toolStripMenuItem35->Click += gcnew System::EventHandler(this, &MainWindow::remove_pq_special_script);
		// 
		// label183
		// 
		this->label183->AutoSize = true;
		this->label183->Location = System::Drawing::Point(14, 493);
		this->label183->Name = L"label183";
		this->label183->Size = System::Drawing::Size(71, 13);
		this->label183->TabIndex = 306;
		this->label183->Text = L"Unknown 17:";
		// 
		// label182
		// 
		this->label182->AutoSize = true;
		this->label182->Location = System::Drawing::Point(460, 467);
		this->label182->Name = L"label182";
		this->label182->Size = System::Drawing::Size(71, 13);
		this->label182->TabIndex = 304;
		this->label182->Text = L"Unknown 16:";
		// 
		// textBox_pq_unknown_16
		// 
		this->textBox_pq_unknown_16->Location = System::Drawing::Point(544, 464);
		this->textBox_pq_unknown_16->Name = L"textBox_pq_unknown_16";
		this->textBox_pq_unknown_16->Size = System::Drawing::Size(112, 20);
		this->textBox_pq_unknown_16->TabIndex = 305;
		this->textBox_pq_unknown_16->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->textBox_pq_unknown_16->Leave += gcnew System::EventHandler(this, &MainWindow::change_pq_unknown_16);
		// 
		// textBox_pq_unknown_17
		// 
		this->textBox_pq_unknown_17->Location = System::Drawing::Point(144, 490);
		this->textBox_pq_unknown_17->Name = L"textBox_pq_unknown_17";
		this->textBox_pq_unknown_17->Size = System::Drawing::Size(112, 20);
		this->textBox_pq_unknown_17->TabIndex = 307;
		this->textBox_pq_unknown_17->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->textBox_pq_unknown_17->Leave += gcnew System::EventHandler(this, &MainWindow::change_pq_unknown_17);
		// 
		// label181
		// 
		this->label181->AutoSize = true;
		this->label181->Location = System::Drawing::Point(263, 470);
		this->label181->Name = L"label181";
		this->label181->Size = System::Drawing::Size(71, 13);
		this->label181->TabIndex = 302;
		this->label181->Text = L"Unknown 15:";
		// 
		// textBox_pq_unknown_15
		// 
		this->textBox_pq_unknown_15->Location = System::Drawing::Point(346, 467);
		this->textBox_pq_unknown_15->Name = L"textBox_pq_unknown_15";
		this->textBox_pq_unknown_15->Size = System::Drawing::Size(112, 20);
		this->textBox_pq_unknown_15->TabIndex = 303;
		this->textBox_pq_unknown_15->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->textBox_pq_unknown_15->Leave += gcnew System::EventHandler(this, &MainWindow::change_pq_unknown_15);
		// 
		// label180
		// 
		this->label180->AutoSize = true;
		this->label180->Location = System::Drawing::Point(13, 467);
		this->label180->Name = L"label180";
		this->label180->Size = System::Drawing::Size(71, 13);
		this->label180->TabIndex = 300;
		this->label180->Text = L"Unknown 14:";
		// 
		// textBox_pq_unknown_14
		// 
		this->textBox_pq_unknown_14->Location = System::Drawing::Point(143, 464);
		this->textBox_pq_unknown_14->Name = L"textBox_pq_unknown_14";
		this->textBox_pq_unknown_14->Size = System::Drawing::Size(112, 20);
		this->textBox_pq_unknown_14->TabIndex = 301;
		this->textBox_pq_unknown_14->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->textBox_pq_unknown_14->Leave += gcnew System::EventHandler(this, &MainWindow::change_pq_unknown_14);
		// 
		// label179
		// 
		this->label179->AutoSize = true;
		this->label179->Location = System::Drawing::Point(464, 441);
		this->label179->Name = L"label179";
		this->label179->Size = System::Drawing::Size(51, 13);
		this->label179->TabIndex = 298;
		this->label179->Text = L"Script ID:";
		// 
		// textBox_pq_id_script
		// 
		this->textBox_pq_id_script->Location = System::Drawing::Point(544, 438);
		this->textBox_pq_id_script->Name = L"textBox_pq_id_script";
		this->textBox_pq_id_script->Size = System::Drawing::Size(112, 20);
		this->textBox_pq_id_script->TabIndex = 299;
		this->textBox_pq_id_script->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->textBox_pq_id_script->Leave += gcnew System::EventHandler(this, &MainWindow::change_pq_id_script);
		// 
		// label178
		// 
		this->label178->AutoSize = true;
		this->label178->Location = System::Drawing::Point(263, 441);
		this->label178->Name = L"label178";
		this->label178->Size = System::Drawing::Size(71, 13);
		this->label178->TabIndex = 296;
		this->label178->Text = L"Unknown 13:";
		// 
		// textBox_pq_unknown_13
		// 
		this->textBox_pq_unknown_13->Location = System::Drawing::Point(346, 438);
		this->textBox_pq_unknown_13->Name = L"textBox_pq_unknown_13";
		this->textBox_pq_unknown_13->Size = System::Drawing::Size(112, 20);
		this->textBox_pq_unknown_13->TabIndex = 297;
		this->textBox_pq_unknown_13->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->textBox_pq_unknown_13->Leave += gcnew System::EventHandler(this, &MainWindow::change_pq_unknown_13);
		// 
		// label177
		// 
		this->label177->AutoSize = true;
		this->label177->Location = System::Drawing::Point(14, 441);
		this->label177->Name = L"label177";
		this->label177->Size = System::Drawing::Size(71, 13);
		this->label177->TabIndex = 294;
		this->label177->Text = L"Unknown 12:";
		// 
		// textBox_pq_unknown_12
		// 
		this->textBox_pq_unknown_12->Location = System::Drawing::Point(144, 438);
		this->textBox_pq_unknown_12->Name = L"textBox_pq_unknown_12";
		this->textBox_pq_unknown_12->Size = System::Drawing::Size(112, 20);
		this->textBox_pq_unknown_12->TabIndex = 295;
		this->textBox_pq_unknown_12->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->textBox_pq_unknown_12->Leave += gcnew System::EventHandler(this, &MainWindow::change_pq_unknown_12);
		// 
		// label173
		// 
		this->label173->AutoSize = true;
		this->label173->Location = System::Drawing::Point(412, 415);
		this->label173->Name = L"label173";
		this->label173->Size = System::Drawing::Size(71, 13);
		this->label173->TabIndex = 291;
		this->label173->Text = L"Unknown 11:";
		// 
		// textBox_pq_unknown_11
		// 
		this->textBox_pq_unknown_11->Location = System::Drawing::Point(492, 412);
		this->textBox_pq_unknown_11->Name = L"textBox_pq_unknown_11";
		this->textBox_pq_unknown_11->Size = System::Drawing::Size(112, 20);
		this->textBox_pq_unknown_11->TabIndex = 292;
		this->textBox_pq_unknown_11->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->textBox_pq_unknown_11->Leave += gcnew System::EventHandler(this, &MainWindow::change_pq_unknown_11);
		// 
		// label174
		// 
		this->label174->AutoSize = true;
		this->label174->Location = System::Drawing::Point(412, 389);
		this->label174->Name = L"label174";
		this->label174->Size = System::Drawing::Size(71, 13);
		this->label174->TabIndex = 289;
		this->label174->Text = L"Unknown 10:";
		// 
		// textBox_pq_unknown_10
		// 
		this->textBox_pq_unknown_10->Location = System::Drawing::Point(501, 386);
		this->textBox_pq_unknown_10->Name = L"textBox_pq_unknown_10";
		this->textBox_pq_unknown_10->Size = System::Drawing::Size(112, 20);
		this->textBox_pq_unknown_10->TabIndex = 290;
		this->textBox_pq_unknown_10->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->textBox_pq_unknown_10->Leave += gcnew System::EventHandler(this, &MainWindow::change_pq_unknown_10);
		// 
		// label169
		// 
		this->label169->AutoSize = true;
		this->label169->Location = System::Drawing::Point(399, 364);
		this->label169->Name = L"label169";
		this->label169->Size = System::Drawing::Size(65, 13);
		this->label169->TabIndex = 287;
		this->label169->Text = L"Unknown 9:";
		// 
		// textBox_pq_unknown_9
		// 
		this->textBox_pq_unknown_9->Location = System::Drawing::Point(483, 360);
		this->textBox_pq_unknown_9->Name = L"textBox_pq_unknown_9";
		this->textBox_pq_unknown_9->Size = System::Drawing::Size(76, 20);
		this->textBox_pq_unknown_9->TabIndex = 288;
		this->textBox_pq_unknown_9->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->textBox_pq_unknown_9->Leave += gcnew System::EventHandler(this, &MainWindow::change_pq_unknown_9);
		// 
		// label170
		// 
		this->label170->AutoSize = true;
		this->label170->Location = System::Drawing::Point(388, 337);
		this->label170->Name = L"label170";
		this->label170->Size = System::Drawing::Size(65, 13);
		this->label170->TabIndex = 285;
		this->label170->Text = L"Unknown 8:";
		// 
		// textBox_pq_unknown_8
		// 
		this->textBox_pq_unknown_8->Location = System::Drawing::Point(463, 334);
		this->textBox_pq_unknown_8->Name = L"textBox_pq_unknown_8";
		this->textBox_pq_unknown_8->Size = System::Drawing::Size(40, 20);
		this->textBox_pq_unknown_8->TabIndex = 286;
		this->textBox_pq_unknown_8->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->textBox_pq_unknown_8->Leave += gcnew System::EventHandler(this, &MainWindow::change_pq_unknown_8);
		// 
		// label171
		// 
		this->label171->AutoSize = true;
		this->label171->Location = System::Drawing::Point(254, 305);
		this->label171->Name = L"label171";
		this->label171->Size = System::Drawing::Size(65, 13);
		this->label171->TabIndex = 283;
		this->label171->Text = L"Unknown 7:";
		// 
		// textBox_pq_unknown_7
		// 
		this->textBox_pq_unknown_7->Location = System::Drawing::Point(323, 305);
		this->textBox_pq_unknown_7->Name = L"textBox_pq_unknown_7";
		this->textBox_pq_unknown_7->Size = System::Drawing::Size(112, 20);
		this->textBox_pq_unknown_7->TabIndex = 284;
		this->textBox_pq_unknown_7->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->textBox_pq_unknown_7->Leave += gcnew System::EventHandler(this, &MainWindow::change_pq_unknown_7);
		// 
		// label168
		// 
		this->label168->AutoSize = true;
		this->label168->Location = System::Drawing::Point(-7, 334);
		this->label168->Name = L"label168";
		this->label168->Size = System::Drawing::Size(86, 13);
		this->label168->TabIndex = 281;
		this->label168->Text = L"Chase Monsters:";
		// 
		// dataGridView_pq_chases
		// 
		this->dataGridView_pq_chases->AllowUserToAddRows = false;
		this->dataGridView_pq_chases->AllowUserToDeleteRows = false;
		this->dataGridView_pq_chases->BackgroundColor = System::Drawing::SystemColors::Window;
		this->dataGridView_pq_chases->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
		this->dataGridView_pq_chases->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
		this->dataGridView_pq_chases->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {this->dataGridViewTextBoxColumn72, 
			this->dataGridViewTextBoxColumn73, this->Column22, this->dataGridViewTextBoxColumn74});
		this->dataGridView_pq_chases->ContextMenuStrip = this->contextMenuStrip_pq_chases;
		this->dataGridView_pq_chases->Location = System::Drawing::Point(85, 330);
		this->dataGridView_pq_chases->MultiSelect = false;
		this->dataGridView_pq_chases->Name = L"dataGridView_pq_chases";
		this->dataGridView_pq_chases->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
		dataGridViewCellStyle28->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
		dataGridViewCellStyle28->BackColor = System::Drawing::SystemColors::Control;
		dataGridViewCellStyle28->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		dataGridViewCellStyle28->ForeColor = System::Drawing::SystemColors::WindowText;
		dataGridViewCellStyle28->SelectionBackColor = System::Drawing::SystemColors::Highlight;
		dataGridViewCellStyle28->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
		dataGridViewCellStyle28->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView_pq_chases->RowHeadersDefaultCellStyle = dataGridViewCellStyle28;
		this->dataGridView_pq_chases->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::AutoSizeToFirstHeader;
		this->dataGridView_pq_chases->RowTemplate->Height = 18;
		this->dataGridView_pq_chases->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView_pq_chases->Size = System::Drawing::Size(276, 98);
		this->dataGridView_pq_chases->TabIndex = 282;
		this->dataGridView_pq_chases->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::change_pq_chases);
		// 
		// dataGridViewTextBoxColumn72
		// 
		this->dataGridViewTextBoxColumn72->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle26->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn72->DefaultCellStyle = dataGridViewCellStyle26;
		this->dataGridViewTextBoxColumn72->HeaderText = L"ID";
		this->dataGridViewTextBoxColumn72->Name = L"dataGridViewTextBoxColumn72";
		this->dataGridViewTextBoxColumn72->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn72->Width = 23;
		// 
		// dataGridViewTextBoxColumn73
		// 
		this->dataGridViewTextBoxColumn73->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle27->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn73->DefaultCellStyle = dataGridViewCellStyle27;
		this->dataGridViewTextBoxColumn73->HeaderText = L"amount_1";
		this->dataGridViewTextBoxColumn73->Name = L"dataGridViewTextBoxColumn73";
		this->dataGridViewTextBoxColumn73->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn73->Width = 59;
		// 
		// Column22
		// 
		this->Column22->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		this->Column22->HeaderText = L"Contribution";
		this->Column22->Name = L"Column22";
		this->Column22->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->Column22->Width = 68;
		// 
		// dataGridViewTextBoxColumn74
		// 
		this->dataGridViewTextBoxColumn74->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
		this->dataGridViewTextBoxColumn74->HeaderText = L"amount_3";
		this->dataGridViewTextBoxColumn74->Name = L"dataGridViewTextBoxColumn74";
		this->dataGridViewTextBoxColumn74->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		// 
		// contextMenuStrip_pq_chases
		// 
		this->contextMenuStrip_pq_chases->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->toolStripMenuItem24, 
			this->toolStripMenuItem25});
		this->contextMenuStrip_pq_chases->Name = L"contextMenuStrip1";
		this->contextMenuStrip_pq_chases->Size = System::Drawing::Size(147, 48);
		// 
		// toolStripMenuItem24
		// 
		this->toolStripMenuItem24->Name = L"toolStripMenuItem24";
		this->toolStripMenuItem24->Size = System::Drawing::Size(146, 22);
		this->toolStripMenuItem24->Text = L"Add Chase";
		this->toolStripMenuItem24->Click += gcnew System::EventHandler(this, &MainWindow::add_pq_chase);
		// 
		// toolStripMenuItem25
		// 
		this->toolStripMenuItem25->Name = L"toolStripMenuItem25";
		this->toolStripMenuItem25->Size = System::Drawing::Size(146, 22);
		this->toolStripMenuItem25->Text = L"Remove Chase";
		this->toolStripMenuItem25->Click += gcnew System::EventHandler(this, &MainWindow::remove_pq_chase);
		// 
		// label167
		// 
		this->label167->AutoSize = true;
		this->label167->Location = System::Drawing::Point(241, 279);
		this->label167->Name = L"label167";
		this->label167->Size = System::Drawing::Size(65, 13);
		this->label167->TabIndex = 279;
		this->label167->Text = L"Unknown 6:";
		// 
		// textBox_pq_unknown_6
		// 
		this->textBox_pq_unknown_6->Location = System::Drawing::Point(319, 279);
		this->textBox_pq_unknown_6->Name = L"textBox_pq_unknown_6";
		this->textBox_pq_unknown_6->Size = System::Drawing::Size(103, 20);
		this->textBox_pq_unknown_6->TabIndex = 280;
		this->textBox_pq_unknown_6->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->textBox_pq_unknown_6->Leave += gcnew System::EventHandler(this, &MainWindow::change_pq_unknown_6);
		// 
		// label166
		// 
		this->label166->AutoSize = true;
		this->label166->Location = System::Drawing::Point(245, 256);
		this->label166->Name = L"label166";
		this->label166->Size = System::Drawing::Size(65, 13);
		this->label166->TabIndex = 277;
		this->label166->Text = L"Unknown 5:";
		// 
		// textBox_pq_unknown_5
		// 
		this->textBox_pq_unknown_5->Location = System::Drawing::Point(319, 253);
		this->textBox_pq_unknown_5->Name = L"textBox_pq_unknown_5";
		this->textBox_pq_unknown_5->Size = System::Drawing::Size(103, 20);
		this->textBox_pq_unknown_5->TabIndex = 278;
		this->textBox_pq_unknown_5->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->textBox_pq_unknown_5->Leave += gcnew System::EventHandler(this, &MainWindow::change_pq_unknown_5);
		// 
		// label164
		// 
		this->label164->AutoSize = true;
		this->label164->Location = System::Drawing::Point(241, 227);
		this->label164->Name = L"label164";
		this->label164->Size = System::Drawing::Size(65, 13);
		this->label164->TabIndex = 275;
		this->label164->Text = L"Unknown 4:";
		// 
		// textBox_pq_unknown_4
		// 
		this->textBox_pq_unknown_4->Location = System::Drawing::Point(316, 227);
		this->textBox_pq_unknown_4->Name = L"textBox_pq_unknown_4";
		this->textBox_pq_unknown_4->Size = System::Drawing::Size(103, 20);
		this->textBox_pq_unknown_4->TabIndex = 276;
		this->textBox_pq_unknown_4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->textBox_pq_unknown_4->Leave += gcnew System::EventHandler(this, &MainWindow::change_pq_unknown_4);
		// 
		// label75
		// 
		this->label75->AutoSize = true;
		this->label75->Location = System::Drawing::Point(14, 123);
		this->label75->Name = L"label75";
		this->label75->Size = System::Drawing::Size(42, 13);
		this->label75->TabIndex = 273;
		this->label75->Text = L"Scripts:";
		// 
		// dataGridView_pq_scripts
		// 
		this->dataGridView_pq_scripts->AllowUserToAddRows = false;
		this->dataGridView_pq_scripts->AllowUserToDeleteRows = false;
		this->dataGridView_pq_scripts->BackgroundColor = System::Drawing::SystemColors::Window;
		this->dataGridView_pq_scripts->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
		this->dataGridView_pq_scripts->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
		this->dataGridView_pq_scripts->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {this->dataGridViewTextBoxColumn68, 
			this->dataGridViewTextBoxColumn70, this->dataGridViewTextBoxColumn71, this->Column19, this->Column20, this->Column21});
		this->dataGridView_pq_scripts->ContextMenuStrip = this->contextMenuStrip_pq_script_infos;
		this->dataGridView_pq_scripts->Location = System::Drawing::Point(85, 123);
		this->dataGridView_pq_scripts->MultiSelect = false;
		this->dataGridView_pq_scripts->Name = L"dataGridView_pq_scripts";
		this->dataGridView_pq_scripts->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
		dataGridViewCellStyle31->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
		dataGridViewCellStyle31->BackColor = System::Drawing::SystemColors::Control;
		dataGridViewCellStyle31->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		dataGridViewCellStyle31->ForeColor = System::Drawing::SystemColors::WindowText;
		dataGridViewCellStyle31->SelectionBackColor = System::Drawing::SystemColors::Highlight;
		dataGridViewCellStyle31->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
		dataGridViewCellStyle31->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView_pq_scripts->RowHeadersDefaultCellStyle = dataGridViewCellStyle31;
		this->dataGridView_pq_scripts->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::AutoSizeToFirstHeader;
		this->dataGridView_pq_scripts->RowTemplate->Height = 18;
		this->dataGridView_pq_scripts->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView_pq_scripts->Size = System::Drawing::Size(551, 101);
		this->dataGridView_pq_scripts->TabIndex = 274;
		this->dataGridView_pq_scripts->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::change_pq_scripts);
		// 
		// dataGridViewTextBoxColumn68
		// 
		this->dataGridViewTextBoxColumn68->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle29->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn68->DefaultCellStyle = dataGridViewCellStyle29;
		this->dataGridViewTextBoxColumn68->HeaderText = L"Name";
		this->dataGridViewTextBoxColumn68->Name = L"dataGridViewTextBoxColumn68";
		this->dataGridViewTextBoxColumn68->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn68->Width = 40;
		// 
		// dataGridViewTextBoxColumn70
		// 
		this->dataGridViewTextBoxColumn70->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle30->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn70->DefaultCellStyle = dataGridViewCellStyle30;
		this->dataGridViewTextBoxColumn70->HeaderText = L"Count";
		this->dataGridViewTextBoxColumn70->Name = L"dataGridViewTextBoxColumn70";
		this->dataGridViewTextBoxColumn70->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn70->Width = 40;
		// 
		// dataGridViewTextBoxColumn71
		// 
		this->dataGridViewTextBoxColumn71->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		this->dataGridViewTextBoxColumn71->HeaderText = L"ID";
		this->dataGridViewTextBoxColumn71->Name = L"dataGridViewTextBoxColumn71";
		this->dataGridViewTextBoxColumn71->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn71->Width = 23;
		// 
		// Column19
		// 
		this->Column19->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		this->Column19->HeaderText = L"Seperator";
		this->Column19->Name = L"Column19";
		this->Column19->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->Column19->Width = 58;
		// 
		// Column20
		// 
		this->Column20->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		this->Column20->HeaderText = L"Ref. ID";
		this->Column20->Name = L"Column20";
		this->Column20->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->Column20->Width = 46;
		// 
		// Column21
		// 
		this->Column21->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
		this->Column21->HeaderText = L"Source Code";
		this->Column21->Name = L"Column21";
		this->Column21->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		// 
		// contextMenuStrip_pq_script_infos
		// 
		this->contextMenuStrip_pq_script_infos->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->toolStripMenuItem30, 
			this->toolStripMenuItem31});
		this->contextMenuStrip_pq_script_infos->Name = L"contextMenuStrip1";
		this->contextMenuStrip_pq_script_infos->Size = System::Drawing::Size(167, 48);
		// 
		// toolStripMenuItem30
		// 
		this->toolStripMenuItem30->Name = L"toolStripMenuItem30";
		this->toolStripMenuItem30->Size = System::Drawing::Size(166, 22);
		this->toolStripMenuItem30->Text = L"Add Script Info";
		this->toolStripMenuItem30->Click += gcnew System::EventHandler(this, &MainWindow::add_pq_script_info);
		// 
		// toolStripMenuItem31
		// 
		this->toolStripMenuItem31->Name = L"toolStripMenuItem31";
		this->toolStripMenuItem31->Size = System::Drawing::Size(166, 22);
		this->toolStripMenuItem31->Text = L"Remove Script Info";
		this->toolStripMenuItem31->Click += gcnew System::EventHandler(this, &MainWindow::remove_pq_script_info);
		// 
		// textBox_pq_unknown_2
		// 
		this->textBox_pq_unknown_2->Location = System::Drawing::Point(448, 50);
		this->textBox_pq_unknown_2->Name = L"textBox_pq_unknown_2";
		this->textBox_pq_unknown_2->Size = System::Drawing::Size(102, 20);
		this->textBox_pq_unknown_2->TabIndex = 272;
		this->textBox_pq_unknown_2->Leave += gcnew System::EventHandler(this, &MainWindow::change_pq_unknown_2);
		// 
		// label8
		// 
		this->label8->AutoSize = true;
		this->label8->Location = System::Drawing::Point(377, 50);
		this->label8->Name = L"label8";
		this->label8->Size = System::Drawing::Size(65, 13);
		this->label8->TabIndex = 271;
		this->label8->Text = L"Unknown 2:";
		// 
		// textBox_pq_unknown_1
		// 
		this->textBox_pq_unknown_1->Location = System::Drawing::Point(448, 19);
		this->textBox_pq_unknown_1->Name = L"textBox_pq_unknown_1";
		this->textBox_pq_unknown_1->Size = System::Drawing::Size(106, 20);
		this->textBox_pq_unknown_1->TabIndex = 270;
		this->textBox_pq_unknown_1->Leave += gcnew System::EventHandler(this, &MainWindow::change_pq_unknown_1);
		// 
		// label9
		// 
		this->label9->AutoSize = true;
		this->label9->Location = System::Drawing::Point(377, 22);
		this->label9->Name = L"label9";
		this->label9->Size = System::Drawing::Size(65, 13);
		this->label9->TabIndex = 269;
		this->label9->Text = L"Unknown 1:";
		// 
		// label54
		// 
		this->label54->AutoSize = true;
		this->label54->Location = System::Drawing::Point(377, 86);
		this->label54->Name = L"label54";
		this->label54->Size = System::Drawing::Size(65, 13);
		this->label54->TabIndex = 267;
		this->label54->Text = L"Unknown 3:";
		// 
		// textBox_pq_unknown_3
		// 
		this->textBox_pq_unknown_3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
		this->textBox_pq_unknown_3->Location = System::Drawing::Point(458, 83);
		this->textBox_pq_unknown_3->Name = L"textBox_pq_unknown_3";
		this->textBox_pq_unknown_3->Size = System::Drawing::Size(92, 20);
		this->textBox_pq_unknown_3->TabIndex = 268;
		this->textBox_pq_unknown_3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->textBox_pq_unknown_3->Leave += gcnew System::EventHandler(this, &MainWindow::change_pq_unknown_3);
		// 
		// label7
		// 
		this->label7->AutoSize = true;
		this->label7->Location = System::Drawing::Point(6, 22);
		this->label7->Name = L"label7";
		this->label7->Size = System::Drawing::Size(63, 13);
		this->label7->TabIndex = 257;
		this->label7->Text = L"Script Infos:";
		// 
		// dataGridView_pq_script_infos
		// 
		this->dataGridView_pq_script_infos->AllowUserToAddRows = false;
		this->dataGridView_pq_script_infos->AllowUserToDeleteRows = false;
		this->dataGridView_pq_script_infos->BackgroundColor = System::Drawing::SystemColors::Window;
		this->dataGridView_pq_script_infos->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
		this->dataGridView_pq_script_infos->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
		this->dataGridView_pq_script_infos->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {this->dataGridViewTextBoxColumn66, 
			this->dataGridViewTextBoxColumn67, this->dataGridViewTextBoxColumn69});
		this->dataGridView_pq_script_infos->ContextMenuStrip = this->contextMenuStrip_pq_script_infos;
		this->dataGridView_pq_script_infos->Location = System::Drawing::Point(85, 19);
		this->dataGridView_pq_script_infos->MultiSelect = false;
		this->dataGridView_pq_script_infos->Name = L"dataGridView_pq_script_infos";
		this->dataGridView_pq_script_infos->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
		dataGridViewCellStyle34->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
		dataGridViewCellStyle34->BackColor = System::Drawing::SystemColors::Control;
		dataGridViewCellStyle34->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		dataGridViewCellStyle34->ForeColor = System::Drawing::SystemColors::WindowText;
		dataGridViewCellStyle34->SelectionBackColor = System::Drawing::SystemColors::Highlight;
		dataGridViewCellStyle34->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
		dataGridViewCellStyle34->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView_pq_script_infos->RowHeadersDefaultCellStyle = dataGridViewCellStyle34;
		this->dataGridView_pq_script_infos->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::AutoSizeToFirstHeader;
		this->dataGridView_pq_script_infos->RowTemplate->Height = 18;
		this->dataGridView_pq_script_infos->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView_pq_script_infos->Size = System::Drawing::Size(276, 98);
		this->dataGridView_pq_script_infos->TabIndex = 258;
		this->dataGridView_pq_script_infos->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::change_pq_script_infos);
		// 
		// dataGridViewTextBoxColumn66
		// 
		this->dataGridViewTextBoxColumn66->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle32->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn66->DefaultCellStyle = dataGridViewCellStyle32;
		this->dataGridViewTextBoxColumn66->HeaderText = L"ID";
		this->dataGridViewTextBoxColumn66->Name = L"dataGridViewTextBoxColumn66";
		this->dataGridViewTextBoxColumn66->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn66->Width = 23;
		// 
		// dataGridViewTextBoxColumn67
		// 
		this->dataGridViewTextBoxColumn67->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle33->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn67->DefaultCellStyle = dataGridViewCellStyle33;
		this->dataGridViewTextBoxColumn67->HeaderText = L"unknown_1";
		this->dataGridViewTextBoxColumn67->Name = L"dataGridViewTextBoxColumn67";
		this->dataGridViewTextBoxColumn67->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn67->Width = 68;
		// 
		// dataGridViewTextBoxColumn69
		// 
		this->dataGridViewTextBoxColumn69->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
		this->dataGridViewTextBoxColumn69->HeaderText = L"unknown_2";
		this->dataGridViewTextBoxColumn69->Name = L"dataGridViewTextBoxColumn69";
		this->dataGridViewTextBoxColumn69->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		// 
		// groupBox_pq_location
		// 
		this->groupBox_pq_location->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->groupBox_pq_location->Controls->Add(this->checkBox_pq_location_has_spans);
		this->groupBox_pq_location->Controls->Add(this->label172);
		this->groupBox_pq_location->Controls->Add(this->textBox_pq_location_unknown_1);
		this->groupBox_pq_location->Controls->Add(this->dataGridView_pq_location_spans);
		this->groupBox_pq_location->Controls->Add(this->textBox_pq_location_map_id);
		this->groupBox_pq_location->Controls->Add(this->label175);
		this->groupBox_pq_location->Controls->Add(this->label176);
		this->groupBox_pq_location->ForeColor = System::Drawing::Color::Gray;
		this->groupBox_pq_location->Location = System::Drawing::Point(3, 391);
		this->groupBox_pq_location->Name = L"groupBox_pq_location";
		this->groupBox_pq_location->Size = System::Drawing::Size(671, 91);
		this->groupBox_pq_location->TabIndex = 293;
		this->groupBox_pq_location->TabStop = false;
		this->groupBox_pq_location->Text = L"PUBLIC QUEST UNKNOWN";
		// 
		// checkBox_pq_location_has_spans
		// 
		this->checkBox_pq_location_has_spans->AutoSize = true;
		this->checkBox_pq_location_has_spans->Enabled = false;
		this->checkBox_pq_location_has_spans->Location = System::Drawing::Point(77, 19);
		this->checkBox_pq_location_has_spans->Name = L"checkBox_pq_location_has_spans";
		this->checkBox_pq_location_has_spans->Size = System::Drawing::Size(15, 14);
		this->checkBox_pq_location_has_spans->TabIndex = 96;
		this->checkBox_pq_location_has_spans->UseVisualStyleBackColor = true;
		this->checkBox_pq_location_has_spans->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_pq_location_has_spans);
		// 
		// textBox_pq_location_unknown_1
		// 
		this->textBox_pq_location_unknown_1->Enabled = false;
		this->textBox_pq_location_unknown_1->Location = System::Drawing::Point(77, 65);
		this->textBox_pq_location_unknown_1->Name = L"textBox_pq_location_unknown_1";
		this->textBox_pq_location_unknown_1->Size = System::Drawing::Size(122, 20);
		this->textBox_pq_location_unknown_1->TabIndex = 94;
		this->textBox_pq_location_unknown_1->Leave += gcnew System::EventHandler(this, &MainWindow::change_pq_location_unknown_1);
		// 
		// dataGridView_pq_location_spans
		// 
		this->dataGridView_pq_location_spans->AllowUserToAddRows = false;
		this->dataGridView_pq_location_spans->AllowUserToDeleteRows = false;
		this->dataGridView_pq_location_spans->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
			| System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->dataGridView_pq_location_spans->BackgroundColor = System::Drawing::SystemColors::Window;
		this->dataGridView_pq_location_spans->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
		this->dataGridView_pq_location_spans->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
		this->dataGridView_pq_location_spans->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {this->dataGridViewTextBoxColumn75, 
			this->dataGridViewTextBoxColumn76, this->dataGridViewTextBoxColumn77, this->dataGridViewTextBoxColumn78, this->dataGridViewTextBoxColumn79, 
			this->dataGridViewTextBoxColumn80});
		this->dataGridView_pq_location_spans->ContextMenuStrip = this->contextMenuStrip_pq_location;
		this->dataGridView_pq_location_spans->Location = System::Drawing::Point(205, 10);
		this->dataGridView_pq_location_spans->MultiSelect = false;
		this->dataGridView_pq_location_spans->Name = L"dataGridView_pq_location_spans";
		this->dataGridView_pq_location_spans->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
		dataGridViewCellStyle41->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
		dataGridViewCellStyle41->BackColor = System::Drawing::SystemColors::Control;
		dataGridViewCellStyle41->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		dataGridViewCellStyle41->ForeColor = System::Drawing::SystemColors::WindowText;
		dataGridViewCellStyle41->SelectionBackColor = System::Drawing::SystemColors::Highlight;
		dataGridViewCellStyle41->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
		dataGridViewCellStyle41->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView_pq_location_spans->RowHeadersDefaultCellStyle = dataGridViewCellStyle41;
		this->dataGridView_pq_location_spans->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::AutoSizeToFirstHeader;
		this->dataGridView_pq_location_spans->RowTemplate->Height = 18;
		this->dataGridView_pq_location_spans->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView_pq_location_spans->Size = System::Drawing::Size(460, 75);
		this->dataGridView_pq_location_spans->TabIndex = 91;
		this->dataGridView_pq_location_spans->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::change_pq_location_span);
		// 
		// dataGridViewTextBoxColumn75
		// 
		this->dataGridViewTextBoxColumn75->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
		dataGridViewCellStyle35->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn75->DefaultCellStyle = dataGridViewCellStyle35;
		this->dataGridViewTextBoxColumn75->HeaderText = L"North";
		this->dataGridViewTextBoxColumn75->Name = L"dataGridViewTextBoxColumn75";
		this->dataGridViewTextBoxColumn75->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		// 
		// dataGridViewTextBoxColumn76
		// 
		this->dataGridViewTextBoxColumn76->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
		dataGridViewCellStyle36->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn76->DefaultCellStyle = dataGridViewCellStyle36;
		this->dataGridViewTextBoxColumn76->HeaderText = L"South";
		this->dataGridViewTextBoxColumn76->Name = L"dataGridViewTextBoxColumn76";
		this->dataGridViewTextBoxColumn76->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		// 
		// dataGridViewTextBoxColumn77
		// 
		this->dataGridViewTextBoxColumn77->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
		dataGridViewCellStyle37->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn77->DefaultCellStyle = dataGridViewCellStyle37;
		this->dataGridViewTextBoxColumn77->HeaderText = L"Weast";
		this->dataGridViewTextBoxColumn77->Name = L"dataGridViewTextBoxColumn77";
		this->dataGridViewTextBoxColumn77->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		// 
		// dataGridViewTextBoxColumn78
		// 
		this->dataGridViewTextBoxColumn78->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
		dataGridViewCellStyle38->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn78->DefaultCellStyle = dataGridViewCellStyle38;
		this->dataGridViewTextBoxColumn78->HeaderText = L"East";
		this->dataGridViewTextBoxColumn78->Name = L"dataGridViewTextBoxColumn78";
		this->dataGridViewTextBoxColumn78->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		// 
		// dataGridViewTextBoxColumn79
		// 
		this->dataGridViewTextBoxColumn79->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
		dataGridViewCellStyle39->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn79->DefaultCellStyle = dataGridViewCellStyle39;
		this->dataGridViewTextBoxColumn79->HeaderText = L"Low";
		this->dataGridViewTextBoxColumn79->Name = L"dataGridViewTextBoxColumn79";
		this->dataGridViewTextBoxColumn79->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		// 
		// dataGridViewTextBoxColumn80
		// 
		this->dataGridViewTextBoxColumn80->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
		dataGridViewCellStyle40->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn80->DefaultCellStyle = dataGridViewCellStyle40;
		this->dataGridViewTextBoxColumn80->HeaderText = L"High";
		this->dataGridViewTextBoxColumn80->Name = L"dataGridViewTextBoxColumn80";
		this->dataGridViewTextBoxColumn80->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		// 
		// contextMenuStrip_pq_location
		// 
		this->contextMenuStrip_pq_location->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->toolStripMenuItem28, 
			this->toolStripMenuItem29});
		this->contextMenuStrip_pq_location->Name = L"contextMenuStrip1";
		this->contextMenuStrip_pq_location->Size = System::Drawing::Size(184, 48);
		// 
		// toolStripMenuItem28
		// 
		this->toolStripMenuItem28->Name = L"toolStripMenuItem28";
		this->toolStripMenuItem28->Size = System::Drawing::Size(183, 22);
		this->toolStripMenuItem28->Text = L"Add Location Span";
		this->toolStripMenuItem28->Click += gcnew System::EventHandler(this, &MainWindow::add_pq_location_span);
		// 
		// toolStripMenuItem29
		// 
		this->toolStripMenuItem29->Name = L"toolStripMenuItem29";
		this->toolStripMenuItem29->Size = System::Drawing::Size(183, 22);
		this->toolStripMenuItem29->Text = L"Remove Location Span";
		this->toolStripMenuItem29->Click += gcnew System::EventHandler(this, &MainWindow::remove_pq_location_span);
		// 
		// textBox_pq_location_map_id
		// 
		this->textBox_pq_location_map_id->Location = System::Drawing::Point(77, 39);
		this->textBox_pq_location_map_id->Name = L"textBox_pq_location_map_id";
		this->textBox_pq_location_map_id->Size = System::Drawing::Size(51, 20);
		this->textBox_pq_location_map_id->TabIndex = 92;
		this->textBox_pq_location_map_id->Leave += gcnew System::EventHandler(this, &MainWindow::change_pq_location_map_id);
		// 
		// groupBox_basic_1
		// 
		this->groupBox_basic_1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->groupBox_basic_1->Controls->Add(this->label35);
		this->groupBox_basic_1->Controls->Add(this->label128);
		this->groupBox_basic_1->Controls->Add(this->textBox_level_min);
		this->groupBox_basic_1->Controls->Add(this->label36);
		this->groupBox_basic_1->Controls->Add(this->textBox_unknown_26_01);
		this->groupBox_basic_1->Controls->Add(this->textBox_level_max);
		this->groupBox_basic_1->Controls->Add(this->checkBox_craft_skill);
		this->groupBox_basic_1->Controls->Add(this->label127);
		this->groupBox_basic_1->Controls->Add(this->checkBox_unknown_26);
		this->groupBox_basic_1->Controls->Add(this->label126);
		this->groupBox_basic_1->Controls->Add(this->checkBox_unknown_25);
		this->groupBox_basic_1->Controls->Add(this->label125);
		this->groupBox_basic_1->Controls->Add(this->checkBox_unknown_24);
		this->groupBox_basic_1->Controls->Add(this->label124);
		this->groupBox_basic_1->Controls->Add(this->label33);
		this->groupBox_basic_1->Controls->Add(this->textBox_quest_npc);
		this->groupBox_basic_1->Controls->Add(this->label34);
		this->groupBox_basic_1->Controls->Add(this->textBox_reward_npc);
		this->groupBox_basic_1->Controls->Add(this->label123);
		this->groupBox_basic_1->Controls->Add(this->checkBox_mark_available_point);
		this->groupBox_basic_1->Controls->Add(this->label122);
		this->groupBox_basic_1->Controls->Add(this->checkBox_mark_available_icon);
		this->groupBox_basic_1->Controls->Add(this->textBox_instant_teleport_location_z);
		this->groupBox_basic_1->Controls->Add(this->label121);
		this->groupBox_basic_1->Controls->Add(this->textBox_instant_teleport_location_alt);
		this->groupBox_basic_1->Controls->Add(this->label120);
		this->groupBox_basic_1->Controls->Add(this->textBox_instant_teleport_location_x);
		this->groupBox_basic_1->Controls->Add(this->label119);
		this->groupBox_basic_1->Controls->Add(this->textBox_instant_teleport_location_map_id);
		this->groupBox_basic_1->Controls->Add(this->label118);
		this->groupBox_basic_1->Controls->Add(this->textBox_unknown_level);
		this->groupBox_basic_1->Controls->Add(this->label117);
		this->groupBox_basic_1->Controls->Add(this->label108);
		this->groupBox_basic_1->Controls->Add(this->checkBox_unknown_23);
		this->groupBox_basic_1->Controls->Add(this->checkBox_unknown_17);
		this->groupBox_basic_1->Controls->Add(this->label116);
		this->groupBox_basic_1->Controls->Add(this->label109);
		this->groupBox_basic_1->Controls->Add(this->checkBox_unknown_22);
		this->groupBox_basic_1->Controls->Add(this->checkBox_has_instant_teleport);
		this->groupBox_basic_1->Controls->Add(this->label115);
		this->groupBox_basic_1->Controls->Add(this->label110);
		this->groupBox_basic_1->Controls->Add(this->checkBox_unknown_21);
		this->groupBox_basic_1->Controls->Add(this->checkBox_unknown_18);
		this->groupBox_basic_1->Controls->Add(this->label114);
		this->groupBox_basic_1->Controls->Add(this->label111);
		this->groupBox_basic_1->Controls->Add(this->textBox_ai_trigger);
		this->groupBox_basic_1->Controls->Add(this->checkBox_unknown_19);
		this->groupBox_basic_1->Controls->Add(this->label113);
		this->groupBox_basic_1->Controls->Add(this->label112);
		this->groupBox_basic_1->Controls->Add(this->checkBox_unknown_20);
		this->groupBox_basic_1->Location = System::Drawing::Point(3, 3);
		this->groupBox_basic_1->Name = L"groupBox_basic_1";
		this->groupBox_basic_1->Size = System::Drawing::Size(671, 229);
		this->groupBox_basic_1->TabIndex = 119;
		this->groupBox_basic_1->TabStop = false;
		this->groupBox_basic_1->Text = L"BASIC PROPERTIES I";
		// 
		// label35
		// 
		this->label35->AutoSize = true;
		this->label35->Location = System::Drawing::Point(6, 206);
		this->label35->Name = L"label35";
		this->label35->Size = System::Drawing::Size(59, 13);
		this->label35->TabIndex = 82;
		this->label35->Text = L"Min. Level:";
		// 
		// label128
		// 
		this->label128->AutoSize = true;
		this->label128->ForeColor = System::Drawing::Color::Red;
		this->label128->Location = System::Drawing::Point(433, 184);
		this->label128->Name = L"label128";
		this->label128->Size = System::Drawing::Size(89, 13);
		this->label128->TabIndex = 145;
		this->label128->Text = L"Unknown 26_01:";
		// 
		// textBox_level_min
		// 
		this->textBox_level_min->Location = System::Drawing::Point(118, 203);
		this->textBox_level_min->Name = L"textBox_level_min";
		this->textBox_level_min->Size = System::Drawing::Size(60, 20);
		this->textBox_level_min->TabIndex = 83;
		this->textBox_level_min->Leave += gcnew System::EventHandler(this, &MainWindow::change_level_min);
		// 
		// label36
		// 
		this->label36->AutoSize = true;
		this->label36->Location = System::Drawing::Point(184, 206);
		this->label36->Name = L"label36";
		this->label36->Size = System::Drawing::Size(62, 13);
		this->label36->TabIndex = 86;
		this->label36->Text = L"Max. Level:";
		// 
		// textBox_unknown_26_01
		// 
		this->textBox_unknown_26_01->Location = System::Drawing::Point(528, 181);
		this->textBox_unknown_26_01->Name = L"textBox_unknown_26_01";
		this->textBox_unknown_26_01->Size = System::Drawing::Size(137, 20);
		this->textBox_unknown_26_01->TabIndex = 146;
		this->textBox_unknown_26_01->Leave += gcnew System::EventHandler(this, &MainWindow::change_unknown_26_01);
		// 
		// textBox_level_max
		// 
		this->textBox_level_max->Location = System::Drawing::Point(252, 203);
		this->textBox_level_max->Name = L"textBox_level_max";
		this->textBox_level_max->Size = System::Drawing::Size(60, 20);
		this->textBox_level_max->TabIndex = 87;
		this->textBox_level_max->Leave += gcnew System::EventHandler(this, &MainWindow::change_level_max);
		// 
		// checkBox_craft_skill
		// 
		this->checkBox_craft_skill->AutoSize = true;
		this->checkBox_craft_skill->Location = System::Drawing::Point(118, 183);
		this->checkBox_craft_skill->Name = L"checkBox_craft_skill";
		this->checkBox_craft_skill->Size = System::Drawing::Size(15, 14);
		this->checkBox_craft_skill->TabIndex = 143;
		this->checkBox_craft_skill->UseVisualStyleBackColor = true;
		this->checkBox_craft_skill->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_craft_skill);
		// 
		// label127
		// 
		this->label127->AutoSize = true;
		this->label127->Location = System::Drawing::Point(6, 183);
		this->label127->Name = L"label127";
		this->label127->Size = System::Drawing::Size(54, 13);
		this->label127->TabIndex = 144;
		this->label127->Text = L"Craft Skill:";
		// 
		// checkBox_unknown_26
		// 
		this->checkBox_unknown_26->AutoSize = true;
		this->checkBox_unknown_26->Location = System::Drawing::Point(412, 183);
		this->checkBox_unknown_26->Name = L"checkBox_unknown_26";
		this->checkBox_unknown_26->Size = System::Drawing::Size(15, 14);
		this->checkBox_unknown_26->TabIndex = 141;
		this->checkBox_unknown_26->UseVisualStyleBackColor = true;
		this->checkBox_unknown_26->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_unknown_26);
		// 
		// label126
		// 
		this->label126->AutoSize = true;
		this->label126->Location = System::Drawing::Point(335, 183);
		this->label126->Name = L"label126";
		this->label126->Size = System::Drawing::Size(71, 13);
		this->label126->TabIndex = 142;
		this->label126->Text = L"Unknown 26:";
		// 
		// checkBox_unknown_25
		// 
		this->checkBox_unknown_25->AutoSize = true;
		this->checkBox_unknown_25->Location = System::Drawing::Point(314, 183);
		this->checkBox_unknown_25->Name = L"checkBox_unknown_25";
		this->checkBox_unknown_25->Size = System::Drawing::Size(15, 14);
		this->checkBox_unknown_25->TabIndex = 139;
		this->checkBox_unknown_25->UseVisualStyleBackColor = true;
		this->checkBox_unknown_25->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_unknown_25);
		// 
		// label125
		// 
		this->label125->AutoSize = true;
		this->label125->Location = System::Drawing::Point(237, 183);
		this->label125->Name = L"label125";
		this->label125->Size = System::Drawing::Size(71, 13);
		this->label125->TabIndex = 140;
		this->label125->Text = L"Unknown 25:";
		// 
		// checkBox_unknown_24
		// 
		this->checkBox_unknown_24->AutoSize = true;
		this->checkBox_unknown_24->Location = System::Drawing::Point(216, 183);
		this->checkBox_unknown_24->Name = L"checkBox_unknown_24";
		this->checkBox_unknown_24->Size = System::Drawing::Size(15, 14);
		this->checkBox_unknown_24->TabIndex = 137;
		this->checkBox_unknown_24->UseVisualStyleBackColor = true;
		this->checkBox_unknown_24->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_unknown_24);
		// 
		// label124
		// 
		this->label124->AutoSize = true;
		this->label124->Location = System::Drawing::Point(139, 183);
		this->label124->Name = L"label124";
		this->label124->Size = System::Drawing::Size(71, 13);
		this->label124->TabIndex = 138;
		this->label124->Text = L"Unknown 24:";
		// 
		// label33
		// 
		this->label33->AutoSize = true;
		this->label33->Location = System::Drawing::Point(6, 154);
		this->label33->Name = L"label33";
		this->label33->Size = System::Drawing::Size(63, 13);
		this->label33->TabIndex = 133;
		this->label33->Text = L"Quest NPC:";
		// 
		// textBox_quest_npc
		// 
		this->textBox_quest_npc->Location = System::Drawing::Point(118, 154);
		this->textBox_quest_npc->Name = L"textBox_quest_npc";
		this->textBox_quest_npc->Size = System::Drawing::Size(60, 20);
		this->textBox_quest_npc->TabIndex = 134;
		this->textBox_quest_npc->Leave += gcnew System::EventHandler(this, &MainWindow::change_quest_npc);
		// 
		// label34
		// 
		this->label34->AutoSize = true;
		this->label34->Location = System::Drawing::Point(184, 157);
		this->label34->Name = L"label34";
		this->label34->Size = System::Drawing::Size(72, 13);
		this->label34->TabIndex = 135;
		this->label34->Text = L"Reward NPC:";
		// 
		// textBox_reward_npc
		// 
		this->textBox_reward_npc->Location = System::Drawing::Point(262, 154);
		this->textBox_reward_npc->Name = L"textBox_reward_npc";
		this->textBox_reward_npc->Size = System::Drawing::Size(60, 20);
		this->textBox_reward_npc->TabIndex = 136;
		this->textBox_reward_npc->Leave += gcnew System::EventHandler(this, &MainWindow::change_reward_npc);
		// 
		// label123
		// 
		this->label123->AutoSize = true;
		this->label123->Location = System::Drawing::Point(139, 131);
		this->label123->Name = L"label123";
		this->label123->Size = System::Drawing::Size(107, 13);
		this->label123->TabIndex = 132;
		this->label123->Text = L"Mark Available Point:";
		// 
		// checkBox_mark_available_point
		// 
		this->checkBox_mark_available_point->AutoSize = true;
		this->checkBox_mark_available_point->Location = System::Drawing::Point(252, 131);
		this->checkBox_mark_available_point->Name = L"checkBox_mark_available_point";
		this->checkBox_mark_available_point->Size = System::Drawing::Size(15, 14);
		this->checkBox_mark_available_point->TabIndex = 131;
		this->checkBox_mark_available_point->UseVisualStyleBackColor = true;
		this->checkBox_mark_available_point->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_mark_available_point);
		// 
		// label122
		// 
		this->label122->AutoSize = true;
		this->label122->Location = System::Drawing::Point(6, 134);
		this->label122->Name = L"label122";
		this->label122->Size = System::Drawing::Size(104, 13);
		this->label122->TabIndex = 130;
		this->label122->Text = L"Mark Available Icon:";
		// 
		// checkBox_mark_available_icon
		// 
		this->checkBox_mark_available_icon->AutoSize = true;
		this->checkBox_mark_available_icon->Location = System::Drawing::Point(118, 134);
		this->checkBox_mark_available_icon->Name = L"checkBox_mark_available_icon";
		this->checkBox_mark_available_icon->Size = System::Drawing::Size(15, 14);
		this->checkBox_mark_available_icon->TabIndex = 129;
		this->checkBox_mark_available_icon->UseVisualStyleBackColor = true;
		this->checkBox_mark_available_icon->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_mark_available_icon);
		// 
		// textBox_instant_teleport_location_z
		// 
		this->textBox_instant_teleport_location_z->Location = System::Drawing::Point(466, 39);
		this->textBox_instant_teleport_location_z->Name = L"textBox_instant_teleport_location_z";
		this->textBox_instant_teleport_location_z->Size = System::Drawing::Size(70, 20);
		this->textBox_instant_teleport_location_z->TabIndex = 128;
		this->textBox_instant_teleport_location_z->Leave += gcnew System::EventHandler(this, &MainWindow::change_instant_teleport_location_z);
		// 
		// label121
		// 
		this->label121->AutoSize = true;
		this->label121->Location = System::Drawing::Point(443, 42);
		this->label121->Name = L"label121";
		this->label121->Size = System::Drawing::Size(17, 13);
		this->label121->TabIndex = 127;
		this->label121->Text = L"Z:";
		// 
		// textBox_instant_teleport_location_alt
		// 
		this->textBox_instant_teleport_location_alt->Location = System::Drawing::Point(367, 39);
		this->textBox_instant_teleport_location_alt->Name = L"textBox_instant_teleport_location_alt";
		this->textBox_instant_teleport_location_alt->Size = System::Drawing::Size(70, 20);
		this->textBox_instant_teleport_location_alt->TabIndex = 126;
		this->textBox_instant_teleport_location_alt->Leave += gcnew System::EventHandler(this, &MainWindow::change_instant_teleport_location_alt);
		// 
		// label120
		// 
		this->label120->AutoSize = true;
		this->label120->Location = System::Drawing::Point(339, 42);
		this->label120->Name = L"label120";
		this->label120->Size = System::Drawing::Size(22, 13);
		this->label120->TabIndex = 125;
		this->label120->Text = L"Alt:";
		// 
		// textBox_instant_teleport_location_x
		// 
		this->textBox_instant_teleport_location_x->Location = System::Drawing::Point(263, 39);
		this->textBox_instant_teleport_location_x->Name = L"textBox_instant_teleport_location_x";
		this->textBox_instant_teleport_location_x->Size = System::Drawing::Size(70, 20);
		this->textBox_instant_teleport_location_x->TabIndex = 124;
		this->textBox_instant_teleport_location_x->Leave += gcnew System::EventHandler(this, &MainWindow::change_instant_teleport_location_x);
		// 
		// label119
		// 
		this->label119->AutoSize = true;
		this->label119->Location = System::Drawing::Point(240, 42);
		this->label119->Name = L"label119";
		this->label119->Size = System::Drawing::Size(17, 13);
		this->label119->TabIndex = 123;
		this->label119->Text = L"X:";
		// 
		// textBox_instant_teleport_location_map_id
		// 
		this->textBox_instant_teleport_location_map_id->Location = System::Drawing::Point(190, 39);
		this->textBox_instant_teleport_location_map_id->Name = L"textBox_instant_teleport_location_map_id";
		this->textBox_instant_teleport_location_map_id->Size = System::Drawing::Size(44, 20);
		this->textBox_instant_teleport_location_map_id->TabIndex = 122;
		this->textBox_instant_teleport_location_map_id->Leave += gcnew System::EventHandler(this, &MainWindow::change_instant_teleport_location_map_id);
		// 
		// label118
		// 
		this->label118->AutoSize = true;
		this->label118->Location = System::Drawing::Point(139, 42);
		this->label118->Name = L"label118";
		this->label118->Size = System::Drawing::Size(45, 13);
		this->label118->TabIndex = 121;
		this->label118->Text = L"Map ID:";
		// 
		// textBox_unknown_level
		// 
		this->textBox_unknown_level->Location = System::Drawing::Point(118, 108);
		this->textBox_unknown_level->Name = L"textBox_unknown_level";
		this->textBox_unknown_level->Size = System::Drawing::Size(44, 20);
		this->textBox_unknown_level->TabIndex = 120;
		this->textBox_unknown_level->Leave += gcnew System::EventHandler(this, &MainWindow::change_unknown_level);
		// 
		// label117
		// 
		this->label117->AutoSize = true;
		this->label117->Location = System::Drawing::Point(6, 111);
		this->label117->Name = L"label117";
		this->label117->Size = System::Drawing::Size(85, 13);
		this->label117->TabIndex = 119;
		this->label117->Text = L"Unknown Level:";
		// 
		// label108
		// 
		this->label108->AutoSize = true;
		this->label108->ForeColor = System::Drawing::Color::Red;
		this->label108->Location = System::Drawing::Point(6, 19);
		this->label108->Name = L"label108";
		this->label108->Size = System::Drawing::Size(71, 13);
		this->label108->TabIndex = 98;
		this->label108->Text = L"Unknown 17:";
		// 
		// checkBox_unknown_23
		// 
		this->checkBox_unknown_23->AutoSize = true;
		this->checkBox_unknown_23->Location = System::Drawing::Point(608, 88);
		this->checkBox_unknown_23->Name = L"checkBox_unknown_23";
		this->checkBox_unknown_23->Size = System::Drawing::Size(15, 14);
		this->checkBox_unknown_23->TabIndex = 117;
		this->checkBox_unknown_23->UseVisualStyleBackColor = true;
		this->checkBox_unknown_23->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_unknown_23);
		// 
		// checkBox_unknown_17
		// 
		this->checkBox_unknown_17->AutoSize = true;
		this->checkBox_unknown_17->Location = System::Drawing::Point(118, 19);
		this->checkBox_unknown_17->Name = L"checkBox_unknown_17";
		this->checkBox_unknown_17->Size = System::Drawing::Size(15, 14);
		this->checkBox_unknown_17->TabIndex = 97;
		this->checkBox_unknown_17->UseVisualStyleBackColor = true;
		this->checkBox_unknown_17->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_unknown_17);
		// 
		// label116
		// 
		this->label116->AutoSize = true;
		this->label116->Location = System::Drawing::Point(531, 88);
		this->label116->Name = L"label116";
		this->label116->Size = System::Drawing::Size(71, 13);
		this->label116->TabIndex = 118;
		this->label116->Text = L"Unknown 23:";
		// 
		// label109
		// 
		this->label109->AutoSize = true;
		this->label109->Location = System::Drawing::Point(6, 42);
		this->label109->Name = L"label109";
		this->label109->Size = System::Drawing::Size(106, 13);
		this->label109->TabIndex = 104;
		this->label109->Text = L"Has Instant Teleport:";
		// 
		// checkBox_unknown_22
		// 
		this->checkBox_unknown_22->AutoSize = true;
		this->checkBox_unknown_22->Location = System::Drawing::Point(510, 88);
		this->checkBox_unknown_22->Name = L"checkBox_unknown_22";
		this->checkBox_unknown_22->Size = System::Drawing::Size(15, 14);
		this->checkBox_unknown_22->TabIndex = 115;
		this->checkBox_unknown_22->UseVisualStyleBackColor = true;
		this->checkBox_unknown_22->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_unknown_22);
		// 
		// checkBox_has_instant_teleport
		// 
		this->checkBox_has_instant_teleport->AutoSize = true;
		this->checkBox_has_instant_teleport->Location = System::Drawing::Point(118, 42);
		this->checkBox_has_instant_teleport->Name = L"checkBox_has_instant_teleport";
		this->checkBox_has_instant_teleport->Size = System::Drawing::Size(15, 14);
		this->checkBox_has_instant_teleport->TabIndex = 103;
		this->checkBox_has_instant_teleport->UseVisualStyleBackColor = true;
		this->checkBox_has_instant_teleport->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_has_instant_teleport);
		// 
		// label115
		// 
		this->label115->AutoSize = true;
		this->label115->ForeColor = System::Drawing::Color::Gray;
		this->label115->Location = System::Drawing::Point(433, 88);
		this->label115->Name = L"label115";
		this->label115->Size = System::Drawing::Size(71, 13);
		this->label115->TabIndex = 116;
		this->label115->Text = L"Unknown 22:";
		// 
		// label110
		// 
		this->label110->AutoSize = true;
		this->label110->Location = System::Drawing::Point(6, 88);
		this->label110->Name = L"label110";
		this->label110->Size = System::Drawing::Size(71, 13);
		this->label110->TabIndex = 106;
		this->label110->Text = L"Unknown 18:";
		// 
		// checkBox_unknown_21
		// 
		this->checkBox_unknown_21->AutoSize = true;
		this->checkBox_unknown_21->Location = System::Drawing::Point(412, 88);
		this->checkBox_unknown_21->Name = L"checkBox_unknown_21";
		this->checkBox_unknown_21->Size = System::Drawing::Size(15, 14);
		this->checkBox_unknown_21->TabIndex = 113;
		this->checkBox_unknown_21->UseVisualStyleBackColor = true;
		this->checkBox_unknown_21->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_unknown_21);
		// 
		// checkBox_unknown_18
		// 
		this->checkBox_unknown_18->AutoSize = true;
		this->checkBox_unknown_18->Location = System::Drawing::Point(118, 88);
		this->checkBox_unknown_18->Name = L"checkBox_unknown_18";
		this->checkBox_unknown_18->Size = System::Drawing::Size(15, 14);
		this->checkBox_unknown_18->TabIndex = 105;
		this->checkBox_unknown_18->UseVisualStyleBackColor = true;
		this->checkBox_unknown_18->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_unknown_18);
		// 
		// label114
		// 
		this->label114->AutoSize = true;
		this->label114->ForeColor = System::Drawing::Color::Gray;
		this->label114->Location = System::Drawing::Point(335, 88);
		this->label114->Name = L"label114";
		this->label114->Size = System::Drawing::Size(71, 13);
		this->label114->TabIndex = 114;
		this->label114->Text = L"Unknown 21:";
		// 
		// label111
		// 
		this->label111->AutoSize = true;
		this->label111->Location = System::Drawing::Point(139, 88);
		this->label111->Name = L"label111";
		this->label111->Size = System::Drawing::Size(71, 13);
		this->label111->TabIndex = 108;
		this->label111->Text = L"Unknown 19:";
		// 
		// textBox_ai_trigger
		// 
		this->textBox_ai_trigger->Location = System::Drawing::Point(118, 62);
		this->textBox_ai_trigger->Name = L"textBox_ai_trigger";
		this->textBox_ai_trigger->Size = System::Drawing::Size(44, 20);
		this->textBox_ai_trigger->TabIndex = 112;
		this->textBox_ai_trigger->Leave += gcnew System::EventHandler(this, &MainWindow::change_ai_trigger);
		// 
		// checkBox_unknown_19
		// 
		this->checkBox_unknown_19->AutoSize = true;
		this->checkBox_unknown_19->Location = System::Drawing::Point(216, 88);
		this->checkBox_unknown_19->Name = L"checkBox_unknown_19";
		this->checkBox_unknown_19->Size = System::Drawing::Size(15, 14);
		this->checkBox_unknown_19->TabIndex = 107;
		this->checkBox_unknown_19->UseVisualStyleBackColor = true;
		this->checkBox_unknown_19->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_unknown_19);
		// 
		// label113
		// 
		this->label113->AutoSize = true;
		this->label113->Location = System::Drawing::Point(6, 65);
		this->label113->Name = L"label113";
		this->label113->Size = System::Drawing::Size(99, 13);
		this->label113->TabIndex = 111;
		this->label113->Text = L"Creature Builder ID:";
		// 
		// label112
		// 
		this->label112->AutoSize = true;
		this->label112->Location = System::Drawing::Point(237, 88);
		this->label112->Name = L"label112";
		this->label112->Size = System::Drawing::Size(71, 13);
		this->label112->TabIndex = 110;
		this->label112->Text = L"Unknown 20:";
		// 
		// checkBox_unknown_20
		// 
		this->checkBox_unknown_20->AutoSize = true;
		this->checkBox_unknown_20->Location = System::Drawing::Point(314, 88);
		this->checkBox_unknown_20->Name = L"checkBox_unknown_20";
		this->checkBox_unknown_20->Size = System::Drawing::Size(15, 14);
		this->checkBox_unknown_20->TabIndex = 109;
		this->checkBox_unknown_20->UseVisualStyleBackColor = true;
		this->checkBox_unknown_20->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_unknown_20);
		// 
		// groupBox_valid_location
		// 
		this->groupBox_valid_location->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->groupBox_valid_location->Controls->Add(this->checkBox_valid_locations_has_spans);
		this->groupBox_valid_location->Controls->Add(this->label53);
		this->groupBox_valid_location->Controls->Add(this->textBox_valid_locations_unknown_1);
		this->groupBox_valid_location->Controls->Add(this->dataGridView_valid_location_spans);
		this->groupBox_valid_location->Controls->Add(this->textBox_valid_locations_map_id);
		this->groupBox_valid_location->Controls->Add(this->label12);
		this->groupBox_valid_location->Controls->Add(this->label13);
		this->groupBox_valid_location->ForeColor = System::Drawing::Color::Gray;
		this->groupBox_valid_location->Location = System::Drawing::Point(3, 197);
		this->groupBox_valid_location->Name = L"groupBox_valid_location";
		this->groupBox_valid_location->Size = System::Drawing::Size(671, 91);
		this->groupBox_valid_location->TabIndex = 97;
		this->groupBox_valid_location->TabStop = false;
		this->groupBox_valid_location->Text = L"FAIL ON LEAVE";
		// 
		// checkBox_valid_locations_has_spans
		// 
		this->checkBox_valid_locations_has_spans->AutoSize = true;
		this->checkBox_valid_locations_has_spans->Location = System::Drawing::Point(77, 19);
		this->checkBox_valid_locations_has_spans->Name = L"checkBox_valid_locations_has_spans";
		this->checkBox_valid_locations_has_spans->Size = System::Drawing::Size(15, 14);
		this->checkBox_valid_locations_has_spans->TabIndex = 96;
		this->checkBox_valid_locations_has_spans->UseVisualStyleBackColor = true;
		this->checkBox_valid_locations_has_spans->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_valid_locations_has_spans);
		// 
		// textBox_valid_locations_unknown_1
		// 
		this->textBox_valid_locations_unknown_1->Location = System::Drawing::Point(77, 65);
		this->textBox_valid_locations_unknown_1->Name = L"textBox_valid_locations_unknown_1";
		this->textBox_valid_locations_unknown_1->Size = System::Drawing::Size(122, 20);
		this->textBox_valid_locations_unknown_1->TabIndex = 94;
		this->textBox_valid_locations_unknown_1->Leave += gcnew System::EventHandler(this, &MainWindow::change_valid_locations_unknown_1);
		// 
		// dataGridView_valid_location_spans
		// 
		this->dataGridView_valid_location_spans->AllowUserToAddRows = false;
		this->dataGridView_valid_location_spans->AllowUserToDeleteRows = false;
		this->dataGridView_valid_location_spans->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
			| System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->dataGridView_valid_location_spans->BackgroundColor = System::Drawing::SystemColors::Window;
		this->dataGridView_valid_location_spans->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
		this->dataGridView_valid_location_spans->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
		this->dataGridView_valid_location_spans->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {this->dataGridViewTextBoxColumn49, 
			this->dataGridViewTextBoxColumn50, this->dataGridViewTextBoxColumn51, this->dataGridViewTextBoxColumn52, this->dataGridViewTextBoxColumn53, 
			this->dataGridViewTextBoxColumn54});
		this->dataGridView_valid_location_spans->ContextMenuStrip = this->contextMenuStrip_valid_location;
		this->dataGridView_valid_location_spans->Location = System::Drawing::Point(205, 10);
		this->dataGridView_valid_location_spans->MultiSelect = false;
		this->dataGridView_valid_location_spans->Name = L"dataGridView_valid_location_spans";
		this->dataGridView_valid_location_spans->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
		dataGridViewCellStyle48->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
		dataGridViewCellStyle48->BackColor = System::Drawing::SystemColors::Control;
		dataGridViewCellStyle48->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		dataGridViewCellStyle48->ForeColor = System::Drawing::SystemColors::WindowText;
		dataGridViewCellStyle48->SelectionBackColor = System::Drawing::SystemColors::Highlight;
		dataGridViewCellStyle48->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
		dataGridViewCellStyle48->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView_valid_location_spans->RowHeadersDefaultCellStyle = dataGridViewCellStyle48;
		this->dataGridView_valid_location_spans->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::AutoSizeToFirstHeader;
		this->dataGridView_valid_location_spans->RowTemplate->Height = 18;
		this->dataGridView_valid_location_spans->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView_valid_location_spans->Size = System::Drawing::Size(460, 75);
		this->dataGridView_valid_location_spans->TabIndex = 91;
		this->dataGridView_valid_location_spans->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::change_valid_locations_span);
		// 
		// dataGridViewTextBoxColumn49
		// 
		this->dataGridViewTextBoxColumn49->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
		dataGridViewCellStyle42->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn49->DefaultCellStyle = dataGridViewCellStyle42;
		this->dataGridViewTextBoxColumn49->HeaderText = L"North";
		this->dataGridViewTextBoxColumn49->Name = L"dataGridViewTextBoxColumn49";
		this->dataGridViewTextBoxColumn49->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		// 
		// dataGridViewTextBoxColumn50
		// 
		this->dataGridViewTextBoxColumn50->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
		dataGridViewCellStyle43->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn50->DefaultCellStyle = dataGridViewCellStyle43;
		this->dataGridViewTextBoxColumn50->HeaderText = L"South";
		this->dataGridViewTextBoxColumn50->Name = L"dataGridViewTextBoxColumn50";
		this->dataGridViewTextBoxColumn50->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		// 
		// dataGridViewTextBoxColumn51
		// 
		this->dataGridViewTextBoxColumn51->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
		dataGridViewCellStyle44->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn51->DefaultCellStyle = dataGridViewCellStyle44;
		this->dataGridViewTextBoxColumn51->HeaderText = L"Weast";
		this->dataGridViewTextBoxColumn51->Name = L"dataGridViewTextBoxColumn51";
		this->dataGridViewTextBoxColumn51->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		// 
		// dataGridViewTextBoxColumn52
		// 
		this->dataGridViewTextBoxColumn52->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
		dataGridViewCellStyle45->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn52->DefaultCellStyle = dataGridViewCellStyle45;
		this->dataGridViewTextBoxColumn52->HeaderText = L"East";
		this->dataGridViewTextBoxColumn52->Name = L"dataGridViewTextBoxColumn52";
		this->dataGridViewTextBoxColumn52->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		// 
		// dataGridViewTextBoxColumn53
		// 
		this->dataGridViewTextBoxColumn53->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
		dataGridViewCellStyle46->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn53->DefaultCellStyle = dataGridViewCellStyle46;
		this->dataGridViewTextBoxColumn53->HeaderText = L"Low";
		this->dataGridViewTextBoxColumn53->Name = L"dataGridViewTextBoxColumn53";
		this->dataGridViewTextBoxColumn53->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		// 
		// dataGridViewTextBoxColumn54
		// 
		this->dataGridViewTextBoxColumn54->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
		dataGridViewCellStyle47->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn54->DefaultCellStyle = dataGridViewCellStyle47;
		this->dataGridViewTextBoxColumn54->HeaderText = L"High";
		this->dataGridViewTextBoxColumn54->Name = L"dataGridViewTextBoxColumn54";
		this->dataGridViewTextBoxColumn54->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		// 
		// contextMenuStrip_valid_location
		// 
		this->contextMenuStrip_valid_location->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->toolStripMenuItem5, 
			this->toolStripMenuItem6});
		this->contextMenuStrip_valid_location->Name = L"contextMenuStrip1";
		this->contextMenuStrip_valid_location->Size = System::Drawing::Size(184, 48);
		// 
		// toolStripMenuItem5
		// 
		this->toolStripMenuItem5->Name = L"toolStripMenuItem5";
		this->toolStripMenuItem5->Size = System::Drawing::Size(183, 22);
		this->toolStripMenuItem5->Text = L"Add Location Span";
		this->toolStripMenuItem5->Click += gcnew System::EventHandler(this, &MainWindow::add_valid_locations_span);
		// 
		// toolStripMenuItem6
		// 
		this->toolStripMenuItem6->Name = L"toolStripMenuItem6";
		this->toolStripMenuItem6->Size = System::Drawing::Size(183, 22);
		this->toolStripMenuItem6->Text = L"Remove Location Span";
		this->toolStripMenuItem6->Click += gcnew System::EventHandler(this, &MainWindow::remove_valid_locations_span);
		// 
		// textBox_valid_locations_map_id
		// 
		this->textBox_valid_locations_map_id->Location = System::Drawing::Point(77, 39);
		this->textBox_valid_locations_map_id->Name = L"textBox_valid_locations_map_id";
		this->textBox_valid_locations_map_id->Size = System::Drawing::Size(51, 20);
		this->textBox_valid_locations_map_id->TabIndex = 92;
		this->textBox_valid_locations_map_id->Leave += gcnew System::EventHandler(this, &MainWindow::change_valid_locations_map_id);
		// 
		// groupBox_fail_location
		// 
		this->groupBox_fail_location->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->groupBox_fail_location->Controls->Add(this->checkBox_fail_locations_has_spans);
		this->groupBox_fail_location->Controls->Add(this->label15);
		this->groupBox_fail_location->Controls->Add(this->textBox_fail_locations_unknown_1);
		this->groupBox_fail_location->Controls->Add(this->dataGridView_fail_location_spans);
		this->groupBox_fail_location->Controls->Add(this->textBox_fail_locations_map_id);
		this->groupBox_fail_location->Controls->Add(this->label10);
		this->groupBox_fail_location->Controls->Add(this->label11);
		this->groupBox_fail_location->ForeColor = System::Drawing::Color::Gray;
		this->groupBox_fail_location->Location = System::Drawing::Point(3, 100);
		this->groupBox_fail_location->Name = L"groupBox_fail_location";
		this->groupBox_fail_location->Size = System::Drawing::Size(671, 91);
		this->groupBox_fail_location->TabIndex = 96;
		this->groupBox_fail_location->TabStop = false;
		this->groupBox_fail_location->Text = L"FAIL ON ENTER";
		// 
		// checkBox_fail_locations_has_spans
		// 
		this->checkBox_fail_locations_has_spans->AutoSize = true;
		this->checkBox_fail_locations_has_spans->Location = System::Drawing::Point(77, 19);
		this->checkBox_fail_locations_has_spans->Name = L"checkBox_fail_locations_has_spans";
		this->checkBox_fail_locations_has_spans->Size = System::Drawing::Size(15, 14);
		this->checkBox_fail_locations_has_spans->TabIndex = 96;
		this->checkBox_fail_locations_has_spans->UseVisualStyleBackColor = true;
		this->checkBox_fail_locations_has_spans->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_fail_locations_has_spans);
		// 
		// textBox_fail_locations_unknown_1
		// 
		this->textBox_fail_locations_unknown_1->Location = System::Drawing::Point(77, 65);
		this->textBox_fail_locations_unknown_1->Name = L"textBox_fail_locations_unknown_1";
		this->textBox_fail_locations_unknown_1->Size = System::Drawing::Size(122, 20);
		this->textBox_fail_locations_unknown_1->TabIndex = 94;
		this->textBox_fail_locations_unknown_1->Leave += gcnew System::EventHandler(this, &MainWindow::change_fail_locations_unknown_1);
		// 
		// dataGridView_fail_location_spans
		// 
		this->dataGridView_fail_location_spans->AllowUserToAddRows = false;
		this->dataGridView_fail_location_spans->AllowUserToDeleteRows = false;
		this->dataGridView_fail_location_spans->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
			| System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->dataGridView_fail_location_spans->BackgroundColor = System::Drawing::SystemColors::Window;
		this->dataGridView_fail_location_spans->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
		this->dataGridView_fail_location_spans->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
		this->dataGridView_fail_location_spans->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {this->dataGridViewTextBoxColumn43, 
			this->dataGridViewTextBoxColumn44, this->dataGridViewTextBoxColumn45, this->dataGridViewTextBoxColumn46, this->dataGridViewTextBoxColumn47, 
			this->dataGridViewTextBoxColumn48});
		this->dataGridView_fail_location_spans->ContextMenuStrip = this->contextMenuStrip_fail_location;
		this->dataGridView_fail_location_spans->Location = System::Drawing::Point(205, 10);
		this->dataGridView_fail_location_spans->MultiSelect = false;
		this->dataGridView_fail_location_spans->Name = L"dataGridView_fail_location_spans";
		this->dataGridView_fail_location_spans->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
		dataGridViewCellStyle55->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
		dataGridViewCellStyle55->BackColor = System::Drawing::SystemColors::Control;
		dataGridViewCellStyle55->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		dataGridViewCellStyle55->ForeColor = System::Drawing::SystemColors::WindowText;
		dataGridViewCellStyle55->SelectionBackColor = System::Drawing::SystemColors::Highlight;
		dataGridViewCellStyle55->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
		dataGridViewCellStyle55->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView_fail_location_spans->RowHeadersDefaultCellStyle = dataGridViewCellStyle55;
		this->dataGridView_fail_location_spans->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::AutoSizeToFirstHeader;
		this->dataGridView_fail_location_spans->RowTemplate->Height = 18;
		this->dataGridView_fail_location_spans->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView_fail_location_spans->Size = System::Drawing::Size(460, 75);
		this->dataGridView_fail_location_spans->TabIndex = 91;
		this->dataGridView_fail_location_spans->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::change_fail_locations_span);
		// 
		// dataGridViewTextBoxColumn43
		// 
		this->dataGridViewTextBoxColumn43->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
		dataGridViewCellStyle49->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn43->DefaultCellStyle = dataGridViewCellStyle49;
		this->dataGridViewTextBoxColumn43->HeaderText = L"North";
		this->dataGridViewTextBoxColumn43->Name = L"dataGridViewTextBoxColumn43";
		this->dataGridViewTextBoxColumn43->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		// 
		// dataGridViewTextBoxColumn44
		// 
		this->dataGridViewTextBoxColumn44->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
		dataGridViewCellStyle50->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn44->DefaultCellStyle = dataGridViewCellStyle50;
		this->dataGridViewTextBoxColumn44->HeaderText = L"South";
		this->dataGridViewTextBoxColumn44->Name = L"dataGridViewTextBoxColumn44";
		this->dataGridViewTextBoxColumn44->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		// 
		// dataGridViewTextBoxColumn45
		// 
		this->dataGridViewTextBoxColumn45->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
		dataGridViewCellStyle51->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn45->DefaultCellStyle = dataGridViewCellStyle51;
		this->dataGridViewTextBoxColumn45->HeaderText = L"Weast";
		this->dataGridViewTextBoxColumn45->Name = L"dataGridViewTextBoxColumn45";
		this->dataGridViewTextBoxColumn45->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		// 
		// dataGridViewTextBoxColumn46
		// 
		this->dataGridViewTextBoxColumn46->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
		dataGridViewCellStyle52->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn46->DefaultCellStyle = dataGridViewCellStyle52;
		this->dataGridViewTextBoxColumn46->HeaderText = L"East";
		this->dataGridViewTextBoxColumn46->Name = L"dataGridViewTextBoxColumn46";
		this->dataGridViewTextBoxColumn46->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		// 
		// dataGridViewTextBoxColumn47
		// 
		this->dataGridViewTextBoxColumn47->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
		dataGridViewCellStyle53->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn47->DefaultCellStyle = dataGridViewCellStyle53;
		this->dataGridViewTextBoxColumn47->HeaderText = L"Low";
		this->dataGridViewTextBoxColumn47->Name = L"dataGridViewTextBoxColumn47";
		this->dataGridViewTextBoxColumn47->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		// 
		// dataGridViewTextBoxColumn48
		// 
		this->dataGridViewTextBoxColumn48->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
		dataGridViewCellStyle54->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn48->DefaultCellStyle = dataGridViewCellStyle54;
		this->dataGridViewTextBoxColumn48->HeaderText = L"High";
		this->dataGridViewTextBoxColumn48->Name = L"dataGridViewTextBoxColumn48";
		this->dataGridViewTextBoxColumn48->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		// 
		// contextMenuStrip_fail_location
		// 
		this->contextMenuStrip_fail_location->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->toolStripMenuItem3, 
			this->toolStripMenuItem4});
		this->contextMenuStrip_fail_location->Name = L"contextMenuStrip1";
		this->contextMenuStrip_fail_location->Size = System::Drawing::Size(184, 48);
		// 
		// toolStripMenuItem3
		// 
		this->toolStripMenuItem3->Name = L"toolStripMenuItem3";
		this->toolStripMenuItem3->Size = System::Drawing::Size(183, 22);
		this->toolStripMenuItem3->Text = L"Add Location Span";
		this->toolStripMenuItem3->Click += gcnew System::EventHandler(this, &MainWindow::add_fail_locations_span);
		// 
		// toolStripMenuItem4
		// 
		this->toolStripMenuItem4->Name = L"toolStripMenuItem4";
		this->toolStripMenuItem4->Size = System::Drawing::Size(183, 22);
		this->toolStripMenuItem4->Text = L"Remove Location Span";
		this->toolStripMenuItem4->Click += gcnew System::EventHandler(this, &MainWindow::remove_fail_locations_span);
		// 
		// textBox_fail_locations_map_id
		// 
		this->textBox_fail_locations_map_id->Location = System::Drawing::Point(77, 39);
		this->textBox_fail_locations_map_id->Name = L"textBox_fail_locations_map_id";
		this->textBox_fail_locations_map_id->Size = System::Drawing::Size(51, 20);
		this->textBox_fail_locations_map_id->TabIndex = 92;
		this->textBox_fail_locations_map_id->Leave += gcnew System::EventHandler(this, &MainWindow::change_fail_locations_map_id);
		// 
		// groupBox_trigger_location
		// 
		this->groupBox_trigger_location->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->groupBox_trigger_location->Controls->Add(this->textBox_trigger_locations_unknown_1);
		this->groupBox_trigger_location->Controls->Add(this->label14);
		this->groupBox_trigger_location->Controls->Add(this->dataGridView_trigger_location_spans);
		this->groupBox_trigger_location->Controls->Add(this->checkBox_trigger_locations_has_spans);
		this->groupBox_trigger_location->Controls->Add(this->textBox_trigger_locations_map_id);
		this->groupBox_trigger_location->Controls->Add(this->label106);
		this->groupBox_trigger_location->Controls->Add(this->label107);
		this->groupBox_trigger_location->Location = System::Drawing::Point(3, 3);
		this->groupBox_trigger_location->Name = L"groupBox_trigger_location";
		this->groupBox_trigger_location->Size = System::Drawing::Size(671, 91);
		this->groupBox_trigger_location->TabIndex = 95;
		this->groupBox_trigger_location->TabStop = false;
		this->groupBox_trigger_location->Text = L"TRIGGER ON ENTER";
		// 
		// textBox_trigger_locations_unknown_1
		// 
		this->textBox_trigger_locations_unknown_1->Location = System::Drawing::Point(77, 65);
		this->textBox_trigger_locations_unknown_1->Name = L"textBox_trigger_locations_unknown_1";
		this->textBox_trigger_locations_unknown_1->Size = System::Drawing::Size(122, 20);
		this->textBox_trigger_locations_unknown_1->TabIndex = 96;
		this->textBox_trigger_locations_unknown_1->Leave += gcnew System::EventHandler(this, &MainWindow::change_trigger_locations_unknown_1);
		// 
		// dataGridView_trigger_location_spans
		// 
		this->dataGridView_trigger_location_spans->AllowUserToAddRows = false;
		this->dataGridView_trigger_location_spans->AllowUserToDeleteRows = false;
		this->dataGridView_trigger_location_spans->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
			| System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->dataGridView_trigger_location_spans->BackgroundColor = System::Drawing::SystemColors::Window;
		this->dataGridView_trigger_location_spans->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
		this->dataGridView_trigger_location_spans->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
		this->dataGridView_trigger_location_spans->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {this->dataGridViewTextBoxColumn37, 
			this->dataGridViewTextBoxColumn38, this->dataGridViewTextBoxColumn39, this->dataGridViewTextBoxColumn40, this->dataGridViewTextBoxColumn41, 
			this->dataGridViewTextBoxColumn42});
		this->dataGridView_trigger_location_spans->ContextMenuStrip = this->contextMenuStrip_trigger_location;
		this->dataGridView_trigger_location_spans->Location = System::Drawing::Point(205, 10);
		this->dataGridView_trigger_location_spans->MultiSelect = false;
		this->dataGridView_trigger_location_spans->Name = L"dataGridView_trigger_location_spans";
		this->dataGridView_trigger_location_spans->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
		dataGridViewCellStyle62->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
		dataGridViewCellStyle62->BackColor = System::Drawing::SystemColors::Control;
		dataGridViewCellStyle62->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		dataGridViewCellStyle62->ForeColor = System::Drawing::SystemColors::WindowText;
		dataGridViewCellStyle62->SelectionBackColor = System::Drawing::SystemColors::Highlight;
		dataGridViewCellStyle62->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
		dataGridViewCellStyle62->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView_trigger_location_spans->RowHeadersDefaultCellStyle = dataGridViewCellStyle62;
		this->dataGridView_trigger_location_spans->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::AutoSizeToFirstHeader;
		this->dataGridView_trigger_location_spans->RowTemplate->Height = 18;
		this->dataGridView_trigger_location_spans->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView_trigger_location_spans->Size = System::Drawing::Size(460, 75);
		this->dataGridView_trigger_location_spans->TabIndex = 91;
		this->dataGridView_trigger_location_spans->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::change_trigger_locations_span);
		// 
		// dataGridViewTextBoxColumn37
		// 
		this->dataGridViewTextBoxColumn37->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
		dataGridViewCellStyle56->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn37->DefaultCellStyle = dataGridViewCellStyle56;
		this->dataGridViewTextBoxColumn37->HeaderText = L"North";
		this->dataGridViewTextBoxColumn37->Name = L"dataGridViewTextBoxColumn37";
		this->dataGridViewTextBoxColumn37->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		// 
		// dataGridViewTextBoxColumn38
		// 
		this->dataGridViewTextBoxColumn38->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
		dataGridViewCellStyle57->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn38->DefaultCellStyle = dataGridViewCellStyle57;
		this->dataGridViewTextBoxColumn38->HeaderText = L"South";
		this->dataGridViewTextBoxColumn38->Name = L"dataGridViewTextBoxColumn38";
		this->dataGridViewTextBoxColumn38->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		// 
		// dataGridViewTextBoxColumn39
		// 
		this->dataGridViewTextBoxColumn39->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
		dataGridViewCellStyle58->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn39->DefaultCellStyle = dataGridViewCellStyle58;
		this->dataGridViewTextBoxColumn39->HeaderText = L"Weast";
		this->dataGridViewTextBoxColumn39->Name = L"dataGridViewTextBoxColumn39";
		this->dataGridViewTextBoxColumn39->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		// 
		// dataGridViewTextBoxColumn40
		// 
		this->dataGridViewTextBoxColumn40->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
		dataGridViewCellStyle59->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn40->DefaultCellStyle = dataGridViewCellStyle59;
		this->dataGridViewTextBoxColumn40->HeaderText = L"East";
		this->dataGridViewTextBoxColumn40->Name = L"dataGridViewTextBoxColumn40";
		this->dataGridViewTextBoxColumn40->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		// 
		// dataGridViewTextBoxColumn41
		// 
		this->dataGridViewTextBoxColumn41->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
		dataGridViewCellStyle60->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn41->DefaultCellStyle = dataGridViewCellStyle60;
		this->dataGridViewTextBoxColumn41->HeaderText = L"Low";
		this->dataGridViewTextBoxColumn41->Name = L"dataGridViewTextBoxColumn41";
		this->dataGridViewTextBoxColumn41->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		// 
		// dataGridViewTextBoxColumn42
		// 
		this->dataGridViewTextBoxColumn42->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
		dataGridViewCellStyle61->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn42->DefaultCellStyle = dataGridViewCellStyle61;
		this->dataGridViewTextBoxColumn42->HeaderText = L"High";
		this->dataGridViewTextBoxColumn42->Name = L"dataGridViewTextBoxColumn42";
		this->dataGridViewTextBoxColumn42->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		// 
		// contextMenuStrip_trigger_location
		// 
		this->contextMenuStrip_trigger_location->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->addToolStripMenuItem1, 
			this->removeToolStripMenuItem1});
		this->contextMenuStrip_trigger_location->Name = L"contextMenuStrip1";
		this->contextMenuStrip_trigger_location->Size = System::Drawing::Size(184, 48);
		// 
		// addToolStripMenuItem1
		// 
		this->addToolStripMenuItem1->Name = L"addToolStripMenuItem1";
		this->addToolStripMenuItem1->Size = System::Drawing::Size(183, 22);
		this->addToolStripMenuItem1->Text = L"Add Location Span";
		this->addToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainWindow::add_trigger_locations_span);
		// 
		// removeToolStripMenuItem1
		// 
		this->removeToolStripMenuItem1->Name = L"removeToolStripMenuItem1";
		this->removeToolStripMenuItem1->Size = System::Drawing::Size(183, 22);
		this->removeToolStripMenuItem1->Text = L"Remove Location Span";
		this->removeToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainWindow::remove_trigger_locations_span);
		// 
		// checkBox_trigger_locations_has_spans
		// 
		this->checkBox_trigger_locations_has_spans->AutoSize = true;
		this->checkBox_trigger_locations_has_spans->Location = System::Drawing::Point(77, 19);
		this->checkBox_trigger_locations_has_spans->Name = L"checkBox_trigger_locations_has_spans";
		this->checkBox_trigger_locations_has_spans->Size = System::Drawing::Size(15, 14);
		this->checkBox_trigger_locations_has_spans->TabIndex = 90;
		this->checkBox_trigger_locations_has_spans->UseVisualStyleBackColor = true;
		this->checkBox_trigger_locations_has_spans->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_trigger_locations_has_spans);
		// 
		// textBox_trigger_locations_map_id
		// 
		this->textBox_trigger_locations_map_id->Location = System::Drawing::Point(77, 39);
		this->textBox_trigger_locations_map_id->Name = L"textBox_trigger_locations_map_id";
		this->textBox_trigger_locations_map_id->Size = System::Drawing::Size(51, 20);
		this->textBox_trigger_locations_map_id->TabIndex = 92;
		this->textBox_trigger_locations_map_id->Leave += gcnew System::EventHandler(this, &MainWindow::change_trigger_locations_map_id);
		// 
		// groupBox_flags
		// 
		this->groupBox_flags->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->groupBox_flags->Controls->Add(this->textBox_player_limit);
		this->groupBox_flags->Controls->Add(this->label102);
		this->groupBox_flags->Controls->Add(this->label101);
		this->groupBox_flags->Controls->Add(this->checkBox_unknown_10);
		this->groupBox_flags->Controls->Add(this->label100);
		this->groupBox_flags->Controls->Add(this->checkBox_on_fail_parent_fail);
		this->groupBox_flags->Controls->Add(this->label99);
		this->groupBox_flags->Controls->Add(this->checkBox_fail_on_death);
		this->groupBox_flags->Controls->Add(this->label98);
		this->groupBox_flags->Controls->Add(this->checkBox_repeatable_after_failure);
		this->groupBox_flags->Controls->Add(this->label97);
		this->groupBox_flags->Controls->Add(this->checkBox_repeatable);
		this->groupBox_flags->Controls->Add(this->label96);
		this->groupBox_flags->Controls->Add(this->checkBox_can_give_up);
		this->groupBox_flags->Controls->Add(this->label95);
		this->groupBox_flags->Controls->Add(this->checkBox_on_success_parent_success);
		this->groupBox_flags->Controls->Add(this->label94);
		this->groupBox_flags->Controls->Add(this->checkBox_on_give_up_parent_fails);
		this->groupBox_flags->Controls->Add(this->label93);
		this->groupBox_flags->Controls->Add(this->checkBox_activate_next_subquest);
		this->groupBox_flags->Controls->Add(this->label92);
		this->groupBox_flags->Controls->Add(this->checkBox_activate_random_subquest);
		this->groupBox_flags->Controls->Add(this->label91);
		this->groupBox_flags->Controls->Add(this->checkBox_activate_first_subquest);
		this->groupBox_flags->Location = System::Drawing::Point(3, 347);
		this->groupBox_flags->Name = L"groupBox_flags";
		this->groupBox_flags->Size = System::Drawing::Size(671, 119);
		this->groupBox_flags->TabIndex = 4;
		this->groupBox_flags->TabStop = false;
		this->groupBox_flags->Text = L"FLAGS";
		// 
		// textBox_player_limit
		// 
		this->textBox_player_limit->Location = System::Drawing::Point(475, 36);
		this->textBox_player_limit->Name = L"textBox_player_limit";
		this->textBox_player_limit->Size = System::Drawing::Size(71, 20);
		this->textBox_player_limit->TabIndex = 97;
		this->textBox_player_limit->Leave += gcnew System::EventHandler(this, &MainWindow::change_player_limit);
		// 
		// label102
		// 
		this->label102->AutoSize = true;
		this->label102->Location = System::Drawing::Point(398, 39);
		this->label102->Name = L"label102";
		this->label102->Size = System::Drawing::Size(69, 13);
		this->label102->TabIndex = 85;
		this->label102->Text = L"Player Limit\?:";
		// 
		// label101
		// 
		this->label101->AutoSize = true;
		this->label101->Location = System::Drawing::Point(398, 19);
		this->label101->Name = L"label101";
		this->label101->Size = System::Drawing::Size(71, 13);
		this->label101->TabIndex = 83;
		this->label101->Text = L"Unknown 10:";
		// 
		// checkBox_unknown_10
		// 
		this->checkBox_unknown_10->AutoSize = true;
		this->checkBox_unknown_10->Location = System::Drawing::Point(475, 19);
		this->checkBox_unknown_10->Name = L"checkBox_unknown_10";
		this->checkBox_unknown_10->RightToLeft = System::Windows::Forms::RightToLeft::No;
		this->checkBox_unknown_10->Size = System::Drawing::Size(15, 14);
		this->checkBox_unknown_10->TabIndex = 82;
		this->checkBox_unknown_10->UseVisualStyleBackColor = true;
		this->checkBox_unknown_10->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_unknown_10);
		// 
		// label100
		// 
		this->label100->AutoSize = true;
		this->label100->Location = System::Drawing::Point(209, 97);
		this->label100->Name = L"label100";
		this->label100->Size = System::Drawing::Size(96, 13);
		this->label100->TabIndex = 81;
		this->label100->Text = L"On Fail Parent Fail:";
		// 
		// checkBox_on_fail_parent_fail
		// 
		this->checkBox_on_fail_parent_fail->AutoSize = true;
		this->checkBox_on_fail_parent_fail->Location = System::Drawing::Point(339, 97);
		this->checkBox_on_fail_parent_fail->Name = L"checkBox_on_fail_parent_fail";
		this->checkBox_on_fail_parent_fail->RightToLeft = System::Windows::Forms::RightToLeft::No;
		this->checkBox_on_fail_parent_fail->Size = System::Drawing::Size(15, 14);
		this->checkBox_on_fail_parent_fail->TabIndex = 80;
		this->checkBox_on_fail_parent_fail->UseVisualStyleBackColor = true;
		this->checkBox_on_fail_parent_fail->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_on_fail_parent_fail);
		// 
		// label99
		// 
		this->label99->AutoSize = true;
		this->label99->Location = System::Drawing::Point(209, 77);
		this->label99->Name = L"label99";
		this->label99->Size = System::Drawing::Size(75, 13);
		this->label99->TabIndex = 79;
		this->label99->Text = L"Fail On Death:";
		// 
		// checkBox_fail_on_death
		// 
		this->checkBox_fail_on_death->AutoSize = true;
		this->checkBox_fail_on_death->Location = System::Drawing::Point(339, 77);
		this->checkBox_fail_on_death->Name = L"checkBox_fail_on_death";
		this->checkBox_fail_on_death->RightToLeft = System::Windows::Forms::RightToLeft::No;
		this->checkBox_fail_on_death->Size = System::Drawing::Size(15, 14);
		this->checkBox_fail_on_death->TabIndex = 78;
		this->checkBox_fail_on_death->UseVisualStyleBackColor = true;
		this->checkBox_fail_on_death->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_fail_on_death);
		// 
		// label98
		// 
		this->label98->AutoSize = true;
		this->label98->Location = System::Drawing::Point(209, 59);
		this->label98->Name = L"label98";
		this->label98->Size = System::Drawing::Size(124, 13);
		this->label98->TabIndex = 77;
		this->label98->Text = L"Repeatable After Failure:";
		// 
		// checkBox_repeatable_after_failure
		// 
		this->checkBox_repeatable_after_failure->AutoSize = true;
		this->checkBox_repeatable_after_failure->Location = System::Drawing::Point(339, 59);
		this->checkBox_repeatable_after_failure->Name = L"checkBox_repeatable_after_failure";
		this->checkBox_repeatable_after_failure->RightToLeft = System::Windows::Forms::RightToLeft::No;
		this->checkBox_repeatable_after_failure->Size = System::Drawing::Size(15, 14);
		this->checkBox_repeatable_after_failure->TabIndex = 76;
		this->checkBox_repeatable_after_failure->UseVisualStyleBackColor = true;
		this->checkBox_repeatable_after_failure->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_repeatable_after_failure);
		// 
		// label97
		// 
		this->label97->AutoSize = true;
		this->label97->Location = System::Drawing::Point(209, 39);
		this->label97->Name = L"label97";
		this->label97->Size = System::Drawing::Size(65, 13);
		this->label97->TabIndex = 75;
		this->label97->Text = L"Repeatable:";
		// 
		// checkBox_repeatable
		// 
		this->checkBox_repeatable->AutoSize = true;
		this->checkBox_repeatable->Location = System::Drawing::Point(339, 39);
		this->checkBox_repeatable->Name = L"checkBox_repeatable";
		this->checkBox_repeatable->RightToLeft = System::Windows::Forms::RightToLeft::No;
		this->checkBox_repeatable->Size = System::Drawing::Size(15, 14);
		this->checkBox_repeatable->TabIndex = 74;
		this->checkBox_repeatable->UseVisualStyleBackColor = true;
		this->checkBox_repeatable->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_repeatable);
		// 
		// label96
		// 
		this->label96->AutoSize = true;
		this->label96->Location = System::Drawing::Point(209, 19);
		this->label96->Name = L"label96";
		this->label96->Size = System::Drawing::Size(71, 13);
		this->label96->TabIndex = 73;
		this->label96->Text = L"Can Give Up:";
		// 
		// checkBox_can_give_up
		// 
		this->checkBox_can_give_up->AutoSize = true;
		this->checkBox_can_give_up->Location = System::Drawing::Point(339, 19);
		this->checkBox_can_give_up->Name = L"checkBox_can_give_up";
		this->checkBox_can_give_up->RightToLeft = System::Windows::Forms::RightToLeft::No;
		this->checkBox_can_give_up->Size = System::Drawing::Size(15, 14);
		this->checkBox_can_give_up->TabIndex = 72;
		this->checkBox_can_give_up->UseVisualStyleBackColor = true;
		this->checkBox_can_give_up->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_can_give_up);
		// 
		// label95
		// 
		this->label95->AutoSize = true;
		this->label95->Location = System::Drawing::Point(6, 99);
		this->label95->Name = L"label95";
		this->label95->Size = System::Drawing::Size(146, 13);
		this->label95->TabIndex = 71;
		this->label95->Text = L"On Success Parent Success:";
		// 
		// checkBox_on_success_parent_success
		// 
		this->checkBox_on_success_parent_success->AutoSize = true;
		this->checkBox_on_success_parent_success->Location = System::Drawing::Point(159, 99);
		this->checkBox_on_success_parent_success->Name = L"checkBox_on_success_parent_success";
		this->checkBox_on_success_parent_success->RightToLeft = System::Windows::Forms::RightToLeft::No;
		this->checkBox_on_success_parent_success->Size = System::Drawing::Size(15, 14);
		this->checkBox_on_success_parent_success->TabIndex = 70;
		this->checkBox_on_success_parent_success->UseVisualStyleBackColor = true;
		this->checkBox_on_success_parent_success->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_on_success_parent_success);
		// 
		// label94
		// 
		this->label94->AutoSize = true;
		this->label94->Location = System::Drawing::Point(6, 79);
		this->label94->Name = L"label94";
		this->label94->Size = System::Drawing::Size(124, 13);
		this->label94->TabIndex = 69;
		this->label94->Text = L"On Give Up Parent Fails:";
		// 
		// checkBox_on_give_up_parent_fails
		// 
		this->checkBox_on_give_up_parent_fails->AutoSize = true;
		this->checkBox_on_give_up_parent_fails->Location = System::Drawing::Point(159, 79);
		this->checkBox_on_give_up_parent_fails->Name = L"checkBox_on_give_up_parent_fails";
		this->checkBox_on_give_up_parent_fails->RightToLeft = System::Windows::Forms::RightToLeft::No;
		this->checkBox_on_give_up_parent_fails->Size = System::Drawing::Size(15, 14);
		this->checkBox_on_give_up_parent_fails->TabIndex = 68;
		this->checkBox_on_give_up_parent_fails->UseVisualStyleBackColor = true;
		this->checkBox_on_give_up_parent_fails->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_on_give_up_parent_fails);
		// 
		// label93
		// 
		this->label93->AutoSize = true;
		this->label93->Location = System::Drawing::Point(6, 59);
		this->label93->Name = L"label93";
		this->label93->Size = System::Drawing::Size(122, 13);
		this->label93->TabIndex = 67;
		this->label93->Text = L"Activate Next Subquest:";
		// 
		// checkBox_activate_next_subquest
		// 
		this->checkBox_activate_next_subquest->AutoSize = true;
		this->checkBox_activate_next_subquest->Location = System::Drawing::Point(159, 59);
		this->checkBox_activate_next_subquest->Name = L"checkBox_activate_next_subquest";
		this->checkBox_activate_next_subquest->RightToLeft = System::Windows::Forms::RightToLeft::No;
		this->checkBox_activate_next_subquest->Size = System::Drawing::Size(15, 14);
		this->checkBox_activate_next_subquest->TabIndex = 66;
		this->checkBox_activate_next_subquest->UseVisualStyleBackColor = true;
		this->checkBox_activate_next_subquest->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_activate_next_subquest);
		// 
		// label92
		// 
		this->label92->AutoSize = true;
		this->label92->Location = System::Drawing::Point(6, 39);
		this->label92->Name = L"label92";
		this->label92->Size = System::Drawing::Size(140, 13);
		this->label92->TabIndex = 65;
		this->label92->Text = L"Activate Random Subquest:";
		// 
		// checkBox_activate_random_subquest
		// 
		this->checkBox_activate_random_subquest->AutoSize = true;
		this->checkBox_activate_random_subquest->Location = System::Drawing::Point(159, 39);
		this->checkBox_activate_random_subquest->Name = L"checkBox_activate_random_subquest";
		this->checkBox_activate_random_subquest->RightToLeft = System::Windows::Forms::RightToLeft::No;
		this->checkBox_activate_random_subquest->Size = System::Drawing::Size(15, 14);
		this->checkBox_activate_random_subquest->TabIndex = 64;
		this->checkBox_activate_random_subquest->UseVisualStyleBackColor = true;
		this->checkBox_activate_random_subquest->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_activate_random_subquest);
		// 
		// label91
		// 
		this->label91->AutoSize = true;
		this->label91->Location = System::Drawing::Point(6, 19);
		this->label91->Name = L"label91";
		this->label91->Size = System::Drawing::Size(119, 13);
		this->label91->TabIndex = 63;
		this->label91->Text = L"Activate First Subquest:";
		// 
		// checkBox_activate_first_subquest
		// 
		this->checkBox_activate_first_subquest->AutoSize = true;
		this->checkBox_activate_first_subquest->Location = System::Drawing::Point(159, 19);
		this->checkBox_activate_first_subquest->Name = L"checkBox_activate_first_subquest";
		this->checkBox_activate_first_subquest->RightToLeft = System::Windows::Forms::RightToLeft::No;
		this->checkBox_activate_first_subquest->Size = System::Drawing::Size(15, 14);
		this->checkBox_activate_first_subquest->TabIndex = 62;
		this->checkBox_activate_first_subquest->UseVisualStyleBackColor = true;
		this->checkBox_activate_first_subquest->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_activate_first_subquest);
		// 
		// groupBox_requirements
		// 
		this->groupBox_requirements->Controls->Add(this->textBox_required_morai_pk_unknown);
		this->groupBox_requirements->Controls->Add(this->label236);
		this->groupBox_requirements->Controls->Add(this->label237);
		this->groupBox_requirements->Controls->Add(this->dataGridView_required_morai_pk);
		this->groupBox_requirements->Controls->Add(this->label235);
		this->groupBox_requirements->Controls->Add(this->comboBox_required_cultivation);
		this->groupBox_requirements->Controls->Add(this->checkBox_unknown_42_2);
		this->groupBox_requirements->Controls->Add(this->label233);
		this->groupBox_requirements->Controls->Add(this->checkBox_unknown_42_1);
		this->groupBox_requirements->Controls->Add(this->label232);
		this->groupBox_requirements->Controls->Add(this->comboBox_required_force);
		this->groupBox_requirements->Controls->Add(this->label230);
		this->groupBox_requirements->Controls->Add(this->textBox_unknown_55_02_02);
		this->groupBox_requirements->Controls->Add(this->label226);
		this->groupBox_requirements->Controls->Add(this->textBox_unknown_55_06);
		this->groupBox_requirements->Controls->Add(this->label227);
		this->groupBox_requirements->Controls->Add(this->textBox_unknown_55_05);
		this->groupBox_requirements->Controls->Add(this->label228);
		this->groupBox_requirements->Controls->Add(this->textBox_unknown_55_04);
		this->groupBox_requirements->Controls->Add(this->label229);
		this->groupBox_requirements->Controls->Add(this->textBox_required_influence_fee);
		this->groupBox_requirements->Controls->Add(this->label224);
		this->groupBox_requirements->Controls->Add(this->textBox_unknown_55_03);
		this->groupBox_requirements->Controls->Add(this->label225);
		this->groupBox_requirements->Controls->Add(this->textBox_required_prestige);
		this->groupBox_requirements->Controls->Add(this->label223);
		this->groupBox_requirements->Controls->Add(this->label222);
		this->groupBox_requirements->Controls->Add(this->label74);
		this->groupBox_requirements->Controls->Add(this->dataGridView_team_members);
		this->groupBox_requirements->Controls->Add(this->label68);
		this->groupBox_requirements->Controls->Add(this->dataGridView_given_items);
		this->groupBox_requirements->Controls->Add(this->label69);
		this->groupBox_requirements->Controls->Add(this->dataGridView_required_items);
		this->groupBox_requirements->Controls->Add(this->textBox_unknown_57_01);
		this->groupBox_requirements->Controls->Add(this->label165);
		this->groupBox_requirements->Controls->Add(this->textBox_unknown_57);
		this->groupBox_requirements->Controls->Add(this->label162);
		this->groupBox_requirements->Controls->Add(this->textBox_unknown_56);
		this->groupBox_requirements->Controls->Add(this->label163);
		this->groupBox_requirements->Controls->Add(this->label27);
		this->groupBox_requirements->Controls->Add(this->textBox_required_wait_time);
		this->groupBox_requirements->Controls->Add(this->textBox_required_coins);
		this->groupBox_requirements->Controls->Add(this->label39);
		this->groupBox_requirements->Controls->Add(this->textBox_required_get_items_unknown);
		this->groupBox_requirements->Controls->Add(this->label67);
		this->groupBox_requirements->Controls->Add(this->label2);
		this->groupBox_requirements->Controls->Add(this->dataGridView_required_get_items);
		this->groupBox_requirements->Controls->Add(this->textBox_required_chases_unknown);
		this->groupBox_requirements->Controls->Add(this->label66);
		this->groupBox_requirements->Controls->Add(this->label1);
		this->groupBox_requirements->Controls->Add(this->dataGridView_required_chases);
		this->groupBox_requirements->Controls->Add(this->textBox_required_npc_type);
		this->groupBox_requirements->Controls->Add(this->label161);
		this->groupBox_requirements->Controls->Add(this->textBox_required_success_type);
		this->groupBox_requirements->Controls->Add(this->label160);
		this->groupBox_requirements->Controls->Add(this->textBox_unknown_55_02_01);
		this->groupBox_requirements->Controls->Add(this->label159);
		this->groupBox_requirements->Controls->Add(this->textBox_unknown_55);
		this->groupBox_requirements->Controls->Add(this->label158);
		this->groupBox_requirements->Controls->Add(this->textBox_required_pq_contribution);
		this->groupBox_requirements->Controls->Add(this->label157);
		this->groupBox_requirements->Controls->Add(this->textBox_unknown_54);
		this->groupBox_requirements->Controls->Add(this->label156);
		this->groupBox_requirements->Controls->Add(this->textBox_unknown_53);
		this->groupBox_requirements->Controls->Add(this->label155);
		this->groupBox_requirements->Controls->Add(this->textBox_resource_pq_audit_id);
		this->groupBox_requirements->Controls->Add(this->label154);
		this->groupBox_requirements->Controls->Add(this->textBox_unknown_52);
		this->groupBox_requirements->Controls->Add(this->label153);
		this->groupBox_requirements->Controls->Add(this->checkBox_unknown_51);
		this->groupBox_requirements->Controls->Add(this->label152);
		this->groupBox_requirements->Controls->Add(this->textBox_unknown_50);
		this->groupBox_requirements->Controls->Add(this->label151);
		this->groupBox_requirements->Controls->Add(this->textBox_unknown_49);
		this->groupBox_requirements->Controls->Add(this->label150);
		this->groupBox_requirements->Controls->Add(this->textBox_unknown_48);
		this->groupBox_requirements->Controls->Add(this->label149);
		this->groupBox_requirements->Controls->Add(this->textBox_required_apothecary_level);
		this->groupBox_requirements->Controls->Add(this->label80);
		this->groupBox_requirements->Controls->Add(this->textBox_required_craftsman_level);
		this->groupBox_requirements->Controls->Add(this->label79);
		this->groupBox_requirements->Controls->Add(this->textBox_required_tailor_level);
		this->groupBox_requirements->Controls->Add(this->label78);
		this->groupBox_requirements->Controls->Add(this->textBox_required_blacksmith_level);
		this->groupBox_requirements->Controls->Add(this->label77);
		this->groupBox_requirements->Controls->Add(this->label48);
		this->groupBox_requirements->Controls->Add(this->textBox_required_quests_undone_1);
		this->groupBox_requirements->Controls->Add(this->textBox_unknown_47);
		this->groupBox_requirements->Controls->Add(this->textBox_required_quests_undone_2);
		this->groupBox_requirements->Controls->Add(this->label148);
		this->groupBox_requirements->Controls->Add(this->textBox_required_quests_undone_3);
		this->groupBox_requirements->Controls->Add(this->checkBox_unknown_46);
		this->groupBox_requirements->Controls->Add(this->textBox_required_quests_undone_5);
		this->groupBox_requirements->Controls->Add(this->textBox_required_quests_undone_4);
		this->groupBox_requirements->Controls->Add(this->label147);
		this->groupBox_requirements->Controls->Add(this->textBox_unknown_45);
		this->groupBox_requirements->Controls->Add(this->label146);
		this->groupBox_requirements->Controls->Add(this->dataGridView_date_unknown);
		this->groupBox_requirements->Controls->Add(this->label145);
		this->groupBox_requirements->Controls->Add(this->textBox_unknown_44);
		this->groupBox_requirements->Controls->Add(this->label144);
		this->groupBox_requirements->Controls->Add(this->checkBox_occupation_seeker);
		this->groupBox_requirements->Controls->Add(this->checkBox_occupation_mystic);
		this->groupBox_requirements->Controls->Add(this->checkBox_occupation_cleric);
		this->groupBox_requirements->Controls->Add(this->checkBox_occupation_archer);
		this->groupBox_requirements->Controls->Add(this->checkBox_occupation_psychic);
		this->groupBox_requirements->Controls->Add(this->checkBox_occupation_barbarian);
		this->groupBox_requirements->Controls->Add(this->checkBox_occupation_venomancer);
		this->groupBox_requirements->Controls->Add(this->checkBox_occupation_assassin);
		this->groupBox_requirements->Controls->Add(this->checkBox_occupation_wizard);
		this->groupBox_requirements->Controls->Add(this->checkBox_occupation_blademaster);
		this->groupBox_requirements->Controls->Add(this->checkBox_unknown_43);
		this->groupBox_requirements->Controls->Add(this->label143);
		this->groupBox_requirements->Controls->Add(this->checkBox_required_be_gm);
		this->groupBox_requirements->Controls->Add(this->label142);
		this->groupBox_requirements->Controls->Add(this->checkBox_unknown_42);
		this->groupBox_requirements->Controls->Add(this->label141);
		this->groupBox_requirements->Controls->Add(this->checkBox_required_be_married);
		this->groupBox_requirements->Controls->Add(this->label140);
		this->groupBox_requirements->Controls->Add(this->checkBox_unknown_41);
		this->groupBox_requirements->Controls->Add(this->label139);
		this->groupBox_requirements->Controls->Add(this->checkBox_unknown_40);
		this->groupBox_requirements->Controls->Add(this->label30);
		this->groupBox_requirements->Controls->Add(this->comboBox_required_gender);
		this->groupBox_requirements->Controls->Add(this->label58);
		this->groupBox_requirements->Controls->Add(this->checkBox_unknown_39);
		this->groupBox_requirements->Controls->Add(this->label138);
		this->groupBox_requirements->Controls->Add(this->textBox_unknown_38);
		this->groupBox_requirements->Controls->Add(this->label137);
		this->groupBox_requirements->Controls->Add(this->textBox_unknown_37);
		this->groupBox_requirements->Controls->Add(this->label136);
		this->groupBox_requirements->Controls->Add(this->textBox_unknown_36);
		this->groupBox_requirements->Controls->Add(this->label135);
		this->groupBox_requirements->Controls->Add(this->checkBox_unknown_35);
		this->groupBox_requirements->Controls->Add(this->label133);
		this->groupBox_requirements->Controls->Add(this->textBox_unknown_34);
		this->groupBox_requirements->Controls->Add(this->label134);
		this->groupBox_requirements->Controls->Add(this->label41);
		this->groupBox_requirements->Controls->Add(this->textBox_required_quests_done_1);
		this->groupBox_requirements->Controls->Add(this->textBox_required_quests_done_2);
		this->groupBox_requirements->Controls->Add(this->textBox_required_quests_done_3);
		this->groupBox_requirements->Controls->Add(this->textBox_required_quests_done_4);
		this->groupBox_requirements->Controls->Add(this->textBox_required_quests_done_5);
		this->groupBox_requirements->Controls->Add(this->checkBox_unknown_33);
		this->groupBox_requirements->Controls->Add(this->label132);
		this->groupBox_requirements->Controls->Add(this->textBox_unknown_32);
		this->groupBox_requirements->Controls->Add(this->label131);
		this->groupBox_requirements->Controls->Add(this->textBox_required_reputation);
		this->groupBox_requirements->Controls->Add(this->label38);
		this->groupBox_requirements->Controls->Add(this->checkBox_unknown_31);
		this->groupBox_requirements->Controls->Add(this->label130);
		this->groupBox_requirements->Controls->Add(this->textBox_given_items_unknown);
		this->groupBox_requirements->Controls->Add(this->label129);
		this->groupBox_requirements->Controls->Add(this->textBox_unknown_30);
		this->groupBox_requirements->Controls->Add(this->label73);
		this->groupBox_requirements->Controls->Add(this->textBox_unknown_29);
		this->groupBox_requirements->Controls->Add(this->label72);
		this->groupBox_requirements->Controls->Add(this->checkBox_unknown_28_01);
		this->groupBox_requirements->Controls->Add(this->label71);
		this->groupBox_requirements->Controls->Add(this->textBox_required_items_unknown);
		this->groupBox_requirements->Controls->Add(this->label70);
		this->groupBox_requirements->Controls->Add(this->checkBox_unknown_28);
		this->groupBox_requirements->Controls->Add(this->checkBox_unknown_27);
		this->groupBox_requirements->Controls->Add(this->label64);
		this->groupBox_requirements->Controls->Add(this->label62);
		this->groupBox_requirements->Controls->Add(this->textBox_instant_pay_coins);
		this->groupBox_requirements->Controls->Add(this->label65);
		this->groupBox_requirements->Location = System::Drawing::Point(3, 3);
		this->groupBox_requirements->Name = L"groupBox_requirements";
		this->groupBox_requirements->Size = System::Drawing::Size(655, 1869);
		this->groupBox_requirements->TabIndex = 2;
		this->groupBox_requirements->TabStop = false;
		this->groupBox_requirements->Text = L"REQUIREMENTS";
		// 
		// textBox_required_morai_pk_unknown
		// 
		this->textBox_required_morai_pk_unknown->Location = System::Drawing::Point(106, 1443);
		this->textBox_required_morai_pk_unknown->Name = L"textBox_required_morai_pk_unknown";
		this->textBox_required_morai_pk_unknown->Size = System::Drawing::Size(184, 20);
		this->textBox_required_morai_pk_unknown->TabIndex = 302;
		this->textBox_required_morai_pk_unknown->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->textBox_required_morai_pk_unknown->Leave += gcnew System::EventHandler(this, &MainWindow::change_required_morai_pk_unknown);
		// 
		// label236
		// 
		this->label236->AutoSize = true;
		this->label236->ForeColor = System::Drawing::Color::Red;
		this->label236->Location = System::Drawing::Point(0, 1445);
		this->label236->Name = L"label236";
		this->label236->Size = System::Drawing::Size(102, 13);
		this->label236->TabIndex = 301;
		this->label236->Text = L"Morai PK Unknown:";
		// 
		// label237
		// 
		this->label237->AutoSize = true;
		this->label237->ForeColor = System::Drawing::Color::Red;
		this->label237->Location = System::Drawing::Point(15, 1317);
		this->label237->Name = L"label237";
		this->label237->Size = System::Drawing::Size(53, 13);
		this->label237->TabIndex = 299;
		this->label237->Text = L"Morai PK:";
		// 
		// dataGridView_required_morai_pk
		// 
		this->dataGridView_required_morai_pk->AllowUserToAddRows = false;
		this->dataGridView_required_morai_pk->AllowUserToDeleteRows = false;
		this->dataGridView_required_morai_pk->BackgroundColor = System::Drawing::SystemColors::Window;
		this->dataGridView_required_morai_pk->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
		this->dataGridView_required_morai_pk->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
		this->dataGridView_required_morai_pk->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(10) {this->dataGridViewTextBoxColumn99, 
			this->dataGridViewTextBoxColumn101, this->dataGridViewTextBoxColumn102, this->dataGridViewTextBoxColumn103, this->dataGridViewTextBoxColumn104, 
			this->DataGridViewTextBoxColumn281, this->dataGridViewTextBoxColumn106, this->dataGridViewTextBoxColumn107, this->Column27, this->Column28});
		this->dataGridView_required_morai_pk->ContextMenuStrip = this->contextMenuStrip_morai_pk;
		this->dataGridView_required_morai_pk->Location = System::Drawing::Point(102, 1312);
		this->dataGridView_required_morai_pk->MultiSelect = false;
		this->dataGridView_required_morai_pk->Name = L"dataGridView_required_morai_pk";
		this->dataGridView_required_morai_pk->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
		dataGridViewCellStyle73->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
		dataGridViewCellStyle73->BackColor = System::Drawing::SystemColors::Control;
		dataGridViewCellStyle73->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		dataGridViewCellStyle73->ForeColor = System::Drawing::SystemColors::WindowText;
		dataGridViewCellStyle73->SelectionBackColor = System::Drawing::SystemColors::Highlight;
		dataGridViewCellStyle73->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
		dataGridViewCellStyle73->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView_required_morai_pk->RowHeadersDefaultCellStyle = dataGridViewCellStyle73;
		this->dataGridView_required_morai_pk->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::AutoSizeToFirstHeader;
		this->dataGridView_required_morai_pk->RowTemplate->Height = 18;
		this->dataGridView_required_morai_pk->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView_required_morai_pk->Size = System::Drawing::Size(547, 120);
		this->dataGridView_required_morai_pk->TabIndex = 300;
		this->dataGridView_required_morai_pk->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::change_required_morai_pk);
		// 
		// contextMenuStrip_morai_pk
		// 
		this->contextMenuStrip_morai_pk->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->toolStripMenuItem48, 
			this->toolStripMenuItem49});
		this->contextMenuStrip_morai_pk->Name = L"contextMenuStrip1";
		this->contextMenuStrip_morai_pk->Size = System::Drawing::Size(158, 48);
		// 
		// toolStripMenuItem48
		// 
		this->toolStripMenuItem48->Name = L"toolStripMenuItem48";
		this->toolStripMenuItem48->Size = System::Drawing::Size(157, 22);
		this->toolStripMenuItem48->Text = L"Add Morai PK";
		this->toolStripMenuItem48->Click += gcnew System::EventHandler(this, &MainWindow::add_required_morai_pk);
		// 
		// toolStripMenuItem49
		// 
		this->toolStripMenuItem49->Name = L"toolStripMenuItem49";
		this->toolStripMenuItem49->Size = System::Drawing::Size(157, 22);
		this->toolStripMenuItem49->Text = L"Remove Morai PK";
		this->toolStripMenuItem49->Click += gcnew System::EventHandler(this, &MainWindow::remove_required_morai_pk);
		// 
		// label235
		// 
		this->label235->AutoSize = true;
		this->label235->Location = System::Drawing::Point(312, 494);
		this->label235->Name = L"label235";
		this->label235->Size = System::Drawing::Size(59, 13);
		this->label235->TabIndex = 298;
		this->label235->Text = L"Cultivation:";
		// 
		// comboBox_required_cultivation
		// 
		this->comboBox_required_cultivation->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
		this->comboBox_required_cultivation->FormattingEnabled = true;
		this->comboBox_required_cultivation->Items->AddRange(gcnew cli::array< System::Object^  >(15) {L"0 - Spiritual Initiate", 
			L"9 - Spiritual Adept", L"19 - Aware of Principle", L"29 - Aware of Harmony", L"39 - Aware of Discord", L"49 - Aware of Coalescence", 
			L"59 - Transcendant", L"69 - Enlightened One", L"79 - Aware of Vacuity", L"89 - Aware of Myriad", L"89 - Aware of the Void", 
			L"99 - Master of Harmony", L"99 - Master of Discord", L"100 - Celestial Sage", L"100 - Celestial Demon"});
		this->comboBox_required_cultivation->Location = System::Drawing::Point(390, 491);
		this->comboBox_required_cultivation->Name = L"comboBox_required_cultivation";
		this->comboBox_required_cultivation->Size = System::Drawing::Size(116, 21);
		this->comboBox_required_cultivation->TabIndex = 297;
		this->comboBox_required_cultivation->SelectedIndexChanged += gcnew System::EventHandler(this, &MainWindow::change_required_cultivation);
		// 
		// checkBox_unknown_42_2
		// 
		this->checkBox_unknown_42_2->AutoSize = true;
		this->checkBox_unknown_42_2->Location = System::Drawing::Point(151, 687);
		this->checkBox_unknown_42_2->Name = L"checkBox_unknown_42_2";
		this->checkBox_unknown_42_2->Size = System::Drawing::Size(15, 14);
		this->checkBox_unknown_42_2->TabIndex = 296;
		this->checkBox_unknown_42_2->UseVisualStyleBackColor = true;
		this->checkBox_unknown_42_2->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_unknown_42_2);
		// 
		// label233
		// 
		this->label233->AutoSize = true;
		this->label233->ForeColor = System::Drawing::Color::Red;
		this->label233->Location = System::Drawing::Point(7, 690);
		this->label233->Name = L"label233";
		this->label233->Size = System::Drawing::Size(83, 13);
		this->label233->TabIndex = 295;
		this->label233->Text = L"Unknown 42_2:";
		// 
		// checkBox_unknown_42_1
		// 
		this->checkBox_unknown_42_1->AutoSize = true;
		this->checkBox_unknown_42_1->Location = System::Drawing::Point(151, 664);
		this->checkBox_unknown_42_1->Name = L"checkBox_unknown_42_1";
		this->checkBox_unknown_42_1->Size = System::Drawing::Size(15, 14);
		this->checkBox_unknown_42_1->TabIndex = 294;
		this->checkBox_unknown_42_1->UseVisualStyleBackColor = true;
		this->checkBox_unknown_42_1->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_unknown_42_1);
		// 
		// label232
		// 
		this->label232->AutoSize = true;
		this->label232->ForeColor = System::Drawing::Color::Red;
		this->label232->Location = System::Drawing::Point(7, 667);
		this->label232->Name = L"label232";
		this->label232->Size = System::Drawing::Size(83, 13);
		this->label232->TabIndex = 293;
		this->label232->Text = L"Unknown 42_1:";
		// 
		// comboBox_required_force
		// 
		this->comboBox_required_force->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
		this->comboBox_required_force->FormattingEnabled = true;
		this->comboBox_required_force->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"NULL", L"Corona", L"Shroud", L"Luminance"});
		this->comboBox_required_force->Location = System::Drawing::Point(215, 1194);
		this->comboBox_required_force->Name = L"comboBox_required_force";
		this->comboBox_required_force->Size = System::Drawing::Size(114, 21);
		this->comboBox_required_force->TabIndex = 292;
		this->comboBox_required_force->SelectedIndexChanged += gcnew System::EventHandler(this, &MainWindow::change_required_force);
		// 
		// label230
		// 
		this->label230->AutoSize = true;
		this->label230->ForeColor = System::Drawing::Color::Red;
		this->label230->Location = System::Drawing::Point(170, 1198);
		this->label230->Name = L"label230";
		this->label230->Size = System::Drawing::Size(37, 13);
		this->label230->TabIndex = 291;
		this->label230->Text = L"Force:";
		// 
		// textBox_unknown_55_02_02
		// 
		this->textBox_unknown_55_02_02->Location = System::Drawing::Point(462, 1195);
		this->textBox_unknown_55_02_02->Name = L"textBox_unknown_55_02_02";
		this->textBox_unknown_55_02_02->Size = System::Drawing::Size(44, 20);
		this->textBox_unknown_55_02_02->TabIndex = 290;
		this->textBox_unknown_55_02_02->Leave += gcnew System::EventHandler(this, &MainWindow::change_unknown_55_02_02);
		// 
		// label226
		// 
		this->label226->AutoSize = true;
		this->label226->ForeColor = System::Drawing::Color::Red;
		this->label226->Location = System::Drawing::Point(342, 1198);
		this->label226->Name = L"label226";
		this->label226->Size = System::Drawing::Size(107, 13);
		this->label226->TabIndex = 289;
		this->label226->Text = L"Unknown 55_02_02:";
		// 
		// textBox_unknown_55_06
		// 
		this->textBox_unknown_55_06->Location = System::Drawing::Point(247, 1251);
		this->textBox_unknown_55_06->Name = L"textBox_unknown_55_06";
		this->textBox_unknown_55_06->Size = System::Drawing::Size(52, 20);
		this->textBox_unknown_55_06->TabIndex = 288;
		this->textBox_unknown_55_06->Leave += gcnew System::EventHandler(this, &MainWindow::change_unknown_55_06);
		// 
		// label227
		// 
		this->label227->AutoSize = true;
		this->label227->ForeColor = System::Drawing::Color::Red;
		this->label227->Location = System::Drawing::Point(156, 1254);
		this->label227->Name = L"label227";
		this->label227->Size = System::Drawing::Size(89, 13);
		this->label227->TabIndex = 287;
		this->label227->Text = L"Unknown 55_06:";
		// 
		// textBox_unknown_55_05
		// 
		this->textBox_unknown_55_05->Location = System::Drawing::Point(86, 1251);
		this->textBox_unknown_55_05->Name = L"textBox_unknown_55_05";
		this->textBox_unknown_55_05->Size = System::Drawing::Size(74, 20);
		this->textBox_unknown_55_05->TabIndex = 286;
		this->textBox_unknown_55_05->Leave += gcnew System::EventHandler(this, &MainWindow::change_unknown_55_05);
		// 
		// label228
		// 
		this->label228->AutoSize = true;
		this->label228->ForeColor = System::Drawing::Color::Red;
		this->label228->Location = System::Drawing::Point(-10, 1254);
		this->label228->Name = L"label228";
		this->label228->Size = System::Drawing::Size(89, 13);
		this->label228->TabIndex = 285;
		this->label228->Text = L"Unknown 55_05:";
		// 
		// textBox_unknown_55_04
		// 
		this->textBox_unknown_55_04->Location = System::Drawing::Point(463, 1226);
		this->textBox_unknown_55_04->Name = L"textBox_unknown_55_04";
		this->textBox_unknown_55_04->Size = System::Drawing::Size(180, 20);
		this->textBox_unknown_55_04->TabIndex = 284;
		this->textBox_unknown_55_04->Leave += gcnew System::EventHandler(this, &MainWindow::change_unknown_55_04);
		// 
		// label229
		// 
		this->label229->AutoSize = true;
		this->label229->ForeColor = System::Drawing::Color::Red;
		this->label229->Location = System::Drawing::Point(372, 1229);
		this->label229->Name = L"label229";
		this->label229->Size = System::Drawing::Size(89, 13);
		this->label229->TabIndex = 283;
		this->label229->Text = L"Unknown 55_04:";
		// 
		// textBox_required_influence_fee
		// 
		this->textBox_required_influence_fee->Location = System::Drawing::Point(305, 1225);
		this->textBox_required_influence_fee->Name = L"textBox_required_influence_fee";
		this->textBox_required_influence_fee->Size = System::Drawing::Size(52, 20);
		this->textBox_required_influence_fee->TabIndex = 282;
		this->textBox_required_influence_fee->Leave += gcnew System::EventHandler(this, &MainWindow::change_required_influence_fee);
		// 
		// label224
		// 
		this->label224->AutoSize = true;
		this->label224->ForeColor = System::Drawing::Color::Red;
		this->label224->Location = System::Drawing::Point(214, 1228);
		this->label224->Name = L"label224";
		this->label224->Size = System::Drawing::Size(75, 13);
		this->label224->TabIndex = 281;
		this->label224->Text = L"Influence Fee:";
		// 
		// textBox_unknown_55_03
		// 
		this->textBox_unknown_55_03->Location = System::Drawing::Point(154, 1223);
		this->textBox_unknown_55_03->Name = L"textBox_unknown_55_03";
		this->textBox_unknown_55_03->Size = System::Drawing::Size(52, 20);
		this->textBox_unknown_55_03->TabIndex = 280;
		this->textBox_unknown_55_03->Leave += gcnew System::EventHandler(this, &MainWindow::change_unknown_55_03);
		// 
		// label225
		// 
		this->label225->AutoSize = true;
		this->label225->ForeColor = System::Drawing::Color::Red;
		this->label225->Location = System::Drawing::Point(63, 1226);
		this->label225->Name = L"label225";
		this->label225->Size = System::Drawing::Size(89, 13);
		this->label225->TabIndex = 279;
		this->label225->Text = L"Unknown 55_03:";
		// 
		// textBox_required_prestige
		// 
		this->textBox_required_prestige->Location = System::Drawing::Point(575, 1196);
		this->textBox_required_prestige->Name = L"textBox_required_prestige";
		this->textBox_required_prestige->Size = System::Drawing::Size(52, 20);
		this->textBox_required_prestige->TabIndex = 278;
		this->textBox_required_prestige->Leave += gcnew System::EventHandler(this, &MainWindow::change_required_prestige);
		// 
		// label223
		// 
		this->label223->AutoSize = true;
		this->label223->ForeColor = System::Drawing::Color::Red;
		this->label223->Location = System::Drawing::Point(522, 1199);
		this->label223->Name = L"label223";
		this->label223->Size = System::Drawing::Size(48, 13);
		this->label223->TabIndex = 277;
		this->label223->Text = L"Prestige:";
		// 
		// label222
		// 
		this->label222->AutoSize = true;
		this->label222->Location = System::Drawing::Point(492, 263);
		this->label222->Name = L"label222";
		this->label222->Size = System::Drawing::Size(70, 13);
		this->label222->TabIndex = 276;
		this->label222->Text = L"Occupations:";
		// 
		// label74
		// 
		this->label74->AutoSize = true;
		this->label74->Location = System::Drawing::Point(9, 1004);
		this->label74->Name = L"label74";
		this->label74->Size = System::Drawing::Size(83, 13);
		this->label74->TabIndex = 275;
		this->label74->Text = L"Team Members:";
		// 
		// dataGridView_team_members
		// 
		this->dataGridView_team_members->AllowUserToAddRows = false;
		this->dataGridView_team_members->AllowUserToDeleteRows = false;
		this->dataGridView_team_members->BackgroundColor = System::Drawing::SystemColors::Window;
		this->dataGridView_team_members->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
		this->dataGridView_team_members->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
		this->dataGridView_team_members->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(9) {this->dataGridViewTextBoxColumn8, 
			this->dataGridViewTextBoxColumn9, this->dataGridViewTextBoxColumn10, this->dataGridViewTextBoxColumn11, this->dataGridViewTextBoxColumn12, 
			this->dataGridViewTextBoxColumn13, this->dataGridViewTextBoxColumn14, this->dataGridViewTextBoxColumn15, this->Column18});
		this->dataGridView_team_members->ContextMenuStrip = this->contextMenuStrip_team_members;
		this->dataGridView_team_members->Location = System::Drawing::Point(95, 996);
		this->dataGridView_team_members->MultiSelect = false;
		this->dataGridView_team_members->Name = L"dataGridView_team_members";
		this->dataGridView_team_members->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
		dataGridViewCellStyle83->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
		dataGridViewCellStyle83->BackColor = System::Drawing::SystemColors::Control;
		dataGridViewCellStyle83->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		dataGridViewCellStyle83->ForeColor = System::Drawing::SystemColors::WindowText;
		dataGridViewCellStyle83->SelectionBackColor = System::Drawing::SystemColors::Highlight;
		dataGridViewCellStyle83->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
		dataGridViewCellStyle83->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView_team_members->RowHeadersDefaultCellStyle = dataGridViewCellStyle83;
		this->dataGridView_team_members->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::AutoSizeToFirstHeader;
		this->dataGridView_team_members->RowTemplate->Height = 18;
		this->dataGridView_team_members->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView_team_members->Size = System::Drawing::Size(487, 81);
		this->dataGridView_team_members->TabIndex = 274;
		this->dataGridView_team_members->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::change_required_team_member_groups);
		// 
		// dataGridViewTextBoxColumn8
		// 
		this->dataGridViewTextBoxColumn8->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle74->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn8->DefaultCellStyle = dataGridViewCellStyle74;
		this->dataGridViewTextBoxColumn8->HeaderText = L"Min. LvL";
		this->dataGridViewTextBoxColumn8->Name = L"dataGridViewTextBoxColumn8";
		this->dataGridViewTextBoxColumn8->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn8->Width = 53;
		// 
		// dataGridViewTextBoxColumn9
		// 
		this->dataGridViewTextBoxColumn9->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle75->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn9->DefaultCellStyle = dataGridViewCellStyle75;
		this->dataGridViewTextBoxColumn9->HeaderText = L"Max. LvL";
		this->dataGridViewTextBoxColumn9->Name = L"dataGridViewTextBoxColumn9";
		this->dataGridViewTextBoxColumn9->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn9->Width = 56;
		// 
		// dataGridViewTextBoxColumn10
		// 
		this->dataGridViewTextBoxColumn10->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle76->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn10->DefaultCellStyle = dataGridViewCellStyle76;
		this->dataGridViewTextBoxColumn10->HeaderText = L"\?";
		this->dataGridViewTextBoxColumn10->Name = L"dataGridViewTextBoxColumn10";
		this->dataGridViewTextBoxColumn10->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn10->Width = 18;
		// 
		// dataGridViewTextBoxColumn11
		// 
		this->dataGridViewTextBoxColumn11->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle77->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn11->DefaultCellStyle = dataGridViewCellStyle77;
		this->dataGridViewTextBoxColumn11->HeaderText = L"\?";
		this->dataGridViewTextBoxColumn11->Name = L"dataGridViewTextBoxColumn11";
		this->dataGridViewTextBoxColumn11->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn11->Width = 18;
		// 
		// dataGridViewTextBoxColumn12
		// 
		this->dataGridViewTextBoxColumn12->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle78->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn12->DefaultCellStyle = dataGridViewCellStyle78;
		this->dataGridViewTextBoxColumn12->HeaderText = L"\?";
		this->dataGridViewTextBoxColumn12->Name = L"dataGridViewTextBoxColumn12";
		this->dataGridViewTextBoxColumn12->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn12->Width = 18;
		// 
		// dataGridViewTextBoxColumn13
		// 
		this->dataGridViewTextBoxColumn13->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle79->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn13->DefaultCellStyle = dataGridViewCellStyle79;
		this->dataGridViewTextBoxColumn13->HeaderText = L"Min.#";
		this->dataGridViewTextBoxColumn13->Name = L"dataGridViewTextBoxColumn13";
		this->dataGridViewTextBoxColumn13->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn13->Width = 39;
		// 
		// dataGridViewTextBoxColumn14
		// 
		this->dataGridViewTextBoxColumn14->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle80->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn14->DefaultCellStyle = dataGridViewCellStyle80;
		this->dataGridViewTextBoxColumn14->HeaderText = L"Max.#";
		this->dataGridViewTextBoxColumn14->Name = L"dataGridViewTextBoxColumn14";
		this->dataGridViewTextBoxColumn14->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn14->Width = 42;
		// 
		// dataGridViewTextBoxColumn15
		// 
		this->dataGridViewTextBoxColumn15->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle81->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn15->DefaultCellStyle = dataGridViewCellStyle81;
		this->dataGridViewTextBoxColumn15->HeaderText = L"Quest";
		this->dataGridViewTextBoxColumn15->Name = L"dataGridViewTextBoxColumn15";
		this->dataGridViewTextBoxColumn15->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn15->Width = 40;
		// 
		// Column18
		// 
		this->Column18->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
		dataGridViewCellStyle82->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		dataGridViewCellStyle82->ForeColor = System::Drawing::Color::Red;
		this->Column18->DefaultCellStyle = dataGridViewCellStyle82;
		this->Column18->HeaderText = L"Affilated Force";
		this->Column18->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"NULL", L"Corona", L"Shroud", L"Luminance"});
		this->Column18->Name = L"Column18";
		this->Column18->Resizable = System::Windows::Forms::DataGridViewTriState::True;
		// 
		// contextMenuStrip_team_members
		// 
		this->contextMenuStrip_team_members->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->toolStripMenuItem13, 
			this->toolStripMenuItem14});
		this->contextMenuStrip_team_members->Name = L"contextMenuStrip1";
		this->contextMenuStrip_team_members->Size = System::Drawing::Size(155, 48);
		// 
		// toolStripMenuItem13
		// 
		this->toolStripMenuItem13->Name = L"toolStripMenuItem13";
		this->toolStripMenuItem13->Size = System::Drawing::Size(154, 22);
		this->toolStripMenuItem13->Text = L"Add Member";
		this->toolStripMenuItem13->Click += gcnew System::EventHandler(this, &MainWindow::add_required_team_member_group);
		// 
		// toolStripMenuItem14
		// 
		this->toolStripMenuItem14->Name = L"toolStripMenuItem14";
		this->toolStripMenuItem14->Size = System::Drawing::Size(154, 22);
		this->toolStripMenuItem14->Text = L"Remove Member";
		this->toolStripMenuItem14->Click += gcnew System::EventHandler(this, &MainWindow::remove_required_team_member_group);
		// 
		// label68
		// 
		this->label68->AutoSize = true;
		this->label68->Location = System::Drawing::Point(6, 156);
		this->label68->Name = L"label68";
		this->label68->Size = System::Drawing::Size(63, 13);
		this->label68->TabIndex = 273;
		this->label68->Text = L"Given Items";
		// 
		// dataGridView_given_items
		// 
		this->dataGridView_given_items->AllowUserToAddRows = false;
		this->dataGridView_given_items->AllowUserToDeleteRows = false;
		this->dataGridView_given_items->BackgroundColor = System::Drawing::SystemColors::Window;
		this->dataGridView_given_items->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
		this->dataGridView_given_items->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
		this->dataGridView_given_items->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {this->dataGridViewTextBoxColumn24, 
			this->dataGridViewTextBoxColumn25, this->dataGridViewTextBoxColumn26, this->dataGridViewTextBoxColumn27, this->Column3});
		this->dataGridView_given_items->ContextMenuStrip = this->contextMenuStrip_given_items;
		this->dataGridView_given_items->Location = System::Drawing::Point(149, 156);
		this->dataGridView_given_items->MultiSelect = false;
		this->dataGridView_given_items->Name = L"dataGridView_given_items";
		this->dataGridView_given_items->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
		dataGridViewCellStyle88->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
		dataGridViewCellStyle88->BackColor = System::Drawing::SystemColors::Control;
		dataGridViewCellStyle88->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		dataGridViewCellStyle88->ForeColor = System::Drawing::SystemColors::WindowText;
		dataGridViewCellStyle88->SelectionBackColor = System::Drawing::SystemColors::Highlight;
		dataGridViewCellStyle88->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
		dataGridViewCellStyle88->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView_given_items->RowHeadersDefaultCellStyle = dataGridViewCellStyle88;
		this->dataGridView_given_items->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::AutoSizeToFirstHeader;
		this->dataGridView_given_items->RowTemplate->Height = 18;
		this->dataGridView_given_items->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView_given_items->Size = System::Drawing::Size(300, 70);
		this->dataGridView_given_items->TabIndex = 272;
		this->dataGridView_given_items->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::change_given_items);
		// 
		// dataGridViewTextBoxColumn24
		// 
		this->dataGridViewTextBoxColumn24->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle84->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn24->DefaultCellStyle = dataGridViewCellStyle84;
		this->dataGridViewTextBoxColumn24->HeaderText = L"ID";
		this->dataGridViewTextBoxColumn24->Name = L"dataGridViewTextBoxColumn24";
		this->dataGridViewTextBoxColumn24->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn24->Width = 23;
		// 
		// dataGridViewTextBoxColumn25
		// 
		this->dataGridViewTextBoxColumn25->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		this->dataGridViewTextBoxColumn25->HeaderText = L"\?";
		this->dataGridViewTextBoxColumn25->Name = L"dataGridViewTextBoxColumn25";
		this->dataGridViewTextBoxColumn25->Resizable = System::Windows::Forms::DataGridViewTriState::True;
		this->dataGridViewTextBoxColumn25->Width = 18;
		// 
		// dataGridViewTextBoxColumn26
		// 
		this->dataGridViewTextBoxColumn26->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle85->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn26->DefaultCellStyle = dataGridViewCellStyle85;
		this->dataGridViewTextBoxColumn26->HeaderText = L"#";
		this->dataGridViewTextBoxColumn26->Name = L"dataGridViewTextBoxColumn26";
		this->dataGridViewTextBoxColumn26->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn26->Width = 19;
		// 
		// dataGridViewTextBoxColumn27
		// 
		this->dataGridViewTextBoxColumn27->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle86->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn27->DefaultCellStyle = dataGridViewCellStyle86;
		this->dataGridViewTextBoxColumn27->HeaderText = L"%";
		this->dataGridViewTextBoxColumn27->Name = L"dataGridViewTextBoxColumn27";
		this->dataGridViewTextBoxColumn27->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn27->Width = 20;
		// 
		// Column3
		// 
		this->Column3->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
		dataGridViewCellStyle87->ForeColor = System::Drawing::Color::Gray;
		this->Column3->DefaultCellStyle = dataGridViewCellStyle87;
		this->Column3->HeaderText = L"Expire";
		this->Column3->Name = L"Column3";
		this->Column3->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		// 
		// contextMenuStrip_given_items
		// 
		this->contextMenuStrip_given_items->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->toolStripMenuItem9, 
			this->toolStripMenuItem10});
		this->contextMenuStrip_given_items->Name = L"contextMenuStrip1";
		this->contextMenuStrip_given_items->Size = System::Drawing::Size(139, 48);
		// 
		// toolStripMenuItem9
		// 
		this->toolStripMenuItem9->Name = L"toolStripMenuItem9";
		this->toolStripMenuItem9->Size = System::Drawing::Size(138, 22);
		this->toolStripMenuItem9->Text = L"Add Item";
		this->toolStripMenuItem9->Click += gcnew System::EventHandler(this, &MainWindow::add_given_item);
		// 
		// toolStripMenuItem10
		// 
		this->toolStripMenuItem10->Name = L"toolStripMenuItem10";
		this->toolStripMenuItem10->Size = System::Drawing::Size(138, 22);
		this->toolStripMenuItem10->Text = L"Remove Item";
		this->toolStripMenuItem10->Click += gcnew System::EventHandler(this, &MainWindow::remove_given_item);
		// 
		// label69
		// 
		this->label69->AutoSize = true;
		this->label69->Location = System::Drawing::Point(6, 37);
		this->label69->Name = L"label69";
		this->label69->Size = System::Drawing::Size(81, 13);
		this->label69->TabIndex = 270;
		this->label69->Text = L"Required Items:";
		// 
		// dataGridView_required_items
		// 
		this->dataGridView_required_items->AllowUserToAddRows = false;
		this->dataGridView_required_items->AllowUserToDeleteRows = false;
		this->dataGridView_required_items->BackgroundColor = System::Drawing::SystemColors::Window;
		this->dataGridView_required_items->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
		this->dataGridView_required_items->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
		this->dataGridView_required_items->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {this->dataGridViewTextBoxColumn4, 
			this->dataGridViewTextBoxColumn5, this->dataGridViewTextBoxColumn6, this->dataGridViewTextBoxColumn7, this->Column2});
		this->dataGridView_required_items->ContextMenuStrip = this->contextMenuStrip_required_items;
		this->dataGridView_required_items->Location = System::Drawing::Point(149, 37);
		this->dataGridView_required_items->MultiSelect = false;
		this->dataGridView_required_items->Name = L"dataGridView_required_items";
		this->dataGridView_required_items->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
		dataGridViewCellStyle93->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
		dataGridViewCellStyle93->BackColor = System::Drawing::SystemColors::Control;
		dataGridViewCellStyle93->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		dataGridViewCellStyle93->ForeColor = System::Drawing::SystemColors::WindowText;
		dataGridViewCellStyle93->SelectionBackColor = System::Drawing::SystemColors::Highlight;
		dataGridViewCellStyle93->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
		dataGridViewCellStyle93->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView_required_items->RowHeadersDefaultCellStyle = dataGridViewCellStyle93;
		this->dataGridView_required_items->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::AutoSizeToFirstHeader;
		this->dataGridView_required_items->RowTemplate->Height = 18;
		this->dataGridView_required_items->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView_required_items->Size = System::Drawing::Size(300, 67);
		this->dataGridView_required_items->TabIndex = 271;
		this->dataGridView_required_items->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::change_required_items);
		// 
		// dataGridViewTextBoxColumn4
		// 
		this->dataGridViewTextBoxColumn4->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle89->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn4->DefaultCellStyle = dataGridViewCellStyle89;
		this->dataGridViewTextBoxColumn4->HeaderText = L"ID";
		this->dataGridViewTextBoxColumn4->Name = L"dataGridViewTextBoxColumn4";
		this->dataGridViewTextBoxColumn4->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn4->Width = 23;
		// 
		// dataGridViewTextBoxColumn5
		// 
		this->dataGridViewTextBoxColumn5->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		this->dataGridViewTextBoxColumn5->HeaderText = L"\?";
		this->dataGridViewTextBoxColumn5->Name = L"dataGridViewTextBoxColumn5";
		this->dataGridViewTextBoxColumn5->Resizable = System::Windows::Forms::DataGridViewTriState::True;
		this->dataGridViewTextBoxColumn5->Width = 18;
		// 
		// dataGridViewTextBoxColumn6
		// 
		this->dataGridViewTextBoxColumn6->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle90->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn6->DefaultCellStyle = dataGridViewCellStyle90;
		this->dataGridViewTextBoxColumn6->HeaderText = L"#";
		this->dataGridViewTextBoxColumn6->Name = L"dataGridViewTextBoxColumn6";
		this->dataGridViewTextBoxColumn6->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn6->Width = 19;
		// 
		// dataGridViewTextBoxColumn7
		// 
		this->dataGridViewTextBoxColumn7->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle91->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn7->DefaultCellStyle = dataGridViewCellStyle91;
		this->dataGridViewTextBoxColumn7->HeaderText = L"%";
		this->dataGridViewTextBoxColumn7->Name = L"dataGridViewTextBoxColumn7";
		this->dataGridViewTextBoxColumn7->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn7->Width = 20;
		// 
		// Column2
		// 
		this->Column2->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
		dataGridViewCellStyle92->ForeColor = System::Drawing::Color::Gray;
		this->Column2->DefaultCellStyle = dataGridViewCellStyle92;
		this->Column2->HeaderText = L"Expire";
		this->Column2->Name = L"Column2";
		this->Column2->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		// 
		// contextMenuStrip_required_items
		// 
		this->contextMenuStrip_required_items->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->toolStripMenuItem7, 
			this->toolStripMenuItem8});
		this->contextMenuStrip_required_items->Name = L"contextMenuStrip1";
		this->contextMenuStrip_required_items->Size = System::Drawing::Size(139, 48);
		// 
		// toolStripMenuItem7
		// 
		this->toolStripMenuItem7->Name = L"toolStripMenuItem7";
		this->toolStripMenuItem7->Size = System::Drawing::Size(138, 22);
		this->toolStripMenuItem7->Text = L"Add Item";
		this->toolStripMenuItem7->Click += gcnew System::EventHandler(this, &MainWindow::add_required_item);
		// 
		// toolStripMenuItem8
		// 
		this->toolStripMenuItem8->Name = L"toolStripMenuItem8";
		this->toolStripMenuItem8->Size = System::Drawing::Size(138, 22);
		this->toolStripMenuItem8->Text = L"Remove Item";
		this->toolStripMenuItem8->Click += gcnew System::EventHandler(this, &MainWindow::remove_required_item);
		// 
		// textBox_unknown_57_01
		// 
		this->textBox_unknown_57_01->Location = System::Drawing::Point(130, 1824);
		this->textBox_unknown_57_01->Name = L"textBox_unknown_57_01";
		this->textBox_unknown_57_01->Size = System::Drawing::Size(241, 20);
		this->textBox_unknown_57_01->TabIndex = 269;
		this->textBox_unknown_57_01->Leave += gcnew System::EventHandler(this, &MainWindow::change_unknown_57_01);
		// 
		// label165
		// 
		this->label165->AutoSize = true;
		this->label165->ForeColor = System::Drawing::Color::Red;
		this->label165->Location = System::Drawing::Point(28, 1826);
		this->label165->Name = L"label165";
		this->label165->Size = System::Drawing::Size(89, 13);
		this->label165->TabIndex = 268;
		this->label165->Text = L"Unknown 57_01:";
		// 
		// textBox_unknown_57
		// 
		this->textBox_unknown_57->Location = System::Drawing::Point(128, 1768);
		this->textBox_unknown_57->Name = L"textBox_unknown_57";
		this->textBox_unknown_57->Size = System::Drawing::Size(241, 20);
		this->textBox_unknown_57->TabIndex = 266;
		this->textBox_unknown_57->Leave += gcnew System::EventHandler(this, &MainWindow::change_unknown_57);
		// 
		// label162
		// 
		this->label162->AutoSize = true;
		this->label162->ForeColor = System::Drawing::Color::Gray;
		this->label162->Location = System::Drawing::Point(41, 1771);
		this->label162->Name = L"label162";
		this->label162->Size = System::Drawing::Size(71, 13);
		this->label162->TabIndex = 265;
		this->label162->Text = L"Unknown 57:";
		// 
		// textBox_unknown_56
		// 
		this->textBox_unknown_56->Location = System::Drawing::Point(128, 1742);
		this->textBox_unknown_56->Name = L"textBox_unknown_56";
		this->textBox_unknown_56->Size = System::Drawing::Size(241, 20);
		this->textBox_unknown_56->TabIndex = 264;
		this->textBox_unknown_56->Leave += gcnew System::EventHandler(this, &MainWindow::change_unknown_56);
		// 
		// label163
		// 
		this->label163->AutoSize = true;
		this->label163->Location = System::Drawing::Point(41, 1745);
		this->label163->Name = L"label163";
		this->label163->Size = System::Drawing::Size(71, 13);
		this->label163->TabIndex = 263;
		this->label163->Text = L"Unknown 56:";
		// 
		// label27
		// 
		this->label27->AutoSize = true;
		this->label27->Location = System::Drawing::Point(44, 1799);
		this->label27->Name = L"label27";
		this->label27->Size = System::Drawing::Size(84, 13);
		this->label27->TabIndex = 261;
		this->label27->Text = L"Wait Time [sec]:";
		// 
		// textBox_required_wait_time
		// 
		this->textBox_required_wait_time->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
		this->textBox_required_wait_time->Location = System::Drawing::Point(189, 1796);
		this->textBox_required_wait_time->Name = L"textBox_required_wait_time";
		this->textBox_required_wait_time->Size = System::Drawing::Size(142, 20);
		this->textBox_required_wait_time->TabIndex = 262;
		this->textBox_required_wait_time->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->textBox_required_wait_time->Leave += gcnew System::EventHandler(this, &MainWindow::change_required_wait_time);
		// 
		// textBox_required_coins
		// 
		this->textBox_required_coins->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
		this->textBox_required_coins->Location = System::Drawing::Point(176, 1718);
		this->textBox_required_coins->Name = L"textBox_required_coins";
		this->textBox_required_coins->Size = System::Drawing::Size(98, 20);
		this->textBox_required_coins->TabIndex = 260;
		this->textBox_required_coins->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->textBox_required_coins->Leave += gcnew System::EventHandler(this, &MainWindow::change_required_coins);
		// 
		// label39
		// 
		this->label39->AutoSize = true;
		this->label39->Location = System::Drawing::Point(50, 1722);
		this->label39->Name = L"label39";
		this->label39->Size = System::Drawing::Size(56, 13);
		this->label39->TabIndex = 259;
		this->label39->Text = L"Get Coins:";
		// 
		// textBox_required_get_items_unknown
		// 
		this->textBox_required_get_items_unknown->Location = System::Drawing::Point(117, 1695);
		this->textBox_required_get_items_unknown->Name = L"textBox_required_get_items_unknown";
		this->textBox_required_get_items_unknown->Size = System::Drawing::Size(103, 20);
		this->textBox_required_get_items_unknown->TabIndex = 258;
		this->textBox_required_get_items_unknown->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->textBox_required_get_items_unknown->Leave += gcnew System::EventHandler(this, &MainWindow::change_required_get_items_unknown);
		// 
		// label67
		// 
		this->label67->AutoSize = true;
		this->label67->Location = System::Drawing::Point(3, 1698);
		this->label67->Name = L"label67";
		this->label67->Size = System::Drawing::Size(104, 13);
		this->label67->TabIndex = 257;
		this->label67->Text = L"Get Items Unknown:";
		// 
		// label2
		// 
		this->label2->AutoSize = true;
		this->label2->Location = System::Drawing::Point(36, 1612);
		this->label2->Name = L"label2";
		this->label2->Size = System::Drawing::Size(55, 13);
		this->label2->TabIndex = 255;
		this->label2->Text = L"Get Items:";
		// 
		// dataGridView_required_get_items
		// 
		this->dataGridView_required_get_items->AllowUserToAddRows = false;
		this->dataGridView_required_get_items->AllowUserToDeleteRows = false;
		this->dataGridView_required_get_items->BackgroundColor = System::Drawing::SystemColors::Window;
		this->dataGridView_required_get_items->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
		this->dataGridView_required_get_items->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
		this->dataGridView_required_get_items->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {this->dataGridViewTextBoxColumn16, 
			this->dataGridViewTextBoxColumn17, this->dataGridViewTextBoxColumn18, this->dataGridViewTextBoxColumn19, this->Column17});
		this->dataGridView_required_get_items->ContextMenuStrip = this->contextMenuStrip_required_get_items;
		this->dataGridView_required_get_items->Location = System::Drawing::Point(115, 1609);
		this->dataGridView_required_get_items->MultiSelect = false;
		this->dataGridView_required_get_items->Name = L"dataGridView_required_get_items";
		this->dataGridView_required_get_items->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
		dataGridViewCellStyle98->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
		dataGridViewCellStyle98->BackColor = System::Drawing::SystemColors::Control;
		dataGridViewCellStyle98->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		dataGridViewCellStyle98->ForeColor = System::Drawing::SystemColors::WindowText;
		dataGridViewCellStyle98->SelectionBackColor = System::Drawing::SystemColors::Highlight;
		dataGridViewCellStyle98->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
		dataGridViewCellStyle98->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView_required_get_items->RowHeadersDefaultCellStyle = dataGridViewCellStyle98;
		this->dataGridView_required_get_items->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::AutoSizeToFirstHeader;
		this->dataGridView_required_get_items->RowTemplate->Height = 18;
		this->dataGridView_required_get_items->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView_required_get_items->Size = System::Drawing::Size(219, 80);
		this->dataGridView_required_get_items->TabIndex = 256;
		this->dataGridView_required_get_items->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::change_required_get_items);
		// 
		// dataGridViewTextBoxColumn16
		// 
		this->dataGridViewTextBoxColumn16->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle94->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn16->DefaultCellStyle = dataGridViewCellStyle94;
		this->dataGridViewTextBoxColumn16->HeaderText = L"ID";
		this->dataGridViewTextBoxColumn16->Name = L"dataGridViewTextBoxColumn16";
		this->dataGridViewTextBoxColumn16->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn16->Width = 23;
		// 
		// dataGridViewTextBoxColumn17
		// 
		this->dataGridViewTextBoxColumn17->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		this->dataGridViewTextBoxColumn17->HeaderText = L"\?";
		this->dataGridViewTextBoxColumn17->Name = L"dataGridViewTextBoxColumn17";
		this->dataGridViewTextBoxColumn17->Resizable = System::Windows::Forms::DataGridViewTriState::True;
		this->dataGridViewTextBoxColumn17->Width = 18;
		// 
		// dataGridViewTextBoxColumn18
		// 
		this->dataGridViewTextBoxColumn18->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle95->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn18->DefaultCellStyle = dataGridViewCellStyle95;
		this->dataGridViewTextBoxColumn18->HeaderText = L"#";
		this->dataGridViewTextBoxColumn18->Name = L"dataGridViewTextBoxColumn18";
		this->dataGridViewTextBoxColumn18->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn18->Width = 19;
		// 
		// dataGridViewTextBoxColumn19
		// 
		this->dataGridViewTextBoxColumn19->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle96->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn19->DefaultCellStyle = dataGridViewCellStyle96;
		this->dataGridViewTextBoxColumn19->HeaderText = L"%";
		this->dataGridViewTextBoxColumn19->Name = L"dataGridViewTextBoxColumn19";
		this->dataGridViewTextBoxColumn19->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn19->Width = 20;
		// 
		// Column17
		// 
		this->Column17->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
		dataGridViewCellStyle97->ForeColor = System::Drawing::Color::Gray;
		this->Column17->DefaultCellStyle = dataGridViewCellStyle97;
		this->Column17->HeaderText = L"Expire";
		this->Column17->Name = L"Column17";
		this->Column17->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		// 
		// contextMenuStrip_required_get_items
		// 
		this->contextMenuStrip_required_get_items->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->toolStripMenuItem11, 
			this->toolStripMenuItem12});
		this->contextMenuStrip_required_get_items->Name = L"contextMenuStrip1";
		this->contextMenuStrip_required_get_items->Size = System::Drawing::Size(139, 48);
		// 
		// toolStripMenuItem11
		// 
		this->toolStripMenuItem11->Name = L"toolStripMenuItem11";
		this->toolStripMenuItem11->Size = System::Drawing::Size(138, 22);
		this->toolStripMenuItem11->Text = L"Add Item";
		this->toolStripMenuItem11->Click += gcnew System::EventHandler(this, &MainWindow::add_required_get_item);
		// 
		// toolStripMenuItem12
		// 
		this->toolStripMenuItem12->Name = L"toolStripMenuItem12";
		this->toolStripMenuItem12->Size = System::Drawing::Size(138, 22);
		this->toolStripMenuItem12->Text = L"Remove Item";
		this->toolStripMenuItem12->Click += gcnew System::EventHandler(this, &MainWindow::remove_required_get_item);
		// 
		// textBox_required_chases_unknown
		// 
		this->textBox_required_chases_unknown->Location = System::Drawing::Point(113, 1583);
		this->textBox_required_chases_unknown->Name = L"textBox_required_chases_unknown";
		this->textBox_required_chases_unknown->Size = System::Drawing::Size(184, 20);
		this->textBox_required_chases_unknown->TabIndex = 254;
		this->textBox_required_chases_unknown->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->textBox_required_chases_unknown->Leave += gcnew System::EventHandler(this, &MainWindow::change_required_chases_unknown);
		// 
		// label66
		// 
		this->label66->AutoSize = true;
		this->label66->Location = System::Drawing::Point(19, 1587);
		this->label66->Name = L"label66";
		this->label66->Size = System::Drawing::Size(94, 13);
		this->label66->TabIndex = 253;
		this->label66->Text = L"Chases Unknown:";
		// 
		// label1
		// 
		this->label1->AutoSize = true;
		this->label1->Location = System::Drawing::Point(28, 1498);
		this->label1->Name = L"label1";
		this->label1->Size = System::Drawing::Size(45, 13);
		this->label1->TabIndex = 251;
		this->label1->Text = L"Chases:";
		// 
		// dataGridView_required_chases
		// 
		this->dataGridView_required_chases->AllowUserToAddRows = false;
		this->dataGridView_required_chases->AllowUserToDeleteRows = false;
		this->dataGridView_required_chases->BackgroundColor = System::Drawing::SystemColors::Window;
		this->dataGridView_required_chases->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
		this->dataGridView_required_chases->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
		this->dataGridView_required_chases->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {this->dataGridViewTextBoxColumn20, 
			this->dataGridViewTextBoxColumn21, this->dataGridViewTextBoxColumn22, this->dataGridViewTextBoxColumn23, this->Column14, this->Column15, 
			this->Column16, this->Column1});
		this->dataGridView_required_chases->ContextMenuStrip = this->contextMenuStrip_chases;
		this->dataGridView_required_chases->Location = System::Drawing::Point(108, 1496);
		this->dataGridView_required_chases->MultiSelect = false;
		this->dataGridView_required_chases->Name = L"dataGridView_required_chases";
		this->dataGridView_required_chases->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
		dataGridViewCellStyle104->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
		dataGridViewCellStyle104->BackColor = System::Drawing::SystemColors::Control;
		dataGridViewCellStyle104->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		dataGridViewCellStyle104->ForeColor = System::Drawing::SystemColors::WindowText;
		dataGridViewCellStyle104->SelectionBackColor = System::Drawing::SystemColors::Highlight;
		dataGridViewCellStyle104->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
		dataGridViewCellStyle104->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView_required_chases->RowHeadersDefaultCellStyle = dataGridViewCellStyle104;
		this->dataGridView_required_chases->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::AutoSizeToFirstHeader;
		this->dataGridView_required_chases->RowTemplate->Height = 18;
		this->dataGridView_required_chases->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView_required_chases->Size = System::Drawing::Size(403, 80);
		this->dataGridView_required_chases->TabIndex = 252;
		this->dataGridView_required_chases->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::change_required_chases);
		// 
		// dataGridViewTextBoxColumn20
		// 
		this->dataGridViewTextBoxColumn20->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle99->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn20->DefaultCellStyle = dataGridViewCellStyle99;
		this->dataGridViewTextBoxColumn20->HeaderText = L"Mob";
		this->dataGridViewTextBoxColumn20->Name = L"dataGridViewTextBoxColumn20";
		this->dataGridViewTextBoxColumn20->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn20->Width = 33;
		// 
		// dataGridViewTextBoxColumn21
		// 
		this->dataGridViewTextBoxColumn21->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle100->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn21->DefaultCellStyle = dataGridViewCellStyle100;
		this->dataGridViewTextBoxColumn21->HeaderText = L"#";
		this->dataGridViewTextBoxColumn21->Name = L"dataGridViewTextBoxColumn21";
		this->dataGridViewTextBoxColumn21->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn21->Width = 19;
		// 
		// dataGridViewTextBoxColumn22
		// 
		this->dataGridViewTextBoxColumn22->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle101->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn22->DefaultCellStyle = dataGridViewCellStyle101;
		this->dataGridViewTextBoxColumn22->HeaderText = L"Drop";
		this->dataGridViewTextBoxColumn22->Name = L"dataGridViewTextBoxColumn22";
		this->dataGridViewTextBoxColumn22->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn22->Width = 35;
		// 
		// dataGridViewTextBoxColumn23
		// 
		this->dataGridViewTextBoxColumn23->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle102->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn23->DefaultCellStyle = dataGridViewCellStyle102;
		this->dataGridViewTextBoxColumn23->HeaderText = L"#";
		this->dataGridViewTextBoxColumn23->Name = L"dataGridViewTextBoxColumn23";
		this->dataGridViewTextBoxColumn23->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn23->Width = 19;
		// 
		// Column14
		// 
		this->Column14->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		this->Column14->HeaderText = L"\?";
		this->Column14->Name = L"Column14";
		this->Column14->Width = 37;
		// 
		// Column15
		// 
		this->Column15->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		this->Column15->HeaderText = L"%";
		this->Column15->Name = L"Column15";
		this->Column15->Width = 39;
		// 
		// Column16
		// 
		this->Column16->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		this->Column16->HeaderText = L"\?";
		this->Column16->Name = L"Column16";
		this->Column16->Width = 37;
		// 
		// Column1
		// 
		this->Column1->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
		dataGridViewCellStyle103->ForeColor = System::Drawing::Color::Gray;
		this->Column1->DefaultCellStyle = dataGridViewCellStyle103;
		this->Column1->HeaderText = L"\?";
		this->Column1->Name = L"Column1";
		this->Column1->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		// 
		// contextMenuStrip_chases
		// 
		this->contextMenuStrip_chases->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->toolStripMenuItem26, 
			this->toolStripMenuItem27});
		this->contextMenuStrip_chases->Name = L"contextMenuStrip1";
		this->contextMenuStrip_chases->Size = System::Drawing::Size(147, 48);
		// 
		// toolStripMenuItem26
		// 
		this->toolStripMenuItem26->Name = L"toolStripMenuItem26";
		this->toolStripMenuItem26->Size = System::Drawing::Size(146, 22);
		this->toolStripMenuItem26->Text = L"Add Chase";
		this->toolStripMenuItem26->Click += gcnew System::EventHandler(this, &MainWindow::add_required_chase);
		// 
		// toolStripMenuItem27
		// 
		this->toolStripMenuItem27->Name = L"toolStripMenuItem27";
		this->toolStripMenuItem27->Size = System::Drawing::Size(146, 22);
		this->toolStripMenuItem27->Text = L"Remove Chase";
		this->toolStripMenuItem27->Click += gcnew System::EventHandler(this, &MainWindow::remove_required_chases);
		// 
		// textBox_required_npc_type
		// 
		this->textBox_required_npc_type->Location = System::Drawing::Point(553, 1256);
		this->textBox_required_npc_type->Name = L"textBox_required_npc_type";
		this->textBox_required_npc_type->Size = System::Drawing::Size(64, 20);
		this->textBox_required_npc_type->TabIndex = 250;
		this->textBox_required_npc_type->Leave += gcnew System::EventHandler(this, &MainWindow::change_required_npc_type);
		// 
		// label161
		// 
		this->label161->AutoSize = true;
		this->label161->Location = System::Drawing::Point(470, 1259);
		this->label161->Name = L"label161";
		this->label161->Size = System::Drawing::Size(59, 13);
		this->label161->TabIndex = 249;
		this->label161->Text = L"NPC Type:";
		// 
		// textBox_required_success_type
		// 
		this->textBox_required_success_type->Location = System::Drawing::Point(389, 1254);
		this->textBox_required_success_type->Name = L"textBox_required_success_type";
		this->textBox_required_success_type->Size = System::Drawing::Size(64, 20);
		this->textBox_required_success_type->TabIndex = 248;
		this->textBox_required_success_type->Leave += gcnew System::EventHandler(this, &MainWindow::change_required_success_type);
		// 
		// label160
		// 
		this->label160->AutoSize = true;
		this->label160->Location = System::Drawing::Point(306, 1257);
		this->label160->Name = L"label160";
		this->label160->Size = System::Drawing::Size(78, 13);
		this->label160->TabIndex = 247;
		this->label160->Text = L"Success Type:";
		// 
		// textBox_unknown_55_02_01
		// 
		this->textBox_unknown_55_02_01->Location = System::Drawing::Point(116, 1193);
		this->textBox_unknown_55_02_01->Name = L"textBox_unknown_55_02_01";
		this->textBox_unknown_55_02_01->Size = System::Drawing::Size(44, 20);
		this->textBox_unknown_55_02_01->TabIndex = 246;
		this->textBox_unknown_55_02_01->Leave += gcnew System::EventHandler(this, &MainWindow::change_unknown_55_02_01);
		// 
		// label159
		// 
		this->label159->AutoSize = true;
		this->label159->ForeColor = System::Drawing::Color::Red;
		this->label159->Location = System::Drawing::Point(1, 1196);
		this->label159->Name = L"label159";
		this->label159->Size = System::Drawing::Size(107, 13);
		this->label159->TabIndex = 245;
		this->label159->Text = L"Unknown 55_02_01:";
		// 
		// textBox_unknown_55
		// 
		this->textBox_unknown_55->Location = System::Drawing::Point(92, 1168);
		this->textBox_unknown_55->Name = L"textBox_unknown_55";
		this->textBox_unknown_55->Size = System::Drawing::Size(484, 20);
		this->textBox_unknown_55->TabIndex = 244;
		this->textBox_unknown_55->Leave += gcnew System::EventHandler(this, &MainWindow::change_unknown_55);
		// 
		// label158
		// 
		this->label158->AutoSize = true;
		this->label158->ForeColor = System::Drawing::Color::Gray;
		this->label158->Location = System::Drawing::Point(9, 1171);
		this->label158->Name = L"label158";
		this->label158->Size = System::Drawing::Size(71, 13);
		this->label158->TabIndex = 243;
		this->label158->Text = L"Unknown 55:";
		// 
		// textBox_required_pq_contribution
		// 
		this->textBox_required_pq_contribution->Location = System::Drawing::Point(490, 1126);
		this->textBox_required_pq_contribution->Name = L"textBox_required_pq_contribution";
		this->textBox_required_pq_contribution->Size = System::Drawing::Size(64, 20);
		this->textBox_required_pq_contribution->TabIndex = 242;
		this->textBox_required_pq_contribution->Leave += gcnew System::EventHandler(this, &MainWindow::change_required_pq_contribution);
		// 
		// label157
		// 
		this->label157->AutoSize = true;
		this->label157->ForeColor = System::Drawing::Color::Gray;
		this->label157->Location = System::Drawing::Point(356, 1131);
		this->label157->Name = L"label157";
		this->label157->Size = System::Drawing::Size(130, 13);
		this->label157->TabIndex = 241;
		this->label157->Text = L"Required PQ Contribution:";
		// 
		// textBox_unknown_54
		// 
		this->textBox_unknown_54->Location = System::Drawing::Point(486, 1094);
		this->textBox_unknown_54->Name = L"textBox_unknown_54";
		this->textBox_unknown_54->Size = System::Drawing::Size(64, 20);
		this->textBox_unknown_54->TabIndex = 240;
		this->textBox_unknown_54->Leave += gcnew System::EventHandler(this, &MainWindow::change_unknown_54);
		// 
		// label156
		// 
		this->label156->AutoSize = true;
		this->label156->ForeColor = System::Drawing::Color::Gray;
		this->label156->Location = System::Drawing::Point(403, 1097);
		this->label156->Name = L"label156";
		this->label156->Size = System::Drawing::Size(71, 13);
		this->label156->TabIndex = 239;
		this->label156->Text = L"Unknown 54:";
		// 
		// textBox_unknown_53
		// 
		this->textBox_unknown_53->Location = System::Drawing::Point(265, 1122);
		this->textBox_unknown_53->Name = L"textBox_unknown_53";
		this->textBox_unknown_53->Size = System::Drawing::Size(64, 20);
		this->textBox_unknown_53->TabIndex = 238;
		this->textBox_unknown_53->Leave += gcnew System::EventHandler(this, &MainWindow::change_unknown_53);
		// 
		// label155
		// 
		this->label155->AutoSize = true;
		this->label155->ForeColor = System::Drawing::Color::Gray;
		this->label155->Location = System::Drawing::Point(182, 1125);
		this->label155->Name = L"label155";
		this->label155->Size = System::Drawing::Size(71, 13);
		this->label155->TabIndex = 237;
		this->label155->Text = L"Unknown 53:";
		// 
		// textBox_resource_pq_audit_id
		// 
		this->textBox_resource_pq_audit_id->Location = System::Drawing::Point(263, 1093);
		this->textBox_resource_pq_audit_id->Name = L"textBox_resource_pq_audit_id";
		this->textBox_resource_pq_audit_id->Size = System::Drawing::Size(64, 20);
		this->textBox_resource_pq_audit_id->TabIndex = 236;
		this->textBox_resource_pq_audit_id->Leave += gcnew System::EventHandler(this, &MainWindow::change_resource_pq_audit_id);
		// 
		// label154
		// 
		this->label154->AutoSize = true;
		this->label154->ForeColor = System::Drawing::Color::Gray;
		this->label154->Location = System::Drawing::Point(174, 1096);
		this->label154->Name = L"label154";
		this->label154->Size = System::Drawing::Size(88, 13);
		this->label154->TabIndex = 235;
		this->label154->Text = L"Resource PQ ID:";
		// 
		// textBox_unknown_52
		// 
		this->textBox_unknown_52->Location = System::Drawing::Point(99, 1141);
		this->textBox_unknown_52->Name = L"textBox_unknown_52";
		this->textBox_unknown_52->Size = System::Drawing::Size(64, 20);
		this->textBox_unknown_52->TabIndex = 234;
		this->textBox_unknown_52->Leave += gcnew System::EventHandler(this, &MainWindow::change_unknown_52);
		// 
		// label153
		// 
		this->label153->AutoSize = true;
		this->label153->ForeColor = System::Drawing::Color::Gray;
		this->label153->Location = System::Drawing::Point(15, 1144);
		this->label153->Name = L"label153";
		this->label153->Size = System::Drawing::Size(71, 13);
		this->label153->TabIndex = 233;
		this->label153->Text = L"Unknown 52:";
		// 
		// checkBox_unknown_51
		// 
		this->checkBox_unknown_51->AutoSize = true;
		this->checkBox_unknown_51->Location = System::Drawing::Point(101, 1119);
		this->checkBox_unknown_51->Name = L"checkBox_unknown_51";
		this->checkBox_unknown_51->Size = System::Drawing::Size(15, 14);
		this->checkBox_unknown_51->TabIndex = 232;
		this->checkBox_unknown_51->UseVisualStyleBackColor = true;
		this->checkBox_unknown_51->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_unknown_51);
		// 
		// label152
		// 
		this->label152->AutoSize = true;
		this->label152->Location = System::Drawing::Point(10, 1119);
		this->label152->Name = L"label152";
		this->label152->Size = System::Drawing::Size(71, 13);
		this->label152->TabIndex = 231;
		this->label152->Text = L"Unknown 51:";
		// 
		// textBox_unknown_50
		// 
		this->textBox_unknown_50->Location = System::Drawing::Point(95, 1092);
		this->textBox_unknown_50->Name = L"textBox_unknown_50";
		this->textBox_unknown_50->Size = System::Drawing::Size(64, 20);
		this->textBox_unknown_50->TabIndex = 230;
		this->textBox_unknown_50->Leave += gcnew System::EventHandler(this, &MainWindow::change_unknown_50);
		// 
		// label151
		// 
		this->label151->AutoSize = true;
		this->label151->Location = System::Drawing::Point(12, 1095);
		this->label151->Name = L"label151";
		this->label151->Size = System::Drawing::Size(71, 13);
		this->label151->TabIndex = 229;
		this->label151->Text = L"Unknown 50:";
		// 
		// textBox_unknown_49
		// 
		this->textBox_unknown_49->Location = System::Drawing::Point(94, 968);
		this->textBox_unknown_49->Name = L"textBox_unknown_49";
		this->textBox_unknown_49->Size = System::Drawing::Size(64, 20);
		this->textBox_unknown_49->TabIndex = 228;
		this->textBox_unknown_49->Leave += gcnew System::EventHandler(this, &MainWindow::change_unknown_49);
		// 
		// label150
		// 
		this->label150->AutoSize = true;
		this->label150->ForeColor = System::Drawing::Color::Gray;
		this->label150->Location = System::Drawing::Point(11, 971);
		this->label150->Name = L"label150";
		this->label150->Size = System::Drawing::Size(71, 13);
		this->label150->TabIndex = 227;
		this->label150->Text = L"Unknown 49:";
		// 
		// textBox_unknown_48
		// 
		this->textBox_unknown_48->Location = System::Drawing::Point(95, 942);
		this->textBox_unknown_48->Name = L"textBox_unknown_48";
		this->textBox_unknown_48->Size = System::Drawing::Size(487, 20);
		this->textBox_unknown_48->TabIndex = 226;
		this->textBox_unknown_48->Leave += gcnew System::EventHandler(this, &MainWindow::change_unknown_48);
		// 
		// label149
		// 
		this->label149->AutoSize = true;
		this->label149->Location = System::Drawing::Point(12, 945);
		this->label149->Name = L"label149";
		this->label149->Size = System::Drawing::Size(71, 13);
		this->label149->TabIndex = 225;
		this->label149->Text = L"Unknown 48:";
		// 
		// textBox_required_apothecary_level
		// 
		this->textBox_required_apothecary_level->Location = System::Drawing::Point(532, 874);
		this->textBox_required_apothecary_level->Name = L"textBox_required_apothecary_level";
		this->textBox_required_apothecary_level->Size = System::Drawing::Size(44, 20);
		this->textBox_required_apothecary_level->TabIndex = 224;
		this->textBox_required_apothecary_level->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->textBox_required_apothecary_level->Leave += gcnew System::EventHandler(this, &MainWindow::change_required_apothecary_level);
		// 
		// label80
		// 
		this->label80->AutoSize = true;
		this->label80->Location = System::Drawing::Point(434, 877);
		this->label80->Name = L"label80";
		this->label80->Size = System::Drawing::Size(93, 13);
		this->label80->TabIndex = 223;
		this->label80->Text = L"Apothecary Level:";
		// 
		// textBox_required_craftsman_level
		// 
		this->textBox_required_craftsman_level->Location = System::Drawing::Point(532, 848);
		this->textBox_required_craftsman_level->Name = L"textBox_required_craftsman_level";
		this->textBox_required_craftsman_level->Size = System::Drawing::Size(44, 20);
		this->textBox_required_craftsman_level->TabIndex = 222;
		this->textBox_required_craftsman_level->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->textBox_required_craftsman_level->Leave += gcnew System::EventHandler(this, &MainWindow::change_required_craftsman_level);
		// 
		// label79
		// 
		this->label79->AutoSize = true;
		this->label79->Location = System::Drawing::Point(434, 851);
		this->label79->Name = L"label79";
		this->label79->Size = System::Drawing::Size(86, 13);
		this->label79->TabIndex = 221;
		this->label79->Text = L"Craftsman Level:";
		// 
		// textBox_required_tailor_level
		// 
		this->textBox_required_tailor_level->Location = System::Drawing::Point(532, 822);
		this->textBox_required_tailor_level->Name = L"textBox_required_tailor_level";
		this->textBox_required_tailor_level->Size = System::Drawing::Size(44, 20);
		this->textBox_required_tailor_level->TabIndex = 220;
		this->textBox_required_tailor_level->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->textBox_required_tailor_level->Leave += gcnew System::EventHandler(this, &MainWindow::change_required_tailor_level);
		// 
		// label78
		// 
		this->label78->AutoSize = true;
		this->label78->Location = System::Drawing::Point(434, 825);
		this->label78->Name = L"label78";
		this->label78->Size = System::Drawing::Size(65, 13);
		this->label78->TabIndex = 219;
		this->label78->Text = L"Tailor Level:";
		// 
		// textBox_required_blacksmith_level
		// 
		this->textBox_required_blacksmith_level->Location = System::Drawing::Point(532, 796);
		this->textBox_required_blacksmith_level->Name = L"textBox_required_blacksmith_level";
		this->textBox_required_blacksmith_level->Size = System::Drawing::Size(44, 20);
		this->textBox_required_blacksmith_level->TabIndex = 218;
		this->textBox_required_blacksmith_level->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->textBox_required_blacksmith_level->Leave += gcnew System::EventHandler(this, &MainWindow::change_required_blacksmith_level);
		// 
		// label77
		// 
		this->label77->AutoSize = true;
		this->label77->Location = System::Drawing::Point(434, 799);
		this->label77->Name = L"label77";
		this->label77->Size = System::Drawing::Size(90, 13);
		this->label77->TabIndex = 217;
		this->label77->Text = L"Blacksmith Level:";
		// 
		// textBox_required_quests_undone_1
		// 
		this->textBox_required_quests_undone_1->Location = System::Drawing::Point(369, 284);
		this->textBox_required_quests_undone_1->Name = L"textBox_required_quests_undone_1";
		this->textBox_required_quests_undone_1->Size = System::Drawing::Size(101, 20);
		this->textBox_required_quests_undone_1->TabIndex = 11;
		this->textBox_required_quests_undone_1->Leave += gcnew System::EventHandler(this, &MainWindow::change_required_quests_undone);
		// 
		// textBox_unknown_47
		// 
		this->textBox_unknown_47->Location = System::Drawing::Point(92, 881);
		this->textBox_unknown_47->Name = L"textBox_unknown_47";
		this->textBox_unknown_47->Size = System::Drawing::Size(111, 20);
		this->textBox_unknown_47->TabIndex = 216;
		this->textBox_unknown_47->Leave += gcnew System::EventHandler(this, &MainWindow::change_unknown_47);
		// 
		// textBox_required_quests_undone_2
		// 
		this->textBox_required_quests_undone_2->Location = System::Drawing::Point(369, 310);
		this->textBox_required_quests_undone_2->Name = L"textBox_required_quests_undone_2";
		this->textBox_required_quests_undone_2->Size = System::Drawing::Size(101, 20);
		this->textBox_required_quests_undone_2->TabIndex = 12;
		this->textBox_required_quests_undone_2->Leave += gcnew System::EventHandler(this, &MainWindow::change_required_quests_undone);
		// 
		// label148
		// 
		this->label148->AutoSize = true;
		this->label148->Location = System::Drawing::Point(9, 884);
		this->label148->Name = L"label148";
		this->label148->Size = System::Drawing::Size(71, 13);
		this->label148->TabIndex = 215;
		this->label148->Text = L"Unknown 47:";
		// 
		// textBox_required_quests_undone_3
		// 
		this->textBox_required_quests_undone_3->Location = System::Drawing::Point(369, 336);
		this->textBox_required_quests_undone_3->Name = L"textBox_required_quests_undone_3";
		this->textBox_required_quests_undone_3->Size = System::Drawing::Size(101, 20);
		this->textBox_required_quests_undone_3->TabIndex = 13;
		this->textBox_required_quests_undone_3->Leave += gcnew System::EventHandler(this, &MainWindow::change_required_quests_undone);
		// 
		// checkBox_unknown_46
		// 
		this->checkBox_unknown_46->AutoSize = true;
		this->checkBox_unknown_46->Location = System::Drawing::Point(98, 861);
		this->checkBox_unknown_46->Name = L"checkBox_unknown_46";
		this->checkBox_unknown_46->Size = System::Drawing::Size(15, 14);
		this->checkBox_unknown_46->TabIndex = 214;
		this->checkBox_unknown_46->UseVisualStyleBackColor = true;
		this->checkBox_unknown_46->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_unknown_46);
		// 
		// textBox_required_quests_undone_5
		// 
		this->textBox_required_quests_undone_5->Location = System::Drawing::Point(369, 388);
		this->textBox_required_quests_undone_5->Name = L"textBox_required_quests_undone_5";
		this->textBox_required_quests_undone_5->Size = System::Drawing::Size(101, 20);
		this->textBox_required_quests_undone_5->TabIndex = 15;
		this->textBox_required_quests_undone_5->Leave += gcnew System::EventHandler(this, &MainWindow::change_required_quests_undone);
		// 
		// textBox_required_quests_undone_4
		// 
		this->textBox_required_quests_undone_4->Location = System::Drawing::Point(369, 362);
		this->textBox_required_quests_undone_4->Name = L"textBox_required_quests_undone_4";
		this->textBox_required_quests_undone_4->Size = System::Drawing::Size(101, 20);
		this->textBox_required_quests_undone_4->TabIndex = 14;
		this->textBox_required_quests_undone_4->Leave += gcnew System::EventHandler(this, &MainWindow::change_required_quests_undone);
		// 
		// label147
		// 
		this->label147->AutoSize = true;
		this->label147->ForeColor = System::Drawing::Color::Gray;
		this->label147->Location = System::Drawing::Point(7, 861);
		this->label147->Name = L"label147";
		this->label147->Size = System::Drawing::Size(71, 13);
		this->label147->TabIndex = 213;
		this->label147->Text = L"Unknown 46:";
		// 
		// textBox_unknown_45
		// 
		this->textBox_unknown_45->Location = System::Drawing::Point(88, 833);
		this->textBox_unknown_45->Name = L"textBox_unknown_45";
		this->textBox_unknown_45->Size = System::Drawing::Size(60, 20);
		this->textBox_unknown_45->TabIndex = 212;
		this->textBox_unknown_45->Leave += gcnew System::EventHandler(this, &MainWindow::change_unknown_45);
		// 
		// label146
		// 
		this->label146->AutoSize = true;
		this->label146->ForeColor = System::Drawing::Color::Gray;
		this->label146->Location = System::Drawing::Point(5, 836);
		this->label146->Name = L"label146";
		this->label146->Size = System::Drawing::Size(71, 13);
		this->label146->TabIndex = 211;
		this->label146->Text = L"Unknown 45:";
		// 
		// dataGridView_date_unknown
		// 
		this->dataGridView_date_unknown->AllowUserToAddRows = false;
		this->dataGridView_date_unknown->AllowUserToDeleteRows = false;
		this->dataGridView_date_unknown->BackgroundColor = System::Drawing::SystemColors::Control;
		this->dataGridView_date_unknown->BorderStyle = System::Windows::Forms::BorderStyle::None;
		this->dataGridView_date_unknown->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
		this->dataGridView_date_unknown->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
		this->dataGridView_date_unknown->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {this->dataGridViewTextBoxColumn55, 
			this->dataGridViewTextBoxColumn56, this->dataGridViewTextBoxColumn57, this->dataGridViewTextBoxColumn58, this->dataGridViewTextBoxColumn59, 
			this->Column_date_unknown_weekday});
		this->dataGridView_date_unknown->Location = System::Drawing::Point(91, 784);
		this->dataGridView_date_unknown->MultiSelect = false;
		this->dataGridView_date_unknown->Name = L"dataGridView_date_unknown";
		this->dataGridView_date_unknown->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
		dataGridViewCellStyle111->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
		dataGridViewCellStyle111->BackColor = System::Drawing::SystemColors::Control;
		dataGridViewCellStyle111->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		dataGridViewCellStyle111->ForeColor = System::Drawing::SystemColors::WindowText;
		dataGridViewCellStyle111->SelectionBackColor = System::Drawing::SystemColors::Highlight;
		dataGridViewCellStyle111->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
		dataGridViewCellStyle111->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView_date_unknown->RowHeadersDefaultCellStyle = dataGridViewCellStyle111;
		this->dataGridView_date_unknown->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::AutoSizeToFirstHeader;
		this->dataGridView_date_unknown->RowTemplate->Height = 18;
		this->dataGridView_date_unknown->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView_date_unknown->Size = System::Drawing::Size(207, 43);
		this->dataGridView_date_unknown->TabIndex = 210;
		this->dataGridView_date_unknown->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::change_date_unknown);
		// 
		// dataGridViewTextBoxColumn55
		// 
		this->dataGridViewTextBoxColumn55->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
		dataGridViewCellStyle105->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn55->DefaultCellStyle = dataGridViewCellStyle105;
		this->dataGridViewTextBoxColumn55->HeaderText = L"Y";
		this->dataGridViewTextBoxColumn55->Name = L"dataGridViewTextBoxColumn55";
		this->dataGridViewTextBoxColumn55->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		// 
		// dataGridViewTextBoxColumn56
		// 
		dataGridViewCellStyle106->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn56->DefaultCellStyle = dataGridViewCellStyle106;
		this->dataGridViewTextBoxColumn56->HeaderText = L"M";
		this->dataGridViewTextBoxColumn56->Name = L"dataGridViewTextBoxColumn56";
		this->dataGridViewTextBoxColumn56->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn56->Width = 21;
		// 
		// dataGridViewTextBoxColumn57
		// 
		dataGridViewCellStyle107->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn57->DefaultCellStyle = dataGridViewCellStyle107;
		this->dataGridViewTextBoxColumn57->HeaderText = L"D";
		this->dataGridViewTextBoxColumn57->Name = L"dataGridViewTextBoxColumn57";
		this->dataGridViewTextBoxColumn57->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn57->Width = 20;
		// 
		// dataGridViewTextBoxColumn58
		// 
		dataGridViewCellStyle108->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn58->DefaultCellStyle = dataGridViewCellStyle108;
		this->dataGridViewTextBoxColumn58->HeaderText = L"H";
		this->dataGridViewTextBoxColumn58->Name = L"dataGridViewTextBoxColumn58";
		this->dataGridViewTextBoxColumn58->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn58->Width = 20;
		// 
		// dataGridViewTextBoxColumn59
		// 
		dataGridViewCellStyle109->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn59->DefaultCellStyle = dataGridViewCellStyle109;
		this->dataGridViewTextBoxColumn59->HeaderText = L"M";
		this->dataGridViewTextBoxColumn59->Name = L"dataGridViewTextBoxColumn59";
		this->dataGridViewTextBoxColumn59->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn59->Width = 21;
		// 
		// Column_date_unknown_weekday
		// 
		this->Column_date_unknown_weekday->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle110->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->Column_date_unknown_weekday->DefaultCellStyle = dataGridViewCellStyle110;
		this->Column_date_unknown_weekday->HeaderText = L"d";
		this->Column_date_unknown_weekday->Items->AddRange(gcnew cli::array< System::Object^  >(8) {L"ALL", L"Mon", L"Tue", L"Wed", 
			L"Thu", L"Fri", L"Sat", L"Sun"});
		this->Column_date_unknown_weekday->Name = L"Column_date_unknown_weekday";
		this->Column_date_unknown_weekday->Resizable = System::Windows::Forms::DataGridViewTriState::True;
		this->Column_date_unknown_weekday->Width = 18;
		// 
		// label145
		// 
		this->label145->AutoSize = true;
		this->label145->ForeColor = System::Drawing::Color::Gray;
		this->label145->Location = System::Drawing::Point(3, 784);
		this->label145->Name = L"label145";
		this->label145->Size = System::Drawing::Size(82, 13);
		this->label145->TabIndex = 209;
		this->label145->Text = L"Date Unknown:";
		// 
		// textBox_unknown_44
		// 
		this->textBox_unknown_44->Location = System::Drawing::Point(85, 758);
		this->textBox_unknown_44->Name = L"textBox_unknown_44";
		this->textBox_unknown_44->Size = System::Drawing::Size(564, 20);
		this->textBox_unknown_44->TabIndex = 207;
		this->textBox_unknown_44->Leave += gcnew System::EventHandler(this, &MainWindow::change_unknown_44);
		// 
		// label144
		// 
		this->label144->AutoSize = true;
		this->label144->ForeColor = System::Drawing::Color::Gray;
		this->label144->Location = System::Drawing::Point(3, 761);
		this->label144->Name = L"label144";
		this->label144->Size = System::Drawing::Size(71, 13);
		this->label144->TabIndex = 206;
		this->label144->Text = L"Unknown 44:";
		// 
		// checkBox_occupation_seeker
		// 
		this->checkBox_occupation_seeker->AutoSize = true;
		this->checkBox_occupation_seeker->ForeColor = System::Drawing::Color::Gray;
		this->checkBox_occupation_seeker->Location = System::Drawing::Point(587, 332);
		this->checkBox_occupation_seeker->Name = L"checkBox_occupation_seeker";
		this->checkBox_occupation_seeker->Size = System::Drawing::Size(60, 17);
		this->checkBox_occupation_seeker->TabIndex = 205;
		this->checkBox_occupation_seeker->Text = L"Seeker";
		this->checkBox_occupation_seeker->UseVisualStyleBackColor = true;
		this->checkBox_occupation_seeker->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_required_occupations);
		// 
		// checkBox_occupation_mystic
		// 
		this->checkBox_occupation_mystic->AutoSize = true;
		this->checkBox_occupation_mystic->ForeColor = System::Drawing::Color::Gray;
		this->checkBox_occupation_mystic->Location = System::Drawing::Point(587, 355);
		this->checkBox_occupation_mystic->Name = L"checkBox_occupation_mystic";
		this->checkBox_occupation_mystic->Size = System::Drawing::Size(56, 17);
		this->checkBox_occupation_mystic->TabIndex = 204;
		this->checkBox_occupation_mystic->Text = L"Mystic";
		this->checkBox_occupation_mystic->UseVisualStyleBackColor = true;
		this->checkBox_occupation_mystic->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_required_occupations);
		// 
		// checkBox_occupation_cleric
		// 
		this->checkBox_occupation_cleric->AutoSize = true;
		this->checkBox_occupation_cleric->Location = System::Drawing::Point(495, 401);
		this->checkBox_occupation_cleric->Name = L"checkBox_occupation_cleric";
		this->checkBox_occupation_cleric->Size = System::Drawing::Size(52, 17);
		this->checkBox_occupation_cleric->TabIndex = 203;
		this->checkBox_occupation_cleric->Text = L"Cleric";
		this->checkBox_occupation_cleric->UseVisualStyleBackColor = true;
		this->checkBox_occupation_cleric->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_required_occupations);
		// 
		// checkBox_occupation_archer
		// 
		this->checkBox_occupation_archer->AutoSize = true;
		this->checkBox_occupation_archer->Location = System::Drawing::Point(495, 378);
		this->checkBox_occupation_archer->Name = L"checkBox_occupation_archer";
		this->checkBox_occupation_archer->Size = System::Drawing::Size(57, 17);
		this->checkBox_occupation_archer->TabIndex = 202;
		this->checkBox_occupation_archer->Text = L"Archer";
		this->checkBox_occupation_archer->UseVisualStyleBackColor = true;
		this->checkBox_occupation_archer->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_required_occupations);
		// 
		// checkBox_occupation_psychic
		// 
		this->checkBox_occupation_psychic->AutoSize = true;
		this->checkBox_occupation_psychic->ForeColor = System::Drawing::Color::Gray;
		this->checkBox_occupation_psychic->Location = System::Drawing::Point(587, 286);
		this->checkBox_occupation_psychic->Name = L"checkBox_occupation_psychic";
		this->checkBox_occupation_psychic->Size = System::Drawing::Size(63, 17);
		this->checkBox_occupation_psychic->TabIndex = 201;
		this->checkBox_occupation_psychic->Text = L"Psychic";
		this->checkBox_occupation_psychic->UseVisualStyleBackColor = true;
		this->checkBox_occupation_psychic->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_required_occupations);
		// 
		// checkBox_occupation_barbarian
		// 
		this->checkBox_occupation_barbarian->AutoSize = true;
		this->checkBox_occupation_barbarian->Location = System::Drawing::Point(495, 355);
		this->checkBox_occupation_barbarian->Name = L"checkBox_occupation_barbarian";
		this->checkBox_occupation_barbarian->Size = System::Drawing::Size(71, 17);
		this->checkBox_occupation_barbarian->TabIndex = 200;
		this->checkBox_occupation_barbarian->Text = L"Barbarian";
		this->checkBox_occupation_barbarian->UseVisualStyleBackColor = true;
		this->checkBox_occupation_barbarian->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_required_occupations);
		// 
		// checkBox_occupation_venomancer
		// 
		this->checkBox_occupation_venomancer->AutoSize = true;
		this->checkBox_occupation_venomancer->Location = System::Drawing::Point(495, 332);
		this->checkBox_occupation_venomancer->Name = L"checkBox_occupation_venomancer";
		this->checkBox_occupation_venomancer->Size = System::Drawing::Size(86, 17);
		this->checkBox_occupation_venomancer->TabIndex = 199;
		this->checkBox_occupation_venomancer->Text = L"Venomancer";
		this->checkBox_occupation_venomancer->UseVisualStyleBackColor = true;
		this->checkBox_occupation_venomancer->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_required_occupations);
		// 
		// checkBox_occupation_assassin
		// 
		this->checkBox_occupation_assassin->AutoSize = true;
		this->checkBox_occupation_assassin->ForeColor = System::Drawing::Color::Gray;
		this->checkBox_occupation_assassin->Location = System::Drawing::Point(587, 309);
		this->checkBox_occupation_assassin->Name = L"checkBox_occupation_assassin";
		this->checkBox_occupation_assassin->Size = System::Drawing::Size(67, 17);
		this->checkBox_occupation_assassin->TabIndex = 198;
		this->checkBox_occupation_assassin->Text = L"Assassin";
		this->checkBox_occupation_assassin->UseVisualStyleBackColor = true;
		this->checkBox_occupation_assassin->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_required_occupations);
		// 
		// checkBox_occupation_wizard
		// 
		this->checkBox_occupation_wizard->AutoSize = true;
		this->checkBox_occupation_wizard->Location = System::Drawing::Point(495, 309);
		this->checkBox_occupation_wizard->Name = L"checkBox_occupation_wizard";
		this->checkBox_occupation_wizard->Size = System::Drawing::Size(59, 17);
		this->checkBox_occupation_wizard->TabIndex = 197;
		this->checkBox_occupation_wizard->Text = L"Wizard";
		this->checkBox_occupation_wizard->UseVisualStyleBackColor = true;
		this->checkBox_occupation_wizard->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_required_occupations);
		// 
		// checkBox_occupation_blademaster
		// 
		this->checkBox_occupation_blademaster->AutoSize = true;
		this->checkBox_occupation_blademaster->Location = System::Drawing::Point(495, 286);
		this->checkBox_occupation_blademaster->Name = L"checkBox_occupation_blademaster";
		this->checkBox_occupation_blademaster->Size = System::Drawing::Size(84, 17);
		this->checkBox_occupation_blademaster->TabIndex = 196;
		this->checkBox_occupation_blademaster->Text = L"Blademaster";
		this->checkBox_occupation_blademaster->UseVisualStyleBackColor = true;
		this->checkBox_occupation_blademaster->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_required_occupations);
		// 
		// checkBox_unknown_43
		// 
		this->checkBox_unknown_43->AutoSize = true;
		this->checkBox_unknown_43->Location = System::Drawing::Point(154, 732);
		this->checkBox_unknown_43->Name = L"checkBox_unknown_43";
		this->checkBox_unknown_43->Size = System::Drawing::Size(15, 14);
		this->checkBox_unknown_43->TabIndex = 195;
		this->checkBox_unknown_43->UseVisualStyleBackColor = true;
		this->checkBox_unknown_43->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_unknown_43);
		// 
		// label143
		// 
		this->label143->AutoSize = true;
		this->label143->Location = System::Drawing::Point(10, 735);
		this->label143->Name = L"label143";
		this->label143->Size = System::Drawing::Size(71, 13);
		this->label143->TabIndex = 194;
		this->label143->Text = L"Unknown 43:";
		// 
		// checkBox_required_be_gm
		// 
		this->checkBox_required_be_gm->AutoSize = true;
		this->checkBox_required_be_gm->Location = System::Drawing::Point(154, 707);
		this->checkBox_required_be_gm->Name = L"checkBox_required_be_gm";
		this->checkBox_required_be_gm->Size = System::Drawing::Size(15, 14);
		this->checkBox_required_be_gm->TabIndex = 193;
		this->checkBox_required_be_gm->UseVisualStyleBackColor = true;
		this->checkBox_required_be_gm->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_required_be_gm);
		// 
		// label142
		// 
		this->label142->AutoSize = true;
		this->label142->Location = System::Drawing::Point(10, 710);
		this->label142->Name = L"label142";
		this->label142->Size = System::Drawing::Size(88, 13);
		this->label142->TabIndex = 192;
		this->label142->Text = L"Required be GM:";
		// 
		// checkBox_unknown_42
		// 
		this->checkBox_unknown_42->AutoSize = true;
		this->checkBox_unknown_42->Location = System::Drawing::Point(148, 648);
		this->checkBox_unknown_42->Name = L"checkBox_unknown_42";
		this->checkBox_unknown_42->Size = System::Drawing::Size(15, 14);
		this->checkBox_unknown_42->TabIndex = 191;
		this->checkBox_unknown_42->UseVisualStyleBackColor = true;
		this->checkBox_unknown_42->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_unknown_42);
		// 
		// label141
		// 
		this->label141->AutoSize = true;
		this->label141->Location = System::Drawing::Point(4, 651);
		this->label141->Name = L"label141";
		this->label141->Size = System::Drawing::Size(71, 13);
		this->label141->TabIndex = 190;
		this->label141->Text = L"Unknown 42:";
		// 
		// checkBox_required_be_married
		// 
		this->checkBox_required_be_married->AutoSize = true;
		this->checkBox_required_be_married->Location = System::Drawing::Point(148, 624);
		this->checkBox_required_be_married->Name = L"checkBox_required_be_married";
		this->checkBox_required_be_married->Size = System::Drawing::Size(15, 14);
		this->checkBox_required_be_married->TabIndex = 189;
		this->checkBox_required_be_married->UseVisualStyleBackColor = true;
		this->checkBox_required_be_married->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_required_be_married);
		// 
		// label140
		// 
		this->label140->AutoSize = true;
		this->label140->Location = System::Drawing::Point(5, 626);
		this->label140->Name = L"label140";
		this->label140->Size = System::Drawing::Size(106, 13);
		this->label140->TabIndex = 188;
		this->label140->Text = L"Required be Married:";
		// 
		// checkBox_unknown_41
		// 
		this->checkBox_unknown_41->AutoSize = true;
		this->checkBox_unknown_41->Location = System::Drawing::Point(145, 601);
		this->checkBox_unknown_41->Name = L"checkBox_unknown_41";
		this->checkBox_unknown_41->Size = System::Drawing::Size(15, 14);
		this->checkBox_unknown_41->TabIndex = 187;
		this->checkBox_unknown_41->UseVisualStyleBackColor = true;
		this->checkBox_unknown_41->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_unknown_41);
		// 
		// label139
		// 
		this->label139->AutoSize = true;
		this->label139->Location = System::Drawing::Point(1, 604);
		this->label139->Name = L"label139";
		this->label139->Size = System::Drawing::Size(71, 13);
		this->label139->TabIndex = 186;
		this->label139->Text = L"Unknown 41:";
		// 
		// checkBox_unknown_40
		// 
		this->checkBox_unknown_40->AutoSize = true;
		this->checkBox_unknown_40->Location = System::Drawing::Point(148, 573);
		this->checkBox_unknown_40->Name = L"checkBox_unknown_40";
		this->checkBox_unknown_40->Size = System::Drawing::Size(15, 14);
		this->checkBox_unknown_40->TabIndex = 185;
		this->checkBox_unknown_40->UseVisualStyleBackColor = true;
		this->checkBox_unknown_40->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_unknown_40);
		// 
		// label30
		// 
		this->label30->AutoSize = true;
		this->label30->Location = System::Drawing::Point(4, 576);
		this->label30->Name = L"label30";
		this->label30->Size = System::Drawing::Size(71, 13);
		this->label30->TabIndex = 184;
		this->label30->Text = L"Unknown 40:";
		// 
		// comboBox_required_gender
		// 
		this->comboBox_required_gender->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
		this->comboBox_required_gender->FormattingEnabled = true;
		this->comboBox_required_gender->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"All", L"Male", L"Female"});
		this->comboBox_required_gender->Location = System::Drawing::Point(149, 537);
		this->comboBox_required_gender->Name = L"comboBox_required_gender";
		this->comboBox_required_gender->Size = System::Drawing::Size(81, 21);
		this->comboBox_required_gender->TabIndex = 182;
		this->comboBox_required_gender->SelectedIndexChanged += gcnew System::EventHandler(this, &MainWindow::change_required_gender);
		// 
		// label58
		// 
		this->label58->AutoSize = true;
		this->label58->Location = System::Drawing::Point(2, 548);
		this->label58->Name = L"label58";
		this->label58->Size = System::Drawing::Size(45, 13);
		this->label58->TabIndex = 183;
		this->label58->Text = L"Gender:";
		// 
		// checkBox_unknown_39
		// 
		this->checkBox_unknown_39->AutoSize = true;
		this->checkBox_unknown_39->Location = System::Drawing::Point(149, 517);
		this->checkBox_unknown_39->Name = L"checkBox_unknown_39";
		this->checkBox_unknown_39->Size = System::Drawing::Size(15, 14);
		this->checkBox_unknown_39->TabIndex = 181;
		this->checkBox_unknown_39->UseVisualStyleBackColor = true;
		this->checkBox_unknown_39->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_unknown_39);
		// 
		// label138
		// 
		this->label138->AutoSize = true;
		this->label138->Location = System::Drawing::Point(5, 520);
		this->label138->Name = L"label138";
		this->label138->Size = System::Drawing::Size(71, 13);
		this->label138->TabIndex = 180;
		this->label138->Text = L"Unknown 39:";
		// 
		// textBox_unknown_38
		// 
		this->textBox_unknown_38->Location = System::Drawing::Point(589, 465);
		this->textBox_unknown_38->Name = L"textBox_unknown_38";
		this->textBox_unknown_38->Size = System::Drawing::Size(60, 20);
		this->textBox_unknown_38->TabIndex = 179;
		this->textBox_unknown_38->Leave += gcnew System::EventHandler(this, &MainWindow::change_unknown_38);
		// 
		// label137
		// 
		this->label137->AutoSize = true;
		this->label137->ForeColor = System::Drawing::Color::Gray;
		this->label137->Location = System::Drawing::Point(512, 468);
		this->label137->Name = L"label137";
		this->label137->Size = System::Drawing::Size(71, 13);
		this->label137->TabIndex = 178;
		this->label137->Text = L"Unknown 38:";
		// 
		// textBox_unknown_37
		// 
		this->textBox_unknown_37->Location = System::Drawing::Point(390, 465);
		this->textBox_unknown_37->Name = L"textBox_unknown_37";
		this->textBox_unknown_37->Size = System::Drawing::Size(116, 20);
		this->textBox_unknown_37->TabIndex = 177;
		this->textBox_unknown_37->Leave += gcnew System::EventHandler(this, &MainWindow::change_unknown_37);
		// 
		// label136
		// 
		this->label136->AutoSize = true;
		this->label136->Location = System::Drawing::Point(313, 468);
		this->label136->Name = L"label136";
		this->label136->Size = System::Drawing::Size(71, 13);
		this->label136->TabIndex = 176;
		this->label136->Text = L"Unknown 37:";
		// 
		// textBox_unknown_36
		// 
		this->textBox_unknown_36->Location = System::Drawing::Point(247, 465);
		this->textBox_unknown_36->Name = L"textBox_unknown_36";
		this->textBox_unknown_36->Size = System::Drawing::Size(60, 20);
		this->textBox_unknown_36->TabIndex = 175;
		this->textBox_unknown_36->Leave += gcnew System::EventHandler(this, &MainWindow::change_unknown_36);
		// 
		// label135
		// 
		this->label135->AutoSize = true;
		this->label135->ForeColor = System::Drawing::Color::Gray;
		this->label135->Location = System::Drawing::Point(170, 468);
		this->label135->Name = L"label135";
		this->label135->Size = System::Drawing::Size(71, 13);
		this->label135->TabIndex = 174;
		this->label135->Text = L"Unknown 36:";
		// 
		// checkBox_unknown_35
		// 
		this->checkBox_unknown_35->AutoSize = true;
		this->checkBox_unknown_35->Location = System::Drawing::Point(149, 468);
		this->checkBox_unknown_35->Name = L"checkBox_unknown_35";
		this->checkBox_unknown_35->Size = System::Drawing::Size(15, 14);
		this->checkBox_unknown_35->TabIndex = 173;
		this->checkBox_unknown_35->UseVisualStyleBackColor = true;
		this->checkBox_unknown_35->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_unknown_35);
		// 
		// label133
		// 
		this->label133->AutoSize = true;
		this->label133->Location = System::Drawing::Point(6, 468);
		this->label133->Name = L"label133";
		this->label133->Size = System::Drawing::Size(71, 13);
		this->label133->TabIndex = 172;
		this->label133->Text = L"Unknown 35:";
		// 
		// textBox_unknown_34
		// 
		this->textBox_unknown_34->Location = System::Drawing::Point(149, 439);
		this->textBox_unknown_34->Name = L"textBox_unknown_34";
		this->textBox_unknown_34->Size = System::Drawing::Size(500, 20);
		this->textBox_unknown_34->TabIndex = 171;
		this->textBox_unknown_34->Leave += gcnew System::EventHandler(this, &MainWindow::change_unknown_34);
		// 
		// label134
		// 
		this->label134->AutoSize = true;
		this->label134->ForeColor = System::Drawing::Color::Gray;
		this->label134->Location = System::Drawing::Point(6, 442);
		this->label134->Name = L"label134";
		this->label134->Size = System::Drawing::Size(71, 13);
		this->label134->TabIndex = 170;
		this->label134->Text = L"Unknown 34:";
		// 
		// textBox_required_quests_done_1
		// 
		this->textBox_required_quests_done_1->Location = System::Drawing::Point(260, 284);
		this->textBox_required_quests_done_1->Name = L"textBox_required_quests_done_1";
		this->textBox_required_quests_done_1->Size = System::Drawing::Size(81, 20);
		this->textBox_required_quests_done_1->TabIndex = 165;
		this->textBox_required_quests_done_1->Leave += gcnew System::EventHandler(this, &MainWindow::change_required_quests_done);
		// 
		// textBox_required_quests_done_2
		// 
		this->textBox_required_quests_done_2->Location = System::Drawing::Point(260, 310);
		this->textBox_required_quests_done_2->Name = L"textBox_required_quests_done_2";
		this->textBox_required_quests_done_2->Size = System::Drawing::Size(81, 20);
		this->textBox_required_quests_done_2->TabIndex = 166;
		this->textBox_required_quests_done_2->Leave += gcnew System::EventHandler(this, &MainWindow::change_required_quests_done);
		// 
		// textBox_required_quests_done_3
		// 
		this->textBox_required_quests_done_3->Location = System::Drawing::Point(260, 336);
		this->textBox_required_quests_done_3->Name = L"textBox_required_quests_done_3";
		this->textBox_required_quests_done_3->Size = System::Drawing::Size(81, 20);
		this->textBox_required_quests_done_3->TabIndex = 167;
		this->textBox_required_quests_done_3->Leave += gcnew System::EventHandler(this, &MainWindow::change_required_quests_done);
		// 
		// textBox_required_quests_done_4
		// 
		this->textBox_required_quests_done_4->Location = System::Drawing::Point(260, 362);
		this->textBox_required_quests_done_4->Name = L"textBox_required_quests_done_4";
		this->textBox_required_quests_done_4->Size = System::Drawing::Size(81, 20);
		this->textBox_required_quests_done_4->TabIndex = 168;
		this->textBox_required_quests_done_4->Leave += gcnew System::EventHandler(this, &MainWindow::change_required_quests_done);
		// 
		// textBox_required_quests_done_5
		// 
		this->textBox_required_quests_done_5->Location = System::Drawing::Point(260, 388);
		this->textBox_required_quests_done_5->Name = L"textBox_required_quests_done_5";
		this->textBox_required_quests_done_5->Size = System::Drawing::Size(81, 20);
		this->textBox_required_quests_done_5->TabIndex = 169;
		this->textBox_required_quests_done_5->Leave += gcnew System::EventHandler(this, &MainWindow::change_required_quests_done);
		// 
		// checkBox_unknown_33
		// 
		this->checkBox_unknown_33->AutoSize = true;
		this->checkBox_unknown_33->Location = System::Drawing::Point(149, 417);
		this->checkBox_unknown_33->Name = L"checkBox_unknown_33";
		this->checkBox_unknown_33->Size = System::Drawing::Size(15, 14);
		this->checkBox_unknown_33->TabIndex = 163;
		this->checkBox_unknown_33->UseVisualStyleBackColor = true;
		this->checkBox_unknown_33->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_unknown_33);
		// 
		// label132
		// 
		this->label132->AutoSize = true;
		this->label132->Location = System::Drawing::Point(6, 417);
		this->label132->Name = L"label132";
		this->label132->Size = System::Drawing::Size(71, 13);
		this->label132->TabIndex = 162;
		this->label132->Text = L"Unknown 33:";
		// 
		// textBox_unknown_32
		// 
		this->textBox_unknown_32->Location = System::Drawing::Point(149, 388);
		this->textBox_unknown_32->Name = L"textBox_unknown_32";
		this->textBox_unknown_32->Size = System::Drawing::Size(81, 20);
		this->textBox_unknown_32->TabIndex = 161;
		this->textBox_unknown_32->Leave += gcnew System::EventHandler(this, &MainWindow::change_unknown_32);
		// 
		// label131
		// 
		this->label131->AutoSize = true;
		this->label131->Location = System::Drawing::Point(6, 391);
		this->label131->Name = L"label131";
		this->label131->Size = System::Drawing::Size(71, 13);
		this->label131->TabIndex = 160;
		this->label131->Text = L"Unknown 32:";
		// 
		// textBox_required_reputation
		// 
		this->textBox_required_reputation->Location = System::Drawing::Point(149, 362);
		this->textBox_required_reputation->Name = L"textBox_required_reputation";
		this->textBox_required_reputation->Size = System::Drawing::Size(81, 20);
		this->textBox_required_reputation->TabIndex = 159;
		this->textBox_required_reputation->Leave += gcnew System::EventHandler(this, &MainWindow::change_required_reputation);
		// 
		// label38
		// 
		this->label38->AutoSize = true;
		this->label38->Location = System::Drawing::Point(6, 365);
		this->label38->Name = L"label38";
		this->label38->Size = System::Drawing::Size(62, 13);
		this->label38->TabIndex = 158;
		this->label38->Text = L"Reputation:";
		// 
		// checkBox_unknown_31
		// 
		this->checkBox_unknown_31->AutoSize = true;
		this->checkBox_unknown_31->Location = System::Drawing::Point(149, 339);
		this->checkBox_unknown_31->Name = L"checkBox_unknown_31";
		this->checkBox_unknown_31->Size = System::Drawing::Size(15, 14);
		this->checkBox_unknown_31->TabIndex = 157;
		this->checkBox_unknown_31->UseVisualStyleBackColor = true;
		this->checkBox_unknown_31->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_unknown_31);
		// 
		// label130
		// 
		this->label130->AutoSize = true;
		this->label130->Location = System::Drawing::Point(6, 339);
		this->label130->Name = L"label130";
		this->label130->Size = System::Drawing::Size(71, 13);
		this->label130->TabIndex = 156;
		this->label130->Text = L"Unknown 31:";
		// 
		// textBox_given_items_unknown
		// 
		this->textBox_given_items_unknown->Location = System::Drawing::Point(149, 232);
		this->textBox_given_items_unknown->Name = L"textBox_given_items_unknown";
		this->textBox_given_items_unknown->Size = System::Drawing::Size(300, 20);
		this->textBox_given_items_unknown->TabIndex = 155;
		this->textBox_given_items_unknown->Leave += gcnew System::EventHandler(this, &MainWindow::change_given_items_unknown);
		// 
		// label129
		// 
		this->label129->AutoSize = true;
		this->label129->Location = System::Drawing::Point(6, 235);
		this->label129->Name = L"label129";
		this->label129->Size = System::Drawing::Size(115, 13);
		this->label129->TabIndex = 154;
		this->label129->Text = L"Given Items Unknown:";
		// 
		// textBox_unknown_30
		// 
		this->textBox_unknown_30->Location = System::Drawing::Point(149, 284);
		this->textBox_unknown_30->Name = L"textBox_unknown_30";
		this->textBox_unknown_30->Size = System::Drawing::Size(81, 20);
		this->textBox_unknown_30->TabIndex = 153;
		this->textBox_unknown_30->Leave += gcnew System::EventHandler(this, &MainWindow::change_unknown_30);
		// 
		// label73
		// 
		this->label73->AutoSize = true;
		this->label73->Location = System::Drawing::Point(6, 287);
		this->label73->Name = L"label73";
		this->label73->Size = System::Drawing::Size(71, 13);
		this->label73->TabIndex = 152;
		this->label73->Text = L"Unknown 30:";
		// 
		// textBox_unknown_29
		// 
		this->textBox_unknown_29->Location = System::Drawing::Point(149, 258);
		this->textBox_unknown_29->Name = L"textBox_unknown_29";
		this->textBox_unknown_29->Size = System::Drawing::Size(81, 20);
		this->textBox_unknown_29->TabIndex = 151;
		this->textBox_unknown_29->Leave += gcnew System::EventHandler(this, &MainWindow::change_unknown_29);
		// 
		// label72
		// 
		this->label72->AutoSize = true;
		this->label72->Location = System::Drawing::Point(6, 261);
		this->label72->Name = L"label72";
		this->label72->Size = System::Drawing::Size(71, 13);
		this->label72->TabIndex = 150;
		this->label72->Text = L"Unknown 29:";
		// 
		// checkBox_unknown_28_01
		// 
		this->checkBox_unknown_28_01->AutoSize = true;
		this->checkBox_unknown_28_01->Location = System::Drawing::Point(265, 136);
		this->checkBox_unknown_28_01->Name = L"checkBox_unknown_28_01";
		this->checkBox_unknown_28_01->Size = System::Drawing::Size(15, 14);
		this->checkBox_unknown_28_01->TabIndex = 149;
		this->checkBox_unknown_28_01->UseVisualStyleBackColor = true;
		this->checkBox_unknown_28_01->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_unknown_28_01);
		// 
		// label71
		// 
		this->label71->AutoSize = true;
		this->label71->ForeColor = System::Drawing::Color::Red;
		this->label71->Location = System::Drawing::Point(170, 136);
		this->label71->Name = L"label71";
		this->label71->Size = System::Drawing::Size(89, 13);
		this->label71->TabIndex = 148;
		this->label71->Text = L"Unknown 28_01:";
		// 
		// textBox_required_items_unknown
		// 
		this->textBox_required_items_unknown->Location = System::Drawing::Point(149, 110);
		this->textBox_required_items_unknown->Name = L"textBox_required_items_unknown";
		this->textBox_required_items_unknown->Size = System::Drawing::Size(300, 20);
		this->textBox_required_items_unknown->TabIndex = 147;
		this->textBox_required_items_unknown->Leave += gcnew System::EventHandler(this, &MainWindow::change_required_items_unknown);
		// 
		// label70
		// 
		this->label70->AutoSize = true;
		this->label70->Location = System::Drawing::Point(6, 113);
		this->label70->Name = L"label70";
		this->label70->Size = System::Drawing::Size(130, 13);
		this->label70->TabIndex = 146;
		this->label70->Text = L"Required Items Unknown:";
		// 
		// checkBox_unknown_28
		// 
		this->checkBox_unknown_28->AutoSize = true;
		this->checkBox_unknown_28->Location = System::Drawing::Point(149, 136);
		this->checkBox_unknown_28->Name = L"checkBox_unknown_28";
		this->checkBox_unknown_28->Size = System::Drawing::Size(15, 14);
		this->checkBox_unknown_28->TabIndex = 145;
		this->checkBox_unknown_28->UseVisualStyleBackColor = true;
		this->checkBox_unknown_28->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_unknown_28);
		// 
		// checkBox_unknown_27
		// 
		this->checkBox_unknown_27->AutoSize = true;
		this->checkBox_unknown_27->Location = System::Drawing::Point(149, 19);
		this->checkBox_unknown_27->Name = L"checkBox_unknown_27";
		this->checkBox_unknown_27->Size = System::Drawing::Size(15, 14);
		this->checkBox_unknown_27->TabIndex = 144;
		this->checkBox_unknown_27->UseVisualStyleBackColor = true;
		this->checkBox_unknown_27->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_unknown_27);
		// 
		// label64
		// 
		this->label64->AutoSize = true;
		this->label64->Location = System::Drawing::Point(6, 136);
		this->label64->Name = L"label64";
		this->label64->Size = System::Drawing::Size(71, 13);
		this->label64->TabIndex = 70;
		this->label64->Text = L"Unknown 28:";
		// 
		// label62
		// 
		this->label62->AutoSize = true;
		this->label62->Location = System::Drawing::Point(6, 19);
		this->label62->Name = L"label62";
		this->label62->Size = System::Drawing::Size(71, 13);
		this->label62->TabIndex = 69;
		this->label62->Text = L"Unknown 27:";
		// 
		// textBox_instant_pay_coins
		// 
		this->textBox_instant_pay_coins->Location = System::Drawing::Point(149, 310);
		this->textBox_instant_pay_coins->Name = L"textBox_instant_pay_coins";
		this->textBox_instant_pay_coins->Size = System::Drawing::Size(81, 20);
		this->textBox_instant_pay_coins->TabIndex = 68;
		this->textBox_instant_pay_coins->Leave += gcnew System::EventHandler(this, &MainWindow::change_instant_pay_coins);
		// 
		// label65
		// 
		this->label65->AutoSize = true;
		this->label65->Location = System::Drawing::Point(6, 313);
		this->label65->Name = L"label65";
		this->label65->Size = System::Drawing::Size(92, 13);
		this->label65->TabIndex = 67;
		this->label65->Text = L"Instant Pay Coins:";
		// 
		// groupBox_general
		// 
		this->groupBox_general->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->groupBox_general->Controls->Add(this->textBox_unknown_09);
		this->groupBox_general->Controls->Add(this->label90);
		this->groupBox_general->Controls->Add(this->textBox_unknown_08);
		this->groupBox_general->Controls->Add(this->label89);
		this->groupBox_general->Controls->Add(this->dataGridView_date_fail);
		this->groupBox_general->Controls->Add(this->label88);
		this->groupBox_general->Controls->Add(this->label87);
		this->groupBox_general->Controls->Add(this->label86);
		this->groupBox_general->Controls->Add(this->label83);
		this->groupBox_general->Controls->Add(this->label82);
		this->groupBox_general->Controls->Add(this->checkBox_unknown_03);
		this->groupBox_general->Controls->Add(this->checkBox_unknown_02);
		this->groupBox_general->Controls->Add(this->textBox_unknown_06);
		this->groupBox_general->Controls->Add(this->label85);
		this->groupBox_general->Controls->Add(this->textBox_unknown_07);
		this->groupBox_general->Controls->Add(this->textBox_unknown_05);
		this->groupBox_general->Controls->Add(this->label76);
		this->groupBox_general->Controls->Add(this->label84);
		this->groupBox_general->Controls->Add(this->textBox_unknown_04);
		this->groupBox_general->Controls->Add(this->label31);
		this->groupBox_general->Controls->Add(this->checkBox_has_date_spans);
		this->groupBox_general->Controls->Add(this->dataGridView_date_spans);
		this->groupBox_general->Controls->Add(this->checkBox_has_date_fail);
		this->groupBox_general->Controls->Add(this->textBox_unknown_01);
		this->groupBox_general->Controls->Add(this->label81);
		this->groupBox_general->Controls->Add(this->label28);
		this->groupBox_general->Controls->Add(this->textBox_id);
		this->groupBox_general->Controls->Add(this->label55);
		this->groupBox_general->Controls->Add(this->comboBox_type);
		this->groupBox_general->Controls->Add(this->label29);
		this->groupBox_general->Controls->Add(this->textBox_name);
		this->groupBox_general->Controls->Add(this->textBox_author_text);
		this->groupBox_general->Controls->Add(this->checkBox_author_mode);
		this->groupBox_general->Controls->Add(this->label32);
		this->groupBox_general->Controls->Add(this->textBox_time_limit);
		this->groupBox_general->Location = System::Drawing::Point(3, 3);
		this->groupBox_general->Name = L"groupBox_general";
		this->groupBox_general->Size = System::Drawing::Size(671, 338);
		this->groupBox_general->TabIndex = 0;
		this->groupBox_general->TabStop = false;
		this->groupBox_general->Text = L"GENERAL";
		// 
		// textBox_unknown_09
		// 
		this->textBox_unknown_09->Location = System::Drawing::Point(446, 312);
		this->textBox_unknown_09->Name = L"textBox_unknown_09";
		this->textBox_unknown_09->Size = System::Drawing::Size(219, 20);
		this->textBox_unknown_09->TabIndex = 70;
		this->textBox_unknown_09->Leave += gcnew System::EventHandler(this, &MainWindow::change_unknown_09);
		// 
		// label90
		// 
		this->label90->AutoSize = true;
		this->label90->ForeColor = System::Drawing::Color::Gray;
		this->label90->Location = System::Drawing::Point(358, 315);
		this->label90->Name = L"label90";
		this->label90->Size = System::Drawing::Size(71, 13);
		this->label90->TabIndex = 69;
		this->label90->Text = L"Unknown 09:";
		// 
		// textBox_unknown_08
		// 
		this->textBox_unknown_08->Location = System::Drawing::Point(446, 286);
		this->textBox_unknown_08->Name = L"textBox_unknown_08";
		this->textBox_unknown_08->Size = System::Drawing::Size(219, 20);
		this->textBox_unknown_08->TabIndex = 68;
		this->textBox_unknown_08->Leave += gcnew System::EventHandler(this, &MainWindow::change_unknown_08);
		// 
		// label89
		// 
		this->label89->AutoSize = true;
		this->label89->Location = System::Drawing::Point(358, 289);
		this->label89->Name = L"label89";
		this->label89->Size = System::Drawing::Size(71, 13);
		this->label89->TabIndex = 67;
		this->label89->Text = L"Unknown 08:";
		// 
		// dataGridView_date_fail
		// 
		this->dataGridView_date_fail->AllowUserToAddRows = false;
		this->dataGridView_date_fail->AllowUserToDeleteRows = false;
		this->dataGridView_date_fail->BackgroundColor = System::Drawing::SystemColors::Control;
		this->dataGridView_date_fail->BorderStyle = System::Windows::Forms::BorderStyle::None;
		this->dataGridView_date_fail->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
		this->dataGridView_date_fail->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
		this->dataGridView_date_fail->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {this->dataGridViewTextBoxColumn32, 
			this->dataGridViewTextBoxColumn33, this->dataGridViewTextBoxColumn34, this->dataGridViewTextBoxColumn35, this->dataGridViewTextBoxColumn36, 
			this->Column_date_fail_weekday});
		this->dataGridView_date_fail->Location = System::Drawing::Point(116, 123);
		this->dataGridView_date_fail->MultiSelect = false;
		this->dataGridView_date_fail->Name = L"dataGridView_date_fail";
		this->dataGridView_date_fail->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
		dataGridViewCellStyle118->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
		dataGridViewCellStyle118->BackColor = System::Drawing::SystemColors::Control;
		dataGridViewCellStyle118->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		dataGridViewCellStyle118->ForeColor = System::Drawing::SystemColors::WindowText;
		dataGridViewCellStyle118->SelectionBackColor = System::Drawing::SystemColors::Highlight;
		dataGridViewCellStyle118->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
		dataGridViewCellStyle118->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView_date_fail->RowHeadersDefaultCellStyle = dataGridViewCellStyle118;
		this->dataGridView_date_fail->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::AutoSizeToFirstHeader;
		this->dataGridView_date_fail->RowTemplate->Height = 18;
		this->dataGridView_date_fail->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView_date_fail->Size = System::Drawing::Size(238, 43);
		this->dataGridView_date_fail->TabIndex = 66;
		this->dataGridView_date_fail->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::change_date_fail);
		// 
		// dataGridViewTextBoxColumn32
		// 
		this->dataGridViewTextBoxColumn32->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
		dataGridViewCellStyle112->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn32->DefaultCellStyle = dataGridViewCellStyle112;
		this->dataGridViewTextBoxColumn32->HeaderText = L"Y";
		this->dataGridViewTextBoxColumn32->Name = L"dataGridViewTextBoxColumn32";
		this->dataGridViewTextBoxColumn32->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		// 
		// dataGridViewTextBoxColumn33
		// 
		dataGridViewCellStyle113->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn33->DefaultCellStyle = dataGridViewCellStyle113;
		this->dataGridViewTextBoxColumn33->HeaderText = L"M";
		this->dataGridViewTextBoxColumn33->Name = L"dataGridViewTextBoxColumn33";
		this->dataGridViewTextBoxColumn33->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn33->Width = 21;
		// 
		// dataGridViewTextBoxColumn34
		// 
		dataGridViewCellStyle114->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn34->DefaultCellStyle = dataGridViewCellStyle114;
		this->dataGridViewTextBoxColumn34->HeaderText = L"D";
		this->dataGridViewTextBoxColumn34->Name = L"dataGridViewTextBoxColumn34";
		this->dataGridViewTextBoxColumn34->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn34->Width = 20;
		// 
		// dataGridViewTextBoxColumn35
		// 
		dataGridViewCellStyle115->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn35->DefaultCellStyle = dataGridViewCellStyle115;
		this->dataGridViewTextBoxColumn35->HeaderText = L"H";
		this->dataGridViewTextBoxColumn35->Name = L"dataGridViewTextBoxColumn35";
		this->dataGridViewTextBoxColumn35->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn35->Width = 20;
		// 
		// dataGridViewTextBoxColumn36
		// 
		dataGridViewCellStyle116->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn36->DefaultCellStyle = dataGridViewCellStyle116;
		this->dataGridViewTextBoxColumn36->HeaderText = L"M";
		this->dataGridViewTextBoxColumn36->Name = L"dataGridViewTextBoxColumn36";
		this->dataGridViewTextBoxColumn36->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn36->Width = 21;
		// 
		// Column_date_fail_weekday
		// 
		this->Column_date_fail_weekday->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle117->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->Column_date_fail_weekday->DefaultCellStyle = dataGridViewCellStyle117;
		this->Column_date_fail_weekday->HeaderText = L"d";
		this->Column_date_fail_weekday->Items->AddRange(gcnew cli::array< System::Object^  >(8) {L"ALL", L"Mon", L"Tue", L"Wed", 
			L"Thu", L"Fri", L"Sat", L"Sun"});
		this->Column_date_fail_weekday->Name = L"Column_date_fail_weekday";
		this->Column_date_fail_weekday->Resizable = System::Windows::Forms::DataGridViewTriState::True;
		this->Column_date_fail_weekday->Width = 18;
		// 
		// label88
		// 
		this->label88->AutoSize = true;
		this->label88->Location = System::Drawing::Point(6, 172);
		this->label88->Name = L"label88";
		this->label88->Size = System::Drawing::Size(59, 13);
		this->label88->TabIndex = 65;
		this->label88->Text = L"Date Valid:";
		// 
		// label87
		// 
		this->label87->AutoSize = true;
		this->label87->ForeColor = System::Drawing::Color::Gray;
		this->label87->Location = System::Drawing::Point(314, 100);
		this->label87->Name = L"label87";
		this->label87->Size = System::Drawing::Size(71, 13);
		this->label87->TabIndex = 64;
		this->label87->Text = L"Unknown 03:";
		// 
		// label86
		// 
		this->label86->AutoSize = true;
		this->label86->ForeColor = System::Drawing::Color::Gray;
		this->label86->Location = System::Drawing::Point(6, 123);
		this->label86->Name = L"label86";
		this->label86->Size = System::Drawing::Size(52, 13);
		this->label86->TabIndex = 63;
		this->label86->Text = L"Date Fail:";
		// 
		// label83
		// 
		this->label83->AutoSize = true;
		this->label83->ForeColor = System::Drawing::Color::Gray;
		this->label83->Location = System::Drawing::Point(216, 100);
		this->label83->Name = L"label83";
		this->label83->Size = System::Drawing::Size(71, 13);
		this->label83->TabIndex = 62;
		this->label83->Text = L"Unknown 02:";
		// 
		// label82
		// 
		this->label82->AutoSize = true;
		this->label82->Location = System::Drawing::Point(6, 74);
		this->label82->Name = L"label82";
		this->label82->Size = System::Drawing::Size(65, 13);
		this->label82->TabIndex = 61;
		this->label82->Text = L"Author Text:";
		// 
		// checkBox_unknown_03
		// 
		this->checkBox_unknown_03->AutoSize = true;
		this->checkBox_unknown_03->ForeColor = System::Drawing::Color::Gray;
		this->checkBox_unknown_03->Location = System::Drawing::Point(391, 100);
		this->checkBox_unknown_03->Name = L"checkBox_unknown_03";
		this->checkBox_unknown_03->Size = System::Drawing::Size(15, 14);
		this->checkBox_unknown_03->TabIndex = 60;
		this->checkBox_unknown_03->UseVisualStyleBackColor = true;
		this->checkBox_unknown_03->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_unknown_03);
		// 
		// checkBox_unknown_02
		// 
		this->checkBox_unknown_02->AutoSize = true;
		this->checkBox_unknown_02->ForeColor = System::Drawing::Color::Gray;
		this->checkBox_unknown_02->Location = System::Drawing::Point(293, 100);
		this->checkBox_unknown_02->Name = L"checkBox_unknown_02";
		this->checkBox_unknown_02->Size = System::Drawing::Size(15, 14);
		this->checkBox_unknown_02->TabIndex = 59;
		this->checkBox_unknown_02->UseVisualStyleBackColor = true;
		this->checkBox_unknown_02->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_unknown_02);
		// 
		// textBox_unknown_06
		// 
		this->textBox_unknown_06->Location = System::Drawing::Point(95, 312);
		this->textBox_unknown_06->Name = L"textBox_unknown_06";
		this->textBox_unknown_06->Size = System::Drawing::Size(219, 20);
		this->textBox_unknown_06->TabIndex = 58;
		this->textBox_unknown_06->Leave += gcnew System::EventHandler(this, &MainWindow::change_unknown_06);
		// 
		// label85
		// 
		this->label85->AutoSize = true;
		this->label85->ForeColor = System::Drawing::Color::Gray;
		this->label85->Location = System::Drawing::Point(6, 315);
		this->label85->Name = L"label85";
		this->label85->Size = System::Drawing::Size(71, 13);
		this->label85->TabIndex = 57;
		this->label85->Text = L"Unknown 06:";
		// 
		// textBox_unknown_05
		// 
		this->textBox_unknown_05->Location = System::Drawing::Point(95, 286);
		this->textBox_unknown_05->Name = L"textBox_unknown_05";
		this->textBox_unknown_05->Size = System::Drawing::Size(219, 20);
		this->textBox_unknown_05->TabIndex = 56;
		this->textBox_unknown_05->Leave += gcnew System::EventHandler(this, &MainWindow::change_unknown_05);
		// 
		// label84
		// 
		this->label84->AutoSize = true;
		this->label84->Location = System::Drawing::Point(6, 289);
		this->label84->Name = L"label84";
		this->label84->Size = System::Drawing::Size(71, 13);
		this->label84->TabIndex = 55;
		this->label84->Text = L"Unknown 05:";
		// 
		// textBox_unknown_04
		// 
		this->textBox_unknown_04->Location = System::Drawing::Point(95, 260);
		this->textBox_unknown_04->Name = L"textBox_unknown_04";
		this->textBox_unknown_04->Size = System::Drawing::Size(219, 20);
		this->textBox_unknown_04->TabIndex = 54;
		this->textBox_unknown_04->Leave += gcnew System::EventHandler(this, &MainWindow::change_unknown_04);
		// 
		// label31
		// 
		this->label31->AutoSize = true;
		this->label31->Location = System::Drawing::Point(6, 263);
		this->label31->Name = L"label31";
		this->label31->Size = System::Drawing::Size(71, 13);
		this->label31->TabIndex = 53;
		this->label31->Text = L"Unknown 04:";
		// 
		// checkBox_has_date_spans
		// 
		this->checkBox_has_date_spans->AutoSize = true;
		this->checkBox_has_date_spans->Location = System::Drawing::Point(95, 172);
		this->checkBox_has_date_spans->Name = L"checkBox_has_date_spans";
		this->checkBox_has_date_spans->Size = System::Drawing::Size(15, 14);
		this->checkBox_has_date_spans->TabIndex = 48;
		this->checkBox_has_date_spans->UseVisualStyleBackColor = true;
		this->checkBox_has_date_spans->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_has_date_spans);
		// 
		// checkBox_has_date_fail
		// 
		this->checkBox_has_date_fail->AutoSize = true;
		this->checkBox_has_date_fail->ForeColor = System::Drawing::Color::Gray;
		this->checkBox_has_date_fail->Location = System::Drawing::Point(95, 123);
		this->checkBox_has_date_fail->Name = L"checkBox_has_date_fail";
		this->checkBox_has_date_fail->Size = System::Drawing::Size(15, 14);
		this->checkBox_has_date_fail->TabIndex = 47;
		this->checkBox_has_date_fail->UseVisualStyleBackColor = true;
		this->checkBox_has_date_fail->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_has_date_fail);
		// 
		// textBox_unknown_01
		// 
		this->textBox_unknown_01->Location = System::Drawing::Point(95, 97);
		this->textBox_unknown_01->Name = L"textBox_unknown_01";
		this->textBox_unknown_01->Size = System::Drawing::Size(115, 20);
		this->textBox_unknown_01->TabIndex = 41;
		this->textBox_unknown_01->Leave += gcnew System::EventHandler(this, &MainWindow::change_unknown_01);
		// 
		// label81
		// 
		this->label81->AutoSize = true;
		this->label81->Location = System::Drawing::Point(6, 100);
		this->label81->Name = L"label81";
		this->label81->Size = System::Drawing::Size(71, 13);
		this->label81->TabIndex = 40;
		this->label81->Text = L"Unknown 01:";
		// 
		// groupBox_reach_location
		// 
		this->groupBox_reach_location->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->groupBox_reach_location->Controls->Add(this->checkBox_reach_locations_has_spans);
		this->groupBox_reach_location->Controls->Add(this->label4);
		this->groupBox_reach_location->Controls->Add(this->textBox_reach_locations_unknown_1);
		this->groupBox_reach_location->Controls->Add(this->dataGridView_reach_location_spans);
		this->groupBox_reach_location->Controls->Add(this->textBox_reach_locations_map_id);
		this->groupBox_reach_location->Controls->Add(this->label5);
		this->groupBox_reach_location->Controls->Add(this->label6);
		this->groupBox_reach_location->Location = System::Drawing::Point(3, 294);
		this->groupBox_reach_location->Name = L"groupBox_reach_location";
		this->groupBox_reach_location->Size = System::Drawing::Size(671, 91);
		this->groupBox_reach_location->TabIndex = 98;
		this->groupBox_reach_location->TabStop = false;
		this->groupBox_reach_location->Text = L"SUCCESS ON ENTER";
		// 
		// checkBox_reach_locations_has_spans
		// 
		this->checkBox_reach_locations_has_spans->AutoSize = true;
		this->checkBox_reach_locations_has_spans->Location = System::Drawing::Point(77, 19);
		this->checkBox_reach_locations_has_spans->Name = L"checkBox_reach_locations_has_spans";
		this->checkBox_reach_locations_has_spans->Size = System::Drawing::Size(15, 14);
		this->checkBox_reach_locations_has_spans->TabIndex = 96;
		this->checkBox_reach_locations_has_spans->UseVisualStyleBackColor = true;
		this->checkBox_reach_locations_has_spans->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_reach_locations_has_spans);
		// 
		// textBox_reach_locations_unknown_1
		// 
		this->textBox_reach_locations_unknown_1->Location = System::Drawing::Point(77, 65);
		this->textBox_reach_locations_unknown_1->Name = L"textBox_reach_locations_unknown_1";
		this->textBox_reach_locations_unknown_1->Size = System::Drawing::Size(122, 20);
		this->textBox_reach_locations_unknown_1->TabIndex = 94;
		this->textBox_reach_locations_unknown_1->Leave += gcnew System::EventHandler(this, &MainWindow::change_reach_locations_unknown_1);
		// 
		// dataGridView_reach_location_spans
		// 
		this->dataGridView_reach_location_spans->AllowUserToAddRows = false;
		this->dataGridView_reach_location_spans->AllowUserToDeleteRows = false;
		this->dataGridView_reach_location_spans->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
			| System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->dataGridView_reach_location_spans->BackgroundColor = System::Drawing::SystemColors::Window;
		this->dataGridView_reach_location_spans->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
		this->dataGridView_reach_location_spans->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
		this->dataGridView_reach_location_spans->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {this->dataGridViewTextBoxColumn60, 
			this->dataGridViewTextBoxColumn61, this->dataGridViewTextBoxColumn62, this->dataGridViewTextBoxColumn63, this->dataGridViewTextBoxColumn64, 
			this->dataGridViewTextBoxColumn65});
		this->dataGridView_reach_location_spans->ContextMenuStrip = this->contextMenuStrip_reach_location;
		this->dataGridView_reach_location_spans->Location = System::Drawing::Point(205, 10);
		this->dataGridView_reach_location_spans->MultiSelect = false;
		this->dataGridView_reach_location_spans->Name = L"dataGridView_reach_location_spans";
		this->dataGridView_reach_location_spans->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
		dataGridViewCellStyle125->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
		dataGridViewCellStyle125->BackColor = System::Drawing::SystemColors::Control;
		dataGridViewCellStyle125->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		dataGridViewCellStyle125->ForeColor = System::Drawing::SystemColors::WindowText;
		dataGridViewCellStyle125->SelectionBackColor = System::Drawing::SystemColors::Highlight;
		dataGridViewCellStyle125->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
		dataGridViewCellStyle125->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView_reach_location_spans->RowHeadersDefaultCellStyle = dataGridViewCellStyle125;
		this->dataGridView_reach_location_spans->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::AutoSizeToFirstHeader;
		this->dataGridView_reach_location_spans->RowTemplate->Height = 18;
		this->dataGridView_reach_location_spans->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView_reach_location_spans->Size = System::Drawing::Size(460, 75);
		this->dataGridView_reach_location_spans->TabIndex = 91;
		this->dataGridView_reach_location_spans->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::change_reach_locations_span);
		// 
		// dataGridViewTextBoxColumn60
		// 
		this->dataGridViewTextBoxColumn60->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
		dataGridViewCellStyle119->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn60->DefaultCellStyle = dataGridViewCellStyle119;
		this->dataGridViewTextBoxColumn60->HeaderText = L"North";
		this->dataGridViewTextBoxColumn60->Name = L"dataGridViewTextBoxColumn60";
		this->dataGridViewTextBoxColumn60->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		// 
		// dataGridViewTextBoxColumn61
		// 
		this->dataGridViewTextBoxColumn61->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
		dataGridViewCellStyle120->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn61->DefaultCellStyle = dataGridViewCellStyle120;
		this->dataGridViewTextBoxColumn61->HeaderText = L"South";
		this->dataGridViewTextBoxColumn61->Name = L"dataGridViewTextBoxColumn61";
		this->dataGridViewTextBoxColumn61->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		// 
		// dataGridViewTextBoxColumn62
		// 
		this->dataGridViewTextBoxColumn62->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
		dataGridViewCellStyle121->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn62->DefaultCellStyle = dataGridViewCellStyle121;
		this->dataGridViewTextBoxColumn62->HeaderText = L"Weast";
		this->dataGridViewTextBoxColumn62->Name = L"dataGridViewTextBoxColumn62";
		this->dataGridViewTextBoxColumn62->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		// 
		// dataGridViewTextBoxColumn63
		// 
		this->dataGridViewTextBoxColumn63->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
		dataGridViewCellStyle122->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn63->DefaultCellStyle = dataGridViewCellStyle122;
		this->dataGridViewTextBoxColumn63->HeaderText = L"East";
		this->dataGridViewTextBoxColumn63->Name = L"dataGridViewTextBoxColumn63";
		this->dataGridViewTextBoxColumn63->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		// 
		// dataGridViewTextBoxColumn64
		// 
		this->dataGridViewTextBoxColumn64->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
		dataGridViewCellStyle123->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn64->DefaultCellStyle = dataGridViewCellStyle123;
		this->dataGridViewTextBoxColumn64->HeaderText = L"Low";
		this->dataGridViewTextBoxColumn64->Name = L"dataGridViewTextBoxColumn64";
		this->dataGridViewTextBoxColumn64->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		// 
		// dataGridViewTextBoxColumn65
		// 
		this->dataGridViewTextBoxColumn65->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
		dataGridViewCellStyle124->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn65->DefaultCellStyle = dataGridViewCellStyle124;
		this->dataGridViewTextBoxColumn65->HeaderText = L"High";
		this->dataGridViewTextBoxColumn65->Name = L"dataGridViewTextBoxColumn65";
		this->dataGridViewTextBoxColumn65->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		// 
		// contextMenuStrip_reach_location
		// 
		this->contextMenuStrip_reach_location->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->toolStripMenuItem15, 
			this->toolStripMenuItem16});
		this->contextMenuStrip_reach_location->Name = L"contextMenuStrip1";
		this->contextMenuStrip_reach_location->Size = System::Drawing::Size(184, 48);
		// 
		// toolStripMenuItem15
		// 
		this->toolStripMenuItem15->Name = L"toolStripMenuItem15";
		this->toolStripMenuItem15->Size = System::Drawing::Size(183, 22);
		this->toolStripMenuItem15->Text = L"Add Location Span";
		this->toolStripMenuItem15->Click += gcnew System::EventHandler(this, &MainWindow::add_reach_locations_span);
		// 
		// toolStripMenuItem16
		// 
		this->toolStripMenuItem16->Name = L"toolStripMenuItem16";
		this->toolStripMenuItem16->Size = System::Drawing::Size(183, 22);
		this->toolStripMenuItem16->Text = L"Remove Location Span";
		this->toolStripMenuItem16->Click += gcnew System::EventHandler(this, &MainWindow::remove_reach_locations_span);
		// 
		// textBox_reach_locations_map_id
		// 
		this->textBox_reach_locations_map_id->Location = System::Drawing::Point(77, 39);
		this->textBox_reach_locations_map_id->Name = L"textBox_reach_locations_map_id";
		this->textBox_reach_locations_map_id->Size = System::Drawing::Size(51, 20);
		this->textBox_reach_locations_map_id->TabIndex = 92;
		this->textBox_reach_locations_map_id->Leave += gcnew System::EventHandler(this, &MainWindow::change_reach_locations_map_id);
		// 
		// tabControl1
		// 
		this->tabControl1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
			| System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->tabControl1->Appearance = System::Windows::Forms::TabAppearance::FlatButtons;
		this->tabControl1->Controls->Add(this->tabPage1);
		this->tabControl1->Controls->Add(this->tabPage2);
		this->tabControl1->Controls->Add(this->tabPage3);
		this->tabControl1->Controls->Add(this->tabPage4);
		this->tabControl1->Controls->Add(this->tabPage5);
		this->tabControl1->Controls->Add(this->tabPage6);
		this->tabControl1->Controls->Add(this->tabPage7);
		this->tabControl1->Location = System::Drawing::Point(225, 27);
		this->tabControl1->Margin = System::Windows::Forms::Padding(0);
		this->tabControl1->Name = L"tabControl1";
		this->tabControl1->SelectedIndex = 0;
		this->tabControl1->Size = System::Drawing::Size(687, 606);
		this->tabControl1->TabIndex = 11;
		// 
		// tabPage1
		// 
		this->tabPage1->AutoScroll = true;
		this->tabPage1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
		this->tabPage1->Controls->Add(this->groupBox_general);
		this->tabPage1->Controls->Add(this->groupBox_flags);
		this->tabPage1->Location = System::Drawing::Point(4, 25);
		this->tabPage1->Margin = System::Windows::Forms::Padding(0);
		this->tabPage1->Name = L"tabPage1";
		this->tabPage1->Size = System::Drawing::Size(679, 577);
		this->tabPage1->TabIndex = 0;
		this->tabPage1->Text = L"General";
		this->tabPage1->UseVisualStyleBackColor = true;
		// 
		// tabPage2
		// 
		this->tabPage2->AutoScroll = true;
		this->tabPage2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
		this->tabPage2->Controls->Add(this->groupBox_reach_location);
		this->tabPage2->Controls->Add(this->groupBox_valid_location);
		this->tabPage2->Controls->Add(this->groupBox_fail_location);
		this->tabPage2->Controls->Add(this->groupBox_trigger_location);
		this->tabPage2->Controls->Add(this->groupBox_pq_location);
		this->tabPage2->Location = System::Drawing::Point(4, 25);
		this->tabPage2->Margin = System::Windows::Forms::Padding(0);
		this->tabPage2->Name = L"tabPage2";
		this->tabPage2->Size = System::Drawing::Size(679, 577);
		this->tabPage2->TabIndex = 1;
		this->tabPage2->Text = L"Locations";
		this->tabPage2->UseVisualStyleBackColor = true;
		// 
		// tabPage3
		// 
		this->tabPage3->AutoScroll = true;
		this->tabPage3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
		this->tabPage3->Controls->Add(this->groupBox_basic_1);
		this->tabPage3->Controls->Add(this->groupBox_basic_2);
		this->tabPage3->Location = System::Drawing::Point(4, 25);
		this->tabPage3->Margin = System::Windows::Forms::Padding(0);
		this->tabPage3->Name = L"tabPage3";
		this->tabPage3->Size = System::Drawing::Size(679, 577);
		this->tabPage3->TabIndex = 2;
		this->tabPage3->Text = L"Basic I+II";
		this->tabPage3->UseVisualStyleBackColor = true;
		// 
		// tabPage4
		// 
		this->tabPage4->AutoScroll = true;
		this->tabPage4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
		this->tabPage4->Controls->Add(this->groupBox_requirements);
		this->tabPage4->Location = System::Drawing::Point(4, 25);
		this->tabPage4->Margin = System::Windows::Forms::Padding(0);
		this->tabPage4->Name = L"tabPage4";
		this->tabPage4->Size = System::Drawing::Size(679, 577);
		this->tabPage4->TabIndex = 3;
		this->tabPage4->Text = L"Requirements";
		this->tabPage4->UseVisualStyleBackColor = true;
		// 
		// tabPage5
		// 
		this->tabPage5->AutoScroll = true;
		this->tabPage5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
		this->tabPage5->Controls->Add(this->groupBox_pq_exit_area);
		this->tabPage5->Location = System::Drawing::Point(4, 25);
		this->tabPage5->Margin = System::Windows::Forms::Padding(0);
		this->tabPage5->Name = L"tabPage5";
		this->tabPage5->Size = System::Drawing::Size(679, 577);
		this->tabPage5->TabIndex = 4;
		this->tabPage5->Text = L"Public Quest";
		this->tabPage5->UseVisualStyleBackColor = true;
		// 
		// tabPage6
		// 
		this->tabPage6->AutoScroll = true;
		this->tabPage6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
		this->tabPage6->Controls->Add(this->groupBox_reward_pq);
		this->tabPage6->Controls->Add(this->groupBox_reward_items);
		this->tabPage6->Controls->Add(this->groupBox_reward);
		this->tabPage6->Controls->Add(this->groupBox_reward_selector);
		this->tabPage6->Location = System::Drawing::Point(4, 25);
		this->tabPage6->Margin = System::Windows::Forms::Padding(0);
		this->tabPage6->Name = L"tabPage6";
		this->tabPage6->Size = System::Drawing::Size(679, 577);
		this->tabPage6->TabIndex = 5;
		this->tabPage6->Text = L"Rewards";
		this->tabPage6->UseVisualStyleBackColor = true;
		// 
		// groupBox_reward_pq
		// 
		this->groupBox_reward_pq->Controls->Add(this->label221);
		this->groupBox_reward_pq->Controls->Add(this->dataGridView_reward_pq_specials);
		this->groupBox_reward_pq->Controls->Add(this->label220);
		this->groupBox_reward_pq->Controls->Add(this->dataGridView_reward_pq_items);
		this->groupBox_reward_pq->Controls->Add(this->label219);
		this->groupBox_reward_pq->Controls->Add(this->dataGridView_reward_pq_chases);
		this->groupBox_reward_pq->Controls->Add(this->dataGridView_reward_pq_messages);
		this->groupBox_reward_pq->Controls->Add(this->label218);
		this->groupBox_reward_pq->Controls->Add(this->dataGridView_reward_pq_scripts);
		this->groupBox_reward_pq->Controls->Add(this->label217);
		this->groupBox_reward_pq->Controls->Add(this->textBox_reward_pq_unknown_7);
		this->groupBox_reward_pq->Controls->Add(this->label216);
		this->groupBox_reward_pq->Controls->Add(this->textBox_reward_pq_unknown_6);
		this->groupBox_reward_pq->Controls->Add(this->label215);
		this->groupBox_reward_pq->Controls->Add(this->textBox_reward_pq_unknown_5);
		this->groupBox_reward_pq->Controls->Add(this->label214);
		this->groupBox_reward_pq->Controls->Add(this->textBox_reward_pq_unknown_4);
		this->groupBox_reward_pq->Controls->Add(this->label213);
		this->groupBox_reward_pq->Controls->Add(this->textBox_reward_pq_unknown_3);
		this->groupBox_reward_pq->Controls->Add(this->label212);
		this->groupBox_reward_pq->Controls->Add(this->textBox_reward_pq_contribution_required);
		this->groupBox_reward_pq->Controls->Add(this->label211);
		this->groupBox_reward_pq->Controls->Add(this->textBox_reward_pq_contribution_random_max);
		this->groupBox_reward_pq->Controls->Add(this->label210);
		this->groupBox_reward_pq->Controls->Add(this->textBox_reward_pq_contribution_random_min);
		this->groupBox_reward_pq->Controls->Add(this->label209);
		this->groupBox_reward_pq->Controls->Add(this->textBox_reward_pq_unknown_level);
		this->groupBox_reward_pq->Controls->Add(this->label208);
		this->groupBox_reward_pq->Controls->Add(this->textBox_reward_pq_unknown_2);
		this->groupBox_reward_pq->Controls->Add(this->label207);
		this->groupBox_reward_pq->Controls->Add(this->textBox_reward_pq_unknown_quest);
		this->groupBox_reward_pq->Controls->Add(this->label206);
		this->groupBox_reward_pq->Controls->Add(this->textBox_reward_pq_unknown_1);
		this->groupBox_reward_pq->Controls->Add(this->label205);
		this->groupBox_reward_pq->Controls->Add(this->textBox_reward_pq_event_gold);
		this->groupBox_reward_pq->Controls->Add(this->label204);
		this->groupBox_reward_pq->Controls->Add(this->textBox_reward_pq_unknown_0);
		this->groupBox_reward_pq->Controls->Add(this->label59);
		this->groupBox_reward_pq->ForeColor = System::Drawing::Color::Gray;
		this->groupBox_reward_pq->Location = System::Drawing::Point(3, 715);
		this->groupBox_reward_pq->Name = L"groupBox_reward_pq";
		this->groupBox_reward_pq->Size = System::Drawing::Size(655, 808);
		this->groupBox_reward_pq->TabIndex = 4;
		this->groupBox_reward_pq->TabStop = false;
		this->groupBox_reward_pq->Text = L"PQ RELATED";
		// 
		// label221
		// 
		this->label221->AutoSize = true;
		this->label221->Location = System::Drawing::Point(21, 489);
		this->label221->Name = L"label221";
		this->label221->Size = System::Drawing::Size(50, 13);
		this->label221->TabIndex = 326;
		this->label221->Text = L"Specials:";
		// 
		// dataGridView_reward_pq_specials
		// 
		this->dataGridView_reward_pq_specials->AllowUserToAddRows = false;
		this->dataGridView_reward_pq_specials->AllowUserToDeleteRows = false;
		this->dataGridView_reward_pq_specials->BackgroundColor = System::Drawing::SystemColors::Window;
		this->dataGridView_reward_pq_specials->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
		this->dataGridView_reward_pq_specials->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
		this->dataGridView_reward_pq_specials->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {this->dataGridViewTextBoxColumn97, 
			this->dataGridViewTextBoxColumn98, this->dataGridViewTextBoxColumn100});
		this->dataGridView_reward_pq_specials->ContextMenuStrip = this->contextMenuStrip_reward_pq_specials;
		this->dataGridView_reward_pq_specials->Location = System::Drawing::Point(129, 489);
		this->dataGridView_reward_pq_specials->MultiSelect = false;
		this->dataGridView_reward_pq_specials->Name = L"dataGridView_reward_pq_specials";
		this->dataGridView_reward_pq_specials->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
		dataGridViewCellStyle128->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
		dataGridViewCellStyle128->BackColor = System::Drawing::SystemColors::Control;
		dataGridViewCellStyle128->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		dataGridViewCellStyle128->ForeColor = System::Drawing::SystemColors::WindowText;
		dataGridViewCellStyle128->SelectionBackColor = System::Drawing::SystemColors::Highlight;
		dataGridViewCellStyle128->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
		dataGridViewCellStyle128->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView_reward_pq_specials->RowHeadersDefaultCellStyle = dataGridViewCellStyle128;
		this->dataGridView_reward_pq_specials->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::AutoSizeToFirstHeader;
		this->dataGridView_reward_pq_specials->RowTemplate->Height = 18;
		this->dataGridView_reward_pq_specials->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView_reward_pq_specials->Size = System::Drawing::Size(492, 98);
		this->dataGridView_reward_pq_specials->TabIndex = 327;
		this->dataGridView_reward_pq_specials->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::change_reward_pq_specials);
		// 
		// dataGridViewTextBoxColumn97
		// 
		this->dataGridViewTextBoxColumn97->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle126->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn97->DefaultCellStyle = dataGridViewCellStyle126;
		this->dataGridViewTextBoxColumn97->HeaderText = L"ID";
		this->dataGridViewTextBoxColumn97->Name = L"dataGridViewTextBoxColumn97";
		this->dataGridViewTextBoxColumn97->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn97->Width = 23;
		// 
		// dataGridViewTextBoxColumn98
		// 
		this->dataGridViewTextBoxColumn98->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle127->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn98->DefaultCellStyle = dataGridViewCellStyle127;
		this->dataGridViewTextBoxColumn98->HeaderText = L"Unknown 2";
		this->dataGridViewTextBoxColumn98->Name = L"dataGridViewTextBoxColumn98";
		this->dataGridViewTextBoxColumn98->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn98->Width = 67;
		// 
		// dataGridViewTextBoxColumn100
		// 
		this->dataGridViewTextBoxColumn100->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
		this->dataGridViewTextBoxColumn100->HeaderText = L"Unknown 3";
		this->dataGridViewTextBoxColumn100->Name = L"dataGridViewTextBoxColumn100";
		this->dataGridViewTextBoxColumn100->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		// 
		// contextMenuStrip_reward_pq_specials
		// 
		this->contextMenuStrip_reward_pq_specials->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->toolStripMenuItem42, 
			this->toolStripMenuItem43});
		this->contextMenuStrip_reward_pq_specials->Name = L"contextMenuStrip1";
		this->contextMenuStrip_reward_pq_specials->Size = System::Drawing::Size(150, 48);
		// 
		// toolStripMenuItem42
		// 
		this->toolStripMenuItem42->Name = L"toolStripMenuItem42";
		this->toolStripMenuItem42->Size = System::Drawing::Size(149, 22);
		this->toolStripMenuItem42->Text = L"Add Special";
		this->toolStripMenuItem42->Click += gcnew System::EventHandler(this, &MainWindow::add_reward_pq_special);
		// 
		// toolStripMenuItem43
		// 
		this->toolStripMenuItem43->Name = L"toolStripMenuItem43";
		this->toolStripMenuItem43->Size = System::Drawing::Size(149, 22);
		this->toolStripMenuItem43->Text = L"Remove Special";
		this->toolStripMenuItem43->Click += gcnew System::EventHandler(this, &MainWindow::remove_reward_pq_special);
		// 
		// label220
		// 
		this->label220->AutoSize = true;
		this->label220->Location = System::Drawing::Point(21, 385);
		this->label220->Name = L"label220";
		this->label220->Size = System::Drawing::Size(30, 13);
		this->label220->TabIndex = 324;
		this->label220->Text = L"Item:";
		// 
		// dataGridView_reward_pq_items
		// 
		this->dataGridView_reward_pq_items->AllowUserToAddRows = false;
		this->dataGridView_reward_pq_items->AllowUserToDeleteRows = false;
		this->dataGridView_reward_pq_items->BackgroundColor = System::Drawing::SystemColors::Window;
		this->dataGridView_reward_pq_items->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
		this->dataGridView_reward_pq_items->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
		this->dataGridView_reward_pq_items->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {this->Column24, 
			this->Column25, this->Column26, this->dataGridViewTextBoxColumn94, this->dataGridViewTextBoxColumn95, this->dataGridViewTextBoxColumn96});
		this->dataGridView_reward_pq_items->ContextMenuStrip = this->contextMenuStrip_reward_pq_items;
		this->dataGridView_reward_pq_items->Location = System::Drawing::Point(129, 385);
		this->dataGridView_reward_pq_items->MultiSelect = false;
		this->dataGridView_reward_pq_items->Name = L"dataGridView_reward_pq_items";
		this->dataGridView_reward_pq_items->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
		dataGridViewCellStyle131->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
		dataGridViewCellStyle131->BackColor = System::Drawing::SystemColors::Control;
		dataGridViewCellStyle131->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		dataGridViewCellStyle131->ForeColor = System::Drawing::SystemColors::WindowText;
		dataGridViewCellStyle131->SelectionBackColor = System::Drawing::SystemColors::Highlight;
		dataGridViewCellStyle131->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
		dataGridViewCellStyle131->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView_reward_pq_items->RowHeadersDefaultCellStyle = dataGridViewCellStyle131;
		this->dataGridView_reward_pq_items->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::AutoSizeToFirstHeader;
		this->dataGridView_reward_pq_items->RowTemplate->Height = 18;
		this->dataGridView_reward_pq_items->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView_reward_pq_items->Size = System::Drawing::Size(492, 98);
		this->dataGridView_reward_pq_items->TabIndex = 325;
		this->dataGridView_reward_pq_items->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::change_reward_pq_items);
		// 
		// Column24
		// 
		this->Column24->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		this->Column24->HeaderText = L"Ranking From";
		this->Column24->Name = L"Column24";
		this->Column24->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->Column24->Width = 78;
		// 
		// Column25
		// 
		this->Column25->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		this->Column25->HeaderText = L"Ranking To";
		this->Column25->Name = L"Column25";
		this->Column25->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->Column25->Width = 68;
		// 
		// Column26
		// 
		this->Column26->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		this->Column26->HeaderText = L"Unknown";
		this->Column26->Name = L"Column26";
		this->Column26->Width = 58;
		// 
		// dataGridViewTextBoxColumn94
		// 
		this->dataGridViewTextBoxColumn94->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle129->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn94->DefaultCellStyle = dataGridViewCellStyle129;
		this->dataGridViewTextBoxColumn94->HeaderText = L"ID";
		this->dataGridViewTextBoxColumn94->Name = L"dataGridViewTextBoxColumn94";
		this->dataGridViewTextBoxColumn94->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn94->Width = 23;
		// 
		// dataGridViewTextBoxColumn95
		// 
		this->dataGridViewTextBoxColumn95->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle130->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn95->DefaultCellStyle = dataGridViewCellStyle130;
		this->dataGridViewTextBoxColumn95->HeaderText = L"Amount";
		this->dataGridViewTextBoxColumn95->Name = L"dataGridViewTextBoxColumn95";
		this->dataGridViewTextBoxColumn95->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn95->Width = 48;
		// 
		// dataGridViewTextBoxColumn96
		// 
		this->dataGridViewTextBoxColumn96->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
		this->dataGridViewTextBoxColumn96->HeaderText = L"Probability";
		this->dataGridViewTextBoxColumn96->Name = L"dataGridViewTextBoxColumn96";
		this->dataGridViewTextBoxColumn96->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		// 
		// contextMenuStrip_reward_pq_items
		// 
		this->contextMenuStrip_reward_pq_items->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->toolStripMenuItem22, 
			this->toolStripMenuItem23});
		this->contextMenuStrip_reward_pq_items->Name = L"contextMenuStrip1";
		this->contextMenuStrip_reward_pq_items->Size = System::Drawing::Size(139, 48);
		// 
		// toolStripMenuItem22
		// 
		this->toolStripMenuItem22->Name = L"toolStripMenuItem22";
		this->toolStripMenuItem22->Size = System::Drawing::Size(138, 22);
		this->toolStripMenuItem22->Text = L"Add Item";
		this->toolStripMenuItem22->Click += gcnew System::EventHandler(this, &MainWindow::add_reward_pq_item);
		// 
		// toolStripMenuItem23
		// 
		this->toolStripMenuItem23->Name = L"toolStripMenuItem23";
		this->toolStripMenuItem23->Size = System::Drawing::Size(138, 22);
		this->toolStripMenuItem23->Text = L"Remove Item";
		this->toolStripMenuItem23->Click += gcnew System::EventHandler(this, &MainWindow::remove_reward_pq_item);
		// 
		// label219
		// 
		this->label219->AutoSize = true;
		this->label219->Location = System::Drawing::Point(21, 281);
		this->label219->Name = L"label219";
		this->label219->Size = System::Drawing::Size(86, 13);
		this->label219->TabIndex = 322;
		this->label219->Text = L"Chase Monsters:";
		// 
		// dataGridView_reward_pq_chases
		// 
		this->dataGridView_reward_pq_chases->AllowUserToAddRows = false;
		this->dataGridView_reward_pq_chases->AllowUserToDeleteRows = false;
		this->dataGridView_reward_pq_chases->BackgroundColor = System::Drawing::SystemColors::Window;
		this->dataGridView_reward_pq_chases->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
		this->dataGridView_reward_pq_chases->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
		this->dataGridView_reward_pq_chases->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {this->dataGridViewTextBoxColumn90, 
			this->dataGridViewTextBoxColumn91, this->dataGridViewTextBoxColumn92, this->dataGridViewTextBoxColumn93});
		this->dataGridView_reward_pq_chases->ContextMenuStrip = this->contextMenuStrip_reward_pq_chases;
		this->dataGridView_reward_pq_chases->Location = System::Drawing::Point(129, 281);
		this->dataGridView_reward_pq_chases->MultiSelect = false;
		this->dataGridView_reward_pq_chases->Name = L"dataGridView_reward_pq_chases";
		this->dataGridView_reward_pq_chases->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
		dataGridViewCellStyle134->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
		dataGridViewCellStyle134->BackColor = System::Drawing::SystemColors::Control;
		dataGridViewCellStyle134->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		dataGridViewCellStyle134->ForeColor = System::Drawing::SystemColors::WindowText;
		dataGridViewCellStyle134->SelectionBackColor = System::Drawing::SystemColors::Highlight;
		dataGridViewCellStyle134->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
		dataGridViewCellStyle134->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView_reward_pq_chases->RowHeadersDefaultCellStyle = dataGridViewCellStyle134;
		this->dataGridView_reward_pq_chases->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::AutoSizeToFirstHeader;
		this->dataGridView_reward_pq_chases->RowTemplate->Height = 18;
		this->dataGridView_reward_pq_chases->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView_reward_pq_chases->Size = System::Drawing::Size(492, 98);
		this->dataGridView_reward_pq_chases->TabIndex = 323;
		this->dataGridView_reward_pq_chases->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::change_reward_pq_chases);
		// 
		// dataGridViewTextBoxColumn90
		// 
		this->dataGridViewTextBoxColumn90->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle132->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn90->DefaultCellStyle = dataGridViewCellStyle132;
		this->dataGridViewTextBoxColumn90->HeaderText = L"ID";
		this->dataGridViewTextBoxColumn90->Name = L"dataGridViewTextBoxColumn90";
		this->dataGridViewTextBoxColumn90->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn90->Width = 23;
		// 
		// dataGridViewTextBoxColumn91
		// 
		this->dataGridViewTextBoxColumn91->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle133->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		this->dataGridViewTextBoxColumn91->DefaultCellStyle = dataGridViewCellStyle133;
		this->dataGridViewTextBoxColumn91->HeaderText = L"Amount";
		this->dataGridViewTextBoxColumn91->Name = L"dataGridViewTextBoxColumn91";
		this->dataGridViewTextBoxColumn91->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn91->Width = 48;
		// 
		// dataGridViewTextBoxColumn92
		// 
		this->dataGridViewTextBoxColumn92->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		this->dataGridViewTextBoxColumn92->HeaderText = L"Probability";
		this->dataGridViewTextBoxColumn92->Name = L"dataGridViewTextBoxColumn92";
		this->dataGridViewTextBoxColumn92->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn92->Width = 60;
		// 
		// dataGridViewTextBoxColumn93
		// 
		this->dataGridViewTextBoxColumn93->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
		this->dataGridViewTextBoxColumn93->HeaderText = L"Unknown (Amount\?)";
		this->dataGridViewTextBoxColumn93->Name = L"dataGridViewTextBoxColumn93";
		this->dataGridViewTextBoxColumn93->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		// 
		// contextMenuStrip_reward_pq_chases
		// 
		this->contextMenuStrip_reward_pq_chases->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->toolStripMenuItem20, 
			this->toolStripMenuItem21});
		this->contextMenuStrip_reward_pq_chases->Name = L"contextMenuStrip1";
		this->contextMenuStrip_reward_pq_chases->Size = System::Drawing::Size(147, 48);
		// 
		// toolStripMenuItem20
		// 
		this->toolStripMenuItem20->Name = L"toolStripMenuItem20";
		this->toolStripMenuItem20->Size = System::Drawing::Size(146, 22);
		this->toolStripMenuItem20->Text = L"Add Chase";
		this->toolStripMenuItem20->Click += gcnew System::EventHandler(this, &MainWindow::add_reward_pq_chase);
		// 
		// toolStripMenuItem21
		// 
		this->toolStripMenuItem21->Name = L"toolStripMenuItem21";
		this->toolStripMenuItem21->Size = System::Drawing::Size(146, 22);
		this->toolStripMenuItem21->Text = L"Remove Chase";
		this->toolStripMenuItem21->Click += gcnew System::EventHandler(this, &MainWindow::remove_reward_pq_chase);
		// 
		// dataGridView_reward_pq_messages
		// 
		this->dataGridView_reward_pq_messages->AllowUserToAddRows = false;
		this->dataGridView_reward_pq_messages->AllowUserToDeleteRows = false;
		this->dataGridView_reward_pq_messages->BackgroundColor = System::Drawing::SystemColors::Window;
		this->dataGridView_reward_pq_messages->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
		this->dataGridView_reward_pq_messages->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
		this->dataGridView_reward_pq_messages->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) {this->dataGridViewTextBoxColumn89});
		this->dataGridView_reward_pq_messages->ContextMenuStrip = this->contextMenuStrip_reward_pq_messages;
		this->dataGridView_reward_pq_messages->Location = System::Drawing::Point(129, 697);
		this->dataGridView_reward_pq_messages->MultiSelect = false;
		this->dataGridView_reward_pq_messages->Name = L"dataGridView_reward_pq_messages";
		this->dataGridView_reward_pq_messages->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
		dataGridViewCellStyle136->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
		dataGridViewCellStyle136->BackColor = System::Drawing::SystemColors::Control;
		dataGridViewCellStyle136->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		dataGridViewCellStyle136->ForeColor = System::Drawing::SystemColors::WindowText;
		dataGridViewCellStyle136->SelectionBackColor = System::Drawing::SystemColors::Highlight;
		dataGridViewCellStyle136->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
		dataGridViewCellStyle136->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView_reward_pq_messages->RowHeadersDefaultCellStyle = dataGridViewCellStyle136;
		this->dataGridView_reward_pq_messages->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::AutoSizeToFirstHeader;
		this->dataGridView_reward_pq_messages->RowTemplate->Height = 18;
		this->dataGridView_reward_pq_messages->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView_reward_pq_messages->Size = System::Drawing::Size(492, 98);
		this->dataGridView_reward_pq_messages->TabIndex = 321;
		this->dataGridView_reward_pq_messages->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::change_reward_pq_messages);
		// 
		// dataGridViewTextBoxColumn89
		// 
		this->dataGridViewTextBoxColumn89->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
		dataGridViewCellStyle135->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
		this->dataGridViewTextBoxColumn89->DefaultCellStyle = dataGridViewCellStyle135;
		this->dataGridViewTextBoxColumn89->HeaderText = L"Text";
		this->dataGridViewTextBoxColumn89->Name = L"dataGridViewTextBoxColumn89";
		this->dataGridViewTextBoxColumn89->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		// 
		// contextMenuStrip_reward_pq_messages
		// 
		this->contextMenuStrip_reward_pq_messages->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->toolStripMenuItem44, 
			this->toolStripMenuItem45});
		this->contextMenuStrip_reward_pq_messages->Name = L"contextMenuStrip1";
		this->contextMenuStrip_reward_pq_messages->Size = System::Drawing::Size(159, 48);
		// 
		// toolStripMenuItem44
		// 
		this->toolStripMenuItem44->Name = L"toolStripMenuItem44";
		this->toolStripMenuItem44->Size = System::Drawing::Size(158, 22);
		this->toolStripMenuItem44->Text = L"Add Message";
		this->toolStripMenuItem44->Click += gcnew System::EventHandler(this, &MainWindow::add_reward_pq_message);
		// 
		// toolStripMenuItem45
		// 
		this->toolStripMenuItem45->Name = L"toolStripMenuItem45";
		this->toolStripMenuItem45->Size = System::Drawing::Size(158, 22);
		this->toolStripMenuItem45->Text = L"Remove Message";
		this->toolStripMenuItem45->Click += gcnew System::EventHandler(this, &MainWindow::remove_reward_pq_message);
		// 
		// label218
		// 
		this->label218->AutoSize = true;
		this->label218->Location = System::Drawing::Point(18, 699);
		this->label218->Name = L"label218";
		this->label218->Size = System::Drawing::Size(58, 13);
		this->label218->TabIndex = 320;
		this->label218->Text = L"Messages:";
		// 
		// dataGridView_reward_pq_scripts
		// 
		this->dataGridView_reward_pq_scripts->AllowUserToAddRows = false;
		this->dataGridView_reward_pq_scripts->AllowUserToDeleteRows = false;
		this->dataGridView_reward_pq_scripts->BackgroundColor = System::Drawing::SystemColors::Window;
		this->dataGridView_reward_pq_scripts->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
		this->dataGridView_reward_pq_scripts->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
		this->dataGridView_reward_pq_scripts->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) {this->dataGridViewTextBoxColumn88});
		this->dataGridView_reward_pq_scripts->ContextMenuStrip = this->contextMenuStrip_reward_pq_scripts;
		this->dataGridView_reward_pq_scripts->Location = System::Drawing::Point(129, 593);
		this->dataGridView_reward_pq_scripts->MultiSelect = false;
		this->dataGridView_reward_pq_scripts->Name = L"dataGridView_reward_pq_scripts";
		this->dataGridView_reward_pq_scripts->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
		dataGridViewCellStyle138->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
		dataGridViewCellStyle138->BackColor = System::Drawing::SystemColors::Control;
		dataGridViewCellStyle138->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		dataGridViewCellStyle138->ForeColor = System::Drawing::SystemColors::WindowText;
		dataGridViewCellStyle138->SelectionBackColor = System::Drawing::SystemColors::Highlight;
		dataGridViewCellStyle138->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
		dataGridViewCellStyle138->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView_reward_pq_scripts->RowHeadersDefaultCellStyle = dataGridViewCellStyle138;
		this->dataGridView_reward_pq_scripts->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::AutoSizeToFirstHeader;
		this->dataGridView_reward_pq_scripts->RowTemplate->Height = 18;
		this->dataGridView_reward_pq_scripts->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView_reward_pq_scripts->Size = System::Drawing::Size(492, 98);
		this->dataGridView_reward_pq_scripts->TabIndex = 319;
		this->dataGridView_reward_pq_scripts->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::change_reward_pq_scripts);
		// 
		// dataGridViewTextBoxColumn88
		// 
		this->dataGridViewTextBoxColumn88->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
		dataGridViewCellStyle137->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
		this->dataGridViewTextBoxColumn88->DefaultCellStyle = dataGridViewCellStyle137;
		this->dataGridViewTextBoxColumn88->HeaderText = L"Code";
		this->dataGridViewTextBoxColumn88->Name = L"dataGridViewTextBoxColumn88";
		this->dataGridViewTextBoxColumn88->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		// 
		// contextMenuStrip_reward_pq_scripts
		// 
		this->contextMenuStrip_reward_pq_scripts->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->toolStripMenuItem40, 
			this->toolStripMenuItem41});
		this->contextMenuStrip_reward_pq_scripts->Name = L"contextMenuStrip1";
		this->contextMenuStrip_reward_pq_scripts->Size = System::Drawing::Size(144, 48);
		// 
		// toolStripMenuItem40
		// 
		this->toolStripMenuItem40->Name = L"toolStripMenuItem40";
		this->toolStripMenuItem40->Size = System::Drawing::Size(143, 22);
		this->toolStripMenuItem40->Text = L"Add Script";
		this->toolStripMenuItem40->Click += gcnew System::EventHandler(this, &MainWindow::add_reward_pq_script);
		// 
		// toolStripMenuItem41
		// 
		this->toolStripMenuItem41->Name = L"toolStripMenuItem41";
		this->toolStripMenuItem41->Size = System::Drawing::Size(143, 22);
		this->toolStripMenuItem41->Text = L"Remove Script";
		this->toolStripMenuItem41->Click += gcnew System::EventHandler(this, &MainWindow::remove_reward_pq_script);
		// 
		// label217
		// 
		this->label217->AutoSize = true;
		this->label217->Location = System::Drawing::Point(17, 593);
		this->label217->Name = L"label217";
		this->label217->Size = System::Drawing::Size(42, 13);
		this->label217->TabIndex = 318;
		this->label217->Text = L"Scripts:";
		// 
		// textBox_reward_pq_unknown_7
		// 
		this->textBox_reward_pq_unknown_7->Location = System::Drawing::Point(447, 225);
		this->textBox_reward_pq_unknown_7->Name = L"textBox_reward_pq_unknown_7";
		this->textBox_reward_pq_unknown_7->Size = System::Drawing::Size(100, 20);
		this->textBox_reward_pq_unknown_7->TabIndex = 47;
		this->textBox_reward_pq_unknown_7->Leave += gcnew System::EventHandler(this, &MainWindow::change_reward_pq_unknown_7);
		// 
		// label216
		// 
		this->label216->AutoSize = true;
		this->label216->Location = System::Drawing::Point(296, 225);
		this->label216->Name = L"label216";
		this->label216->Size = System::Drawing::Size(65, 13);
		this->label216->TabIndex = 46;
		this->label216->Text = L"Unknown 7:";
		// 
		// textBox_reward_pq_unknown_6
		// 
		this->textBox_reward_pq_unknown_6->Location = System::Drawing::Point(147, 222);
		this->textBox_reward_pq_unknown_6->Name = L"textBox_reward_pq_unknown_6";
		this->textBox_reward_pq_unknown_6->Size = System::Drawing::Size(100, 20);
		this->textBox_reward_pq_unknown_6->TabIndex = 45;
		this->textBox_reward_pq_unknown_6->Leave += gcnew System::EventHandler(this, &MainWindow::change_reward_pq_unknown_6);
		// 
		// label215
		// 
		this->label215->AutoSize = true;
		this->label215->Location = System::Drawing::Point(14, 225);
		this->label215->Name = L"label215";
		this->label215->Size = System::Drawing::Size(65, 13);
		this->label215->TabIndex = 44;
		this->label215->Text = L"Unknown 6:";
		// 
		// textBox_reward_pq_unknown_5
		// 
		this->textBox_reward_pq_unknown_5->Location = System::Drawing::Point(147, 192);
		this->textBox_reward_pq_unknown_5->Name = L"textBox_reward_pq_unknown_5";
		this->textBox_reward_pq_unknown_5->Size = System::Drawing::Size(400, 20);
		this->textBox_reward_pq_unknown_5->TabIndex = 43;
		this->textBox_reward_pq_unknown_5->Leave += gcnew System::EventHandler(this, &MainWindow::change_reward_unknown_5);
		// 
		// label214
		// 
		this->label214->AutoSize = true;
		this->label214->Location = System::Drawing::Point(6, 195);
		this->label214->Name = L"label214";
		this->label214->Size = System::Drawing::Size(65, 13);
		this->label214->TabIndex = 42;
		this->label214->Text = L"Unknown 5:";
		// 
		// textBox_reward_pq_unknown_4
		// 
		this->textBox_reward_pq_unknown_4->Location = System::Drawing::Point(447, 123);
		this->textBox_reward_pq_unknown_4->Name = L"textBox_reward_pq_unknown_4";
		this->textBox_reward_pq_unknown_4->Size = System::Drawing::Size(100, 20);
		this->textBox_reward_pq_unknown_4->TabIndex = 41;
		this->textBox_reward_pq_unknown_4->Leave += gcnew System::EventHandler(this, &MainWindow::change_reward_pq_unknown_4);
		// 
		// label213
		// 
		this->label213->AutoSize = true;
		this->label213->Location = System::Drawing::Point(306, 126);
		this->label213->Name = L"label213";
		this->label213->Size = System::Drawing::Size(65, 13);
		this->label213->TabIndex = 40;
		this->label213->Text = L"Unknown 4:";
		// 
		// textBox_reward_pq_unknown_3
		// 
		this->textBox_reward_pq_unknown_3->Location = System::Drawing::Point(447, 97);
		this->textBox_reward_pq_unknown_3->Name = L"textBox_reward_pq_unknown_3";
		this->textBox_reward_pq_unknown_3->Size = System::Drawing::Size(100, 20);
		this->textBox_reward_pq_unknown_3->TabIndex = 39;
		this->textBox_reward_pq_unknown_3->Leave += gcnew System::EventHandler(this, &MainWindow::change_reward_pq_unknown_3);
		// 
		// label212
		// 
		this->label212->AutoSize = true;
		this->label212->Location = System::Drawing::Point(306, 100);
		this->label212->Name = L"label212";
		this->label212->Size = System::Drawing::Size(65, 13);
		this->label212->TabIndex = 38;
		this->label212->Text = L"Unknown 3:";
		// 
		// textBox_reward_pq_contribution_required
		// 
		this->textBox_reward_pq_contribution_required->Location = System::Drawing::Point(447, 71);
		this->textBox_reward_pq_contribution_required->Name = L"textBox_reward_pq_contribution_required";
		this->textBox_reward_pq_contribution_required->Size = System::Drawing::Size(100, 20);
		this->textBox_reward_pq_contribution_required->TabIndex = 37;
		this->textBox_reward_pq_contribution_required->Leave += gcnew System::EventHandler(this, &MainWindow::change_reward_pq_contribution_required);
		// 
		// label211
		// 
		this->label211->AutoSize = true;
		this->label211->Location = System::Drawing::Point(306, 74);
		this->label211->Name = L"label211";
		this->label211->Size = System::Drawing::Size(112, 13);
		this->label211->TabIndex = 36;
		this->label211->Text = L"Contribution Required:";
		// 
		// textBox_reward_pq_contribution_random_max
		// 
		this->textBox_reward_pq_contribution_random_max->Location = System::Drawing::Point(447, 45);
		this->textBox_reward_pq_contribution_random_max->Name = L"textBox_reward_pq_contribution_random_max";
		this->textBox_reward_pq_contribution_random_max->Size = System::Drawing::Size(100, 20);
		this->textBox_reward_pq_contribution_random_max->TabIndex = 35;
		this->textBox_reward_pq_contribution_random_max->Leave += gcnew System::EventHandler(this, &MainWindow::change_reward_pq_contribution_random_max);
		// 
		// label210
		// 
		this->label210->AutoSize = true;
		this->label210->Location = System::Drawing::Point(306, 48);
		this->label210->Name = L"label210";
		this->label210->Size = System::Drawing::Size(135, 13);
		this->label210->TabIndex = 34;
		this->label210->Text = L"Contribution Random Max.:";
		// 
		// textBox_reward_pq_contribution_random_min
		// 
		this->textBox_reward_pq_contribution_random_min->Location = System::Drawing::Point(447, 19);
		this->textBox_reward_pq_contribution_random_min->Name = L"textBox_reward_pq_contribution_random_min";
		this->textBox_reward_pq_contribution_random_min->Size = System::Drawing::Size(100, 20);
		this->textBox_reward_pq_contribution_random_min->TabIndex = 33;
		this->textBox_reward_pq_contribution_random_min->Leave += gcnew System::EventHandler(this, &MainWindow::change_reward_pq_contribution_random_min);
		// 
		// label209
		// 
		this->label209->AutoSize = true;
		this->label209->Location = System::Drawing::Point(306, 22);
		this->label209->Name = L"label209";
		this->label209->Size = System::Drawing::Size(132, 13);
		this->label209->TabIndex = 32;
		this->label209->Text = L"Contribution Random Min.:";
		// 
		// textBox_reward_pq_unknown_level
		// 
		this->textBox_reward_pq_unknown_level->Location = System::Drawing::Point(147, 149);
		this->textBox_reward_pq_unknown_level->Name = L"textBox_reward_pq_unknown_level";
		this->textBox_reward_pq_unknown_level->Size = System::Drawing::Size(100, 20);
		this->textBox_reward_pq_unknown_level->TabIndex = 31;
		this->textBox_reward_pq_unknown_level->Leave += gcnew System::EventHandler(this, &MainWindow::change_reward_pq_unknown_level);
		// 
		// label208
		// 
		this->label208->AutoSize = true;
		this->label208->Location = System::Drawing::Point(6, 152);
		this->label208->Name = L"label208";
		this->label208->Size = System::Drawing::Size(85, 13);
		this->label208->TabIndex = 30;
		this->label208->Text = L"Unknown Level:";
		// 
		// textBox_reward_pq_unknown_2
		// 
		this->textBox_reward_pq_unknown_2->Location = System::Drawing::Point(147, 123);
		this->textBox_reward_pq_unknown_2->Name = L"textBox_reward_pq_unknown_2";
		this->textBox_reward_pq_unknown_2->Size = System::Drawing::Size(100, 20);
		this->textBox_reward_pq_unknown_2->TabIndex = 29;
		this->textBox_reward_pq_unknown_2->Leave += gcnew System::EventHandler(this, &MainWindow::change_reward_pq_unknown_2);
		// 
		// label207
		// 
		this->label207->AutoSize = true;
		this->label207->Location = System::Drawing::Point(6, 126);
		this->label207->Name = L"label207";
		this->label207->Size = System::Drawing::Size(65, 13);
		this->label207->TabIndex = 28;
		this->label207->Text = L"Unknown 2:";
		// 
		// textBox_reward_pq_unknown_quest
		// 
		this->textBox_reward_pq_unknown_quest->Location = System::Drawing::Point(147, 97);
		this->textBox_reward_pq_unknown_quest->Name = L"textBox_reward_pq_unknown_quest";
		this->textBox_reward_pq_unknown_quest->Size = System::Drawing::Size(100, 20);
		this->textBox_reward_pq_unknown_quest->TabIndex = 27;
		this->textBox_reward_pq_unknown_quest->Leave += gcnew System::EventHandler(this, &MainWindow::change_reward_pq_unknown_quest);
		// 
		// label206
		// 
		this->label206->AutoSize = true;
		this->label206->Location = System::Drawing::Point(6, 100);
		this->label206->Name = L"label206";
		this->label206->Size = System::Drawing::Size(87, 13);
		this->label206->TabIndex = 26;
		this->label206->Text = L"Unknown Quest:";
		// 
		// textBox_reward_pq_unknown_1
		// 
		this->textBox_reward_pq_unknown_1->Location = System::Drawing::Point(147, 71);
		this->textBox_reward_pq_unknown_1->Name = L"textBox_reward_pq_unknown_1";
		this->textBox_reward_pq_unknown_1->Size = System::Drawing::Size(100, 20);
		this->textBox_reward_pq_unknown_1->TabIndex = 25;
		this->textBox_reward_pq_unknown_1->Leave += gcnew System::EventHandler(this, &MainWindow::change_reward_pq_unknown_1);
		// 
		// label205
		// 
		this->label205->AutoSize = true;
		this->label205->Location = System::Drawing::Point(6, 74);
		this->label205->Name = L"label205";
		this->label205->Size = System::Drawing::Size(65, 13);
		this->label205->TabIndex = 24;
		this->label205->Text = L"Unknown 1:";
		// 
		// textBox_reward_pq_event_gold
		// 
		this->textBox_reward_pq_event_gold->Location = System::Drawing::Point(147, 45);
		this->textBox_reward_pq_event_gold->Name = L"textBox_reward_pq_event_gold";
		this->textBox_reward_pq_event_gold->Size = System::Drawing::Size(100, 20);
		this->textBox_reward_pq_event_gold->TabIndex = 23;
		this->textBox_reward_pq_event_gold->Leave += gcnew System::EventHandler(this, &MainWindow::change_reward_pq_event_gold);
		// 
		// label204
		// 
		this->label204->AutoSize = true;
		this->label204->Location = System::Drawing::Point(6, 48);
		this->label204->Name = L"label204";
		this->label204->Size = System::Drawing::Size(63, 13);
		this->label204->TabIndex = 22;
		this->label204->Text = L"Event Gold:";
		// 
		// textBox_reward_pq_unknown_0
		// 
		this->textBox_reward_pq_unknown_0->Location = System::Drawing::Point(147, 19);
		this->textBox_reward_pq_unknown_0->Name = L"textBox_reward_pq_unknown_0";
		this->textBox_reward_pq_unknown_0->Size = System::Drawing::Size(100, 20);
		this->textBox_reward_pq_unknown_0->TabIndex = 21;
		this->textBox_reward_pq_unknown_0->Leave += gcnew System::EventHandler(this, &MainWindow::change_reward_pq_unknown_0);
		// 
		// label59
		// 
		this->label59->AutoSize = true;
		this->label59->Location = System::Drawing::Point(6, 22);
		this->label59->Name = L"label59";
		this->label59->Size = System::Drawing::Size(65, 13);
		this->label59->TabIndex = 20;
		this->label59->Text = L"Unknown 0:";
		// 
		// groupBox_reward_items
		// 
		this->groupBox_reward_items->Controls->Add(this->checkedListBox_reward_item_groups_flag);
		this->groupBox_reward_items->Controls->Add(this->label56);
		this->groupBox_reward_items->Controls->Add(this->numericUpDown_reward_item_groups_count);
		this->groupBox_reward_items->Controls->Add(this->label57);
		this->groupBox_reward_items->Controls->Add(this->dataGridView_reward_item_group_items);
		this->groupBox_reward_items->Controls->Add(this->label37);
		this->groupBox_reward_items->Location = System::Drawing::Point(3, 518);
		this->groupBox_reward_items->Name = L"groupBox_reward_items";
		this->groupBox_reward_items->Size = System::Drawing::Size(655, 191);
		this->groupBox_reward_items->TabIndex = 3;
		this->groupBox_reward_items->TabStop = false;
		this->groupBox_reward_items->Text = L"ITEMS";
		// 
		// checkedListBox_reward_item_groups_flag
		// 
		this->checkedListBox_reward_item_groups_flag->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
			| System::Windows::Forms::AnchorStyles::Left));
		this->checkedListBox_reward_item_groups_flag->FormattingEnabled = true;
		this->checkedListBox_reward_item_groups_flag->Location = System::Drawing::Point(6, 76);
		this->checkedListBox_reward_item_groups_flag->Name = L"checkedListBox_reward_item_groups_flag";
		this->checkedListBox_reward_item_groups_flag->RightToLeft = System::Windows::Forms::RightToLeft::No;
		this->checkedListBox_reward_item_groups_flag->Size = System::Drawing::Size(100, 109);
		this->checkedListBox_reward_item_groups_flag->TabIndex = 41;
		this->checkedListBox_reward_item_groups_flag->ItemCheck += gcnew System::Windows::Forms::ItemCheckEventHandler(this, &MainWindow::change_reward_item_group_flag);
		// 
		// tabPage7
		// 
		this->tabPage7->AutoScroll = true;
		this->tabPage7->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
		this->tabPage7->Controls->Add(this->groupBox_answers);
		this->tabPage7->Controls->Add(this->groupBox_conversation);
		this->tabPage7->Controls->Add(this->groupBox_questions);
		this->tabPage7->Controls->Add(this->groupBox_dialogs);
		this->tabPage7->Location = System::Drawing::Point(4, 25);
		this->tabPage7->Margin = System::Windows::Forms::Padding(0);
		this->tabPage7->Name = L"tabPage7";
		this->tabPage7->Size = System::Drawing::Size(679, 577);
		this->tabPage7->TabIndex = 6;
		this->tabPage7->Text = L"Conversation";
		this->tabPage7->UseVisualStyleBackColor = true;
		// 
		// contextMenuStrip_pq_scripts
		// 
		this->contextMenuStrip_pq_scripts->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->toolStripMenuItem32, 
			this->toolStripMenuItem33});
		this->contextMenuStrip_pq_scripts->Name = L"contextMenuStrip1";
		this->contextMenuStrip_pq_scripts->Size = System::Drawing::Size(144, 48);
		// 
		// toolStripMenuItem32
		// 
		this->toolStripMenuItem32->Name = L"toolStripMenuItem32";
		this->toolStripMenuItem32->Size = System::Drawing::Size(143, 22);
		this->toolStripMenuItem32->Text = L"Add Script";
		this->toolStripMenuItem32->Click += gcnew System::EventHandler(this, &MainWindow::add_pq_script);
		// 
		// toolStripMenuItem33
		// 
		this->toolStripMenuItem33->Name = L"toolStripMenuItem33";
		this->toolStripMenuItem33->Size = System::Drawing::Size(143, 22);
		this->toolStripMenuItem33->Text = L"Remove Script";
		this->toolStripMenuItem33->Click += gcnew System::EventHandler(this, &MainWindow::remove_pq_script);
		// 
		// dataGridViewTextBoxColumn99
		// 
		this->dataGridViewTextBoxColumn99->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle63->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		dataGridViewCellStyle63->ForeColor = System::Drawing::Color::Red;
		this->dataGridViewTextBoxColumn99->DefaultCellStyle = dataGridViewCellStyle63;
		this->dataGridViewTextBoxColumn99->HeaderText = L"\?";
		this->dataGridViewTextBoxColumn99->Name = L"dataGridViewTextBoxColumn99";
		this->dataGridViewTextBoxColumn99->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn99->Width = 18;
		// 
		// dataGridViewTextBoxColumn101
		// 
		this->dataGridViewTextBoxColumn101->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle64->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		dataGridViewCellStyle64->ForeColor = System::Drawing::Color::Red;
		this->dataGridViewTextBoxColumn101->DefaultCellStyle = dataGridViewCellStyle64;
		this->dataGridViewTextBoxColumn101->HeaderText = L"\?";
		this->dataGridViewTextBoxColumn101->Name = L"dataGridViewTextBoxColumn101";
		this->dataGridViewTextBoxColumn101->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn101->Width = 18;
		// 
		// dataGridViewTextBoxColumn102
		// 
		this->dataGridViewTextBoxColumn102->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle65->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		dataGridViewCellStyle65->ForeColor = System::Drawing::Color::Red;
		this->dataGridViewTextBoxColumn102->DefaultCellStyle = dataGridViewCellStyle65;
		this->dataGridViewTextBoxColumn102->HeaderText = L"\?";
		this->dataGridViewTextBoxColumn102->Name = L"dataGridViewTextBoxColumn102";
		this->dataGridViewTextBoxColumn102->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn102->Width = 18;
		// 
		// dataGridViewTextBoxColumn103
		// 
		this->dataGridViewTextBoxColumn103->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle66->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		dataGridViewCellStyle66->ForeColor = System::Drawing::Color::Red;
		this->dataGridViewTextBoxColumn103->DefaultCellStyle = dataGridViewCellStyle66;
		this->dataGridViewTextBoxColumn103->HeaderText = L"\?";
		this->dataGridViewTextBoxColumn103->Name = L"dataGridViewTextBoxColumn103";
		this->dataGridViewTextBoxColumn103->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn103->Width = 18;
		// 
		// dataGridViewTextBoxColumn104
		// 
		this->dataGridViewTextBoxColumn104->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle67->ForeColor = System::Drawing::Color::Red;
		this->dataGridViewTextBoxColumn104->DefaultCellStyle = dataGridViewCellStyle67;
		this->dataGridViewTextBoxColumn104->HeaderText = L"Probability";
		this->dataGridViewTextBoxColumn104->Name = L"dataGridViewTextBoxColumn104";
		this->dataGridViewTextBoxColumn104->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn104->Width = 60;
		// 
		// DataGridViewTextBoxColumn281
		// 
		this->DataGridViewTextBoxColumn281->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::ColumnHeader;
		dataGridViewCellStyle68->ForeColor = System::Drawing::Color::Red;
		this->DataGridViewTextBoxColumn281->DefaultCellStyle = dataGridViewCellStyle68;
		this->DataGridViewTextBoxColumn281->HeaderText = L"Class Mask";
		this->DataGridViewTextBoxColumn281->Name = L"DataGridViewTextBoxColumn281";
		this->DataGridViewTextBoxColumn281->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->DataGridViewTextBoxColumn281->Width = 66;
		// 
		// dataGridViewTextBoxColumn106
		// 
		this->dataGridViewTextBoxColumn106->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle69->ForeColor = System::Drawing::Color::Red;
		this->dataGridViewTextBoxColumn106->DefaultCellStyle = dataGridViewCellStyle69;
		this->dataGridViewTextBoxColumn106->HeaderText = L"Min. LvL";
		this->dataGridViewTextBoxColumn106->Name = L"dataGridViewTextBoxColumn106";
		this->dataGridViewTextBoxColumn106->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn106->Width = 53;
		// 
		// dataGridViewTextBoxColumn107
		// 
		this->dataGridViewTextBoxColumn107->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle70->ForeColor = System::Drawing::Color::Red;
		this->dataGridViewTextBoxColumn107->DefaultCellStyle = dataGridViewCellStyle70;
		this->dataGridViewTextBoxColumn107->HeaderText = L"Max. LvL";
		this->dataGridViewTextBoxColumn107->Name = L"dataGridViewTextBoxColumn107";
		this->dataGridViewTextBoxColumn107->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn107->Width = 56;
		// 
		// Column27
		// 
		this->Column27->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle71->ForeColor = System::Drawing::Color::Red;
		this->Column27->DefaultCellStyle = dataGridViewCellStyle71;
		this->Column27->HeaderText = L"\?";
		this->Column27->Name = L"Column27";
		this->Column27->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->Column27->Width = 18;
		// 
		// Column28
		// 
		this->Column28->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
		dataGridViewCellStyle72->ForeColor = System::Drawing::Color::Red;
		this->Column28->DefaultCellStyle = dataGridViewCellStyle72;
		this->Column28->HeaderText = L"Enemy Force";
		this->Column28->Items->AddRange(gcnew cli::array< System::Object^  >(5) {L"NULL", L"Corona", L"Shroud", L"[3] - \?", L"Luminance"});
		this->Column28->Name = L"Column28";
		// 
		// MainWindow
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->ClientSize = System::Drawing::Size(912, 653);
		this->Controls->Add(this->tabControl1);
		this->Controls->Add(this->comboBox_search);
		this->Controls->Add(this->treeView_tasks);
		this->Controls->Add(this->button_search);
		this->Controls->Add(this->progressBar_progress);
		this->Controls->Add(this->menuStrip_mainMenu);
		this->Controls->Add(this->textBox_search);
		this->MinimumSize = System::Drawing::Size(920, 680);
		this->Name = L"MainWindow";
		this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
		this->Text = L" sTASKedit";
		this->menuStrip_mainMenu->ResumeLayout(false);
		this->menuStrip_mainMenu->PerformLayout();
		this->contextMenuStrip_date_spans->ResumeLayout(false);
		this->contextMenuStrip_task->ResumeLayout(false);
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_date_spans))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_reward_item_group_items))->EndInit();
		this->contextMenuStrip_reward_items->ResumeLayout(false);
		this->groupBox_reward_selector->ResumeLayout(false);
		this->groupBox_reward_selector->PerformLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown_time_factor))->EndInit();
		this->contextMenuStrip_reward_timed->ResumeLayout(false);
		this->groupBox_reward->ResumeLayout(false);
		this->groupBox_reward->PerformLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown_reward_item_groups_count))->EndInit();
		this->groupBox_conversation->ResumeLayout(false);
		this->groupBox_conversation->PerformLayout();
		this->groupBox_answers->ResumeLayout(false);
		this->groupBox_answers->PerformLayout();
		this->contextMenuStrip_conversation_answer->ResumeLayout(false);
		this->contextMenuStrip_conversation_question->ResumeLayout(false);
		this->groupBox_questions->ResumeLayout(false);
		this->groupBox_questions->PerformLayout();
		this->groupBox_dialogs->ResumeLayout(false);
		this->groupBox_dialogs->PerformLayout();
		this->groupBox_basic_2->ResumeLayout(false);
		this->groupBox_basic_2->PerformLayout();
		this->groupBox_pq_exit_area->ResumeLayout(false);
		this->groupBox_pq_exit_area->PerformLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_pq_messages))->EndInit();
		this->contextMenuStrip_pq_messages->ResumeLayout(false);
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_pq_special_scripts))->EndInit();
		this->contextMenuStrip_pq_special_scripts->ResumeLayout(false);
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_pq_chases))->EndInit();
		this->contextMenuStrip_pq_chases->ResumeLayout(false);
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_pq_scripts))->EndInit();
		this->contextMenuStrip_pq_script_infos->ResumeLayout(false);
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_pq_script_infos))->EndInit();
		this->groupBox_pq_location->ResumeLayout(false);
		this->groupBox_pq_location->PerformLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_pq_location_spans))->EndInit();
		this->contextMenuStrip_pq_location->ResumeLayout(false);
		this->groupBox_basic_1->ResumeLayout(false);
		this->groupBox_basic_1->PerformLayout();
		this->groupBox_valid_location->ResumeLayout(false);
		this->groupBox_valid_location->PerformLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_valid_location_spans))->EndInit();
		this->contextMenuStrip_valid_location->ResumeLayout(false);
		this->groupBox_fail_location->ResumeLayout(false);
		this->groupBox_fail_location->PerformLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_fail_location_spans))->EndInit();
		this->contextMenuStrip_fail_location->ResumeLayout(false);
		this->groupBox_trigger_location->ResumeLayout(false);
		this->groupBox_trigger_location->PerformLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_trigger_location_spans))->EndInit();
		this->contextMenuStrip_trigger_location->ResumeLayout(false);
		this->groupBox_flags->ResumeLayout(false);
		this->groupBox_flags->PerformLayout();
		this->groupBox_requirements->ResumeLayout(false);
		this->groupBox_requirements->PerformLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_required_morai_pk))->EndInit();
		this->contextMenuStrip_morai_pk->ResumeLayout(false);
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_team_members))->EndInit();
		this->contextMenuStrip_team_members->ResumeLayout(false);
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_given_items))->EndInit();
		this->contextMenuStrip_given_items->ResumeLayout(false);
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_required_items))->EndInit();
		this->contextMenuStrip_required_items->ResumeLayout(false);
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_required_get_items))->EndInit();
		this->contextMenuStrip_required_get_items->ResumeLayout(false);
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_required_chases))->EndInit();
		this->contextMenuStrip_chases->ResumeLayout(false);
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_date_unknown))->EndInit();
		this->groupBox_general->ResumeLayout(false);
		this->groupBox_general->PerformLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_date_fail))->EndInit();
		this->groupBox_reach_location->ResumeLayout(false);
		this->groupBox_reach_location->PerformLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_reach_location_spans))->EndInit();
		this->contextMenuStrip_reach_location->ResumeLayout(false);
		this->tabControl1->ResumeLayout(false);
		this->tabPage1->ResumeLayout(false);
		this->tabPage2->ResumeLayout(false);
		this->tabPage3->ResumeLayout(false);
		this->tabPage4->ResumeLayout(false);
		this->tabPage5->ResumeLayout(false);
		this->tabPage6->ResumeLayout(false);
		this->groupBox_reward_pq->ResumeLayout(false);
		this->groupBox_reward_pq->PerformLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_reward_pq_specials))->EndInit();
		this->contextMenuStrip_reward_pq_specials->ResumeLayout(false);
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_reward_pq_items))->EndInit();
		this->contextMenuStrip_reward_pq_items->ResumeLayout(false);
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_reward_pq_chases))->EndInit();
		this->contextMenuStrip_reward_pq_chases->ResumeLayout(false);
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_reward_pq_messages))->EndInit();
		this->contextMenuStrip_reward_pq_messages->ResumeLayout(false);
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_reward_pq_scripts))->EndInit();
		this->contextMenuStrip_reward_pq_scripts->ResumeLayout(false);
		this->groupBox_reward_items->ResumeLayout(false);
		this->groupBox_reward_items->PerformLayout();
		this->tabPage7->ResumeLayout(false);
		this->contextMenuStrip_pq_scripts->ResumeLayout(false);
		this->ResumeLayout(false);
		this->PerformLayout();

	}

#pragma endregion

#pragma region I/O FUNCTIONS

	private: System::Void click_load(System::Object^  sender, System::EventArgs^  e)
	{
		OpenFileDialog^ load = gcnew OpenFileDialog();
		load->Filter = "Tasks File (*.data)|*.data|All Files (*.*)|*.*";
		if(load->ShowDialog() == Windows::Forms::DialogResult::OK && File::Exists(load->FileName))
		{
			try
			{
				Cursor = Windows::Forms::Cursors::WaitCursor;
				progressBar_progress->Style = ProgressBarStyle::Marquee;

				treeView_tasks->Nodes->Clear();
				treeView_tasks->BeginUpdate();

				FileStream^ fr = File::OpenRead(load->FileName);
				BinaryReader^ br = gcnew BinaryReader(fr);

				int stamp = br->ReadInt32();
				int version = br->ReadInt32();

				if(!versions->Contains(version))
				{
					br->Close();
					fr->Close();
					treeView_tasks->EndUpdate();
					progressBar_progress->Style = ProgressBarStyle::Continuous;
					Cursor = Windows::Forms::Cursors::Default;
					MessageBox::Show("Version Unsupported: " + version.ToString());
					return;
				}

				int count = br->ReadInt32();

				array<int>^ ItemStreamPositions = gcnew array<int>(count);

				for(int i=0; i<count; i++)
				{
					ItemStreamPositions[i] = br->ReadInt32();
				}

				Tasks = gcnew array<Task^>(count);

				Application::DoEvents();

				for(int i=0; i<count; i++)
				{
					Application::DoEvents();

					Tasks[i] = gcnew Task(version, br, ItemStreamPositions[i], treeView_tasks->Nodes);
				}

				br->Close();
				fr->Close();

				treeView_tasks->EndUpdate();
				treeView_tasks->SelectedNode = treeView_tasks->Nodes[0];

				this->Text = " sTASKedit (" + load->FileName + ")";

				progressBar_progress->Style = ProgressBarStyle::Continuous;
				Cursor = Windows::Forms::Cursors::Default;

				MessageBox::Show("Version: " + version.ToString() + "\n\nIt is not recommend exporting to a higher version!\nExporting to a higher version will fill new fields with default values which may corrupt the file.\n\nColor Encoding:\nBlack Labels - v55/v56 (1.2.6/1.3.6)\nGray Labels - v93 (1.4.4)\nRed Labels - v100+ (1.4.5+)", "Loading Complete");
			}
			catch(Exception^ e)
			{
				treeView_tasks->EndUpdate();
				progressBar_progress->Style = ProgressBarStyle::Continuous;
				Cursor = Windows::Forms::Cursors::Default;
				MessageBox::Show("IMPORT ERROR!\n\n" + e->Message);
			}
		}
	}
	private: System::Void click_save(System::Object^  sender, System::EventArgs^  e)
	{
		// Leave Focus to ensure all changes are saved...
		menuStrip_mainMenu->Focus();

		SaveFileDialog^ save = gcnew SaveFileDialog();
		save->Filter = "Tasks File (*.data)|*.data|All Files (*.*)|*.*";
		if(save->ShowDialog() == Windows::Forms::DialogResult::OK && save->FileName != "")
		{
			try
			{
				Cursor = Windows::Forms::Cursors::WaitCursor;
				progressBar_progress->Style = ProgressBarStyle::Marquee;

				int stamp = -1819966623;
				int version = Convert::ToInt32(((ToolStripMenuItem^)sender)->Text->Substring(1));

				FileStream^ fs = gcnew FileStream(save->FileName, FileMode::Create, FileAccess::Write);
				BinaryWriter^ bw = gcnew BinaryWriter(fs);

				bw->Write(stamp);
				bw->Write(version);
				bw->Write(Tasks->Length);

				array<int>^ ItemStreamPositions = gcnew array<int>(Tasks->Length);

				// write placeholder
				bw->Write(gcnew array<unsigned char>(4*Tasks->Length));

				for(int i=0; i<Tasks->Length; i++)
				{
					Application::DoEvents();
					ItemStreamPositions[i] = (int)bw->BaseStream->Position;
					Tasks[i]->Save(version, bw);
				}

				// insert into placeholder
				bw->BaseStream->Position = 12;
				for(int i=0; i<ItemStreamPositions->Length; i++)
				{
					bw->Write(ItemStreamPositions[i]);
				}

				bw->Close();
				fs->Close();

				progressBar_progress->Style = ProgressBarStyle::Continuous;
				Cursor = Windows::Forms::Cursors::Default;
			}
			catch(Exception^ e)
			{
				progressBar_progress->Style = ProgressBarStyle::Continuous;
				Cursor = Windows::Forms::Cursors::Default;
				MessageBox::Show("EXPORT ERROR!\n\n" + e->Message);
			}
		}
	}
	private: System::Void click_ImportTask(System::Object^  sender, System::EventArgs^  e)
	{
		OpenFileDialog^ qLoad = gcnew OpenFileDialog();
		qLoad->Filter = "Task File (*.data)|*.data|All Files (*.*)|*.*";
		if(qLoad->ShowDialog() == Windows::Forms::DialogResult::OK && File::Exists(qLoad->FileName))
		{
			try
			{
				Cursor = Windows::Forms::Cursors::AppStarting;

				FileStream^ fr = File::OpenRead(qLoad->FileName);
				BinaryReader^ br = gcnew BinaryReader(fr);

				br->ReadInt32(); // stamp
				int version = br->ReadInt32();
				int count = br->ReadInt32();

				// offset list
				// 4*count bytes

				array<Task^>^ temp = gcnew array<Task^>(Tasks->Length+1);
				temp[temp->Length-1] = gcnew Task(version, br, 4*count+12, treeView_tasks->Nodes);
				Array::Copy(Tasks, 0, temp, 0, Tasks->Length);
				Tasks = temp;

				br->Close();
				fr->Close();

				treeView_tasks->SelectedNode = treeView_tasks->Nodes[treeView_tasks->Nodes->Count-1];

				Cursor = Windows::Forms::Cursors::Default;
			}
			catch(...)
			{
				MessageBox::Show("IMPORT ERROR!");
				Cursor = Windows::Forms::Cursors::Default;
			}
		}
	}
	private: System::Void click_ExportTask(System::Object^  sender, System::EventArgs^  e)
	{
		SaveFileDialog^ qSave = gcnew SaveFileDialog();
		qSave->Filter = "Task File (*.data)|*.data|All Files (*.*)|*.*";
		if(qSave->ShowDialog() == Windows::Forms::DialogResult::OK && qSave->FileName != "")
		{
			try
			{
				Cursor = Windows::Forms::Cursors::AppStarting;

				FileStream^ fs = gcnew FileStream(qSave->FileName, FileMode::Create, FileAccess::Write);
				BinaryWriter^ bw = gcnew BinaryWriter(fs);

				int version = 9999;
				bw->Write(0); // stamp
				bw->Write(version);
				bw->Write((int)1);

				// offset list
				bw->Write((int)16);

				SelectedTask->Save(version, bw);

				bw->Close();
				fs->Close();

				Cursor = Windows::Forms::Cursors::Default;
			}
			catch(...)
			{
				MessageBox::Show("EXPORT ERROR!\nExporting item to binary file failed!");
				Cursor = Windows::Forms::Cursors::Default;
			}
		}
	}

#pragma endregion

#pragma region SELECTOR FUNCTIONS

	private: System::Void select_task(System::Object^  sender, System::Windows::Forms::TreeViewEventArgs^  e)
	{
		ArrayList^ task_index_path = gcnew ArrayList();
		TreeNode^ node = ((TreeView^)sender)->SelectedNode;
		while(node->Parent != nullptr)
		{
			task_index_path->Add(node->Index);
			node = node->Parent;
		}

		SelectedTask = Tasks[node->Index];
		
		for(int i=task_index_path->Count-1; i>=0; i--)
		{
			SelectedTask = SelectedTask->sub_quests[(int)task_index_path[i]];
		}

		// general
		textBox_id->Text = SelectedTask->ID.ToString();
		textBox_name->Text = SelectedTask->Name;
		checkBox_author_mode->Checked = SelectedTask->author_mode;
		textBox_author_text->Text = SelectedTask->AuthorText;
		textBox_unknown_01->Text = ByteArray_to_HexString(SelectedTask->UNKNOWN_01);
		comboBox_type->SelectedIndex = SelectedTask->type;
		textBox_time_limit->Text = SelectedTask->time_limit.ToString();
		checkBox_unknown_02->Checked = SelectedTask->UNKNOWN_02;
		checkBox_has_date_fail->Checked = SelectedTask->has_date_fail;
		dataGridView_date_fail->Rows->Clear();
		for(int r=0; r<1; r++)
		{
			try
			{
				dataGridView_date_fail->Rows->Add(gcnew array<String^>
				{
					SelectedTask->date_fail->year.ToString(),
					SelectedTask->date_fail->month.ToString(),
					SelectedTask->date_fail->day.ToString(),
					SelectedTask->date_fail->hour.ToString(),
					SelectedTask->date_fail->minute.ToString(),
					Column_date_fail_weekday->Items[SelectedTask->date_fail->weekday]->ToString()
				}
				);
			}
			catch(...)
			{
				MessageBox::Show("ERROR Loading Date Fail!");
			}
		}
		checkBox_unknown_03->Checked = SelectedTask->UNKNOWN_03;
		checkBox_has_date_spans->Checked = SelectedTask->has_date_spans;
		dataGridView_date_spans->Rows->Clear();
		for(int r=0; r<SelectedTask->date_spans->Length; r++)
		{
			try
			{
				dataGridView_date_spans->Rows->Add(gcnew array<String^>
				{
					SelectedTask->date_spans[r]->from->year.ToString(),
					SelectedTask->date_spans[r]->from->month.ToString(),
					SelectedTask->date_spans[r]->from->day.ToString(),
					SelectedTask->date_spans[r]->from->hour.ToString(),
					SelectedTask->date_spans[r]->from->minute.ToString(),
					Column6->Items[SelectedTask->date_spans[r]->from->weekday]->ToString(),
					"to",
					SelectedTask->date_spans[r]->to->year.ToString(),
					SelectedTask->date_spans[r]->to->month.ToString(),
					SelectedTask->date_spans[r]->to->day.ToString(),
					SelectedTask->date_spans[r]->to->hour.ToString(),
					SelectedTask->date_spans[r]->to->minute.ToString(),
					Column13->Items[SelectedTask->date_spans[r]->to->weekday]->ToString()
				}
				);
			}
			catch(...)
			{
				MessageBox::Show("ERROR Loading Date Span!");
			}
		}
		textBox_unknown_04->Text = ByteArray_to_HexString(SelectedTask->UNKNOWN_04);
		textBox_unknown_05->Text = ByteArray_to_HexString(SelectedTask->UNKNOWN_05);
		textBox_unknown_06->Text = ByteArray_to_HexString(SelectedTask->UNKNOWN_06);
		textBox_unknown_07->Text = ByteArray_to_HexString(SelectedTask->UNKNOWN_07);
		textBox_unknown_08->Text = SelectedTask->UNKNOWN_08.ToString();
		textBox_unknown_09->Text = SelectedTask->UNKNOWN_09.ToString();
		// flags
		checkBox_activate_first_subquest->Checked = SelectedTask->activate_first_subquest;
		checkBox_activate_random_subquest->Checked = SelectedTask->activate_random_subquest;
		checkBox_activate_next_subquest->Checked = SelectedTask->activate_next_subquest;
		checkBox_on_give_up_parent_fails->Checked = SelectedTask->on_give_up_parent_fails;
		checkBox_on_success_parent_success->Checked = SelectedTask->on_success_parent_success;
		checkBox_can_give_up->Checked = SelectedTask->can_give_up;
		checkBox_repeatable->Checked = SelectedTask->repeatable;
		checkBox_repeatable_after_failure->Checked = SelectedTask->repeatable_after_failure;
		checkBox_fail_on_death->Checked = SelectedTask->fail_on_death;
		checkBox_on_fail_parent_fail->Checked = SelectedTask->on_fail_parent_fail;
		checkBox_unknown_10->Checked = SelectedTask->UNKNOWN_10;
		textBox_player_limit->Text = SelectedTask->player_limit.ToString();
		// trigger locations
		checkBox_trigger_locations_has_spans->Checked = SelectedTask->trigger_locations->has_location;
		textBox_trigger_locations_map_id->Text = SelectedTask->trigger_locations->map_id.ToString();
		textBox_trigger_locations_unknown_1->Text = ByteArray_to_HexString(SelectedTask->trigger_locations->unknown_1);
		dataGridView_trigger_location_spans->Rows->Clear();
		for(int r=0; r<SelectedTask->trigger_locations->spans->Length; r++)
		{
			try
			{
				dataGridView_trigger_location_spans->Rows->Add(gcnew array<String^>
				{
					SelectedTask->trigger_locations->spans[r]->north.ToString("F3"),
					SelectedTask->trigger_locations->spans[r]->south.ToString("F3"),
					SelectedTask->trigger_locations->spans[r]->west.ToString("F3"),
					SelectedTask->trigger_locations->spans[r]->east.ToString("F3"),
					SelectedTask->trigger_locations->spans[r]->bottom.ToString("F3"),
					SelectedTask->trigger_locations->spans[r]->top.ToString("F3")
				}
				);
			}
			catch(...)
			{
				MessageBox::Show("ERROR Loading Trigger Location Span!");
			}
		}
		// fail locations
		checkBox_fail_locations_has_spans->Checked = SelectedTask->fail_locations->has_location;
		textBox_fail_locations_map_id->Text = SelectedTask->fail_locations->map_id.ToString();
		textBox_fail_locations_unknown_1->Text = ByteArray_to_HexString(SelectedTask->fail_locations->unknown_1);
		dataGridView_fail_location_spans->Rows->Clear();
		for(int r=0; r<SelectedTask->fail_locations->spans->Length; r++)
		{
			try
			{
				dataGridView_fail_location_spans->Rows->Add(gcnew array<String^>
				{
					SelectedTask->fail_locations->spans[r]->north.ToString("F3"),
					SelectedTask->fail_locations->spans[r]->south.ToString("F3"),
					SelectedTask->fail_locations->spans[r]->west.ToString("F3"),
					SelectedTask->fail_locations->spans[r]->east.ToString("F3"),
					SelectedTask->fail_locations->spans[r]->bottom.ToString("F3"),
					SelectedTask->fail_locations->spans[r]->top.ToString("F3")
				}
				);
			}
			catch(...)
			{
				MessageBox::Show("ERROR Loading Fail Location Span!");
			}
		}
		// valid locations
		checkBox_valid_locations_has_spans->Checked = SelectedTask->valid_locations->has_location;
		textBox_valid_locations_map_id->Text = SelectedTask->valid_locations->map_id.ToString();
		textBox_valid_locations_unknown_1->Text = ByteArray_to_HexString(SelectedTask->valid_locations->unknown_1);
		dataGridView_valid_location_spans->Rows->Clear();
		for(int r=0; r<SelectedTask->valid_locations->spans->Length; r++)
		{
			try
			{
				dataGridView_valid_location_spans->Rows->Add(gcnew array<String^>
				{
					SelectedTask->valid_locations->spans[r]->north.ToString("F3"),
					SelectedTask->valid_locations->spans[r]->south.ToString("F3"),
					SelectedTask->valid_locations->spans[r]->west.ToString("F3"),
					SelectedTask->valid_locations->spans[r]->east.ToString("F3"),
					SelectedTask->valid_locations->spans[r]->bottom.ToString("F3"),
					SelectedTask->valid_locations->spans[r]->top.ToString("F3")
				}
				);
			}
			catch(...)
			{
				MessageBox::Show("ERROR Loading Valid Location Span!");
			}
		}
		// basic I
		checkBox_unknown_17->Checked = SelectedTask->UNKNOWN_17;
		checkBox_has_instant_teleport->Checked = SelectedTask->has_instant_teleport;
		textBox_instant_teleport_location_map_id->Text = SelectedTask->instant_teleport_location->map_id.ToString();
		textBox_instant_teleport_location_x->Text = SelectedTask->instant_teleport_location->x.ToString("F3");
		textBox_instant_teleport_location_alt->Text = SelectedTask->instant_teleport_location->altitude.ToString("F3");
		textBox_instant_teleport_location_z->Text = SelectedTask->instant_teleport_location->z.ToString("F3");
		textBox_ai_trigger->Text = SelectedTask->ai_trigger.ToString();
		checkBox_unknown_18->Checked = SelectedTask->UNKNOWN_18;
		checkBox_unknown_19->Checked = SelectedTask->UNKNOWN_19;
		checkBox_unknown_20->Checked = SelectedTask->UNKNOWN_20;
		checkBox_unknown_21->Checked = SelectedTask->UNKNOWN_21;
		checkBox_unknown_22->Checked = SelectedTask->UNKNOWN_22;
		checkBox_unknown_23->Checked = SelectedTask->UNKNOWN_23;
		textBox_unknown_level->Text = SelectedTask->UNKNOWN_LEVEL.ToString();
		checkBox_mark_available_icon->Checked = SelectedTask->mark_available_icon;
		checkBox_mark_available_point->Checked = SelectedTask->mark_available_point;
		textBox_quest_npc->Text = SelectedTask->quest_npc.ToString();
		textBox_reward_npc->Text = SelectedTask->reward_npc.ToString();
		checkBox_craft_skill->Checked = SelectedTask->craft_skill;
		checkBox_unknown_24->Checked = SelectedTask->UNKNOWN_24;
		checkBox_unknown_25->Checked = SelectedTask->UNKNOWN_25;
		checkBox_unknown_26->Checked = SelectedTask->UNKNOWN_26;
		textBox_unknown_26_01->Text = ByteArray_to_HexString(SelectedTask->UNKNOWN_26_01);
		textBox_level_min->Text = SelectedTask->level_min.ToString();
		textBox_level_max->Text = SelectedTask->level_max.ToString();
		//
		checkBox_unknown_27->Checked = SelectedTask->UNKNOWN_27;
		// required items
		dataGridView_required_items->Rows->Clear();
		for(int r=0; r<SelectedTask->required_items->Length; r++)
		{
			try
			{
				dataGridView_required_items->Rows->Add(gcnew array<String^>
				{
					SelectedTask->required_items[r]->id.ToString(),
					SelectedTask->required_items[r]->unknown.ToString(),
					SelectedTask->required_items[r]->amount.ToString(),
					SelectedTask->required_items[r]->probability.ToString("F6"),
					SelectedTask->required_items[r]->expiration.ToString()
				}
				);
			}
			catch(...)
			{
				MessageBox::Show("ERROR Loading Required Items!");
			}
		}
		textBox_required_items_unknown->Text = ByteArray_to_HexString(SelectedTask->required_items_unknown);
		//
		checkBox_unknown_28->Checked = SelectedTask->UNKNOWN_28;
		checkBox_unknown_28_01->Checked = SelectedTask->UNKNOWN_28_01;
		// given items
		dataGridView_given_items->Rows->Clear();
		for(int r=0; r<SelectedTask->given_items->Length; r++)
		{
			try
			{
				dataGridView_given_items->Rows->Add(gcnew array<String^>
				{
					SelectedTask->given_items[r]->id.ToString(),
					SelectedTask->given_items[r]->unknown.ToString(),
					SelectedTask->given_items[r]->amount.ToString(),
					SelectedTask->given_items[r]->probability.ToString("F6"),
					SelectedTask->given_items[r]->expiration.ToString()
				}
				);
			}
			catch(...)
			{
				MessageBox::Show("ERROR Loading Given Items!");
			}
		}
		textBox_unknown_29->Text = SelectedTask->UNKNOWN_29.ToString();
		textBox_unknown_30->Text = SelectedTask->UNKNOWN_30.ToString();
		textBox_given_items_unknown->Text = ByteArray_to_HexString(SelectedTask->given_items_unknown);
		//
		textBox_instant_pay_coins->Text = SelectedTask->instant_pay_coins.ToString();
		checkBox_unknown_31->Checked = SelectedTask->UNKNOWN_31;
		textBox_required_reputation->Text = SelectedTask->required_reputation.ToString();
		textBox_unknown_32->Text = ByteArray_to_HexString(SelectedTask->UNKNOWN_32);
		checkBox_unknown_33->Checked = SelectedTask->UNKNOWN_33;
		textBox_required_quests_done_1->Text = SelectedTask->required_quests_done[0].ToString();
		textBox_required_quests_done_2->Text = SelectedTask->required_quests_done[1].ToString();
		textBox_required_quests_done_3->Text = SelectedTask->required_quests_done[2].ToString();
		textBox_required_quests_done_4->Text = SelectedTask->required_quests_done[3].ToString();
		textBox_required_quests_done_5->Text = SelectedTask->required_quests_done[4].ToString();
		textBox_unknown_34->Text = ByteArray_to_HexString(SelectedTask->UNKNOWN_34);
		checkBox_unknown_35->Checked = SelectedTask->UNKNOWN_35;
		textBox_unknown_36->Text = SelectedTask->UNKNOWN_36.ToString();
		switch(SelectedTask->required_cultivation)
		{
			case 0:		comboBox_required_cultivation->SelectedIndex = 0;
						break;
			case 1:		comboBox_required_cultivation->SelectedIndex = 1;
						break;
			case 2:		comboBox_required_cultivation->SelectedIndex = 2;
						break;
			case 3:		comboBox_required_cultivation->SelectedIndex = 3;
						break;
			case 4:		comboBox_required_cultivation->SelectedIndex = 4;
						break;
			case 5:		comboBox_required_cultivation->SelectedIndex = 5;
						break;
			case 6:		comboBox_required_cultivation->SelectedIndex = 6;
						break;
			case 7:		comboBox_required_cultivation->SelectedIndex = 7;
						break;
			case 8:		comboBox_required_cultivation->SelectedIndex = 8;
						break;
			case 20:	comboBox_required_cultivation->SelectedIndex = 9;
						break;
			case 30:	comboBox_required_cultivation->SelectedIndex = 10;
						break;
			case 21:	comboBox_required_cultivation->SelectedIndex = 11;
						break;
			case 31:	comboBox_required_cultivation->SelectedIndex = 12;
						break;
			case 22:	comboBox_required_cultivation->SelectedIndex = 13;
						break;
			case 32:	comboBox_required_cultivation->SelectedIndex = 14;
						break;
		}
		textBox_unknown_37->Text = ByteArray_to_HexString(SelectedTask->UNKNOWN_37);
		textBox_unknown_38->Text = SelectedTask->UNKNOWN_38.ToString();
		checkBox_unknown_39->Checked = SelectedTask->UNKNOWN_39;
		comboBox_required_gender->SelectedIndex = SelectedTask->required_gender;
		checkBox_unknown_40->Checked = SelectedTask->UNKNOWN_40;
		checkBox_unknown_41->Checked = SelectedTask->UNKNOWN_41;
		checkBox_required_be_married->Checked = SelectedTask->required_be_married;
		checkBox_unknown_42->Checked = SelectedTask->UNKNOWN_42;
		checkBox_unknown_42_1->Checked = SelectedTask->UNKNOWN_42_1;
		checkBox_unknown_42_2->Checked = SelectedTask->UNKNOWN_42_2;
		checkBox_required_be_gm->Checked = SelectedTask->required_be_gm;
		checkBox_unknown_43->Checked = SelectedTask->UNKNOWN_43;
		// occupations
		this->checkBox_occupation_blademaster->CheckedChanged -= gcnew System::EventHandler(this, &MainWindow::change_required_occupations);
		this->checkBox_occupation_wizard->CheckedChanged -= gcnew System::EventHandler(this, &MainWindow::change_required_occupations);
		this->checkBox_occupation_psychic->CheckedChanged -= gcnew System::EventHandler(this, &MainWindow::change_required_occupations);
		this->checkBox_occupation_venomancer->CheckedChanged -= gcnew System::EventHandler(this, &MainWindow::change_required_occupations);
		this->checkBox_occupation_barbarian->CheckedChanged -= gcnew System::EventHandler(this, &MainWindow::change_required_occupations);
		this->checkBox_occupation_assassin->CheckedChanged -= gcnew System::EventHandler(this, &MainWindow::change_required_occupations);
		this->checkBox_occupation_archer->CheckedChanged -= gcnew System::EventHandler(this, &MainWindow::change_required_occupations);
		this->checkBox_occupation_cleric->CheckedChanged -= gcnew System::EventHandler(this, &MainWindow::change_required_occupations);
		this->checkBox_occupation_seeker->CheckedChanged -= gcnew System::EventHandler(this, &MainWindow::change_required_occupations);
		this->checkBox_occupation_mystic->CheckedChanged -= gcnew System::EventHandler(this, &MainWindow::change_required_occupations);
		checkBox_occupation_blademaster->Checked = false;
		checkBox_occupation_wizard->Checked = false;
		checkBox_occupation_psychic->Checked = false;
		checkBox_occupation_venomancer->Checked = false;
		checkBox_occupation_barbarian->Checked = false;
		checkBox_occupation_assassin->Checked = false;
		checkBox_occupation_archer->Checked = false;
		checkBox_occupation_cleric->Checked = false;
		checkBox_occupation_seeker->Checked = false;
		checkBox_occupation_mystic->Checked = false;
		if(Array::IndexOf(SelectedTask->required_occupations, 0) < SelectedTask->required_occupations_count && Array::IndexOf(SelectedTask->required_occupations, 0) > -1){ checkBox_occupation_blademaster->Checked = true; }
		if(Array::IndexOf(SelectedTask->required_occupations, 1) < SelectedTask->required_occupations_count && Array::IndexOf(SelectedTask->required_occupations, 1) > -1){ checkBox_occupation_wizard->Checked = true; }
		if(Array::IndexOf(SelectedTask->required_occupations, 2) < SelectedTask->required_occupations_count && Array::IndexOf(SelectedTask->required_occupations, 2) > -1){ checkBox_occupation_psychic->Checked = true; }
		if(Array::IndexOf(SelectedTask->required_occupations, 3) < SelectedTask->required_occupations_count && Array::IndexOf(SelectedTask->required_occupations, 3) > -1){ checkBox_occupation_venomancer->Checked = true; }
		if(Array::IndexOf(SelectedTask->required_occupations, 4) < SelectedTask->required_occupations_count && Array::IndexOf(SelectedTask->required_occupations, 4) > -1){ checkBox_occupation_barbarian->Checked = true; }
		if(Array::IndexOf(SelectedTask->required_occupations, 5) < SelectedTask->required_occupations_count && Array::IndexOf(SelectedTask->required_occupations, 5) > -1){ checkBox_occupation_assassin->Checked = true; }
		if(Array::IndexOf(SelectedTask->required_occupations, 6) < SelectedTask->required_occupations_count && Array::IndexOf(SelectedTask->required_occupations, 6) > -1){ checkBox_occupation_archer->Checked = true; }
		if(Array::IndexOf(SelectedTask->required_occupations, 7) < SelectedTask->required_occupations_count && Array::IndexOf(SelectedTask->required_occupations, 7) > -1){ checkBox_occupation_cleric->Checked = true; }
		if(Array::IndexOf(SelectedTask->required_occupations, 7) < SelectedTask->required_occupations_count && Array::IndexOf(SelectedTask->required_occupations, 8) > -1){ checkBox_occupation_seeker->Checked = true; }
		if(Array::IndexOf(SelectedTask->required_occupations, 7) < SelectedTask->required_occupations_count && Array::IndexOf(SelectedTask->required_occupations, 9) > -1){ checkBox_occupation_mystic->Checked = true; }
		this->checkBox_occupation_blademaster->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_required_occupations);
		this->checkBox_occupation_wizard->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_required_occupations);
		this->checkBox_occupation_psychic->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_required_occupations);
		this->checkBox_occupation_venomancer->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_required_occupations);
		this->checkBox_occupation_barbarian->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_required_occupations);
		this->checkBox_occupation_assassin->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_required_occupations);
		this->checkBox_occupation_archer->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_required_occupations);
		this->checkBox_occupation_cleric->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_required_occupations);
		this->checkBox_occupation_seeker->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_required_occupations);
		this->checkBox_occupation_mystic->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::change_required_occupations);
		//
		textBox_unknown_44->Text = ByteArray_to_HexString(SelectedTask->UNKNOWN_44);
		// date unknown
		dataGridView_date_unknown->Rows->Clear();
		for(int r=0; r<1; r++)
		{
			try
			{
				dataGridView_date_unknown->Rows->Add(gcnew array<String^>
				{
					SelectedTask->date_unknown->year.ToString(),
					SelectedTask->date_unknown->month.ToString(),
					SelectedTask->date_unknown->day.ToString(),
					SelectedTask->date_unknown->hour.ToString(),
					SelectedTask->date_unknown->minute.ToString(),
					Column_date_unknown_weekday->Items[SelectedTask->date_unknown->weekday]->ToString()
				}
				);
			}
			catch(...)
			{
				MessageBox::Show("ERROR Loading Date Unknown!");
			}
		}
		textBox_unknown_45->Text = SelectedTask->UNKNOWN_45.ToString();
		checkBox_unknown_46->Checked = SelectedTask->UNKNOWN_46;
		textBox_unknown_47->Text = ByteArray_to_HexString(SelectedTask->UNKNOWN_47);
		// quests undone
		textBox_required_quests_undone_1->Text = SelectedTask->required_quests_undone[0].ToString();
		textBox_required_quests_undone_2->Text = SelectedTask->required_quests_undone[1].ToString();
		textBox_required_quests_undone_3->Text = SelectedTask->required_quests_undone[2].ToString();
		textBox_required_quests_undone_4->Text = SelectedTask->required_quests_undone[3].ToString();
		textBox_required_quests_undone_5->Text = SelectedTask->required_quests_undone[4].ToString();
		// skill levels
		textBox_required_blacksmith_level->Text = SelectedTask->required_blacksmith_level.ToString();
		textBox_required_tailor_level->Text = SelectedTask->required_tailor_level.ToString();
		textBox_required_craftsman_level->Text = SelectedTask->required_craftsman_level.ToString();
		textBox_required_apothecary_level->Text = SelectedTask->required_apothecary_level.ToString();
		//
		textBox_unknown_48->Text = ByteArray_to_HexString(SelectedTask->UNKNOWN_48);
		textBox_unknown_49->Text = ByteArray_to_HexString(SelectedTask->UNKNOWN_49);
		// team members
		dataGridView_team_members->Rows->Clear();
		for(int r=0; r<SelectedTask->required_team_member_groups->Length; r++)
		{
			try
			{
				dataGridView_team_members->Rows->Add(gcnew array<String^>
				{
					SelectedTask->required_team_member_groups[r]->level_min.ToString(),
					SelectedTask->required_team_member_groups[r]->level_max.ToString(),
					SelectedTask->required_team_member_groups[r]->unknown_1.ToString(),
					SelectedTask->required_team_member_groups[r]->unknown_2.ToString(),
					SelectedTask->required_team_member_groups[r]->unknown_3.ToString(),
					SelectedTask->required_team_member_groups[r]->amount_min.ToString(),
					SelectedTask->required_team_member_groups[r]->amount_max.ToString(),
					SelectedTask->required_team_member_groups[r]->quest.ToString(),
					Column18->Items[Math::Max(0, SelectedTask->required_team_member_groups[r]->force-1003)]->ToString()
				}
				);
			}
			catch(...)
			{
				MessageBox::Show("ERROR Loading Team Members!");
			}
		}
		//
		textBox_unknown_50->Text = ByteArray_to_HexString(SelectedTask->UNKNOWN_50);
		checkBox_unknown_51->Checked = SelectedTask->UNKNOWN_51;
		textBox_unknown_52->Text = ByteArray_to_HexString(SelectedTask->UNKNOWN_52);
		textBox_resource_pq_audit_id->Text = SelectedTask->resource_pq_audit_id.ToString();
		textBox_unknown_53->Text = SelectedTask->UNKNOWN_53.ToString();
		textBox_unknown_54->Text = SelectedTask->UNKNOWN_54.ToString();
		textBox_required_pq_contribution->Text = SelectedTask->required_pq_contribution.ToString();
		textBox_unknown_55->Text = ByteArray_to_HexString(SelectedTask->UNKNOWN_55);
		textBox_unknown_55_02_01->Text = ByteArray_to_HexString(SelectedTask->UNKNOWN_55_02_01);
		comboBox_required_force->SelectedIndex = Math::Max(0, SelectedTask->required_force-1003);
		textBox_unknown_55_02_02->Text = ByteArray_to_HexString(SelectedTask->UNKNOWN_55_02_02);
		textBox_required_prestige->Text = SelectedTask->required_prestige.ToString();
		textBox_unknown_55_03->Text = ByteArray_to_HexString(SelectedTask->UNKNOWN_55_03);
		textBox_required_influence_fee->Text = SelectedTask->required_influence_fee.ToString();
		textBox_unknown_55_04->Text = ByteArray_to_HexString(SelectedTask->UNKNOWN_55_04);
		textBox_unknown_55_05->Text = ByteArray_to_HexString(SelectedTask->UNKNOWN_55_05);
		textBox_unknown_55_06->Text = ByteArray_to_HexString(SelectedTask->UNKNOWN_55_06);
		textBox_required_success_type->Text = SelectedTask->required_success_type.ToString();
		textBox_required_npc_type->Text = SelectedTask->required_npc_type.ToString();
		// morai pk
		dataGridView_required_morai_pk->Rows->Clear();
		for(int r=0; r<SelectedTask->required_morai_pk->Length; r++)
		{
			try
			{
				dataGridView_required_morai_pk->Rows->Add(gcnew array<String^>
				{
					SelectedTask->required_morai_pk[r]->unknown_1.ToString(),
					SelectedTask->required_morai_pk[r]->unknown_2.ToString(),
					SelectedTask->required_morai_pk[r]->unknown_3.ToString(),
					SelectedTask->required_morai_pk[r]->unknown_4.ToString(),
					SelectedTask->required_morai_pk[r]->probability.ToString("F6"),
					SelectedTask->required_morai_pk[r]->class_mask.ToString(),
					SelectedTask->required_morai_pk[r]->level_min.ToString(),
					SelectedTask->required_morai_pk[r]->level_max.ToString(),
					SelectedTask->required_morai_pk[r]->unknown_5.ToString(),
					Column28->Items[SelectedTask->required_morai_pk[r]->type]->ToString()
				}
				);
			}
			catch(...)
			{
				MessageBox::Show("ERROR Loading Morai PK!");
			}
		}
		textBox_required_morai_pk_unknown->Text = ByteArray_to_HexString(SelectedTask->required_morai_pk_unknown);
		// chases
		dataGridView_required_chases->Rows->Clear();
		for(int r=0; r<SelectedTask->required_chases->Length; r++)
		{
			try
			{
				dataGridView_required_chases->Rows->Add(gcnew array<String^>
				{
					SelectedTask->required_chases[r]->id_monster.ToString(),
					SelectedTask->required_chases[r]->amount_monster.ToString(),
					SelectedTask->required_chases[r]->id_drop.ToString(),
					SelectedTask->required_chases[r]->amount_drop.ToString(),
					SelectedTask->required_chases[r]->unknown_1.ToString(),
					SelectedTask->required_chases[r]->probability.ToString("F6"),
					SelectedTask->required_chases[r]->unknown_2.ToString(),
					ByteArray_to_HexString(SelectedTask->required_chases[r]->unknown_3)
				}
				);
			}
			catch(...)
			{
				MessageBox::Show("ERROR Loading Chases!");
			}
		}
		textBox_required_chases_unknown->Text = ByteArray_to_HexString(SelectedTask->required_chases_unknown);
		// get items
		dataGridView_required_get_items->Rows->Clear();
		for(int r=0; r<SelectedTask->required_get_items->Length; r++)
		{
			try
			{
				dataGridView_required_get_items->Rows->Add(gcnew array<String^>
				{
					SelectedTask->required_get_items[r]->id.ToString(),
					SelectedTask->required_get_items[r]->unknown.ToString(),
					SelectedTask->required_get_items[r]->amount.ToString(),
					SelectedTask->required_get_items[r]->probability.ToString("F6"),
					SelectedTask->required_get_items[r]->expiration.ToString()
				}
				);
			}
			catch(...)
			{
				MessageBox::Show("ERROR Loading Get Items!");
			}
		}
		textBox_required_get_items_unknown->Text = ByteArray_to_HexString(SelectedTask->required_get_items_unknown);
		//
		textBox_required_coins->Text = SelectedTask->required_coins.ToString();
		textBox_unknown_56->Text = ByteArray_to_HexString(SelectedTask->UNKNOWN_56);
		textBox_unknown_57->Text = ByteArray_to_HexString(SelectedTask->UNKNOWN_57);
		// reach locations
		checkBox_reach_locations_has_spans->Checked = SelectedTask->reach_locations->has_location;
		textBox_reach_locations_map_id->Text = SelectedTask->reach_locations->map_id.ToString();
		textBox_reach_locations_unknown_1->Text = ByteArray_to_HexString(SelectedTask->reach_locations->unknown_1);
		dataGridView_reach_location_spans->Rows->Clear();
		for(int r=0; r<SelectedTask->reach_locations->spans->Length; r++)
		{
			try
			{
				dataGridView_reach_location_spans->Rows->Add(gcnew array<String^>
				{
					SelectedTask->reach_locations->spans[r]->north.ToString("F3"),
					SelectedTask->reach_locations->spans[r]->south.ToString("F3"),
					SelectedTask->reach_locations->spans[r]->west.ToString("F3"),
					SelectedTask->reach_locations->spans[r]->east.ToString("F3"),
					SelectedTask->reach_locations->spans[r]->bottom.ToString("F3"),
					SelectedTask->reach_locations->spans[r]->top.ToString("F3")
				}
				);
			}
			catch(...)
			{
				MessageBox::Show("ERROR Loading Reach Location Span!");
			}
		}
		//
		textBox_required_wait_time->Text = SelectedTask->required_wait_time.ToString();
		textBox_unknown_57_01->Text = ByteArray_to_HexString(SelectedTask->UNKNOWN_57_01);
		// pq script infos
		dataGridView_pq_script_infos->Rows->Clear();
		for(int r=0; r<SelectedTask->pq->script_infos->Length; r++)
		{
			try
			{
				dataGridView_pq_script_infos->Rows->Add(gcnew array<String^>
				{
					SelectedTask->pq->script_infos[r]->id.ToString(),
					SelectedTask->pq->script_infos[r]->unknown_1.ToString(),
					ByteArray_to_HexString(SelectedTask->pq->script_infos[r]->unknown_2)
				}
				);
			}
			catch(...)
			{
				MessageBox::Show("ERROR Loading PQ Script Infos!");
			}
		}
		textBox_pq_unknown_1->Text = ByteArray_to_HexString(SelectedTask->pq->unknown_1);
		textBox_pq_unknown_2->Text = SelectedTask->pq->unknown_2.ToString();
		textBox_pq_unknown_3->Text = ByteArray_to_HexString(SelectedTask->pq->unknown_3);
		// pq scripts
		dataGridView_pq_scripts->Rows->Clear();
		for(int r=0; r<SelectedTask->pq->scripts->Length; r++)
		{
			try
			{
				dataGridView_pq_scripts->Rows->Add(gcnew array<String^>
				{
					SelectedTask->pq->scripts[r]->Name,
					SelectedTask->pq->scripts[r]->count.ToString(),
					SelectedTask->pq->scripts[r]->id.ToString(),
					ByteArray_to_HexString(SelectedTask->pq->scripts[r]->seperator),
					SelectedTask->pq->scripts[r]->reference_id.ToString("F0"),
					SelectedTask->pq->scripts[r]->Code
				}
				);
			}
			catch(...)
			{
				MessageBox::Show("ERROR Loading PQ Scripts!");
			}
		}
		textBox_pq_unknown_4->Text = ByteArray_to_HexString(SelectedTask->pq->unknown_4);
		textBox_pq_unknown_5->Text = ByteArray_to_HexString(SelectedTask->pq->unknown_5);
		textBox_pq_unknown_6->Text = ByteArray_to_HexString(SelectedTask->pq->unknown_6);
		// pq chases
		dataGridView_pq_chases->Rows->Clear();
		for(int r=0; r<SelectedTask->pq->chases->Length; r++)
		{
			try
			{
				dataGridView_pq_chases->Rows->Add(gcnew array<String^>
				{
					SelectedTask->pq->chases[r]->id_monster.ToString(),
					SelectedTask->pq->chases[r]->amount_1.ToString(),
					SelectedTask->pq->chases[r]->contribution.ToString(),
					SelectedTask->pq->chases[r]->amount_3.ToString()
				}
				);
			}
			catch(...)
			{
				MessageBox::Show("ERROR Loading PQ Chases!");
			}
		}
		textBox_pq_unknown_7->Text = ByteArray_to_HexString(SelectedTask->pq->unknown_7);
		textBox_pq_required_quests_completed->Text = SelectedTask->pq->required_quests_completed.ToString();
		textBox_pq_unknown_8->Text = ByteArray_to_HexString(SelectedTask->pq->unknown_8);
		textBox_pq_unknown_9->Text = ByteArray_to_HexString(SelectedTask->pq->unknown_9);
		textBox_pq_unknown_10->Text = ByteArray_to_HexString(SelectedTask->pq->unknown_10);
		textBox_pq_unknown_11->Text = ByteArray_to_HexString(SelectedTask->pq->unknown_11);
		// pq locations
		checkBox_pq_location_has_spans->Checked = SelectedTask->pq->location->has_location;
		textBox_pq_location_map_id->Text = SelectedTask->pq->location->map_id.ToString();
		textBox_pq_location_unknown_1->Text = ByteArray_to_HexString(SelectedTask->pq->location->unknown_1);
		dataGridView_pq_location_spans->Rows->Clear();
		for(int r=0; r<SelectedTask->pq->location->spans->Length; r++)
		{
			try
			{
				dataGridView_pq_location_spans->Rows->Add(gcnew array<String^>
				{
					SelectedTask->pq->location->spans[r]->north.ToString("F3"),
					SelectedTask->pq->location->spans[r]->south.ToString("F3"),
					SelectedTask->pq->location->spans[r]->west.ToString("F3"),
					SelectedTask->pq->location->spans[r]->east.ToString("F3"),
					SelectedTask->pq->location->spans[r]->bottom.ToString("F3"),
					SelectedTask->pq->location->spans[r]->top.ToString("F3")
				}
				);
			}
			catch(...)
			{
				MessageBox::Show("ERROR Loading PQ Location Span!");
			}
		}
		textBox_pq_unknown_12->Text = SelectedTask->pq->unknown_12.ToString();
		textBox_pq_unknown_13->Text = ByteArray_to_HexString(SelectedTask->pq->unknown_13);
		textBox_pq_id_script->Text = SelectedTask->pq->id_script.ToString();
		textBox_pq_unknown_14->Text = SelectedTask->pq->unknown_14.ToString();
		textBox_pq_unknown_15->Text = SelectedTask->pq->unknown_15.ToString();
		textBox_pq_unknown_16->Text = SelectedTask->pq->unknown_16.ToString();
		textBox_pq_unknown_17->Text = ByteArray_to_HexString(SelectedTask->pq->unknown_17);
		// pq special scripts
		dataGridView_pq_special_scripts->Rows->Clear();
		for(int r=0; r<SelectedTask->pq->special_scripts->Length; r++)
		{
			try
			{
				dataGridView_pq_special_scripts->Rows->Add(gcnew array<String^>
				{
					SelectedTask->pq->special_scripts[r]->Name,
					SelectedTask->pq->special_scripts[r]->count.ToString(),
					SelectedTask->pq->special_scripts[r]->id.ToString(),
					ByteArray_to_HexString(SelectedTask->pq->special_scripts[r]->seperator),
					SelectedTask->pq->special_scripts[r]->reference_id.ToString("F0"),
					SelectedTask->pq->special_scripts[r]->Code
				}
				);
			}
			catch(...)
			{
				MessageBox::Show("ERROR Loading Special Scripts!");
			}
		}
		textBox_pq_unknown_18->Text = ByteArray_to_HexString(SelectedTask->pq->unknown_18);
		textBox_pq_unknown_19->Text = ByteArray_to_HexString(SelectedTask->pq->unknown_19);
		// pq messages
		dataGridView_pq_messages->Rows->Clear();
		for(int r=0; r<SelectedTask->pq->messages->Length; r++)
		{
			try
			{
				dataGridView_pq_messages->Rows->Add(gcnew array<String^>
				{
					ByteArray_to_UnicodeString(SelectedTask->pq->messages[r])
				}
				);
			}
			catch(...)
			{
				MessageBox::Show("ERROR Loading PQ Message!");
			}
		}
		textBox_pq_unknown_20->Text = ByteArray_to_HexString(SelectedTask->pq->unknown_20);
		//
		textBox_unknown_58->Text = ByteArray_to_HexString(SelectedTask->UNKNOWN_58);
		textBox_unknown_59->Text = ByteArray_to_HexString(SelectedTask->UNKNOWN_59);
		//
		textBox_parent_quest->Text = SelectedTask->parent_quest.ToString();
		textBox_previous_quest->Text = SelectedTask->previous_quest.ToString();
		textBox_next_quest->Text = SelectedTask->next_quest.ToString();
		textBox_sub_quest_first->Text = SelectedTask->sub_quest_first.ToString();
		//
		checkBox_unknown_60->Checked = SelectedTask->UNKNOWN_60;
		textBox_receive_quest_probability->Text = SelectedTask->receive_quest_probability.ToString("F3");
		checkBox_unknown_60_01->Checked = SelectedTask->UNKNOWN_60_01;
		// reward
		listBox_reward_timed->Items->Clear();
		for(int i=0; i<SelectedTask->rewards_timed->Length; i++)
		{
			listBox_reward_timed->Items->Add("Success Time [sec]: " + (SelectedTask->time_limit*SelectedTask->rewards_timed_factors[i]));
		}
		select_reward(nullptr, nullptr);
		//
		textBox_unknown_61->Text = ByteArray_to_HexString(SelectedTask->UNKNOWN_61);
		// conversation
		textBox_conversation_prompt_text->Text = SelectedTask->conversation->PromptText;
		textBox_conversation_general_text->Text = SelectedTask->conversation->GeneralText;
		// answers
		textBox_conversation_answer_text->Clear();
		textBox_conversation_answer_question_link->Clear();
		textBox_conversation_answer_task_link->Clear();
		listBox_conversation_answers->Items->Clear();
		// questions
		textBox_conversation_question_text->Clear();
		textBox_conversation_question_id->Clear();
		textBox_conversation_question_previous->Clear();
		listBox_conversation_questions->Items->Clear();
		// dialog
		textBox_conversation_dialog_text->Clear();
		textBox_conversation_dialog_unknown->Clear();
		listBox_conversation_dialogs->SelectedIndex = -1;
	}
	private: System::Void select_reward(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			SelectedReward = nullptr;

			if(radioButton_success->Checked)
			{
				listBox_reward_timed->Enabled = false;
				numericUpDown_time_factor->Enabled = false;
				numericUpDown_time_factor->Value = 0;
				SelectedReward = SelectedTask->reward_success;
			}
			if(radioButton_failed->Checked)
			{
				listBox_reward_timed->Enabled = false;
				numericUpDown_time_factor->Enabled = false;
				numericUpDown_time_factor->Value = 0;
				SelectedReward = SelectedTask->reward_failed;
			}
			if(radioButton_timed->Checked)
			{
				listBox_reward_timed->Enabled = true;
				numericUpDown_time_factor->Enabled = true;
				if(listBox_reward_timed->SelectedIndex>-1)
				{
					SelectedReward = SelectedTask->rewards_timed[listBox_reward_timed->SelectedIndex];
					numericUpDown_time_factor->Value = Convert::ToDecimal(SelectedTask->rewards_timed_factors[listBox_reward_timed->SelectedIndex]);
				}
				else
				{
					numericUpDown_time_factor->Value = 0;
				}
			}

			if(SelectedReward)
			{
				textBox_reward_coins->Text = SelectedReward->coins.ToString();
				textBox_reward_experience->Text = SelectedReward->experience.ToString();
				textBox_reward_new_quest->Text = SelectedReward->new_quest.ToString();
				textBox_reward_spirit->Text = SelectedReward->spirit.ToString();
				textBox_reward_reputation->Text = SelectedReward->reputation.ToString();
				textBox_reward_cultivation->Text = SelectedReward->cultivation.ToString();
				textBox_reward_new_waypoint->Text = SelectedReward->new_waypoint.ToString();
				textBox_reward_storage_slots->Text = SelectedReward->storage_slots.ToString();
				textBox_reward_cupboard_slots->Text = SelectedReward->cupboard_slots.ToString();
				textBox_reward_wardrobe_slots->Text = SelectedReward->wardrobe_slots.ToString();
				textBox_reward_account_stash_slots->Text = SelectedReward->account_stash_slots.ToString();
				textBox_reward_inventory_slots->Text = SelectedReward->inventory_slots.ToString();
				textBox_reward_petbag_slots->Text = SelectedReward->petbag_slots.ToString();
				textBox_reward_vigor->Text = SelectedReward->vigor.ToString();
				textBox_reward_teleport_map_id->Text = SelectedReward->teleport->map_id.ToString();
				textBox_reward_teleport_x->Text = SelectedReward->teleport->x.ToString("F1");
				textBox_reward_teleport_altitude->Text = SelectedReward->teleport->altitude.ToString("F1");
				textBox_reward_teleport_z->Text = SelectedReward->teleport->z.ToString("F1");
				textBox_reward_ai_trigger->Text = SelectedReward->ai_trigger.ToString();
				textBox_reward_unknown_2a->Text = ByteArray_to_HexString(SelectedReward->UNKNOWN_2a);
				textBox_reward_unknown_2b->Text = ByteArray_to_HexString(SelectedReward->UNKNOWN_2b);
				textBox_reward_seperator->Text = ByteArray_to_HexString(SelectedReward->SEPERATOR);

				// pq chases
				dataGridView_reward_pq_chases->Rows->Clear();
				for(int r=0; r<SelectedReward->pq->chases->Length; r++)
				{
					try
					{
						dataGridView_reward_pq_chases->Rows->Add(gcnew array<String^>
						{
							SelectedReward->pq->chases[r]->id_monster.ToString(),
							SelectedReward->pq->chases[r]->amount_monster.ToString(),
							SelectedReward->pq->chases[r]->probability.ToString("F3"),
							SelectedReward->pq->chases[r]->amount_unknown.ToString()
						}
						);
					}
					catch(...)
					{
						MessageBox::Show("ERROR Loading Reward PQ Chases!");
					}
				}
				textBox_reward_pq_unknown_0->Text = ByteArray_to_HexString(SelectedReward->pq->unknown_0);
				textBox_reward_pq_event_gold->Text = SelectedReward->pq->event_gold.ToString();
				textBox_reward_pq_unknown_1->Text = ByteArray_to_HexString(SelectedReward->pq->unknown_1);
				textBox_reward_pq_unknown_quest->Text = SelectedReward->pq->unknown_quest.ToString();
				textBox_reward_pq_unknown_2->Text = ByteArray_to_HexString(SelectedReward->pq->unknown_2);
				textBox_reward_pq_unknown_level->Text = SelectedReward->pq->unknown_level.ToString();
				textBox_reward_pq_contribution_random_min->Text = SelectedReward->pq->contribution_random_min.ToString();
				textBox_reward_pq_contribution_random_max->Text = SelectedReward->pq->contribution_random_max.ToString();
				textBox_reward_pq_contribution_required->Text = SelectedReward->pq->contribution_required.ToString();
				textBox_reward_pq_unknown_3->Text = ByteArray_to_HexString(SelectedReward->pq->unknown_3);
				// pq items
				dataGridView_reward_pq_items->Rows->Clear();
				for(int r=0; r<SelectedReward->pq->items->Length; r++)
				{
					try
					{
						dataGridView_reward_pq_items->Rows->Add(gcnew array<String^>
						{
							SelectedReward->pq->items[r]->ranking_from.ToString(),
							SelectedReward->pq->items[r]->ranking_to.ToString(),
							SelectedReward->pq->items[r]->unknown_3.ToString(),
							SelectedReward->pq->items[r]->id.ToString(),
							SelectedReward->pq->items[r]->amount.ToString(),
							SelectedReward->pq->items[r]->probability.ToString("F6")
						}
						);
					}
					catch(...)
					{
						MessageBox::Show("ERROR Loading Reward PQ Items!");
					}
				}
				textBox_reward_pq_unknown_4->Text = ByteArray_to_HexString(SelectedReward->pq->unknown_4);
				// pq specials
				dataGridView_reward_pq_specials->Rows->Clear();
				for(int r=0; r<SelectedReward->pq->specials->Length; r++)
				{
					try
					{
						dataGridView_reward_pq_specials->Rows->Add(gcnew array<String^>
						{
							SelectedReward->pq->specials[r]->id_pq.ToString(),
							SelectedReward->pq->specials[r]->unknown_2.ToString(),
							SelectedReward->pq->specials[r]->unknown_3.ToString()
						}
						);
					}
					catch(...)
					{
						MessageBox::Show("ERROR Loading Reward PQ Specials!");
					}
				}
				textBox_reward_pq_unknown_5->Text = ByteArray_to_HexString(SelectedReward->pq->unknown_5);
				// pq scripts
				dataGridView_reward_pq_scripts->Rows->Clear();
				for(int r=0; r<SelectedReward->pq->scripts->Length; r++)
				{
					try
					{
						dataGridView_reward_pq_scripts->Rows->Add(gcnew array<String^>
						{
							ByteArray_to_HexString(SelectedReward->pq->scripts[r])
						}
						);
					}
					catch(...)
					{
						MessageBox::Show("ERROR Loading Reward PQ Scripts!");
					}
				}
				textBox_reward_pq_unknown_6->Text = ByteArray_to_HexString(SelectedReward->pq->unknown_6);
				// pq messages
				dataGridView_reward_pq_messages->Rows->Clear();
				for(int r=0; r<SelectedReward->pq->messages->Length; r++)
				{
					try
					{
						dataGridView_reward_pq_messages->Rows->Add(gcnew array<String^>
						{
							ByteArray_to_UnicodeString(SelectedReward->pq->messages[r])
						}
						);
					}
					catch(...)
					{
						MessageBox::Show("ERROR Loading Reward PQ Messages!");
					}
				}
				textBox_reward_pq_unknown_7->Text = ByteArray_to_HexString(SelectedReward->pq->unknown_7);

				textBox_reward_influence->Text = SelectedReward->influence.ToString();
				textBox_reward_prestige->Text = SelectedReward->prestige.ToString();
				textBox_reward_unknown_5->Text = SelectedReward->UNKNOWN_5.ToString();
				textBox_reward_unknown_6->Text = SelectedReward->UNKNOWN_6.ToString();
				textBox_reward_quest_slot_expansion->Text = SelectedReward->quest_slot_expansion.ToString();

				numericUpDown_reward_item_groups_count->Value = Convert::ToDecimal(SelectedReward->item_groups_count);

				checkedListBox_reward_item_groups_flag->Items->Clear();
				dataGridView_reward_item_group_items->Rows->Clear();
				Column_reward_item_groups->Items->Clear();

				for(int g=0; g<SelectedReward->item_groups->Length; g++)
				{
					Column_reward_item_groups->Items->Add(g.ToString());
					checkedListBox_reward_item_groups_flag->Items->Add("Group[" + g.ToString() + "] Flag", SelectedReward->item_groups[g]->unknown);

					for(int r=0; r<SelectedReward->item_groups[g]->items->Length; r++)
					{
						dataGridView_reward_item_group_items->Rows->Add(gcnew array<String^>
						{
							g.ToString(),
							SelectedReward->item_groups[g]->items[r]->id.ToString(),
							SelectedReward->item_groups[g]->items[r]->unknown.ToString(),
							SelectedReward->item_groups[g]->items[r]->amount.ToString(),
							SelectedReward->item_groups[g]->items[r]->probability.ToString("F6"),
							SelectedReward->item_groups[g]->items[r]->expiration.ToString()
						}
						);
						// set row background color depending on item group
						if(g%2 == 0)
						{
							dataGridView_reward_item_group_items->Rows[dataGridView_reward_item_group_items->Rows->Count-1]->DefaultCellStyle->BackColor = Color::White;
						}
						else
						{
							dataGridView_reward_item_group_items->Rows[dataGridView_reward_item_group_items->Rows->Count-1]->DefaultCellStyle->BackColor = Color::AliceBlue;
						}
					}
				}
			}
			else
			{
				textBox_reward_coins->Clear();
				textBox_reward_experience->Clear();
				textBox_reward_new_quest->Clear();
				textBox_reward_spirit->Clear();
				textBox_reward_reputation->Clear();
				textBox_reward_cultivation->Clear();
				textBox_reward_new_waypoint->Clear();
				textBox_reward_storage_slots->Clear();
				textBox_reward_cupboard_slots->Clear();
				textBox_reward_wardrobe_slots->Clear();
				textBox_reward_account_stash_slots->Clear();
				textBox_reward_inventory_slots->Clear();
				textBox_reward_petbag_slots->Clear();
				textBox_reward_vigor->Clear();
				textBox_reward_teleport_map_id->Clear();
				textBox_reward_teleport_x->Clear();
				textBox_reward_teleport_altitude->Clear();
				textBox_reward_teleport_z->Clear();
				textBox_reward_ai_trigger->Clear();
				textBox_reward_unknown_2a->Clear();
				textBox_reward_unknown_2b->Clear();
				textBox_reward_seperator->Clear();
				// pq
				dataGridView_reward_pq_chases->Rows->Clear();
				textBox_reward_pq_unknown_0->Clear();
				textBox_reward_pq_event_gold->Clear();
				textBox_reward_pq_unknown_1->Clear();
				textBox_reward_pq_unknown_quest->Clear();
				textBox_reward_pq_unknown_2->Clear();
				textBox_reward_pq_unknown_level->Clear();
				textBox_reward_pq_contribution_random_min->Clear();
				textBox_reward_pq_contribution_random_max->Clear();
				textBox_reward_pq_contribution_required->Clear();
				textBox_reward_pq_unknown_3->Clear();
				dataGridView_reward_pq_items->Rows->Clear();
				textBox_reward_pq_unknown_4->Clear();
				dataGridView_reward_pq_specials->Rows->Clear();
				textBox_reward_pq_unknown_5->Clear();
				dataGridView_reward_pq_scripts->Rows->Clear();
				textBox_reward_pq_unknown_6->Clear();
				dataGridView_reward_pq_messages->Rows->Clear();
				textBox_reward_pq_unknown_7->Clear();
				//
				textBox_reward_influence->Clear();
				textBox_reward_prestige->Clear();
				textBox_reward_unknown_5->Clear();
				textBox_reward_unknown_6->Clear();
				// items
				numericUpDown_reward_item_groups_count->Value = 0;
				checkedListBox_reward_item_groups_flag->Items->Clear();
				dataGridView_reward_item_group_items->Rows->Clear();
				Column_reward_item_groups->Items->Clear();
			}
		}
	}
	private: System::Void select_dialog(System::Object^  sender, System::EventArgs^  e)
	{
		int d = listBox_conversation_dialogs->SelectedIndex;

		if(SelectedTask && d>-1)
		{
			textBox_conversation_dialog_unknown->Text = SelectedTask->conversation->dialogs[d]->unknown.ToString();
			textBox_conversation_dialog_text->Text = SelectedTask->conversation->dialogs[d]->DialogText;
			textBox_conversation_question_text->Clear();
			textBox_conversation_question_id->Clear();
			textBox_conversation_question_previous->Clear();
			listBox_conversation_questions->Items->Clear();
			for(int q=0; q<SelectedTask->conversation->dialogs[d]->question_count; q++)
			{
				listBox_conversation_questions->Items->Add("[" + SelectedTask->conversation->dialogs[d]->questions[q]->question_id + "] Question");
			}
			textBox_conversation_answer_text->Clear();
			listBox_conversation_answers->Items->Clear();
		}
	}
	private: System::Void select_question(System::Object^  sender, System::EventArgs^  e)
	{
		int d = listBox_conversation_dialogs->SelectedIndex;
		int q = listBox_conversation_questions->SelectedIndex;

		if(SelectedTask && d>-1 && q>-1)
		{
			textBox_conversation_question_text->Text = SelectedTask->conversation->dialogs[d]->questions[q]->QuestionText;
			textBox_conversation_question_id->Text = SelectedTask->conversation->dialogs[d]->questions[q]->question_id.ToString();
			textBox_conversation_question_previous->Text = SelectedTask->conversation->dialogs[d]->questions[q]->previous_question.ToString();
			textBox_conversation_answer_text->Clear();
			textBox_conversation_answer_question_link->Clear();
			textBox_conversation_answer_task_link->Clear();
			listBox_conversation_answers->Items->Clear();
			for(int a=0; a<SelectedTask->conversation->dialogs[d]->questions[q]->answer_count; a++)
			{
				listBox_conversation_answers->Items->Add("[" + (a+1) + "] Answer");
			}
		}
	}
	private: System::Void select_answer(System::Object^  sender, System::EventArgs^  e)
	{
		int d = listBox_conversation_dialogs->SelectedIndex;
		int q = listBox_conversation_questions->SelectedIndex;
		int a = listBox_conversation_answers->SelectedIndex;

		if(SelectedTask && d>-1 && q>-1 && a>-1)
		{
			textBox_conversation_answer_text->Text = SelectedTask->conversation->dialogs[d]->questions[q]->answers[a]->AnswerText;
			textBox_conversation_answer_question_link->Text = SelectedTask->conversation->dialogs[d]->questions[q]->answers[a]->question_link.ToString();
			textBox_conversation_answer_task_link->Text = SelectedTask->conversation->dialogs[d]->questions[q]->answers[a]->task_link.ToString();
		}
	}

#pragma endregion

#pragma region EDIT FUNCTIONS

	private: System::Void click_cloneTask(System::Object^  sender, System::EventArgs^  e)
	{
		if(treeView_tasks->SelectedNode)
		{
			try
			{
				ArrayList^ task_index_path = gcnew ArrayList();
				TreeNode^ node = ((TreeView^)contextMenuStrip_task->SourceControl)->SelectedNode;

				while(node->Parent != nullptr)
				{
					task_index_path->Add(node->Index);
					node = node->Parent;
				}

				if(task_index_path->Count == 0)
				{
					array<Task^>^ temp = gcnew array<Task^>(Tasks->Length+1);
					temp[0] = Tasks[node->Index]->Clone();
					Array::Copy(Tasks, 0, temp, 1, Tasks->Length);
					Tasks = temp;

					treeView_tasks->Nodes->Insert(0, (TreeNode^)treeView_tasks->SelectedNode->Clone());
					treeView_tasks->SelectedNode = treeView_tasks->Nodes[0];
				}
				else
				{
					Task^ parent = Tasks[node->Index];
		
					for(int i=task_index_path->Count-1; i>0; i--)
					{
						parent = parent->sub_quests[(int)task_index_path[i]];
					}

					parent->sub_quest_count++;
					array<Task^>^ temp = gcnew array<Task^>(parent->sub_quests->Length+1);
					Array::Copy(parent->sub_quests, 0, temp, 0, parent->sub_quests->Length);
					temp[temp->Length-1] = parent->sub_quests[(int)task_index_path[0]]->Clone();
					parent->sub_quests = temp;

					MessageBox::Show("NOTE:\nCheck association like \"Next Quest\" and \"Previous Quest\" of all affected quests!");

					treeView_tasks->SelectedNode->Parent->Nodes->Add((TreeNode^)treeView_tasks->SelectedNode->Clone());
				}							
			}
			catch(Exception^ e)
			{
				MessageBox::Show("ERROR\n" + e->Message);
			}
		}
	}
	private: System::Void click_deleteTask(System::Object^  sender, System::EventArgs^  e)
	{
		if(treeView_tasks->SelectedNode)
		{
			try
			{
				ArrayList^ task_index_path = gcnew ArrayList();
				TreeNode^ node = ((TreeView^)contextMenuStrip_task->SourceControl)->SelectedNode;

				while(node->Parent != nullptr)
				{
					task_index_path->Add(node->Index);
					node = node->Parent;
				}

				if(task_index_path->Count == 0)
				{
					array<Task^>^ temp = gcnew array<Task^>(Tasks->Length-1);
					Array::Copy(Tasks, 0, temp, 0, node->Index);
					Array::Copy(Tasks, node->Index+1, temp, node->Index, Tasks->Length-1 - node->Index);
					Tasks = temp;
				}
				else
				{
					Task^ parent = Tasks[node->Index];
		
					for(int i=task_index_path->Count-1; i>0; i--)
					{
						parent = parent->sub_quests[(int)task_index_path[i]];
					}

					parent->sub_quest_count--;
					array<Task^>^ temp = gcnew array<Task^>(parent->sub_quests->Length-1);
					Array::Copy(parent->sub_quests, 0, temp, 0, (int)task_index_path[0]);
					Array::Copy(parent->sub_quests, (int)task_index_path[0]+1, temp, (int)task_index_path[0], parent->sub_quests->Length-1 - (int)task_index_path[0]);
					parent->sub_quests = temp;

// Update all links (parent, subquest, next, previous) for all affected quests...
					MessageBox::Show("NOTE:\nCheck association like \"Next Quest\" and \"Previous Quest\" of all affected quests!");
				}				

				// Remove node from treeview
				treeView_tasks->SelectedNode->Remove();
			}
			catch(Exception^ e)
			{
				MessageBox::Show("ERROR\n" + e->Message);
			}
		}
		// after deletion: select task above or below if possible...
	}

	private: System::Void click_split(System::Object^  sender, System::EventArgs^  e)
	{
		OpenFileDialog^ load = gcnew OpenFileDialog();
		load->Filter = "Tasks File (*.data)|*.data|All Files (*.*)|*.*";
		if(load->ShowDialog() == Windows::Forms::DialogResult::OK && File::Exists(load->FileName))
		{
			FolderBrowserDialog^ save = gcnew FolderBrowserDialog();

			if(save->ShowDialog() == Windows::Forms::DialogResult::OK && Directory::Exists(save->SelectedPath))
			{
				try
				{
					Cursor = Windows::Forms::Cursors::WaitCursor;
					progressBar_progress->Style = ProgressBarStyle::Marquee;

					int count;
					int value;

					FileStream^ fr = File::OpenRead(load->FileName);
					BinaryReader^ br = gcnew BinaryReader(fr);

					value = br->ReadInt32();
					value = br->ReadInt32()-1;
					count = br->ReadInt32();

					array<int>^ ItemStreamPositions = gcnew array<int>(count);

					for(int i=0; i<count; i++)
					{
						ItemStreamPositions[i] = br->ReadInt32();
					}

					for(int i=0; i<count; i++)
					{
						br->BaseStream->Position = ItemStreamPositions[i];
						int id = br->ReadInt32();

						br->BaseStream->Position = ItemStreamPositions[i];

						FileStream^ fw = gcnew FileStream(save->SelectedPath + "\\" + id + ".data", FileMode::Create, FileAccess::Write);
						//FileStream^ fw = gcnew FileStream(save->SelectedPath + "\\cn.client.tasks." + i, FileMode::Create, FileAccess::Write);
						BinaryWriter^ bw = gcnew BinaryWriter(fw);

						int bytes = (int)(br->BaseStream->Length-1 - ItemStreamPositions[i]);
						if(i<count-1)
						{
							bytes = ItemStreamPositions[i+1] - ItemStreamPositions[i];
						}

						bw->Write(br->ReadBytes(bytes));

						bw->Close();
						fw->Close();
					}

					br->Close();
					fr->Close();

					progressBar_progress->Style = ProgressBarStyle::Continuous;
					Cursor = Windows::Forms::Cursors::Default;
				}
				catch(...)
				{
					progressBar_progress->Style = ProgressBarStyle::Continuous;
					Cursor = Windows::Forms::Cursors::Default;
					MessageBox::Show("EXPORT ERROR!\nNo information available");
				}
			}
		}
	}

 	private: System::Void save_CreatureBuilder(Task^ t, StreamWriter^ sw)
	{
		String^ line = "";
		if(t->ai_trigger>0 || t->reward_success->ai_trigger>0 || t->reward_failed->ai_trigger>0)
		{
			if(t->Name->StartsWith("^"))
			{
				line += t->ID.ToString() + "\t" + t->Name->Substring(7);
			}
			else
			{
				line += t->ID.ToString() + "\t" + t->Name;
			}
			
			if(t->ai_trigger>0)
			{
				line += "\t" + t->ai_trigger.ToString();
			}
			else
			{
				line += "\t-";
			}
			if(t->reward_success->ai_trigger>0)
			{
				line += "\t" + t->reward_success->ai_trigger.ToString();
			}
			else
			{
				line += "\t-";
			}
			if(t->reward_failed->ai_trigger>0)
			{
				line += "\t" + t->reward_failed->ai_trigger.ToString();
			}
			else
			{
				line += "\t-";
			}
		}
		if(line != "")
		{
			sw->WriteLine(line);
		}
		for(int i=0; i<t->sub_quests->Length; i++)
		{
			save_CreatureBuilder(t->sub_quests[i], sw);
		}
	}
	private: System::Void click_creatureBuilder(System::Object^  sender, System::EventArgs^  e)
	{
		SaveFileDialog^ save = gcnew SaveFileDialog();
		save->InitialDirectory = Environment::CurrentDirectory;
		save->Filter = "Text File (*.txt)|*.txt|All Files (*.*)|*.*";
		if(Tasks && save->ShowDialog() == Windows::Forms::DialogResult::OK && save->FileName != "")
		{
			try
			{
				Cursor = Windows::Forms::Cursors::AppStarting;

				StreamWriter^ sw = gcnew StreamWriter(save->FileName, false, Encoding::Unicode);

				for(int i=Tasks->Length-1; i>-1; i--)
				{
					save_CreatureBuilder(Tasks[i], sw);
				}

				sw->Close();

				Cursor = Windows::Forms::Cursors::Default;
			}
			catch(...)
			{
				MessageBox::Show("SAVING ERROR!");
				Cursor = Windows::Forms::Cursors::Default;
			}
		}
	}

#pragma endregion

#pragma region SEARCH FUNCTIONS

	// search
	private: System::Void keyPress_search(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
	{
		if(e->KeyChar == (wchar_t)Keys::Enter)
		{
			click_search(nullptr, nullptr);
		}
	}
	private: System::Void click_search(System::Object^  sender, System::EventArgs^  e)
	{
		if(treeView_tasks->Nodes->Count>0)
		{
			array<int>^ indices = next_treeNode();

			// while there is a next task
			while(indices->Length > 0)
			{
				// search success
				if(search(indices))
				{
					return;
				}
				indices = next_task(indices);
			}

			MessageBox::Show("Search reached end of List without result");
		}
	}

	// return an array of indices for the next node after the selected in the tree view
	private: array<int>^ next_treeNode()
	{
		array<int>^ indices = gcnew array<int>{0};

		if(treeView_tasks->SelectedNode->Index > -1)
		{
			indices = gcnew array<int>(treeView_tasks->SelectedNode->Level+1);
			bool foundNext = false;
			TreeNode^ node = treeView_tasks->SelectedNode;

			// search through parents
			for(int i=indices->Length-1; i>-1; i--)
			{
				indices[i] = node->Index;

				if(node == treeView_tasks->SelectedNode && treeView_tasks->SelectedNode->Nodes->Count > 0)
				{
					foundNext = true;
				}
				if(!foundNext)
				{
					if(node->NextNode)
					{
						indices[i]++;
						foundNext = true;
					}
					else
					{
						Array::Resize(indices, indices->Length-1);
					}
				}

				node = node->Parent;
			}

			node = treeView_tasks->SelectedNode;

			// search through children
			while(node->Nodes->Count > 0)
			{
				Array::Resize(indices, indices->Length+1);
				indices[indices->Length-1] = 0;
				node = node->Nodes[0];
			}
		}

		return indices;
	}

	// returns the task depending on the array of indices to the current path
	private: Task^ current_task(array<int>^ currentIndices)
	{
		if(currentIndices->Length > 0)
		{
			// get the task from indices path
			Task^ t = Tasks[currentIndices[0]];
			for(int i=1; i<currentIndices->Length; i++)
			{
				t = t->sub_quests[currentIndices[i]];
			}
			return t;
		}
		return nullptr;
	}

	// return an array of indices for the next task depending on the array of indices to the current path
	private: array<int>^ next_task(array<int>^ currentIndices)
	{
		if(currentIndices->Length > 0)
		{
			array<int>^ indices = gcnew array<int>(currentIndices->Length);

			// get the task from indices path
			Task^ t = current_task(currentIndices);

			currentIndices->CopyTo(indices, 0);

			// select the next subtask, if available
			if(t->sub_quest_count > 0)
			{
				Array::Resize(indices, indices->Length+1);
				indices[indices->Length-1] = 0;
				return indices;
			}

			// search through parents
			for(int i=indices->Length-1; i>0; i--)
			{
				// check if the current task has a successor
				if(current_task(indices)->next_quest != 0)
				{
					indices[i]++;
					return indices;
				}
				else
				{
					Array::Resize(indices, indices->Length-1);
				}
			}

			// we end up in root task tree
			// at this point indices should have a length of exactly 1
			// we return incremented indices[0] if possible
			if(indices[0] < Tasks->Length-1)
			{
				indices[0]++;
				return indices;
			}
		}

		return gcnew array<int>(0);
	}

	// return the path of indices to the child task that contains the pattern
	private: bool search(array<int>^ indices)
	{
		if(indices->Length > 0)
		{
			// get the task from indices path
			Task^ t = current_task(indices);
			if(!t)
			{
				return false;
			}
			// check search options for this path
			if(comboBox_search->SelectedItem == "ID" && t->ID.ToString() == textBox_search->Text)
			{
				select_treeNode(indices);
				return true;
			}
			if(comboBox_search->SelectedItem == "Name" && t->Name->Contains(textBox_search->Text))
			{
				select_treeNode(indices);
				return true;
			}
			if( (comboBox_search->SelectedItem == "Creature Builder ID") && ((t->ai_trigger.ToString() == textBox_search->Text) || (t->reward_success->ai_trigger.ToString() == textBox_search->Text) || (t->reward_failed->ai_trigger.ToString() == textBox_search->Text)) )
			{
				select_treeNode(indices);
				return true;
			}
		}

		return false; // no entry found
	}

	// select the treenode that corresponds to array of indices
	private: System::Void select_treeNode(array<int>^ indices)
	{
		if(indices->Length > 0)
		{
			TreeNode^ node = treeView_tasks->Nodes[indices[0]];
			for(int i=1; i<indices->Length; i++)
			{
				node = node->Nodes[indices[i]];
			}
			treeView_tasks->SelectedNode = node;
		}
	}

#pragma endregion

//################### NEW #########################

#pragma region DEBUG TRIGGER FUNCTION

	// debug: change information
	private: void TriggerDebug(Control^ sender)
	{
		if(changeConfirmationToolStripMenuItem->Checked)
		{
			MessageBox::Show("Sender: " + sender->Name, "Change Trigger");
		}
	}

#pragma endregion

#pragma region CHANGE EVENT FUNCTIONS

	// general
	private: System::Void change_id(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->ID != Convert::ToInt32(textBox_id->Text))
				{
					if(MessageBox::Show("Changing a task id is dangerous and can lead to inconsistence. Please check all answers and other (child)tasks that are connected to this id!\n\nChange task id anyway?", "NOTE!", MessageBoxButtons::YesNo) == Windows::Forms::DialogResult::Yes)
					{
						SelectedTask->ID = Convert::ToInt32(textBox_id->Text);

						// Update node in treeview
						String^ name = SelectedTask->Name;
						Drawing::Color c = Drawing::Color::White;
						treeView_tasks->BeginUpdate();
						if(name->StartsWith("^"))
						{
							try
							{
								c = Drawing::Color::FromArgb(int::Parse(name->Substring(1, 6), Globalization::NumberStyles::HexNumber));
								name = name->Substring(7);
							}
							catch(...)
							{
								c = Drawing::Color::White;
							}
						}
						treeView_tasks->SelectedNode->ForeColor = c;
						treeView_tasks->SelectedNode->Text = SelectedTask->ID.ToString() + " - " + name;
						treeView_tasks->EndUpdate();

						// call debug function
						TriggerDebug((Control^)sender);
					}
					else
					{
						textBox_id->Text = SelectedTask->ID.ToString();
					}
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}

	private: System::Void change_name(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->Name != textBox_name->Text)
				{
					String^ node = textBox_name->Text;
					SelectedTask->Name = node;

					// Update node in treeview
					Drawing::Color c = Drawing::Color::White;
					treeView_tasks->BeginUpdate();
					if(node->StartsWith("^"))
					{
						try
						{
							c = Drawing::Color::FromArgb(int::Parse(node->Substring(1, 6), Globalization::NumberStyles::HexNumber));
							node = node->Substring(7);
						}
						catch(...)
						{
							c = Drawing::Color::White;
						}
					}
					treeView_tasks->SelectedNode->ForeColor = c;
					treeView_tasks->SelectedNode->Text = SelectedTask->ID.ToString() + " - " + node;
					treeView_tasks->EndUpdate();

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}

	private: System::Void change_author_text(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->AuthorText != textBox_author_text->Text)
				{
					if(textBox_author_text->Text == "")
					{
						checkBox_author_mode->Checked = false;
						SelectedTask->author_mode = false;
					}
					else
					{
						checkBox_author_mode->Checked = true;
						SelectedTask->author_mode = true;
					}

					SelectedTask->AuthorText = textBox_author_text->Text;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}

	private: System::Void change_unknown_01(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedTask->UNKNOWN_01) != textBox_unknown_01->Text)
				{
					SelectedTask->UNKNOWN_01 = HexString_to_ByteArray(textBox_unknown_01->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}

	private: System::Void change_type(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(comboBox_type->SelectedIndex > -1 && SelectedTask->type != comboBox_type->SelectedIndex)
				{
					SelectedTask->type = comboBox_type->SelectedIndex;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}

	private: System::Void change_time_limit(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->time_limit != Convert::ToInt32(textBox_time_limit->Text))
				{
					SelectedTask->time_limit = Convert::ToInt32(textBox_time_limit->Text);
					// Recalculate time for time based rewards...
					for(int i=0; i<listBox_reward_timed->Items->Count; i++)
					{
						listBox_reward_timed->Items[i] = "Success Time [sec]: " + (SelectedTask->time_limit*SelectedTask->rewards_timed_factors[i]);
					}

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}

	private: System::Void change_unknown_02(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->UNKNOWN_02 != checkBox_unknown_02->Checked)
				{
					SelectedTask->UNKNOWN_02 = checkBox_unknown_02->Checked;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}

	private: System::Void change_has_date_fail(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->has_date_fail != checkBox_has_date_fail->Checked)
				{
					SelectedTask->has_date_fail = checkBox_has_date_fail->Checked;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}

	private: System::Void change_date_fail(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				int r = dataGridView_date_fail->CurrentCell->RowIndex;
				switch (dataGridView_date_fail->CurrentCell->ColumnIndex)
				{
					case 0:		SelectedTask->date_fail->year = Convert::ToInt32(dataGridView_date_fail->CurrentCell->Value);
								break;
					case 1:		SelectedTask->date_fail->month = Convert::ToInt32(dataGridView_date_fail->CurrentCell->Value);
								break;
					case 2:		SelectedTask->date_fail->day = Convert::ToInt32(dataGridView_date_fail->CurrentCell->Value);
								break;
					case 3:		SelectedTask->date_fail->hour = Convert::ToInt32(dataGridView_date_fail->CurrentCell->Value);
								break;
					case 4:		SelectedTask->date_fail->minute = Convert::ToInt32(dataGridView_date_fail->CurrentCell->Value);
								break;
					case 5:		SelectedTask->date_fail->weekday = Column_date_fail_weekday->Items->IndexOf(dataGridView_date_fail->CurrentCell->Value);
								break;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}

	private: System::Void change_unknown_03(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->UNKNOWN_03 != checkBox_unknown_03->Checked)
				{
					SelectedTask->UNKNOWN_03 = checkBox_unknown_03->Checked;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}

	private: System::Void change_has_date_spans(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->has_date_spans != checkBox_has_date_spans->Checked)
				{
					SelectedTask->has_date_spans = checkBox_has_date_spans->Checked;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_date_span(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				int r = dataGridView_date_spans->CurrentCell->RowIndex;
				switch(dataGridView_date_spans->CurrentCell->ColumnIndex)
				{
					case 0:		SelectedTask->date_spans[r]->from->year = Convert::ToInt32(dataGridView_date_spans->CurrentCell->Value);
								break;
					case 1:		SelectedTask->date_spans[r]->from->month = Convert::ToInt32(dataGridView_date_spans->CurrentCell->Value);
								break;
					case 2:		SelectedTask->date_spans[r]->from->day = Convert::ToInt32(dataGridView_date_spans->CurrentCell->Value);
								break;
					case 3:		SelectedTask->date_spans[r]->from->hour = Convert::ToInt32(dataGridView_date_spans->CurrentCell->Value);
								break;
					case 4:		SelectedTask->date_spans[r]->from->minute = Convert::ToInt32(dataGridView_date_spans->CurrentCell->Value);
								break;
					case 5:		SelectedTask->date_spans[r]->from->weekday = Column6->Items->IndexOf(dataGridView_date_spans->CurrentCell->Value);
								break;
					case 7:		SelectedTask->date_spans[r]->to->year = Convert::ToInt32(dataGridView_date_spans->CurrentCell->Value);
								break;
					case 8:		SelectedTask->date_spans[r]->to->month = Convert::ToInt32(dataGridView_date_spans->CurrentCell->Value);
								break;
					case 9:		SelectedTask->date_spans[r]->to->day = Convert::ToInt32(dataGridView_date_spans->CurrentCell->Value);
								break;
					case 10:	SelectedTask->date_spans[r]->to->hour = Convert::ToInt32(dataGridView_date_spans->CurrentCell->Value);
								break;
					case 11:	SelectedTask->date_spans[r]->to->minute = Convert::ToInt32(dataGridView_date_spans->CurrentCell->Value);
								break;
					case 12:	SelectedTask->date_spans[r]->to->weekday = Column13->Items->IndexOf(dataGridView_date_spans->CurrentCell->Value);
								break;
				}
				// call debug function
				TriggerDebug((Control^)sender);
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}

	private: System::Void add_date_span(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			SelectedTask->date_spans_count++;
			Array::Resize(SelectedTask->date_spans, SelectedTask->date_spans->Length+1);
			SelectedTask->date_spans[SelectedTask->date_spans->Length-1] = gcnew DateSpan();

			SelectedTask->date_spans[SelectedTask->date_spans->Length-1]->from = gcnew Date();
			SelectedTask->date_spans[SelectedTask->date_spans->Length-1]->from->year = 0;
			SelectedTask->date_spans[SelectedTask->date_spans->Length-1]->from->month = 0;
			SelectedTask->date_spans[SelectedTask->date_spans->Length-1]->from->day = 0;
			SelectedTask->date_spans[SelectedTask->date_spans->Length-1]->from->hour = 0;
			SelectedTask->date_spans[SelectedTask->date_spans->Length-1]->from->minute = 0;
			SelectedTask->date_spans[SelectedTask->date_spans->Length-1]->from->weekday = 0;

			SelectedTask->date_spans[SelectedTask->date_spans->Length-1]->to = gcnew Date();
			SelectedTask->date_spans[SelectedTask->date_spans->Length-1]->to->year = 0;
			SelectedTask->date_spans[SelectedTask->date_spans->Length-1]->to->month = 0;
			SelectedTask->date_spans[SelectedTask->date_spans->Length-1]->to->day = 0;
			SelectedTask->date_spans[SelectedTask->date_spans->Length-1]->to->hour = 0;
			SelectedTask->date_spans[SelectedTask->date_spans->Length-1]->to->minute = 0;
			SelectedTask->date_spans[SelectedTask->date_spans->Length-1]->to->weekday = 0;

			dataGridView_date_spans->Rows->Add(gcnew array<String^>{"0", "0", "0", "0", "0", Column6->Items[0]->ToString(), "to", "0", "0", "0", "0", "0", Column13->Items[0]->ToString()});
		}
	}
	private: System::Void remove_date_span(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			if(SelectedTask->date_spans_count>0 && dataGridView_date_spans->CurrentCell->RowIndex>-1)
			{
				SelectedTask->date_spans_count--;

				array<DateSpan^>^ temp = gcnew array<DateSpan^>(SelectedTask->date_spans_count);
				Array::Copy(SelectedTask->date_spans, 0, temp, 0, dataGridView_date_spans->CurrentCell->RowIndex);
				Array::Copy(SelectedTask->date_spans, dataGridView_date_spans->CurrentCell->RowIndex+1, temp, dataGridView_date_spans->CurrentCell->RowIndex, SelectedTask->date_spans_count - dataGridView_date_spans->CurrentCell->RowIndex);
				SelectedTask->date_spans = temp;

				dataGridView_date_spans->Rows->RemoveAt(dataGridView_date_spans->CurrentCell->RowIndex);
			}
		}
	}
	private: System::Void change_unknown_04(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedTask->UNKNOWN_04) != textBox_unknown_04->Text)
				{
					SelectedTask->UNKNOWN_04 = HexString_to_ByteArray(textBox_unknown_04->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}

	private: System::Void change_unknown_05(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedTask->UNKNOWN_05) != textBox_unknown_05->Text)
				{
					SelectedTask->UNKNOWN_05 = HexString_to_ByteArray(textBox_unknown_05->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}

	private: System::Void change_unknown_06(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedTask->UNKNOWN_06) != textBox_unknown_06->Text)
				{
					SelectedTask->UNKNOWN_06 = HexString_to_ByteArray(textBox_unknown_06->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}

	private: System::Void change_unknown_07(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedTask->UNKNOWN_07) != textBox_unknown_07->Text)
				{
					SelectedTask->UNKNOWN_07 = HexString_to_ByteArray(textBox_unknown_07->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}

	private: System::Void change_unknown_08(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->UNKNOWN_08 != Convert::ToInt32(textBox_unknown_08->Text))
				{
					SelectedTask->UNKNOWN_08 = Convert::ToInt32(textBox_unknown_08->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}

	private: System::Void change_unknown_09(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->UNKNOWN_09 != Convert::ToInt32(textBox_unknown_09->Text))
				{
					SelectedTask->UNKNOWN_09 = Convert::ToInt32(textBox_unknown_09->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	// flags
	private: System::Void change_activate_first_subquest(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->activate_first_subquest != checkBox_activate_first_subquest->Checked)
				{
					SelectedTask->activate_first_subquest = checkBox_activate_first_subquest->Checked;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_activate_random_subquest(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->activate_random_subquest != checkBox_activate_random_subquest->Checked)
				{
					SelectedTask->activate_random_subquest = checkBox_activate_random_subquest->Checked;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_activate_next_subquest(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->activate_next_subquest != checkBox_activate_next_subquest->Checked)
				{
					SelectedTask->activate_next_subquest = checkBox_activate_next_subquest->Checked;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_on_give_up_parent_fails(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->on_give_up_parent_fails != checkBox_on_give_up_parent_fails->Checked)
				{
					SelectedTask->on_give_up_parent_fails = checkBox_on_give_up_parent_fails->Checked;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_on_success_parent_success(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->on_success_parent_success != checkBox_on_success_parent_success->Checked)
				{
					SelectedTask->on_success_parent_success = checkBox_on_success_parent_success->Checked;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_can_give_up(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->can_give_up != checkBox_can_give_up->Checked)
				{
					SelectedTask->can_give_up = checkBox_can_give_up->Checked;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_repeatable(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->repeatable != checkBox_repeatable->Checked)
				{
					SelectedTask->repeatable = checkBox_repeatable->Checked;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_repeatable_after_failure(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->repeatable_after_failure != checkBox_repeatable_after_failure->Checked)
				{
					SelectedTask->repeatable_after_failure = checkBox_repeatable_after_failure->Checked;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_fail_on_death(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->fail_on_death != checkBox_fail_on_death->Checked)
				{
					SelectedTask->fail_on_death = checkBox_fail_on_death->Checked;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_on_fail_parent_fail(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->on_fail_parent_fail != checkBox_on_fail_parent_fail->Checked)
				{
					SelectedTask->on_fail_parent_fail = checkBox_on_fail_parent_fail->Checked;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_unknown_10(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->UNKNOWN_10 != checkBox_unknown_10->Checked)
				{
					SelectedTask->UNKNOWN_10 = checkBox_unknown_10->Checked;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_player_limit(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->player_limit != Convert::ToInt32(textBox_player_limit->Text))
				{
					SelectedTask->player_limit = Convert::ToInt32(textBox_player_limit->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	// trigger locations (start on enter)
	private: System::Void change_trigger_locations_has_spans(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->trigger_locations->has_location != checkBox_trigger_locations_has_spans->Checked)
				{
					SelectedTask->trigger_locations->has_location = checkBox_trigger_locations_has_spans->Checked;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_trigger_locations_map_id(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->trigger_locations->map_id != Convert::ToInt32(textBox_trigger_locations_map_id->Text))
				{
					SelectedTask->trigger_locations->map_id = Convert::ToInt32(textBox_trigger_locations_map_id->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_trigger_locations_unknown_1(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedTask->trigger_locations->unknown_1) != textBox_trigger_locations_unknown_1->Text)
				{
					SelectedTask->trigger_locations->unknown_1 = HexString_to_ByteArray(textBox_trigger_locations_unknown_1->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_trigger_locations_span(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				int r = dataGridView_trigger_location_spans->CurrentCell->RowIndex;
				switch(dataGridView_trigger_location_spans->CurrentCell->ColumnIndex)
				{
					case 0:		SelectedTask->trigger_locations->spans[r]->north = Convert::ToSingle(dataGridView_trigger_location_spans->CurrentCell->Value);
								break;
					case 1:		SelectedTask->trigger_locations->spans[r]->south = Convert::ToSingle(dataGridView_trigger_location_spans->CurrentCell->Value);
								break;
					case 2:		SelectedTask->trigger_locations->spans[r]->west = Convert::ToSingle(dataGridView_trigger_location_spans->CurrentCell->Value);
								break;
					case 3:		SelectedTask->trigger_locations->spans[r]->east = Convert::ToSingle(dataGridView_trigger_location_spans->CurrentCell->Value);
								break;
					case 4:		SelectedTask->trigger_locations->spans[r]->bottom = Convert::ToSingle(dataGridView_trigger_location_spans->CurrentCell->Value);
								break;
					case 5:		SelectedTask->trigger_locations->spans[r]->top = Convert::ToSingle(dataGridView_trigger_location_spans->CurrentCell->Value);
								break;
				}
				// call debug function
				TriggerDebug((Control^)sender);
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void add_trigger_locations_span(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			SelectedTask->trigger_locations->count++;
			Array::Resize(SelectedTask->trigger_locations->spans, SelectedTask->trigger_locations->spans->Length+1);
			SelectedTask->trigger_locations->spans[SelectedTask->trigger_locations->spans->Length-1] = gcnew Span();

			SelectedTask->trigger_locations->spans[SelectedTask->trigger_locations->spans->Length-1]->north = 0.0;
			SelectedTask->trigger_locations->spans[SelectedTask->trigger_locations->spans->Length-1]->south = 0.0;
			SelectedTask->trigger_locations->spans[SelectedTask->trigger_locations->spans->Length-1]->west = 0.0;
			SelectedTask->trigger_locations->spans[SelectedTask->trigger_locations->spans->Length-1]->east = 0.0;
			SelectedTask->trigger_locations->spans[SelectedTask->trigger_locations->spans->Length-1]->bottom = 0.0;
			SelectedTask->trigger_locations->spans[SelectedTask->trigger_locations->spans->Length-1]->top = 0.0;

			dataGridView_trigger_location_spans->Rows->Add(gcnew array<String^>{"0.0", "0.0", "0.0", "0.0", "0.0", "0.0"});
		}
	}
	private: System::Void remove_trigger_locations_span(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			if(SelectedTask->trigger_locations->count>0 && dataGridView_trigger_location_spans->CurrentCell->RowIndex>-1)
			{
				SelectedTask->trigger_locations->count--;

				array<Span^>^ temp = gcnew array<Span^>(SelectedTask->trigger_locations->count);
				Array::Copy(SelectedTask->trigger_locations->spans, 0, temp, 0, dataGridView_trigger_location_spans->CurrentCell->RowIndex);
				Array::Copy(SelectedTask->trigger_locations->spans, dataGridView_trigger_location_spans->CurrentCell->RowIndex+1, temp, dataGridView_trigger_location_spans->CurrentCell->RowIndex, SelectedTask->trigger_locations->count - dataGridView_trigger_location_spans->CurrentCell->RowIndex);
				SelectedTask->trigger_locations->spans = temp;

				dataGridView_trigger_location_spans->Rows->RemoveAt(dataGridView_trigger_location_spans->CurrentCell->RowIndex);
			}
		}
	}
	// fail locations (fail on enter)
	private: System::Void change_fail_locations_has_spans(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->fail_locations->has_location != checkBox_fail_locations_has_spans->Checked)
				{
					SelectedTask->fail_locations->has_location = checkBox_fail_locations_has_spans->Checked;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_fail_locations_map_id(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->fail_locations->map_id != Convert::ToInt32(textBox_fail_locations_map_id->Text))
				{
					SelectedTask->fail_locations->map_id = Convert::ToInt32(textBox_fail_locations_map_id->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_fail_locations_unknown_1(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedTask->fail_locations->unknown_1) != textBox_fail_locations_unknown_1->Text)
				{
					SelectedTask->fail_locations->unknown_1 = HexString_to_ByteArray(textBox_fail_locations_unknown_1->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_fail_locations_span(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				int r = dataGridView_fail_location_spans->CurrentCell->RowIndex;
				switch(dataGridView_fail_location_spans->CurrentCell->ColumnIndex)
				{
					case 0:		SelectedTask->fail_locations->spans[r]->north = Convert::ToSingle(dataGridView_fail_location_spans->CurrentCell->Value);
								break;
					case 1:		SelectedTask->fail_locations->spans[r]->south = Convert::ToSingle(dataGridView_fail_location_spans->CurrentCell->Value);
								break;
					case 2:		SelectedTask->fail_locations->spans[r]->west = Convert::ToSingle(dataGridView_fail_location_spans->CurrentCell->Value);
								break;
					case 3:		SelectedTask->fail_locations->spans[r]->east = Convert::ToSingle(dataGridView_fail_location_spans->CurrentCell->Value);
								break;
					case 4:		SelectedTask->fail_locations->spans[r]->bottom = Convert::ToSingle(dataGridView_fail_location_spans->CurrentCell->Value);
								break;
					case 5:		SelectedTask->fail_locations->spans[r]->top = Convert::ToSingle(dataGridView_fail_location_spans->CurrentCell->Value);
								break;
				}
				// call debug function
				TriggerDebug((Control^)sender);
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void add_fail_locations_span(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			SelectedTask->fail_locations->count++;
			Array::Resize(SelectedTask->fail_locations->spans, SelectedTask->fail_locations->spans->Length+1);
			SelectedTask->fail_locations->spans[SelectedTask->fail_locations->spans->Length-1] = gcnew Span();

			SelectedTask->fail_locations->spans[SelectedTask->fail_locations->spans->Length-1]->north = 0.0;
			SelectedTask->fail_locations->spans[SelectedTask->fail_locations->spans->Length-1]->south = 0.0;
			SelectedTask->fail_locations->spans[SelectedTask->fail_locations->spans->Length-1]->west = 0.0;
			SelectedTask->fail_locations->spans[SelectedTask->fail_locations->spans->Length-1]->east = 0.0;
			SelectedTask->fail_locations->spans[SelectedTask->fail_locations->spans->Length-1]->bottom = 0.0;
			SelectedTask->fail_locations->spans[SelectedTask->fail_locations->spans->Length-1]->top = 0.0;

			dataGridView_fail_location_spans->Rows->Add(gcnew array<String^>{"0.0", "0.0", "0.0", "0.0", "0.0", "0.0"});
		}
	}
	private: System::Void remove_fail_locations_span(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			if(SelectedTask->fail_locations->count>0 && dataGridView_fail_location_spans->CurrentCell->RowIndex>-1)
			{
				SelectedTask->fail_locations->count--;

				array<Span^>^ temp = gcnew array<Span^>(SelectedTask->fail_locations->count);
				Array::Copy(SelectedTask->fail_locations->spans, 0, temp, 0, dataGridView_fail_location_spans->CurrentCell->RowIndex);
				Array::Copy(SelectedTask->fail_locations->spans, dataGridView_fail_location_spans->CurrentCell->RowIndex+1, temp, dataGridView_fail_location_spans->CurrentCell->RowIndex, SelectedTask->fail_locations->count - dataGridView_fail_location_spans->CurrentCell->RowIndex);
				SelectedTask->fail_locations->spans = temp;

				dataGridView_fail_location_spans->Rows->RemoveAt(dataGridView_fail_location_spans->CurrentCell->RowIndex);
			}
		}
	}
	// valid locations (fail on leave)
	private: System::Void change_valid_locations_has_spans(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->valid_locations->has_location != checkBox_valid_locations_has_spans->Checked)
				{
					SelectedTask->valid_locations->has_location = checkBox_valid_locations_has_spans->Checked;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_valid_locations_map_id(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->valid_locations->map_id != Convert::ToInt32(textBox_valid_locations_map_id->Text))
				{
					SelectedTask->valid_locations->map_id = Convert::ToInt32(textBox_valid_locations_map_id->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_valid_locations_unknown_1(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedTask->valid_locations->unknown_1) != textBox_valid_locations_unknown_1->Text)
				{
					SelectedTask->valid_locations->unknown_1 = HexString_to_ByteArray(textBox_valid_locations_unknown_1->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_valid_locations_span(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				int r = dataGridView_valid_location_spans->CurrentCell->RowIndex;
				switch(dataGridView_valid_location_spans->CurrentCell->ColumnIndex)
				{
					case 0:		SelectedTask->valid_locations->spans[r]->north = Convert::ToSingle(dataGridView_valid_location_spans->CurrentCell->Value);
								break;
					case 1:		SelectedTask->valid_locations->spans[r]->south = Convert::ToSingle(dataGridView_valid_location_spans->CurrentCell->Value);
								break;
					case 2:		SelectedTask->valid_locations->spans[r]->west = Convert::ToSingle(dataGridView_valid_location_spans->CurrentCell->Value);
								break;
					case 3:		SelectedTask->valid_locations->spans[r]->east = Convert::ToSingle(dataGridView_valid_location_spans->CurrentCell->Value);
								break;
					case 4:		SelectedTask->valid_locations->spans[r]->bottom = Convert::ToSingle(dataGridView_valid_location_spans->CurrentCell->Value);
								break;
					case 5:		SelectedTask->valid_locations->spans[r]->top = Convert::ToSingle(dataGridView_valid_location_spans->CurrentCell->Value);
								break;
				}
				// call debug function
				TriggerDebug((Control^)sender);
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void add_valid_locations_span(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			SelectedTask->valid_locations->count++;
			Array::Resize(SelectedTask->valid_locations->spans, SelectedTask->valid_locations->spans->Length+1);
			SelectedTask->valid_locations->spans[SelectedTask->valid_locations->spans->Length-1] = gcnew Span();

			SelectedTask->valid_locations->spans[SelectedTask->valid_locations->spans->Length-1]->north = 0.0;
			SelectedTask->valid_locations->spans[SelectedTask->valid_locations->spans->Length-1]->south = 0.0;
			SelectedTask->valid_locations->spans[SelectedTask->valid_locations->spans->Length-1]->west = 0.0;
			SelectedTask->valid_locations->spans[SelectedTask->valid_locations->spans->Length-1]->east = 0.0;
			SelectedTask->valid_locations->spans[SelectedTask->valid_locations->spans->Length-1]->bottom = 0.0;
			SelectedTask->valid_locations->spans[SelectedTask->valid_locations->spans->Length-1]->top = 0.0;

			dataGridView_valid_location_spans->Rows->Add(gcnew array<String^>{"0.0", "0.0", "0.0", "0.0", "0.0", "0.0"});
		}
	}
	private: System::Void remove_valid_locations_span(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			if(SelectedTask->valid_locations->count>0 && dataGridView_valid_location_spans->CurrentCell->RowIndex>-1)
			{
				SelectedTask->valid_locations->count--;

				array<Span^>^ temp = gcnew array<Span^>(SelectedTask->valid_locations->count);
				Array::Copy(SelectedTask->valid_locations->spans, 0, temp, 0, dataGridView_valid_location_spans->CurrentCell->RowIndex);
				Array::Copy(SelectedTask->valid_locations->spans, dataGridView_valid_location_spans->CurrentCell->RowIndex+1, temp, dataGridView_valid_location_spans->CurrentCell->RowIndex, SelectedTask->valid_locations->count - dataGridView_valid_location_spans->CurrentCell->RowIndex);
				SelectedTask->valid_locations->spans = temp;

				dataGridView_valid_location_spans->Rows->RemoveAt(dataGridView_valid_location_spans->CurrentCell->RowIndex);
			}
		}
	}
	// reach locations
	private: System::Void change_reach_locations_has_spans(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->reach_locations->has_location != checkBox_reach_locations_has_spans->Checked)
				{
					SelectedTask->reach_locations->has_location = checkBox_reach_locations_has_spans->Checked;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_reach_locations_map_id(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->reach_locations->map_id != Convert::ToInt32(textBox_reach_locations_map_id->Text))
				{
					SelectedTask->reach_locations->map_id = Convert::ToInt32(textBox_reach_locations_map_id->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_reach_locations_unknown_1(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedTask->reach_locations->unknown_1) != textBox_reach_locations_unknown_1->Text)
				{
					SelectedTask->reach_locations->unknown_1 = HexString_to_ByteArray(textBox_reach_locations_unknown_1->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_reach_locations_span(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				int r = dataGridView_reach_location_spans->CurrentCell->RowIndex;
				switch(dataGridView_reach_location_spans->CurrentCell->ColumnIndex)
				{
					case 0:		SelectedTask->reach_locations->spans[r]->north = Convert::ToSingle(dataGridView_reach_location_spans->CurrentCell->Value);
								break;
					case 1:		SelectedTask->reach_locations->spans[r]->south = Convert::ToSingle(dataGridView_reach_location_spans->CurrentCell->Value);
								break;
					case 2:		SelectedTask->reach_locations->spans[r]->west = Convert::ToSingle(dataGridView_reach_location_spans->CurrentCell->Value);
								break;
					case 3:		SelectedTask->reach_locations->spans[r]->east = Convert::ToSingle(dataGridView_reach_location_spans->CurrentCell->Value);
								break;
					case 4:		SelectedTask->reach_locations->spans[r]->bottom = Convert::ToSingle(dataGridView_reach_location_spans->CurrentCell->Value);
								break;
					case 5:		SelectedTask->reach_locations->spans[r]->top = Convert::ToSingle(dataGridView_reach_location_spans->CurrentCell->Value);
								break;
				}
				// call debug function
				TriggerDebug((Control^)sender);
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void add_reach_locations_span(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			SelectedTask->reach_locations->count++;
			Array::Resize(SelectedTask->reach_locations->spans, SelectedTask->reach_locations->spans->Length+1);
			SelectedTask->reach_locations->spans[SelectedTask->reach_locations->spans->Length-1] = gcnew Span();

			SelectedTask->reach_locations->spans[SelectedTask->reach_locations->spans->Length-1]->north = 0.0;
			SelectedTask->reach_locations->spans[SelectedTask->reach_locations->spans->Length-1]->south = 0.0;
			SelectedTask->reach_locations->spans[SelectedTask->reach_locations->spans->Length-1]->west = 0.0;
			SelectedTask->reach_locations->spans[SelectedTask->reach_locations->spans->Length-1]->east = 0.0;
			SelectedTask->reach_locations->spans[SelectedTask->reach_locations->spans->Length-1]->bottom = 0.0;
			SelectedTask->reach_locations->spans[SelectedTask->reach_locations->spans->Length-1]->top = 0.0;

			dataGridView_reach_location_spans->Rows->Add(gcnew array<String^>{"0.0", "0.0", "0.0", "0.0", "0.0", "0.0"});
		}
	}
	private: System::Void remove_reach_locations_span(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			if(SelectedTask->reach_locations->count>0 && dataGridView_reach_location_spans->CurrentCell->RowIndex>-1)
			{
				SelectedTask->reach_locations->count--;

				array<Span^>^ temp = gcnew array<Span^>(SelectedTask->reach_locations->count);
				Array::Copy(SelectedTask->reach_locations->spans, 0, temp, 0, dataGridView_reach_location_spans->CurrentCell->RowIndex);
				Array::Copy(SelectedTask->reach_locations->spans, dataGridView_reach_location_spans->CurrentCell->RowIndex+1, temp, dataGridView_reach_location_spans->CurrentCell->RowIndex, SelectedTask->reach_locations->count - dataGridView_reach_location_spans->CurrentCell->RowIndex);
				SelectedTask->reach_locations->spans = temp;

				dataGridView_reach_location_spans->Rows->RemoveAt(dataGridView_reach_location_spans->CurrentCell->RowIndex);
			}
		}
	}
	// basic I
	private: System::Void change_unknown_17(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->UNKNOWN_17 != checkBox_unknown_17->Checked)
				{
					SelectedTask->UNKNOWN_17 = checkBox_unknown_17->Checked;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_has_instant_teleport(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->has_instant_teleport != checkBox_has_instant_teleport->Checked)
				{
					SelectedTask->has_instant_teleport = checkBox_has_instant_teleport->Checked;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_instant_teleport_location_map_id(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->instant_teleport_location->map_id != Convert::ToInt32(textBox_instant_teleport_location_map_id->Text))
				{
					SelectedTask->instant_teleport_location->map_id = Convert::ToInt32(textBox_instant_teleport_location_map_id->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}

	private: System::Void change_instant_teleport_location_x(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->instant_teleport_location->x != Convert::ToSingle(textBox_instant_teleport_location_x->Text))
				{
					SelectedTask->instant_teleport_location->x = Convert::ToSingle(textBox_instant_teleport_location_x->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}

	private: System::Void change_instant_teleport_location_alt(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->instant_teleport_location->altitude != Convert::ToSingle(textBox_instant_teleport_location_alt->Text))
				{
					SelectedTask->instant_teleport_location->altitude = Convert::ToSingle(textBox_instant_teleport_location_alt->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}

	private: System::Void change_instant_teleport_location_z(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->instant_teleport_location->z != Convert::ToSingle(textBox_instant_teleport_location_z->Text))
				{
					SelectedTask->instant_teleport_location->z = Convert::ToSingle(textBox_instant_teleport_location_z->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}

	private: System::Void change_ai_trigger(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->ai_trigger != Convert::ToInt32(textBox_ai_trigger->Text))
				{
					SelectedTask->ai_trigger = Convert::ToInt32(textBox_ai_trigger->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}

	private: System::Void change_unknown_18(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->UNKNOWN_18 != checkBox_unknown_18->Checked)
				{
					SelectedTask->UNKNOWN_18 = checkBox_unknown_18->Checked;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_unknown_19(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->UNKNOWN_19 != checkBox_unknown_19->Checked)
				{
					SelectedTask->UNKNOWN_19 = checkBox_unknown_19->Checked;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_unknown_20(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->UNKNOWN_20 != checkBox_unknown_20->Checked)
				{
					SelectedTask->UNKNOWN_20 = checkBox_unknown_20->Checked;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_unknown_21(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->UNKNOWN_21 != checkBox_unknown_21->Checked)
				{
					SelectedTask->UNKNOWN_21 = checkBox_unknown_21->Checked;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_unknown_22(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->UNKNOWN_22 != checkBox_unknown_22->Checked)
				{
					SelectedTask->UNKNOWN_22 = checkBox_unknown_22->Checked;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_unknown_23(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->UNKNOWN_23 != checkBox_unknown_23->Checked)
				{
					SelectedTask->UNKNOWN_23 = checkBox_unknown_23->Checked;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_unknown_level(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->UNKNOWN_LEVEL != Convert::ToInt32(textBox_unknown_level->Text))
				{
					SelectedTask->UNKNOWN_LEVEL = Convert::ToInt32(textBox_unknown_level->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}

	private: System::Void change_mark_available_icon(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->mark_available_icon != checkBox_mark_available_icon->Checked)
				{
					SelectedTask->mark_available_icon = checkBox_mark_available_icon->Checked;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_mark_available_point(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->mark_available_point != checkBox_mark_available_point->Checked)
				{
					SelectedTask->mark_available_point = checkBox_mark_available_point->Checked;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_quest_npc(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->quest_npc != Convert::ToInt32(textBox_quest_npc->Text))
				{
					SelectedTask->quest_npc = Convert::ToInt32(textBox_quest_npc->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}

	private: System::Void change_reward_npc(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->reward_npc != Convert::ToInt32(textBox_reward_npc->Text))
				{
					SelectedTask->reward_npc = Convert::ToInt32(textBox_reward_npc->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}

	private: System::Void change_craft_skill(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->craft_skill != checkBox_craft_skill->Checked)
				{
					SelectedTask->craft_skill = checkBox_craft_skill->Checked;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_unknown_24(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->UNKNOWN_24 != checkBox_unknown_24->Checked)
				{
					SelectedTask->UNKNOWN_24 = checkBox_unknown_24->Checked;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_unknown_25(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->UNKNOWN_25 != checkBox_unknown_25->Checked)
				{
					SelectedTask->UNKNOWN_25 = checkBox_unknown_25->Checked;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_unknown_26(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->UNKNOWN_26 != checkBox_unknown_26->Checked)
				{
					SelectedTask->UNKNOWN_26 = checkBox_unknown_26->Checked;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_unknown_26_01(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedTask->UNKNOWN_26_01) != textBox_unknown_26_01->Text)
				{
					SelectedTask->UNKNOWN_26_01 = HexString_to_ByteArray(textBox_unknown_26_01->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}

	private: System::Void change_level_min(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->level_min != Convert::ToInt32(textBox_level_min->Text))
				{
					SelectedTask->level_min = Convert::ToInt32(textBox_level_min->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_level_max(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->level_max != Convert::ToInt32(textBox_level_max->Text))
				{
					SelectedTask->level_max = Convert::ToInt32(textBox_level_max->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	// requirements
	private: System::Void change_unknown_27(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->UNKNOWN_27 != checkBox_unknown_27->Checked)
				{
					SelectedTask->UNKNOWN_27 = checkBox_unknown_27->Checked;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	// required items
	private: System::Void change_required_items(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				int r = dataGridView_required_items->CurrentCell->RowIndex;
				switch(dataGridView_required_items->CurrentCell->ColumnIndex)
				{
					case 0:		SelectedTask->required_items[r]->id = Convert::ToInt32(dataGridView_required_items->CurrentCell->Value);
								break;
					case 1:		SelectedTask->required_items[r]->unknown = Convert::ToBoolean(dataGridView_required_items->CurrentCell->Value);
								break;
					case 2:		SelectedTask->required_items[r]->amount = Convert::ToInt32(dataGridView_required_items->CurrentCell->Value);
								break;
					case 3:		SelectedTask->required_items[r]->probability = Convert::ToSingle(dataGridView_required_items->CurrentCell->Value);
								break;
					case 4:		SelectedTask->required_items[r]->expiration = Convert::ToInt32(dataGridView_required_items->CurrentCell->Value);
								break;
				}
				// call debug function
				TriggerDebug((Control^)sender);
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void add_required_item(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			SelectedTask->required_items_count++;
			Array::Resize(SelectedTask->required_items, SelectedTask->required_items->Length+1);
			SelectedTask->required_items[SelectedTask->required_items->Length-1] = gcnew Item();

			SelectedTask->required_items[SelectedTask->required_items->Length-1]->id = 0;
			SelectedTask->required_items[SelectedTask->required_items->Length-1]->unknown = true;
			SelectedTask->required_items[SelectedTask->required_items->Length-1]->amount = 0;
			SelectedTask->required_items[SelectedTask->required_items->Length-1]->probability = 1.0;
			SelectedTask->required_items[SelectedTask->required_items->Length-1]->expiration = 0;

			dataGridView_required_items->Rows->Add(gcnew array<String^>{"0", "True", "0", "1.0", "0"});
		}
	}
	private: System::Void remove_required_item(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			if(SelectedTask->required_items_count>0 && dataGridView_required_items->CurrentCell->RowIndex>-1)
			{
				SelectedTask->required_items_count--;

				array<Item^>^ temp = gcnew array<Item^>(SelectedTask->required_items_count);
				Array::Copy(SelectedTask->required_items, 0, temp, 0, dataGridView_required_items->CurrentCell->RowIndex);
				Array::Copy(SelectedTask->required_items, dataGridView_required_items->CurrentCell->RowIndex+1, temp, dataGridView_required_items->CurrentCell->RowIndex, SelectedTask->required_items_count - dataGridView_required_items->CurrentCell->RowIndex);
				SelectedTask->required_items = temp;

				dataGridView_required_items->Rows->RemoveAt(dataGridView_required_items->CurrentCell->RowIndex);
			}
		}
	}
	private: System::Void change_required_items_unknown(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedTask->required_items_unknown) != textBox_required_items_unknown->Text)
				{
					SelectedTask->required_items_unknown = HexString_to_ByteArray(textBox_required_items_unknown->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}

	//
	private: System::Void change_unknown_28(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->UNKNOWN_28 != checkBox_unknown_28->Checked)
				{
					SelectedTask->UNKNOWN_28 = checkBox_unknown_28->Checked;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_unknown_28_01(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->UNKNOWN_28_01 != checkBox_unknown_28_01->Checked)
				{
					SelectedTask->UNKNOWN_28_01 = checkBox_unknown_28_01->Checked;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	// given items
	private: System::Void change_given_items(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				int r = dataGridView_given_items->CurrentCell->RowIndex;
				switch(dataGridView_given_items->CurrentCell->ColumnIndex)
				{
					case 0:		SelectedTask->given_items[r]->id = Convert::ToInt32(dataGridView_given_items->CurrentCell->Value);
								break;
					case 1:		SelectedTask->given_items[r]->unknown = Convert::ToBoolean(dataGridView_given_items->CurrentCell->Value);
								break;
					case 2:		SelectedTask->given_items[r]->amount = Convert::ToInt32(dataGridView_given_items->CurrentCell->Value);
								break;
					case 3:		SelectedTask->given_items[r]->probability = Convert::ToSingle(dataGridView_given_items->CurrentCell->Value);
								break;
					case 4:		SelectedTask->given_items[r]->expiration = Convert::ToInt32(dataGridView_given_items->CurrentCell->Value);
								break;
				}
				// call debug function
				TriggerDebug((Control^)sender);
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void add_given_item(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			SelectedTask->given_items_count++;
			Array::Resize(SelectedTask->given_items, SelectedTask->given_items->Length+1);
			SelectedTask->given_items[SelectedTask->given_items->Length-1] = gcnew Item();

			SelectedTask->given_items[SelectedTask->given_items->Length-1]->id = 0;
			SelectedTask->given_items[SelectedTask->given_items->Length-1]->unknown = true;
			SelectedTask->given_items[SelectedTask->given_items->Length-1]->amount = 0;
			SelectedTask->given_items[SelectedTask->given_items->Length-1]->probability = 1.0;
			SelectedTask->given_items[SelectedTask->given_items->Length-1]->expiration = 0;

			dataGridView_given_items->Rows->Add(gcnew array<String^>{"0", "True", "0", "1.0", "0"});
		}
	}
	private: System::Void remove_given_item(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			if(SelectedTask->given_items_count>0 && dataGridView_given_items->CurrentCell->RowIndex>-1)
			{
				SelectedTask->given_items_count--;

				array<Item^>^ temp = gcnew array<Item^>(SelectedTask->given_items_count);
				Array::Copy(SelectedTask->given_items, 0, temp, 0, dataGridView_given_items->CurrentCell->RowIndex);
				Array::Copy(SelectedTask->given_items, dataGridView_given_items->CurrentCell->RowIndex+1, temp, dataGridView_given_items->CurrentCell->RowIndex, SelectedTask->given_items_count - dataGridView_given_items->CurrentCell->RowIndex);
				SelectedTask->given_items = temp;

				dataGridView_given_items->Rows->RemoveAt(dataGridView_given_items->CurrentCell->RowIndex);
			}
		}
	}
	private: System::Void change_given_items_unknown(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedTask->given_items_unknown) != textBox_given_items_unknown->Text)
				{
					SelectedTask->given_items_unknown = HexString_to_ByteArray(textBox_given_items_unknown->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}

	//
	private: System::Void change_unknown_29(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->UNKNOWN_29 != Convert::ToInt32(textBox_unknown_29->Text))
				{
					SelectedTask->UNKNOWN_29 = Convert::ToInt32(textBox_unknown_29->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_unknown_30(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->UNKNOWN_30 != Convert::ToInt32(textBox_unknown_30->Text))
				{
					SelectedTask->UNKNOWN_30 = Convert::ToInt32(textBox_unknown_30->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}

	private: System::Void change_instant_pay_coins(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->instant_pay_coins != Convert::ToInt32(textBox_instant_pay_coins->Text))
				{
					SelectedTask->instant_pay_coins = Convert::ToInt32(textBox_instant_pay_coins->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_unknown_31(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->UNKNOWN_31 != checkBox_unknown_31->Checked)
				{
					SelectedTask->UNKNOWN_31 = checkBox_unknown_31->Checked;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	// quests done
	private: System::Void change_required_quests_done(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				int i = 0;
				SelectedTask->required_quests_done = gcnew array<int>(5);

				if(textBox_required_quests_done_1->Text != "0")	{ SelectedTask->required_quests_done[i] = Convert::ToInt32(textBox_required_quests_done_1->Text); i++; }
				if(textBox_required_quests_done_2->Text != "0")	{ SelectedTask->required_quests_done[i] = Convert::ToInt32(textBox_required_quests_done_2->Text); i++; }
				if(textBox_required_quests_done_3->Text != "0")	{ SelectedTask->required_quests_done[i] = Convert::ToInt32(textBox_required_quests_done_3->Text); i++; }
				if(textBox_required_quests_done_4->Text != "0")	{ SelectedTask->required_quests_done[i] = Convert::ToInt32(textBox_required_quests_done_4->Text); i++; }
				if(textBox_required_quests_done_5->Text != "0")	{ SelectedTask->required_quests_done[i] = Convert::ToInt32(textBox_required_quests_done_5->Text); i++; }

				SelectedTask->required_quests_done_count = i;

				// call debug function
				TriggerDebug((Control^)sender);
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	//
	private: System::Void change_required_reputation(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->required_reputation != Convert::ToInt32(textBox_required_reputation->Text))
				{
					SelectedTask->required_reputation = Convert::ToInt32(textBox_required_reputation->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_unknown_32(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedTask->UNKNOWN_32) != textBox_unknown_32->Text)
				{
					SelectedTask->UNKNOWN_32 = HexString_to_ByteArray(textBox_unknown_32->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_unknown_33(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->UNKNOWN_33 != checkBox_unknown_33->Checked)
				{
					SelectedTask->UNKNOWN_33 = checkBox_unknown_33->Checked;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_unknown_34(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedTask->UNKNOWN_34) != textBox_unknown_34->Text)
				{
					SelectedTask->UNKNOWN_34 = HexString_to_ByteArray(textBox_unknown_34->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_unknown_35(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->UNKNOWN_35 != checkBox_unknown_35->Checked)
				{
					SelectedTask->UNKNOWN_35 = checkBox_unknown_35->Checked;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_unknown_36(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->UNKNOWN_36 != Convert::ToInt32(textBox_unknown_36->Text))
				{
					SelectedTask->UNKNOWN_36 = Convert::ToInt32(textBox_unknown_36->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_required_cultivation(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				switch(comboBox_required_cultivation->SelectedIndex)
				{
					case 0:		SelectedTask->required_cultivation = 0;
								break;
					case 1:		SelectedTask->required_cultivation = 1;
								break;
					case 2:		SelectedTask->required_cultivation = 2;
								break;
					case 3:		SelectedTask->required_cultivation = 3;
								break;
					case 4:		SelectedTask->required_cultivation = 4;
								break;
					case 5:		SelectedTask->required_cultivation = 5;
								break;
					case 6:		SelectedTask->required_cultivation = 6;
								break;
					case 7:		SelectedTask->required_cultivation = 7;
								break;
					case 8:		SelectedTask->required_cultivation = 8;
								break;
					case 9:		SelectedTask->required_cultivation = 20;
								break;
					case 10:	SelectedTask->required_cultivation = 30;
								break;
					case 11:	SelectedTask->required_cultivation = 21;
								break;
					case 12:	SelectedTask->required_cultivation = 31;
								break;
					case 13:	SelectedTask->required_cultivation = 22;
								break;
					case 14:	SelectedTask->required_cultivation = 32;
								break;
				}

				// call debug function
				TriggerDebug((Control^)sender);
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_unknown_37(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedTask->UNKNOWN_37) != textBox_unknown_37->Text)
				{
					SelectedTask->UNKNOWN_37 = HexString_to_ByteArray(textBox_unknown_37->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_unknown_38(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->UNKNOWN_38 != Convert::ToInt32(textBox_unknown_38->Text))
				{
					SelectedTask->UNKNOWN_38 = Convert::ToInt32(textBox_unknown_38->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_unknown_39(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->UNKNOWN_39 != checkBox_unknown_39->Checked)
				{
					SelectedTask->UNKNOWN_39 = checkBox_unknown_39->Checked;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_required_gender(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->required_gender != comboBox_required_gender->SelectedIndex)
				{
					SelectedTask->required_gender = comboBox_required_gender->SelectedIndex;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_unknown_40(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->UNKNOWN_40 != checkBox_unknown_40->Checked)
				{
					SelectedTask->UNKNOWN_40 = checkBox_unknown_40->Checked;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_unknown_41(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->UNKNOWN_41 != checkBox_unknown_41->Checked)
				{
					SelectedTask->UNKNOWN_41 = checkBox_unknown_41->Checked;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_required_be_married(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->required_be_married != checkBox_required_be_married->Checked)
				{
					SelectedTask->required_be_married = checkBox_required_be_married->Checked;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_unknown_42(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->UNKNOWN_42 != checkBox_unknown_42->Checked)
				{
					SelectedTask->UNKNOWN_42 = checkBox_unknown_42->Checked;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_unknown_42_1(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->UNKNOWN_42_1 != checkBox_unknown_42_1->Checked)
				{
					SelectedTask->UNKNOWN_42_1 = checkBox_unknown_42_1->Checked;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_unknown_42_2(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->UNKNOWN_42_2 != checkBox_unknown_42_2->Checked)
				{
					SelectedTask->UNKNOWN_42_2 = checkBox_unknown_42_2->Checked;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_required_be_gm(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->required_be_gm != checkBox_required_be_gm->Checked)
				{
					SelectedTask->required_be_gm = checkBox_required_be_gm->Checked;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_unknown_43(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->UNKNOWN_43 != checkBox_unknown_43->Checked)
				{
					SelectedTask->UNKNOWN_43 = checkBox_unknown_43->Checked;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	// occupations
	private: System::Void change_required_occupations(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				int i = 0;
				SelectedTask->required_occupations = gcnew array<int>(10);

				if(checkBox_occupation_blademaster->Checked)	{ SelectedTask->required_occupations[i] = 0; i++; }
				if(checkBox_occupation_wizard->Checked)			{ SelectedTask->required_occupations[i] = 1; i++; }
				if(checkBox_occupation_psychic->Checked)		{ SelectedTask->required_occupations[i] = 2; i++; }
				if(checkBox_occupation_venomancer->Checked)		{ SelectedTask->required_occupations[i] = 3; i++; }
				if(checkBox_occupation_barbarian->Checked)		{ SelectedTask->required_occupations[i] = 4; i++; }
				if(checkBox_occupation_assassin->Checked)		{ SelectedTask->required_occupations[i] = 5; i++; }
				if(checkBox_occupation_archer->Checked)			{ SelectedTask->required_occupations[i] = 6; i++; }
				if(checkBox_occupation_cleric->Checked)			{ SelectedTask->required_occupations[i] = 7; i++; }
				if(checkBox_occupation_seeker->Checked)			{ SelectedTask->required_occupations[i] = 8; i++; }
				if(checkBox_occupation_mystic->Checked)			{ SelectedTask->required_occupations[i] = 9; i++; }

				SelectedTask->required_occupations_count = i;

				// call debug function
				TriggerDebug((Control^)sender);
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	//
	private: System::Void change_unknown_44(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedTask->UNKNOWN_44) != textBox_unknown_44->Text)
				{
					SelectedTask->UNKNOWN_44 = HexString_to_ByteArray(textBox_unknown_44->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_date_unknown(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				int r = dataGridView_date_unknown->CurrentCell->RowIndex;
				switch (dataGridView_date_unknown->CurrentCell->ColumnIndex)
				{
					case 0:		SelectedTask->date_unknown->year = Convert::ToInt32(dataGridView_date_unknown->CurrentCell->Value);
								break;
					case 1:		SelectedTask->date_unknown->month = Convert::ToInt32(dataGridView_date_unknown->CurrentCell->Value);
								break;
					case 2:		SelectedTask->date_unknown->day = Convert::ToInt32(dataGridView_date_unknown->CurrentCell->Value);
								break;
					case 3:		SelectedTask->date_unknown->hour = Convert::ToInt32(dataGridView_date_unknown->CurrentCell->Value);
								break;
					case 4:		SelectedTask->date_unknown->minute = Convert::ToInt32(dataGridView_date_unknown->CurrentCell->Value);
								break;
					case 5:		SelectedTask->date_unknown->weekday = Column_date_fail_weekday->Items->IndexOf(dataGridView_date_unknown->CurrentCell->Value);
								break;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_unknown_45(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->UNKNOWN_45 != Convert::ToInt32(textBox_unknown_45->Text))
				{
					SelectedTask->UNKNOWN_45 = Convert::ToInt32(textBox_unknown_45->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_unknown_46(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->UNKNOWN_46 != checkBox_unknown_46->Checked)
				{
					SelectedTask->UNKNOWN_46 = checkBox_unknown_46->Checked;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_unknown_47(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedTask->UNKNOWN_47) != textBox_unknown_47->Text)
				{
					SelectedTask->UNKNOWN_47 = HexString_to_ByteArray(textBox_unknown_47->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	// quests undone
	private: System::Void change_required_quests_undone(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				int i = 0;
				SelectedTask->required_quests_undone = gcnew array<int>(5);

				if(textBox_required_quests_undone_1->Text != "0")	{ SelectedTask->required_quests_undone[i] = Convert::ToInt32(textBox_required_quests_undone_1->Text); i++; }
				if(textBox_required_quests_undone_2->Text != "0")	{ SelectedTask->required_quests_undone[i] = Convert::ToInt32(textBox_required_quests_undone_2->Text); i++; }
				if(textBox_required_quests_undone_3->Text != "0")	{ SelectedTask->required_quests_undone[i] = Convert::ToInt32(textBox_required_quests_undone_3->Text); i++; }
				if(textBox_required_quests_undone_4->Text != "0")	{ SelectedTask->required_quests_undone[i] = Convert::ToInt32(textBox_required_quests_undone_4->Text); i++; }
				if(textBox_required_quests_undone_5->Text != "0")	{ SelectedTask->required_quests_undone[i] = Convert::ToInt32(textBox_required_quests_undone_5->Text); i++; }

				SelectedTask->required_quests_undone_count = i;

				// call debug function
				TriggerDebug((Control^)sender);
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	// skills
	private: System::Void change_required_blacksmith_level(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->required_blacksmith_level != Convert::ToInt32(textBox_required_blacksmith_level->Text))
				{
					SelectedTask->required_blacksmith_level = Convert::ToInt32(textBox_required_blacksmith_level->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_required_tailor_level(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->required_tailor_level != Convert::ToInt32(textBox_required_tailor_level->Text))
				{
					SelectedTask->required_tailor_level = Convert::ToInt32(textBox_required_tailor_level->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_required_craftsman_level(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->required_craftsman_level != Convert::ToInt32(textBox_required_craftsman_level->Text))
				{
					SelectedTask->required_craftsman_level = Convert::ToInt32(textBox_required_craftsman_level->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_required_apothecary_level(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->required_apothecary_level != Convert::ToInt32(textBox_required_apothecary_level->Text))
				{
					SelectedTask->required_apothecary_level = Convert::ToInt32(textBox_required_apothecary_level->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	//
	private: System::Void change_unknown_48(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedTask->UNKNOWN_48) != textBox_unknown_48->Text)
				{
					SelectedTask->UNKNOWN_48 = HexString_to_ByteArray(textBox_unknown_48->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_unknown_49(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedTask->UNKNOWN_49) != textBox_unknown_49->Text)
				{
					SelectedTask->UNKNOWN_49 = HexString_to_ByteArray(textBox_unknown_49->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	// team members
	private: System::Void change_required_team_member_groups(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				int r = dataGridView_team_members->CurrentCell->RowIndex;
				switch(dataGridView_team_members->CurrentCell->ColumnIndex)
				{
					case 0:		SelectedTask->required_team_member_groups[r]->level_min = Convert::ToInt32(dataGridView_team_members->CurrentCell->Value);
								break;
					case 1:		SelectedTask->required_team_member_groups[r]->level_max = Convert::ToInt32(dataGridView_team_members->CurrentCell->Value);
								break;
					case 2:		SelectedTask->required_team_member_groups[r]->unknown_1 = Convert::ToInt32(dataGridView_team_members->CurrentCell->Value);
								break;
					case 3:		SelectedTask->required_team_member_groups[r]->unknown_2 = Convert::ToInt32(dataGridView_team_members->CurrentCell->Value);
								break;
					case 4:		SelectedTask->required_team_member_groups[r]->unknown_3 = Convert::ToInt32(dataGridView_team_members->CurrentCell->Value);
								break;
					case 5:		SelectedTask->required_team_member_groups[r]->amount_min = Convert::ToInt32(dataGridView_team_members->CurrentCell->Value);
								break;
					case 6:		SelectedTask->required_team_member_groups[r]->amount_max = Convert::ToInt32(dataGridView_team_members->CurrentCell->Value);
								break;
					case 7:		SelectedTask->required_team_member_groups[r]->quest = Convert::ToInt32(dataGridView_team_members->CurrentCell->Value);
								break;
					case 8:		if(Column18->Items->IndexOf(dataGridView_team_members->CurrentCell->Value) > 0)
								{
									SelectedTask->required_team_member_groups[r]->force = Column18->Items->IndexOf(dataGridView_team_members->CurrentCell->Value)+1003;
								}
								else
								{
									SelectedTask->required_team_member_groups[r]->force = 0;
								}
								break;
				}
				// call debug function
				TriggerDebug((Control^)sender);
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void add_required_team_member_group(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			SelectedTask->required_team_member_groups_count++;
			Array::Resize(SelectedTask->required_team_member_groups, SelectedTask->required_team_member_groups->Length+1);
			SelectedTask->required_team_member_groups[SelectedTask->required_team_member_groups->Length-1] = gcnew TeamMembers();

			SelectedTask->required_team_member_groups[SelectedTask->required_team_member_groups->Length-1]->level_min = 1;
			SelectedTask->required_team_member_groups[SelectedTask->required_team_member_groups->Length-1]->level_max = 150;
			SelectedTask->required_team_member_groups[SelectedTask->required_team_member_groups->Length-1]->unknown_1 = 0;
			SelectedTask->required_team_member_groups[SelectedTask->required_team_member_groups->Length-1]->unknown_2 = 0;
			SelectedTask->required_team_member_groups[SelectedTask->required_team_member_groups->Length-1]->unknown_3 = 0;
			SelectedTask->required_team_member_groups[SelectedTask->required_team_member_groups->Length-1]->amount_min = 1;
			SelectedTask->required_team_member_groups[SelectedTask->required_team_member_groups->Length-1]->amount_max = 5;
			SelectedTask->required_team_member_groups[SelectedTask->required_team_member_groups->Length-1]->quest = 0;
			SelectedTask->required_team_member_groups[SelectedTask->required_team_member_groups->Length-1]->force = 0;

			dataGridView_team_members->Rows->Add(gcnew array<String^>{"1", "150", "0", "0", "0", "1", "5", "0", Column18->Items[0]->ToString()});
		}
	}
	private: System::Void remove_required_team_member_group(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			if(SelectedTask->required_team_member_groups_count>0 && dataGridView_team_members->CurrentCell->RowIndex>-1)
			{
				SelectedTask->required_team_member_groups_count--;

				array<TeamMembers^>^ temp = gcnew array<TeamMembers^>(SelectedTask->required_team_member_groups_count);
				Array::Copy(SelectedTask->required_team_member_groups, 0, temp, 0, dataGridView_team_members->CurrentCell->RowIndex);
				Array::Copy(SelectedTask->required_team_member_groups, dataGridView_team_members->CurrentCell->RowIndex+1, temp, dataGridView_team_members->CurrentCell->RowIndex, SelectedTask->required_team_member_groups_count - dataGridView_team_members->CurrentCell->RowIndex);
				SelectedTask->required_team_member_groups = temp;

				dataGridView_team_members->Rows->RemoveAt(dataGridView_team_members->CurrentCell->RowIndex);
			}
		}
	}
	//
	private: System::Void change_unknown_50(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedTask->UNKNOWN_50) != textBox_unknown_50->Text)
				{
					SelectedTask->UNKNOWN_50 = HexString_to_ByteArray(textBox_unknown_50->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_unknown_51(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->UNKNOWN_51 != checkBox_unknown_51->Checked)
				{
					SelectedTask->UNKNOWN_51 = checkBox_unknown_51->Checked;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_unknown_52(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedTask->UNKNOWN_52) != textBox_unknown_52->Text)
				{
					SelectedTask->UNKNOWN_52 = HexString_to_ByteArray(textBox_unknown_52->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_resource_pq_audit_id(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->resource_pq_audit_id != Convert::ToInt32(textBox_resource_pq_audit_id->Text))
				{
					SelectedTask->resource_pq_audit_id = Convert::ToInt32(textBox_resource_pq_audit_id->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_unknown_53(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->UNKNOWN_53 != Convert::ToInt32(textBox_unknown_53->Text))
				{
					SelectedTask->UNKNOWN_53 = Convert::ToInt32(textBox_unknown_53->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_unknown_54(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->UNKNOWN_54 != Convert::ToInt32(textBox_unknown_54->Text))
				{
					SelectedTask->UNKNOWN_54 = Convert::ToInt32(textBox_unknown_54->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_required_pq_contribution(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->required_pq_contribution != Convert::ToInt32(textBox_required_pq_contribution->Text))
				{
					SelectedTask->required_pq_contribution = Convert::ToInt32(textBox_required_pq_contribution->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_unknown_55(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedTask->UNKNOWN_55) != textBox_unknown_55->Text)
				{
					SelectedTask->UNKNOWN_55 = HexString_to_ByteArray(textBox_unknown_55->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_unknown_55_02_01(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedTask->UNKNOWN_55_02_01) != textBox_unknown_55_02_01->Text)
				{
					SelectedTask->UNKNOWN_55_02_01 = HexString_to_ByteArray(textBox_unknown_55_02_01->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_required_force(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				if(comboBox_required_force->SelectedIndex > 0)
				{
					SelectedTask->required_force = comboBox_required_force->SelectedIndex + 1003;
				}
				else
				{
					SelectedTask->required_force = 0;
				}

				// call debug function
				TriggerDebug((Control^)sender);
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_unknown_55_02_02(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedTask->UNKNOWN_55_02_02) != textBox_unknown_55_02_02->Text)
				{
					SelectedTask->UNKNOWN_55_02_02 = HexString_to_ByteArray(textBox_unknown_55_02_02->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_required_prestige(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->required_prestige != Convert::ToInt32(textBox_required_prestige->Text))
				{
					SelectedTask->required_prestige = Convert::ToInt32(textBox_required_prestige->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_unknown_55_03(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedTask->UNKNOWN_55_03) != textBox_unknown_55_03->Text)
				{
					SelectedTask->UNKNOWN_55_03 = HexString_to_ByteArray(textBox_unknown_55_03->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_required_influence_fee(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->required_influence_fee != Convert::ToInt32(textBox_required_influence_fee->Text))
				{
					SelectedTask->required_influence_fee = Convert::ToInt32(textBox_required_influence_fee->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_unknown_55_04(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedTask->UNKNOWN_55_04) != textBox_unknown_55_04->Text)
				{
					SelectedTask->UNKNOWN_55_04 = HexString_to_ByteArray(textBox_unknown_55_04->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_unknown_55_05(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedTask->UNKNOWN_55_05) != textBox_unknown_55_05->Text)
				{
					SelectedTask->UNKNOWN_55_05 = HexString_to_ByteArray(textBox_unknown_55_05->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_unknown_55_06(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedTask->UNKNOWN_55_06) != textBox_unknown_55_06->Text)
				{
					SelectedTask->UNKNOWN_55_06 = HexString_to_ByteArray(textBox_unknown_55_06->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_required_success_type(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->required_success_type != Convert::ToInt32(textBox_required_success_type->Text))
				{
					SelectedTask->required_success_type = Convert::ToInt32(textBox_required_success_type->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_required_npc_type(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->required_npc_type != Convert::ToInt32(textBox_required_npc_type->Text))
				{
					SelectedTask->required_npc_type = Convert::ToInt32(textBox_required_npc_type->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	// morai pk
	private: System::Void change_required_morai_pk(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				int r = dataGridView_required_morai_pk->CurrentCell->RowIndex;
				switch(dataGridView_required_morai_pk->CurrentCell->ColumnIndex)
				{
					case 0:		SelectedTask->required_morai_pk[r]->unknown_1 = Convert::ToInt32(dataGridView_required_morai_pk->CurrentCell->Value);
								break;
					case 1:		SelectedTask->required_morai_pk[r]->unknown_2 = Convert::ToInt32(dataGridView_required_morai_pk->CurrentCell->Value);
								break;
					case 2:		SelectedTask->required_morai_pk[r]->unknown_3 = Convert::ToInt32(dataGridView_required_morai_pk->CurrentCell->Value);
								break;
					case 3:		SelectedTask->required_morai_pk[r]->unknown_4 = Convert::ToByte(dataGridView_required_morai_pk->CurrentCell->Value);
								break;
					case 4:		SelectedTask->required_morai_pk[r]->probability = Convert::ToSingle(dataGridView_required_morai_pk->CurrentCell->Value);
								break;
					case 5:		SelectedTask->required_morai_pk[r]->class_mask = Convert::ToInt32(dataGridView_required_morai_pk->CurrentCell->Value);
								break;
					case 6:		SelectedTask->required_morai_pk[r]->level_min = Convert::ToInt32(dataGridView_required_morai_pk->CurrentCell->Value);
								break;
					case 7:		SelectedTask->required_morai_pk[r]->level_max = Convert::ToInt32(dataGridView_required_morai_pk->CurrentCell->Value);
								break;
					case 8:		SelectedTask->required_morai_pk[r]->unknown_5 = Convert::ToInt32(dataGridView_required_morai_pk->CurrentCell->Value);
								break;
					case 9:		SelectedTask->required_morai_pk[r]->type = Column28->Items->IndexOf(dataGridView_required_morai_pk->CurrentCell->Value);
								break;
				}
				// call debug function
				TriggerDebug((Control^)sender);
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}

	private: System::Void add_required_morai_pk(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			SelectedTask->required_morai_pk_count++;
			Array::Resize(SelectedTask->required_morai_pk, SelectedTask->required_morai_pk->Length+1);
			SelectedTask->required_morai_pk[SelectedTask->required_morai_pk->Length-1] = gcnew MoraiPK();

			SelectedTask->required_morai_pk[SelectedTask->required_morai_pk->Length-1]->unknown_1 = 1;
			SelectedTask->required_morai_pk[SelectedTask->required_morai_pk->Length-1]->unknown_2 = 0;
			SelectedTask->required_morai_pk[SelectedTask->required_morai_pk->Length-1]->unknown_3 = 1;
			SelectedTask->required_morai_pk[SelectedTask->required_morai_pk->Length-1]->unknown_4 = 0;
			SelectedTask->required_morai_pk[SelectedTask->required_morai_pk->Length-1]->probability = 1.0f;
			SelectedTask->required_morai_pk[SelectedTask->required_morai_pk->Length-1]->class_mask = 1023;
			SelectedTask->required_morai_pk[SelectedTask->required_morai_pk->Length-1]->level_min = 0;
			SelectedTask->required_morai_pk[SelectedTask->required_morai_pk->Length-1]->level_max = 150;
			SelectedTask->required_morai_pk[SelectedTask->required_morai_pk->Length-1]->unknown_5 = 0;
			SelectedTask->required_morai_pk[SelectedTask->required_morai_pk->Length-1]->type = 0;

			dataGridView_required_morai_pk->Rows->Add(gcnew array<String^>{"1", "0", "1", "0", "1.0", "1023", "0", "150", "0", Column28->Items[0]->ToString()});
		}
	}
	private: System::Void remove_required_morai_pk(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			if(SelectedTask->required_morai_pk_count>0 && dataGridView_required_morai_pk->CurrentCell->RowIndex>-1)
			{
				SelectedTask->required_morai_pk_count--;

				array<MoraiPK^>^ temp = gcnew array<MoraiPK^>(SelectedTask->required_morai_pk_count);
				Array::Copy(SelectedTask->required_morai_pk, 0, temp, 0, dataGridView_required_morai_pk->CurrentCell->RowIndex);
				Array::Copy(SelectedTask->required_morai_pk, dataGridView_required_morai_pk->CurrentCell->RowIndex+1, temp, dataGridView_required_morai_pk->CurrentCell->RowIndex, SelectedTask->required_morai_pk_count - dataGridView_required_morai_pk->CurrentCell->RowIndex);
				SelectedTask->required_morai_pk = temp;

				dataGridView_required_morai_pk->Rows->RemoveAt(dataGridView_required_morai_pk->CurrentCell->RowIndex);
			}
		}
	}
	private: System::Void change_required_morai_pk_unknown(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedTask->required_morai_pk_unknown) != textBox_required_morai_pk_unknown->Text)
				{
					SelectedTask->required_morai_pk_unknown = HexString_to_ByteArray(textBox_required_morai_pk_unknown->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	// chases
	private: System::Void change_required_chases(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				int r = dataGridView_required_chases->CurrentCell->RowIndex;
				switch(dataGridView_required_chases->CurrentCell->ColumnIndex)
				{
					case 0:		SelectedTask->required_chases[r]->id_monster = Convert::ToInt32(dataGridView_required_chases->CurrentCell->Value);
								break;
					case 1:		SelectedTask->required_chases[r]->amount_monster = Convert::ToInt32(dataGridView_required_chases->CurrentCell->Value);
								break;
					case 2:		SelectedTask->required_chases[r]->id_drop = Convert::ToInt32(dataGridView_required_chases->CurrentCell->Value);
								break;
					case 3:		SelectedTask->required_chases[r]->amount_drop = Convert::ToInt32(dataGridView_required_chases->CurrentCell->Value);
								break;
					case 4:		SelectedTask->required_chases[r]->unknown_1 = Convert::ToByte(dataGridView_required_items->CurrentCell->Value);
								break;
					case 5:		SelectedTask->required_chases[r]->probability = Convert::ToSingle(dataGridView_required_items->CurrentCell->Value);
								break;
					case 6:		SelectedTask->required_chases[r]->unknown_2 = Convert::ToByte(dataGridView_required_items->CurrentCell->Value);
								break;
					case 7:		SelectedTask->required_chases[r]->unknown_3 = HexString_to_ByteArray(Convert::ToString(dataGridView_required_items->CurrentCell->Value));
								break;
				}
				// call debug function
				TriggerDebug((Control^)sender);
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void add_required_chase(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			SelectedTask->required_chases_count++;
			Array::Resize(SelectedTask->required_chases, SelectedTask->required_chases->Length+1);
			SelectedTask->required_chases[SelectedTask->required_chases->Length-1] = gcnew Chase();

			SelectedTask->required_chases[SelectedTask->required_chases->Length-1]->id_monster = 0;
			SelectedTask->required_chases[SelectedTask->required_chases->Length-1]->amount_monster = 0;
			SelectedTask->required_chases[SelectedTask->required_chases->Length-1]->id_drop = 0;
			SelectedTask->required_chases[SelectedTask->required_chases->Length-1]->amount_drop = 0;
			SelectedTask->required_chases[SelectedTask->required_chases->Length-1]->unknown_1 = 0;
			SelectedTask->required_chases[SelectedTask->required_chases->Length-1]->probability = 1.0;
			SelectedTask->required_chases[SelectedTask->required_chases->Length-1]->unknown_2 = 0;
			SelectedTask->required_chases[SelectedTask->required_chases->Length-1]->unknown_3 = gcnew array<unsigned char>(8);

			dataGridView_required_chases->Rows->Add(gcnew array<String^>{"0", "0", "0", "0", "0", "1.0", "0", "00-00-00-00-00-00-00-00"});
		}
	}
	private: System::Void remove_required_chases(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			if(SelectedTask->required_chases_count>0 && dataGridView_required_chases->CurrentCell->RowIndex>-1)
			{
				SelectedTask->required_chases_count--;

				array<Chase^>^ temp = gcnew array<Chase^>(SelectedTask->required_chases_count);
				Array::Copy(SelectedTask->required_chases, 0, temp, 0, dataGridView_required_chases->CurrentCell->RowIndex);
				Array::Copy(SelectedTask->required_chases, dataGridView_required_chases->CurrentCell->RowIndex+1, temp, dataGridView_required_chases->CurrentCell->RowIndex, SelectedTask->required_chases_count - dataGridView_required_chases->CurrentCell->RowIndex);
				SelectedTask->required_chases = temp;

				dataGridView_required_chases->Rows->RemoveAt(dataGridView_required_chases->CurrentCell->RowIndex);
			}
		}
	}
	private: System::Void change_required_chases_unknown(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedTask->required_chases_unknown) != textBox_required_chases_unknown->Text)
				{
					SelectedTask->required_chases_unknown = HexString_to_ByteArray(textBox_required_chases_unknown->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	// get items
	private: System::Void change_required_get_items(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				int r = dataGridView_required_get_items->CurrentCell->RowIndex;
				switch(dataGridView_required_get_items->CurrentCell->ColumnIndex)
				{
					case 0:		SelectedTask->required_get_items[r]->id = Convert::ToInt32(dataGridView_required_get_items->CurrentCell->Value);
								break;
					case 1:		SelectedTask->required_get_items[r]->unknown = Convert::ToBoolean(dataGridView_required_get_items->CurrentCell->Value);
								break;
					case 2:		SelectedTask->required_get_items[r]->amount = Convert::ToInt32(dataGridView_required_get_items->CurrentCell->Value);
								break;
					case 3:		SelectedTask->required_get_items[r]->probability = Convert::ToSingle(dataGridView_required_get_items->CurrentCell->Value);
								break;
					case 4:		SelectedTask->required_get_items[r]->expiration = Convert::ToInt32(dataGridView_required_get_items->CurrentCell->Value);
								break;
				}
				// call debug function
				TriggerDebug((Control^)sender);
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void add_required_get_item(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			SelectedTask->required_get_items_count++;
			Array::Resize(SelectedTask->required_get_items, SelectedTask->required_get_items->Length+1);
			SelectedTask->required_get_items[SelectedTask->required_get_items->Length-1] = gcnew Item();

			SelectedTask->required_get_items[SelectedTask->required_get_items->Length-1]->id = 0;
			SelectedTask->required_get_items[SelectedTask->required_get_items->Length-1]->unknown = true;
			SelectedTask->required_get_items[SelectedTask->required_get_items->Length-1]->amount = 0;
			SelectedTask->required_get_items[SelectedTask->required_get_items->Length-1]->probability = 1.0;
			SelectedTask->required_get_items[SelectedTask->required_get_items->Length-1]->expiration = 0;

			dataGridView_required_get_items->Rows->Add(gcnew array<String^>{"0", "True", "0", "1.0", "0"});
		}
	}
	private: System::Void remove_required_get_item(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			if(SelectedTask->required_get_items_count>0 && dataGridView_required_get_items->CurrentCell->RowIndex>-1)
			{
				SelectedTask->required_get_items_count--;

				array<Item^>^ temp = gcnew array<Item^>(SelectedTask->required_get_items_count);
				Array::Copy(SelectedTask->required_get_items, 0, temp, 0, dataGridView_required_get_items->CurrentCell->RowIndex);
				Array::Copy(SelectedTask->required_get_items, dataGridView_required_get_items->CurrentCell->RowIndex+1, temp, dataGridView_required_get_items->CurrentCell->RowIndex, SelectedTask->required_get_items_count - dataGridView_required_get_items->CurrentCell->RowIndex);
				SelectedTask->required_get_items = temp;

				dataGridView_required_get_items->Rows->RemoveAt(dataGridView_required_get_items->CurrentCell->RowIndex);
			}
		}
	}
	private: System::Void change_required_get_items_unknown(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedTask->required_get_items_unknown) != textBox_required_get_items_unknown->Text)
				{
					SelectedTask->required_get_items_unknown = HexString_to_ByteArray(textBox_required_get_items_unknown->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	//
	private: System::Void change_required_coins(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->required_coins != Convert::ToInt32(textBox_required_coins->Text))
				{
					SelectedTask->required_coins = Convert::ToInt32(textBox_required_coins->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_unknown_56(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedTask->UNKNOWN_56) != textBox_unknown_56->Text)
				{
					SelectedTask->UNKNOWN_56 = HexString_to_ByteArray(textBox_unknown_56->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_unknown_57(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedTask->UNKNOWN_57) != textBox_unknown_57->Text)
				{
					SelectedTask->UNKNOWN_57 = HexString_to_ByteArray(textBox_unknown_57->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_required_wait_time(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->required_wait_time != Convert::ToInt32(textBox_required_wait_time->Text))
				{
					SelectedTask->required_wait_time = Convert::ToInt32(textBox_required_wait_time->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_unknown_57_01(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedTask->UNKNOWN_57_01) != textBox_unknown_57_01->Text)
				{
					SelectedTask->UNKNOWN_57_01 = HexString_to_ByteArray(textBox_unknown_57_01->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	// pq script infos
	private: System::Void change_pq_script_infos(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				int r = dataGridView_pq_script_infos->CurrentCell->RowIndex;
				switch(dataGridView_pq_script_infos->CurrentCell->ColumnIndex)
				{
					case 0:		SelectedTask->pq->script_infos[r]->id = Convert::ToInt32(dataGridView_required_get_items->CurrentCell->Value);
								break;
					case 1:		SelectedTask->pq->script_infos[r]->unknown_1 = Convert::ToInt32(dataGridView_required_get_items->CurrentCell->Value);
								break;
					case 2:		SelectedTask->pq->script_infos[r]->unknown_2 = HexString_to_ByteArray(Convert::ToString(dataGridView_required_get_items->CurrentCell->Value));
								break;
				}
				// call debug function
				TriggerDebug((Control^)sender);
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void add_pq_script_info(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			SelectedTask->pq->script_info_count++;
			Array::Resize(SelectedTask->pq->script_infos, SelectedTask->pq->script_infos->Length+1);
			SelectedTask->pq->script_infos[SelectedTask->pq->script_infos->Length-1] = gcnew PQ_AuditScriptInfo();

			SelectedTask->pq->script_infos[SelectedTask->pq->script_infos->Length-1]->id = 0;
			SelectedTask->pq->script_infos[SelectedTask->pq->script_infos->Length-1]->unknown_1 = 0;
			SelectedTask->pq->script_infos[SelectedTask->pq->script_infos->Length-1]->unknown_2 = gcnew array<unsigned char>(1);

			dataGridView_pq_script_infos->Rows->Add(gcnew array<String^>{"0", "0", "00"});
		}
	}
	private: System::Void remove_pq_script_info(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			if(SelectedTask->pq->script_info_count>0 && dataGridView_pq_script_infos->CurrentCell->RowIndex>-1)
			{
				SelectedTask->pq->script_info_count--;

				array<PQ_AuditScriptInfo^>^ temp = gcnew array<PQ_AuditScriptInfo^>(SelectedTask->pq->script_info_count);
				Array::Copy(SelectedTask->pq->script_infos, 0, temp, 0, dataGridView_pq_script_infos->CurrentCell->RowIndex);
				Array::Copy(SelectedTask->pq->script_infos, dataGridView_pq_script_infos->CurrentCell->RowIndex+1, temp, dataGridView_pq_script_infos->CurrentCell->RowIndex, SelectedTask->pq->script_info_count - dataGridView_pq_script_infos->CurrentCell->RowIndex);
				SelectedTask->pq->script_infos = temp;

				dataGridView_pq_script_infos->Rows->RemoveAt(dataGridView_pq_script_infos->CurrentCell->RowIndex);
			}
		}
	}
	//
	private: System::Void change_pq_unknown_1(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedTask->pq->unknown_1) != textBox_pq_unknown_1->Text)
				{
					SelectedTask->pq->unknown_1 = HexString_to_ByteArray(textBox_pq_unknown_1->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_pq_unknown_2(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->pq->unknown_2 != Convert::ToInt32(textBox_pq_unknown_2->Text))
				{
					SelectedTask->pq->unknown_2 = Convert::ToInt32(textBox_pq_unknown_2->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_pq_unknown_3(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedTask->pq->unknown_3) != textBox_pq_unknown_3->Text)
				{
					SelectedTask->pq->unknown_3 = HexString_to_ByteArray(textBox_pq_unknown_3->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	// pq scripts
	private: System::Void change_pq_scripts(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				int r = dataGridView_pq_scripts->CurrentCell->RowIndex;
				switch(dataGridView_pq_scripts->CurrentCell->ColumnIndex)
				{
					case 0:		SelectedTask->pq->scripts[r]->Name = Convert::ToString(dataGridView_pq_scripts->CurrentCell->Value);
								break;
					case 1:		SelectedTask->pq->scripts[r]->count = Convert::ToInt32(dataGridView_pq_scripts->CurrentCell->Value);
								break;
					case 2:		SelectedTask->pq->scripts[r]->id = Convert::ToSingle(dataGridView_pq_scripts->CurrentCell->Value);
								break;
					case 3:		SelectedTask->pq->scripts[r]->seperator = HexString_to_ByteArray(Convert::ToString(dataGridView_pq_scripts->CurrentCell->Value));
								break;
					case 4:		SelectedTask->pq->scripts[r]->reference_id = Convert::ToSingle(dataGridView_pq_scripts->CurrentCell->Value);
								break;
					case 5:		SelectedTask->pq->scripts[r]->code = HexString_to_ByteArray(Convert::ToString(dataGridView_pq_scripts->CurrentCell->Value));
								break;
				}
				// call debug function
				TriggerDebug((Control^)sender);
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void add_pq_script(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			SelectedTask->pq->script_count++;
			Array::Resize(SelectedTask->pq->scripts, SelectedTask->pq->scripts->Length+1);
			SelectedTask->pq->scripts[SelectedTask->pq->scripts->Length-1] = gcnew PQ_AuditScript();

			SelectedTask->pq->scripts[SelectedTask->pq->scripts->Length-1]->Name = "";
			SelectedTask->pq->scripts[SelectedTask->pq->scripts->Length-1]->count = 0;
			SelectedTask->pq->scripts[SelectedTask->pq->scripts->Length-1]->id = 0.0;
			SelectedTask->pq->scripts[SelectedTask->pq->scripts->Length-1]->seperator = gcnew array<unsigned char>{255, 255, 255, 255};
			SelectedTask->pq->scripts[SelectedTask->pq->scripts->Length-1]->reference_id = 0.0;
			SelectedTask->pq->scripts[SelectedTask->pq->scripts->Length-1]->code = gcnew array<unsigned char>(496);

			dataGridView_pq_scripts->Rows->Add(gcnew array<String^>{"", "0", "0", "FF-FF-FF-FF", "0", ByteArray_to_HexString(SelectedTask->pq->scripts[SelectedTask->pq->scripts->Length-1]->code)});
		}
	}
	private: System::Void remove_pq_script(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			if(SelectedTask->pq->script_count>0 && dataGridView_pq_scripts->CurrentCell->RowIndex>-1)
			{
				SelectedTask->pq->script_count--;

				array<PQ_AuditScript^>^ temp = gcnew array<PQ_AuditScript^>(SelectedTask->pq->script_count);
				Array::Copy(SelectedTask->pq->scripts, 0, temp, 0, dataGridView_pq_scripts->CurrentCell->RowIndex);
				Array::Copy(SelectedTask->pq->scripts, dataGridView_pq_scripts->CurrentCell->RowIndex+1, temp, dataGridView_pq_scripts->CurrentCell->RowIndex, SelectedTask->pq->script_count - dataGridView_pq_scripts->CurrentCell->RowIndex);
				SelectedTask->pq->scripts = temp;

				dataGridView_pq_scripts->Rows->RemoveAt(dataGridView_pq_scripts->CurrentCell->RowIndex);
			}
		}
	}
	//
	private: System::Void change_pq_unknown_4(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedTask->pq->unknown_4) != textBox_pq_unknown_4->Text)
				{
					SelectedTask->pq->unknown_4 = HexString_to_ByteArray(textBox_pq_unknown_4->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_pq_unknown_5(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedTask->pq->unknown_5) != textBox_pq_unknown_5->Text)
				{
					SelectedTask->pq->unknown_5 = HexString_to_ByteArray(textBox_pq_unknown_5->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_pq_unknown_6(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedTask->pq->unknown_6) != textBox_pq_unknown_6->Text)
				{
					SelectedTask->pq->unknown_6 = HexString_to_ByteArray(textBox_pq_unknown_6->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	// pq chase
	private: System::Void change_pq_chases(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				int r = dataGridView_pq_chases->CurrentCell->RowIndex;
				switch(dataGridView_pq_chases->CurrentCell->ColumnIndex)
				{
					case 0:		SelectedTask->pq->chases[r]->id_monster = Convert::ToInt32(dataGridView_pq_chases->CurrentCell->Value);
								break;
					case 1:		SelectedTask->pq->chases[r]->amount_1 = Convert::ToInt32(dataGridView_pq_chases->CurrentCell->Value);
								break;
					case 2:		SelectedTask->pq->chases[r]->contribution = Convert::ToInt32(dataGridView_pq_chases->CurrentCell->Value);
								break;
					case 3:		SelectedTask->pq->chases[r]->amount_3 = Convert::ToInt32(dataGridView_pq_chases->CurrentCell->Value);
								break;
				}
				// call debug function
				TriggerDebug((Control^)sender);
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void add_pq_chase(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			SelectedTask->pq->chase_count++;
			Array::Resize(SelectedTask->pq->chases, SelectedTask->pq->chases->Length+1);
			SelectedTask->pq->chases[SelectedTask->pq->chases->Length-1] = gcnew PQ_AuditChase();

			SelectedTask->pq->chases[SelectedTask->pq->chases->Length-1]->id_monster = 0;
			SelectedTask->pq->chases[SelectedTask->pq->chases->Length-1]->amount_1 = 0;
			SelectedTask->pq->chases[SelectedTask->pq->chases->Length-1]->contribution = 0;
			SelectedTask->pq->chases[SelectedTask->pq->chases->Length-1]->amount_3 = 0;

			dataGridView_pq_chases->Rows->Add(gcnew array<String^>{"0", "0", "0", "0"});
		}
	}
	private: System::Void remove_pq_chase(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			if(SelectedTask->pq->chase_count>0 && dataGridView_pq_chases->CurrentCell->RowIndex>-1)
			{
				SelectedTask->pq->chase_count--;

				array<PQ_AuditChase^>^ temp = gcnew array<PQ_AuditChase^>(SelectedTask->pq->chase_count);
				Array::Copy(SelectedTask->pq->chases, 0, temp, 0, dataGridView_pq_chases->CurrentCell->RowIndex);
				Array::Copy(SelectedTask->pq->chases, dataGridView_pq_chases->CurrentCell->RowIndex+1, temp, dataGridView_pq_chases->CurrentCell->RowIndex, SelectedTask->pq->chase_count - dataGridView_pq_chases->CurrentCell->RowIndex);
				SelectedTask->pq->chases = temp;

				dataGridView_pq_chases->Rows->RemoveAt(dataGridView_pq_chases->CurrentCell->RowIndex);
			}
		}
	}
	//
	private: System::Void change_pq_unknown_7(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedTask->pq->unknown_7) != textBox_pq_unknown_7->Text)
				{
					SelectedTask->pq->unknown_7 = HexString_to_ByteArray(textBox_pq_unknown_7->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_pq_required_quests_completed(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->pq->required_quests_completed != Convert::ToInt32(textBox_pq_required_quests_completed->Text))
				{
					SelectedTask->pq->required_quests_completed = Convert::ToInt32(textBox_pq_required_quests_completed->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_pq_unknown_8(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedTask->pq->unknown_8) != textBox_pq_unknown_8->Text)
				{
					SelectedTask->pq->unknown_8 = HexString_to_ByteArray(textBox_pq_unknown_8->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_pq_unknown_9(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedTask->pq->unknown_9) != textBox_pq_unknown_9->Text)
				{
					SelectedTask->pq->unknown_10 = HexString_to_ByteArray(textBox_pq_unknown_10->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_pq_unknown_10(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedTask->pq->unknown_10) != textBox_pq_unknown_10->Text)
				{
					SelectedTask->pq->unknown_10 = HexString_to_ByteArray(textBox_pq_unknown_10->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_pq_unknown_11(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedTask->pq->unknown_11) != textBox_pq_unknown_11->Text)
				{
					SelectedTask->pq->unknown_11 = HexString_to_ByteArray(textBox_pq_unknown_11->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}


	// pq location
	private: System::Void change_pq_location_has_spans(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->pq->location->has_location != checkBox_pq_location_has_spans->Checked)
				{
					SelectedTask->pq->location->has_location = checkBox_pq_location_has_spans->Checked;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_pq_location_map_id(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->pq->location->map_id != Convert::ToInt32(textBox_pq_location_map_id->Text))
				{
					SelectedTask->pq->location->map_id = Convert::ToInt32(textBox_pq_location_map_id->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_pq_location_unknown_1(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedTask->pq->location->unknown_1) != textBox_pq_location_unknown_1->Text)
				{
					SelectedTask->pq->location->unknown_1 = HexString_to_ByteArray(textBox_pq_location_unknown_1->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_pq_location_span(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				int r = dataGridView_pq_location_spans->CurrentCell->RowIndex;
				switch(dataGridView_pq_location_spans->CurrentCell->ColumnIndex)
				{
					case 0:		SelectedTask->pq->location->spans[r]->north = Convert::ToSingle(dataGridView_pq_location_spans->CurrentCell->Value);
								break;
					case 1:		SelectedTask->pq->location->spans[r]->south = Convert::ToSingle(dataGridView_pq_location_spans->CurrentCell->Value);
								break;
					case 2:		SelectedTask->pq->location->spans[r]->west = Convert::ToSingle(dataGridView_pq_location_spans->CurrentCell->Value);
								break;
					case 3:		SelectedTask->pq->location->spans[r]->east = Convert::ToSingle(dataGridView_pq_location_spans->CurrentCell->Value);
								break;
					case 4:		SelectedTask->pq->location->spans[r]->bottom = Convert::ToSingle(dataGridView_pq_location_spans->CurrentCell->Value);
								break;
					case 5:		SelectedTask->pq->location->spans[r]->top = Convert::ToSingle(dataGridView_pq_location_spans->CurrentCell->Value);
								break;
				}
				// call debug function
				TriggerDebug((Control^)sender);
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void add_pq_location_span(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			SelectedTask->pq->location->count++;
			Array::Resize(SelectedTask->pq->location->spans, SelectedTask->pq->location->spans->Length+1);
			SelectedTask->pq->location->spans[SelectedTask->pq->location->spans->Length-1] = gcnew Span();

			SelectedTask->pq->location->spans[SelectedTask->pq->location->spans->Length-1]->north = 0.0;
			SelectedTask->pq->location->spans[SelectedTask->pq->location->spans->Length-1]->south = 0.0;
			SelectedTask->pq->location->spans[SelectedTask->pq->location->spans->Length-1]->west = 0.0;
			SelectedTask->pq->location->spans[SelectedTask->pq->location->spans->Length-1]->east = 0.0;
			SelectedTask->pq->location->spans[SelectedTask->pq->location->spans->Length-1]->bottom = 0.0;
			SelectedTask->pq->location->spans[SelectedTask->pq->location->spans->Length-1]->top = 0.0;

			dataGridView_pq_location_spans->Rows->Add(gcnew array<String^>{"0.0", "0.0", "0.0", "0.0", "0.0", "0.0"});
		}
	}
	private: System::Void remove_pq_location_span(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			if(SelectedTask->pq->location->count>0 && dataGridView_pq_location_spans->CurrentCell->RowIndex>-1)
			{
				SelectedTask->pq->location->count--;

				array<Span^>^ temp = gcnew array<Span^>(SelectedTask->pq->location->count);
				Array::Copy(SelectedTask->pq->location->spans, 0, temp, 0, dataGridView_pq_location_spans->CurrentCell->RowIndex);
				Array::Copy(SelectedTask->pq->location->spans, dataGridView_pq_location_spans->CurrentCell->RowIndex+1, temp, dataGridView_pq_location_spans->CurrentCell->RowIndex, SelectedTask->pq->location->count - dataGridView_pq_location_spans->CurrentCell->RowIndex);
				SelectedTask->pq->location->spans = temp;

				dataGridView_pq_location_spans->Rows->RemoveAt(dataGridView_pq_location_spans->CurrentCell->RowIndex);
			}
		}
	}
	//
	private: System::Void change_pq_unknown_12(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->pq->unknown_12 != Convert::ToInt32(textBox_pq_unknown_12->Text))
				{
					SelectedTask->pq->unknown_12 = Convert::ToInt32(textBox_pq_unknown_12->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_pq_unknown_13(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedTask->pq->unknown_13) != textBox_pq_unknown_13->Text)
				{
					SelectedTask->pq->unknown_13 = HexString_to_ByteArray(textBox_pq_unknown_13->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_pq_id_script(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->pq->id_script != Convert::ToInt32(textBox_pq_id_script->Text))
				{
					SelectedTask->pq->id_script = Convert::ToInt32(textBox_pq_id_script->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_pq_unknown_14(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->pq->unknown_14 != Convert::ToInt32(textBox_pq_unknown_14->Text))
				{
					SelectedTask->pq->unknown_14 = Convert::ToInt32(textBox_pq_unknown_14->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_pq_unknown_15(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->pq->unknown_15 != Convert::ToInt32(textBox_pq_unknown_15->Text))
				{
					SelectedTask->pq->unknown_15 = Convert::ToInt32(textBox_pq_unknown_15->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_pq_unknown_16(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->pq->unknown_16 != Convert::ToInt32(textBox_pq_unknown_16->Text))
				{
					SelectedTask->pq->unknown_16 = Convert::ToInt32(textBox_pq_unknown_16->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_pq_unknown_17(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedTask->pq->unknown_17) != textBox_pq_unknown_17->Text)
				{
					SelectedTask->pq->unknown_17 = HexString_to_ByteArray(textBox_pq_unknown_17->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	// pq special scripts
	private: System::Void change_pq_special_scripts(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				int r = dataGridView_pq_special_scripts->CurrentCell->RowIndex;
				switch(dataGridView_pq_special_scripts->CurrentCell->ColumnIndex)
				{
					case 0:		SelectedTask->pq->special_scripts[r]->Name = Convert::ToString(dataGridView_pq_special_scripts->CurrentCell->Value);
								break;
					case 1:		SelectedTask->pq->special_scripts[r]->count = Convert::ToInt32(dataGridView_pq_special_scripts->CurrentCell->Value);
								break;
					case 2:		SelectedTask->pq->special_scripts[r]->id = Convert::ToSingle(dataGridView_pq_special_scripts->CurrentCell->Value);
								break;
					case 3:		SelectedTask->pq->special_scripts[r]->seperator = HexString_to_ByteArray(Convert::ToString(dataGridView_pq_special_scripts->CurrentCell->Value));
								break;
					case 4:		SelectedTask->pq->special_scripts[r]->reference_id = Convert::ToSingle(dataGridView_pq_special_scripts->CurrentCell->Value);
								break;
					case 5:		SelectedTask->pq->special_scripts[r]->code = HexString_to_ByteArray(Convert::ToString(dataGridView_pq_special_scripts->CurrentCell->Value));
								break;
				}
				// call debug function
				TriggerDebug((Control^)sender);
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void add_pq_special_script(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			SelectedTask->pq->special_script_count++;
			Array::Resize(SelectedTask->pq->special_scripts, SelectedTask->pq->special_scripts->Length+1);
			SelectedTask->pq->special_scripts[SelectedTask->pq->special_scripts->Length-1] = gcnew PQ_AuditScript();

			SelectedTask->pq->special_scripts[SelectedTask->pq->special_scripts->Length-1]->Name = "";
			SelectedTask->pq->special_scripts[SelectedTask->pq->special_scripts->Length-1]->count = 0;
			SelectedTask->pq->special_scripts[SelectedTask->pq->special_scripts->Length-1]->id = 0.0;
			SelectedTask->pq->special_scripts[SelectedTask->pq->special_scripts->Length-1]->seperator = gcnew array<unsigned char>{255, 255, 255, 255};
			SelectedTask->pq->special_scripts[SelectedTask->pq->special_scripts->Length-1]->reference_id = 0.0;
			SelectedTask->pq->special_scripts[SelectedTask->pq->special_scripts->Length-1]->code = gcnew array<unsigned char>(496);

			dataGridView_pq_special_scripts->Rows->Add(gcnew array<String^>{"", "0", "0", "FF-FF-FF-FF", "0", ByteArray_to_HexString(SelectedTask->pq->scripts[SelectedTask->pq->scripts->Length-1]->code)});
		}
	}
	private: System::Void remove_pq_special_script(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			if(SelectedTask->pq->special_script_count>0 && dataGridView_pq_special_scripts->CurrentCell->RowIndex>-1)
			{
				SelectedTask->pq->special_script_count--;

				array<PQ_AuditScript^>^ temp = gcnew array<PQ_AuditScript^>(SelectedTask->pq->special_script_count);
				Array::Copy(SelectedTask->pq->special_scripts, 0, temp, 0, dataGridView_pq_special_scripts->CurrentCell->RowIndex);
				Array::Copy(SelectedTask->pq->special_scripts, dataGridView_pq_special_scripts->CurrentCell->RowIndex+1, temp, dataGridView_pq_special_scripts->CurrentCell->RowIndex, SelectedTask->pq->special_script_count - dataGridView_pq_special_scripts->CurrentCell->RowIndex);
				SelectedTask->pq->special_scripts = temp;

				dataGridView_pq_special_scripts->Rows->RemoveAt(dataGridView_pq_special_scripts->CurrentCell->RowIndex);
			}
		}
	}
	//
	private: System::Void change_pq_unknown_18(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedTask->pq->unknown_18) != textBox_pq_unknown_18->Text)
				{
					SelectedTask->pq->unknown_18 = HexString_to_ByteArray(textBox_pq_unknown_18->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_pq_unknown_19(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedTask->pq->unknown_19) != textBox_pq_unknown_19->Text)
				{
					SelectedTask->pq->unknown_19 = HexString_to_ByteArray(textBox_pq_unknown_19->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	// pq messages
	private: System::Void change_pq_messages(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				int r = dataGridView_pq_messages->CurrentCell->RowIndex;
				switch(dataGridView_pq_messages->CurrentCell->ColumnIndex)
				{
					case 0:		SelectedTask->pq->messages[r] = UnicodeString_to_ByteArray(Convert::ToString(dataGridView_pq_messages->CurrentCell->Value), 128);
								break;
				}
				// call debug function
				TriggerDebug((Control^)sender);
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void add_pq_message(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			SelectedTask->pq->message_count++;
			Array::Resize(SelectedTask->pq->messages, SelectedTask->pq->messages->Length+1);
			SelectedTask->pq->messages[SelectedTask->pq->messages->Length-1] = gcnew array<unsigned char>(128);

			dataGridView_pq_messages->Rows->Add(gcnew array<String^>{""});
		}
	}
	private: System::Void remove_pq_message(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			if(SelectedTask->pq->message_count>0 && dataGridView_pq_messages->CurrentCell->RowIndex>-1)
			{
				SelectedTask->pq->message_count--;

				array<array<unsigned char>^>^ temp = gcnew array<array<unsigned char>^>(SelectedTask->pq->message_count);
				Array::Copy(SelectedTask->pq->messages, 0, temp, 0, dataGridView_pq_messages->CurrentCell->RowIndex);
				Array::Copy(SelectedTask->pq->messages, dataGridView_pq_messages->CurrentCell->RowIndex+1, temp, dataGridView_pq_messages->CurrentCell->RowIndex, SelectedTask->pq->message_count - dataGridView_pq_messages->CurrentCell->RowIndex);
				SelectedTask->pq->messages = temp;

				dataGridView_pq_messages->Rows->RemoveAt(dataGridView_pq_messages->CurrentCell->RowIndex);
			}
		}
	}
	//
	private: System::Void change_pq_unknown_20(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedTask->pq->unknown_20) != textBox_pq_unknown_20->Text)
				{
					SelectedTask->pq->unknown_20 = HexString_to_ByteArray(textBox_pq_unknown_20->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	// basic II
	private: System::Void change_unknown_58(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedTask->UNKNOWN_58) != textBox_unknown_58->Text)
				{
					SelectedTask->UNKNOWN_58 = HexString_to_ByteArray(textBox_unknown_58->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_unknown_59(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedTask->UNKNOWN_59) != textBox_unknown_59->Text)
				{
					SelectedTask->UNKNOWN_59 = HexString_to_ByteArray(textBox_unknown_59->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_parent_quest(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->parent_quest != Convert::ToInt32(textBox_parent_quest->Text))
				{
					SelectedTask->parent_quest = Convert::ToInt32(textBox_parent_quest->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_previous_quest(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->previous_quest != Convert::ToInt32(textBox_previous_quest->Text))
				{
					SelectedTask->previous_quest = Convert::ToInt32(textBox_previous_quest->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_next_quest(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->next_quest != Convert::ToInt32(textBox_next_quest->Text))
				{
					SelectedTask->next_quest = Convert::ToInt32(textBox_next_quest->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_sub_quest_first(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->sub_quest_first != Convert::ToInt32(textBox_sub_quest_first->Text))
				{
					SelectedTask->sub_quest_first = Convert::ToInt32(textBox_sub_quest_first->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_unknown_60(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->UNKNOWN_60 != checkBox_unknown_60->Checked)
				{
					SelectedTask->UNKNOWN_60 = checkBox_unknown_60->Checked;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_receive_quest_probability(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->receive_quest_probability != Convert::ToSingle(textBox_receive_quest_probability->Text))
				{
					SelectedTask->receive_quest_probability = Convert::ToSingle(textBox_receive_quest_probability->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_unknown_60_01(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->UNKNOWN_60_01 != checkBox_unknown_60_01->Checked)
				{
					SelectedTask->UNKNOWN_60_01 = checkBox_unknown_60_01->Checked;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_unknown_61(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedTask->UNKNOWN_61) != textBox_unknown_61->Text)
				{
					SelectedTask->UNKNOWN_61 = HexString_to_ByteArray(textBox_unknown_61->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	// reward
	private: System::Void change_reward_time_factor(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				int i = listBox_reward_timed->SelectedIndex;
				if(radioButton_timed->Checked && i > -1)
				{
					// check if value really changed
					if(SelectedTask->rewards_timed_factors[i] != Convert::ToSingle(numericUpDown_time_factor->Value))
					{
						SelectedTask->rewards_timed_factors[i] = Convert::ToSingle(numericUpDown_time_factor->Value);
						listBox_reward_timed->Items[i] = "Success Time [sec]: " + (SelectedTask->time_limit*SelectedTask->rewards_timed_factors[i]);

						// call debug function
						TriggerDebug((Control^)sender);
					}
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void add_reward_timed(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			/*
			SelectedReward->pq->chase_count++;
			Array::Resize(SelectedReward->pq->chases, SelectedReward->pq->chases->Length+1);
			SelectedReward->pq->chases[SelectedReward->pq->chases->Length-1] = gcnew PQ_Chase();

			SelectedReward->pq->chases[SelectedReward->pq->chases->Length-1]->id_monster = 0;
			SelectedReward->pq->chases[SelectedReward->pq->chases->Length-1]->amount_monster = 0;
			SelectedReward->pq->chases[SelectedReward->pq->chases->Length-1]->probability = 1.0;
			SelectedReward->pq->chases[SelectedReward->pq->chases->Length-1]->amount_unknown = 0;

			dataGridView_reward_pq_chases->Rows->Add(gcnew array<String^>{"0", "0", "1.0", "0"});
			*/
			MessageBox::Show("Currently not Supported!");
		}
	}
	private: System::Void remove_reward_timed(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			/*
			if(SelectedReward->pq->chase_count>0 && dataGridView_reward_pq_chases->CurrentCell->RowIndex>-1)
			{
				SelectedReward->pq->chase_count--;

				array<PQ_Chase^>^ temp = gcnew array<PQ_Chase^>(SelectedReward->pq->chase_count);
				Array::Copy(SelectedReward->pq->chases, 0, temp, 0, dataGridView_reward_pq_chases->CurrentCell->RowIndex);
				Array::Copy(SelectedReward->pq->chases, dataGridView_reward_pq_chases->CurrentCell->RowIndex+1, temp, dataGridView_reward_pq_chases->CurrentCell->RowIndex, SelectedReward->pq->chase_count - dataGridView_reward_pq_chases->CurrentCell->RowIndex);
				SelectedReward->pq->chases = temp;

				dataGridView_reward_pq_chases->Rows->RemoveAt(dataGridView_reward_pq_chases->CurrentCell->RowIndex);
			}
			*/
			MessageBox::Show("Currently not Supported!");
		}
	}
	private: System::Void change_reward_coins(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedReward)
		{
			try
			{
				// check if value really changed
				if(SelectedReward->coins != Convert::ToInt32(textBox_reward_coins->Text))
				{
					SelectedReward->coins = Convert::ToInt32(textBox_reward_coins->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_reward_experience(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedReward)
		{
			try
			{
				// check if value really changed
				if(SelectedReward->experience != Convert::ToInt32(textBox_reward_experience->Text))
				{
					SelectedReward->experience = Convert::ToInt32(textBox_reward_experience->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_reward_new_quest(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedReward)
		{
			try
			{
				// check if value really changed
				if(SelectedReward->new_quest != Convert::ToInt32(textBox_reward_new_quest->Text))
				{
					SelectedReward->new_quest = Convert::ToInt32(textBox_reward_new_quest->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_reward_spirit(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedReward)
		{
			try
			{
				// check if value really changed
				if(SelectedReward->spirit != Convert::ToInt32(textBox_reward_spirit->Text))
				{
					SelectedReward->spirit = Convert::ToInt32(textBox_reward_spirit->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_reward_reputation(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedReward)
		{
			try
			{
				// check if value really changed
				if(SelectedReward->reputation != Convert::ToInt32(textBox_reward_reputation->Text))
				{
					SelectedReward->reputation = Convert::ToInt32(textBox_reward_reputation->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_reward_cultivation(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedReward)
		{
			try
			{
				// check if value really changed
				if(SelectedReward->cultivation != Convert::ToInt32(textBox_reward_cultivation->Text))
				{
					SelectedReward->cultivation = Convert::ToInt32(textBox_reward_cultivation->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_reward_new_waypoint(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedReward)
		{
			try
			{
				// check if value really changed
				if(SelectedReward->new_waypoint != Convert::ToInt32(textBox_reward_new_waypoint->Text))
				{
					SelectedReward->new_waypoint = Convert::ToInt32(textBox_reward_new_waypoint->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_reward_storage_slots(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedReward)
		{
			try
			{
				// check if value really changed
				if(SelectedReward->storage_slots != Convert::ToInt32(textBox_reward_storage_slots->Text))
				{
					SelectedReward->storage_slots = Convert::ToInt32(textBox_reward_storage_slots->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_reward_cupboard_slots(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedReward)
		{
			try
			{
				// check if value really changed
				if(SelectedReward->cupboard_slots != Convert::ToInt32(textBox_reward_cupboard_slots->Text))
				{
					SelectedReward->cupboard_slots = Convert::ToInt32(textBox_reward_cupboard_slots->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_reward_wardrobe_slots(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedReward)
		{
			try
			{
				// check if value really changed
				if(SelectedReward->wardrobe_slots != Convert::ToInt32(textBox_reward_wardrobe_slots->Text))
				{
					SelectedReward->wardrobe_slots = Convert::ToInt32(textBox_reward_wardrobe_slots->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_reward_account_stash_slots(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedReward)
		{
			try
			{
				// check if value really changed
				if(SelectedReward->account_stash_slots != Convert::ToInt32(textBox_reward_account_stash_slots->Text))
				{
					SelectedReward->account_stash_slots = Convert::ToInt32(textBox_reward_account_stash_slots->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_reward_inventory_slots(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedReward)
		{
			try
			{
				// check if value really changed
				if(SelectedReward->inventory_slots != Convert::ToInt32(textBox_reward_inventory_slots->Text))
				{
					SelectedReward->inventory_slots = Convert::ToInt32(textBox_reward_inventory_slots->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_reward_petbag_slots(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedReward)
		{
			try
			{
				// check if value really changed
				if(SelectedReward->petbag_slots != Convert::ToInt32(textBox_reward_petbag_slots->Text))
				{
					SelectedReward->petbag_slots = Convert::ToInt32(textBox_reward_petbag_slots->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_reward_vigor(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedReward)
		{
			try
			{
				// check if value really changed
				if(SelectedReward->vigor != Convert::ToInt32(textBox_reward_vigor->Text))
				{
					SelectedReward->vigor = Convert::ToInt32(textBox_reward_vigor->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_reward_teleport_map_id(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedReward)
		{
			try
			{
				// check if value really changed
				if(SelectedReward->teleport->map_id != Convert::ToInt32(textBox_reward_teleport_map_id->Text))
				{
					SelectedReward->teleport->map_id = Convert::ToInt32(textBox_reward_teleport_map_id->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_reward_teleport_x(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedReward)
		{
			try
			{
				// check if value really changed
				if(SelectedReward->teleport->x != Convert::ToSingle(textBox_reward_teleport_x->Text))
				{
					SelectedReward->teleport->x = Convert::ToSingle(textBox_reward_teleport_x->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_reward_teleport_altitude(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedReward)
		{
			try
			{
				// check if value really changed
				if(SelectedReward->teleport->altitude != Convert::ToSingle(textBox_reward_teleport_altitude->Text))
				{
					SelectedReward->teleport->altitude = Convert::ToSingle(textBox_reward_teleport_altitude->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_reward_teleport_z(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedReward)
		{
			try
			{
				// check if value really changed
				if(SelectedReward->teleport->z != Convert::ToSingle(textBox_reward_teleport_z->Text))
				{
					SelectedReward->teleport->z = Convert::ToSingle(textBox_reward_teleport_z->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_reward_ai_trigger(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedReward)
		{
			try
			{
				// check if value really changed
				if(SelectedReward->ai_trigger != Convert::ToInt32(textBox_reward_ai_trigger->Text))
				{
					SelectedReward->ai_trigger = Convert::ToInt32(textBox_reward_ai_trigger->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_reward_unknown_2a(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedReward->UNKNOWN_2a) != textBox_reward_unknown_2a->Text)
				{
					SelectedReward->UNKNOWN_2a = HexString_to_ByteArray(textBox_reward_unknown_2a->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_reward_unknown_2b(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedReward->UNKNOWN_2b) != textBox_reward_unknown_2b->Text)
				{
					SelectedReward->UNKNOWN_2b = HexString_to_ByteArray(textBox_reward_unknown_2b->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_reward_seperator(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedReward->SEPERATOR) != textBox_reward_seperator->Text)
				{
					SelectedReward->SEPERATOR = HexString_to_ByteArray(textBox_reward_seperator->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	// reward pq
	private: System::Void change_reward_pq_unknown_0(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedReward->pq->unknown_0) != textBox_reward_pq_unknown_0->Text)
				{
					SelectedReward->pq->unknown_0 = HexString_to_ByteArray(textBox_reward_pq_unknown_0->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_reward_pq_event_gold(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedReward)
		{
			try
			{
				// check if value really changed
				if(SelectedReward->pq->event_gold != Convert::ToInt32(textBox_reward_pq_event_gold->Text))
				{
					SelectedReward->pq->event_gold = Convert::ToInt32(textBox_reward_pq_event_gold->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_reward_pq_unknown_1(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedReward->pq->unknown_1) != textBox_reward_pq_unknown_1->Text)
				{
					SelectedReward->pq->unknown_1 = HexString_to_ByteArray(textBox_reward_pq_unknown_1->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_reward_pq_unknown_quest(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedReward)
		{
			try
			{
				// check if value really changed
				if(SelectedReward->pq->unknown_quest != Convert::ToInt32(textBox_reward_pq_unknown_quest->Text))
				{
					SelectedReward->pq->unknown_quest = Convert::ToInt32(textBox_reward_pq_unknown_quest->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_reward_pq_unknown_2(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedReward->pq->unknown_2) != textBox_reward_pq_unknown_2->Text)
				{
					SelectedReward->pq->unknown_2 = HexString_to_ByteArray(textBox_reward_pq_unknown_2->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_reward_pq_unknown_level(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedReward)
		{
			try
			{
				// check if value really changed
				if(SelectedReward->pq->unknown_level != Convert::ToInt32(textBox_reward_pq_unknown_level->Text))
				{
					SelectedReward->pq->unknown_level = Convert::ToInt32(textBox_reward_pq_unknown_level->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_reward_pq_contribution_random_min(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedReward)
		{
			try
			{
				// check if value really changed
				if(SelectedReward->pq->contribution_random_min != Convert::ToInt32(textBox_reward_pq_contribution_random_min->Text))
				{
					SelectedReward->pq->contribution_random_min = Convert::ToInt32(textBox_reward_pq_contribution_random_min->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_reward_pq_contribution_random_max(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedReward)
		{
			try
			{
				// check if value really changed
				if(SelectedReward->pq->contribution_random_max != Convert::ToInt32(textBox_reward_pq_contribution_random_max->Text))
				{
					SelectedReward->pq->contribution_random_max = Convert::ToInt32(textBox_reward_pq_contribution_random_max->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_reward_pq_contribution_required(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedReward)
		{
			try
			{
				// check if value really changed
				if(SelectedReward->pq->contribution_required != Convert::ToInt32(textBox_reward_pq_contribution_required->Text))
				{
					SelectedReward->pq->contribution_required = Convert::ToInt32(textBox_reward_pq_contribution_required->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_reward_pq_unknown_3(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedReward->pq->unknown_3) != textBox_reward_pq_unknown_3->Text)
				{
					SelectedReward->pq->unknown_3 = HexString_to_ByteArray(textBox_reward_pq_unknown_3->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_reward_pq_unknown_4(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedReward->pq->unknown_4) != textBox_reward_pq_unknown_4->Text)
				{
					SelectedReward->pq->unknown_4 = HexString_to_ByteArray(textBox_reward_pq_unknown_4->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_reward_pq_unknown_5(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedReward->pq->unknown_5) != textBox_reward_pq_unknown_5->Text)
				{
					SelectedReward->pq->unknown_5 = HexString_to_ByteArray(textBox_reward_pq_unknown_5->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_reward_pq_unknown_6(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedReward->pq->unknown_6) != textBox_reward_pq_unknown_6->Text)
				{
					SelectedReward->pq->unknown_6 = HexString_to_ByteArray(textBox_reward_pq_unknown_6->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_reward_pq_unknown_7(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(ByteArray_to_HexString(SelectedReward->pq->unknown_7) != textBox_reward_pq_unknown_7->Text)
				{
					SelectedReward->pq->unknown_7 = HexString_to_ByteArray(textBox_reward_pq_unknown_7->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	// reward pq chases
	private: System::Void change_reward_pq_chases(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
	{
		if(SelectedReward)
		{
			try
			{
				int r = dataGridView_reward_pq_chases->CurrentCell->RowIndex;
				switch(dataGridView_reward_pq_chases->CurrentCell->ColumnIndex)
				{
					case 0:		SelectedReward->pq->chases[r]->id_monster = Convert::ToInt32(dataGridView_reward_pq_chases->CurrentCell->Value);
								break;
					case 1:		SelectedReward->pq->chases[r]->amount_monster = Convert::ToInt32(dataGridView_reward_pq_chases->CurrentCell->Value);
								break;
					case 2:		SelectedReward->pq->chases[r]->probability = Convert::ToSingle(dataGridView_reward_pq_chases->CurrentCell->Value);
								break;
					case 3:		SelectedReward->pq->chases[r]->amount_unknown = Convert::ToInt32(dataGridView_pq_chases->CurrentCell->Value);
								break;
				}
				// call debug function
				TriggerDebug((Control^)sender);
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void add_reward_pq_chase(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedReward)
		{
			SelectedReward->pq->chase_count++;
			Array::Resize(SelectedReward->pq->chases, SelectedReward->pq->chases->Length+1);
			SelectedReward->pq->chases[SelectedReward->pq->chases->Length-1] = gcnew PQ_Chase();

			SelectedReward->pq->chases[SelectedReward->pq->chases->Length-1]->id_monster = 0;
			SelectedReward->pq->chases[SelectedReward->pq->chases->Length-1]->amount_monster = 0;
			SelectedReward->pq->chases[SelectedReward->pq->chases->Length-1]->probability = 1.0;
			SelectedReward->pq->chases[SelectedReward->pq->chases->Length-1]->amount_unknown = 0;

			dataGridView_reward_pq_chases->Rows->Add(gcnew array<String^>{"0", "0", "1.0", "0"});
		}
	}
	private: System::Void remove_reward_pq_chase(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedReward)
		{
			if(SelectedReward->pq->chase_count>0 && dataGridView_reward_pq_chases->CurrentCell->RowIndex>-1)
			{
				SelectedReward->pq->chase_count--;

				array<PQ_Chase^>^ temp = gcnew array<PQ_Chase^>(SelectedReward->pq->chase_count);
				Array::Copy(SelectedReward->pq->chases, 0, temp, 0, dataGridView_reward_pq_chases->CurrentCell->RowIndex);
				Array::Copy(SelectedReward->pq->chases, dataGridView_reward_pq_chases->CurrentCell->RowIndex+1, temp, dataGridView_reward_pq_chases->CurrentCell->RowIndex, SelectedReward->pq->chase_count - dataGridView_reward_pq_chases->CurrentCell->RowIndex);
				SelectedReward->pq->chases = temp;

				dataGridView_reward_pq_chases->Rows->RemoveAt(dataGridView_reward_pq_chases->CurrentCell->RowIndex);
			}
		}
	}
	// reward pq items
	private: System::Void change_reward_pq_items(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
	{
		if(SelectedReward)
		{
			try
			{
				int r = dataGridView_reward_pq_items->CurrentCell->RowIndex;
				switch(dataGridView_reward_pq_items->CurrentCell->ColumnIndex)
				{
					case 0:		SelectedReward->pq->items[r]->ranking_from = Convert::ToInt32(dataGridView_reward_pq_items->CurrentCell->Value);
								break;
					case 1:		SelectedReward->pq->items[r]->ranking_to = Convert::ToInt32(dataGridView_reward_pq_items->CurrentCell->Value);
								break;
					case 2:		SelectedReward->pq->items[r]->unknown_3 = Convert::ToBoolean(dataGridView_reward_pq_items->CurrentCell->Value);
								break;
					case 3:		SelectedReward->pq->items[r]->id = Convert::ToInt32(dataGridView_reward_pq_items->CurrentCell->Value);
								break;
					case 4:		SelectedReward->pq->items[r]->amount = Convert::ToInt32(dataGridView_reward_pq_items->CurrentCell->Value);
								break;
					case 5:		SelectedReward->pq->items[r]->probability = Convert::ToSingle(dataGridView_reward_pq_items->CurrentCell->Value);
								break;
				}
				// call debug function
				TriggerDebug((Control^)sender);
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void add_reward_pq_item(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedReward)
		{
			SelectedReward->pq->item_count++;
			Array::Resize(SelectedReward->pq->items, SelectedReward->pq->items->Length+1);
			SelectedReward->pq->items[SelectedReward->pq->items->Length-1] = gcnew PQ_Item();

			SelectedReward->pq->items[SelectedReward->pq->items->Length-1]->ranking_from = 0;
			SelectedReward->pq->items[SelectedReward->pq->items->Length-1]->ranking_to = 0;
			SelectedReward->pq->items[SelectedReward->pq->items->Length-1]->unknown_3 = true;
			SelectedReward->pq->items[SelectedReward->pq->items->Length-1]->id = 0;
			SelectedReward->pq->items[SelectedReward->pq->items->Length-1]->amount = 0;
			SelectedReward->pq->items[SelectedReward->pq->items->Length-1]->probability = 1.0;

			dataGridView_reward_pq_items->Rows->Add(gcnew array<String^>{"0", "0", "True", "0", "0", "1.0"});
		}
	}
	private: System::Void remove_reward_pq_item(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedReward)
		{
			if(SelectedReward->pq->item_count>0 && dataGridView_reward_pq_items->CurrentCell->RowIndex>-1)
			{
				SelectedReward->pq->item_count--;

				array<PQ_Item^>^ temp = gcnew array<PQ_Item^>(SelectedReward->pq->item_count);
				Array::Copy(SelectedReward->pq->items, 0, temp, 0, dataGridView_reward_pq_items->CurrentCell->RowIndex);
				Array::Copy(SelectedReward->pq->items, dataGridView_reward_pq_items->CurrentCell->RowIndex+1, temp, dataGridView_reward_pq_items->CurrentCell->RowIndex, SelectedReward->pq->item_count - dataGridView_reward_pq_items->CurrentCell->RowIndex);
				SelectedReward->pq->items = temp;

				dataGridView_reward_pq_items->Rows->RemoveAt(dataGridView_reward_pq_items->CurrentCell->RowIndex);
			}
		}
	}
	// reward pq specials
	private: System::Void change_reward_pq_specials(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
	{
		if(SelectedReward)
		{
			try
			{
				int r = dataGridView_reward_pq_specials->CurrentCell->RowIndex;
				switch(dataGridView_reward_pq_specials->CurrentCell->ColumnIndex)
				{
					case 0:		SelectedReward->pq->specials[r]->id_pq = Convert::ToInt32(dataGridView_reward_pq_specials->CurrentCell->Value);
								break;
					case 1:		SelectedReward->pq->specials[r]->unknown_2 = Convert::ToInt32(dataGridView_reward_pq_specials->CurrentCell->Value);
								break;
					case 2:		SelectedReward->pq->specials[r]->unknown_3 = Convert::ToByte(dataGridView_reward_pq_specials->CurrentCell->Value);
								break;
				}
				// call debug function
				TriggerDebug((Control^)sender);
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void add_reward_pq_special(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedReward)
		{
			SelectedReward->pq->special_count++;
			Array::Resize(SelectedReward->pq->specials, SelectedReward->pq->specials->Length+1);
			SelectedReward->pq->specials[SelectedReward->pq->specials->Length-1] = gcnew PQ_Special();

			SelectedReward->pq->specials[SelectedReward->pq->items->Length-1]->id_pq = 0;
			SelectedReward->pq->specials[SelectedReward->pq->items->Length-1]->unknown_2 = 0;
			SelectedReward->pq->specials[SelectedReward->pq->items->Length-1]->unknown_3 = 0;

			dataGridView_reward_pq_specials->Rows->Add(gcnew array<String^>{"0", "0", "0"});
		}
	}
	private: System::Void remove_reward_pq_special(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedReward)
		{
			if(SelectedReward->pq->special_count>0 && dataGridView_reward_pq_specials->CurrentCell->RowIndex>-1)
			{
				SelectedReward->pq->special_count--;

				array<PQ_Special^>^ temp = gcnew array<PQ_Special^>(SelectedReward->pq->special_count);
				Array::Copy(SelectedReward->pq->specials, 0, temp, 0, dataGridView_reward_pq_specials->CurrentCell->RowIndex);
				Array::Copy(SelectedReward->pq->specials, dataGridView_reward_pq_specials->CurrentCell->RowIndex+1, temp, dataGridView_reward_pq_specials->CurrentCell->RowIndex, SelectedReward->pq->special_count - dataGridView_reward_pq_specials->CurrentCell->RowIndex);
				SelectedReward->pq->specials = temp;

				dataGridView_reward_pq_specials->Rows->RemoveAt(dataGridView_reward_pq_specials->CurrentCell->RowIndex);
			}
		}
	}
	// reward pq scripts
	private: System::Void change_reward_pq_scripts(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
	{
		if(SelectedReward)
		{
			try
			{
				int r = dataGridView_reward_pq_scripts->CurrentCell->RowIndex;
				switch(dataGridView_reward_pq_scripts->CurrentCell->ColumnIndex)
				{
					case 0:		SelectedReward->pq->scripts[r] = HexString_to_ByteArray(dataGridView_reward_pq_scripts->CurrentCell->Value->ToString());
								break;
				}
				// call debug function
				TriggerDebug((Control^)sender);
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void add_reward_pq_script(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedReward)
		{
			SelectedReward->pq->script_count++;
			Array::Resize(SelectedReward->pq->scripts, SelectedReward->pq->scripts->Length+1);
			SelectedReward->pq->scripts[SelectedReward->pq->scripts->Length-1] = gcnew array<unsigned char>(576);

			dataGridView_reward_pq_scripts->Rows->Add(gcnew array<String^>{ByteArray_to_HexString(SelectedReward->pq->scripts[SelectedReward->pq->scripts->Length-1])});
		}
	}
	private: System::Void remove_reward_pq_script(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedReward)
		{
			if(SelectedReward->pq->script_count>0 && dataGridView_reward_pq_scripts->CurrentCell->RowIndex>-1)
			{
				SelectedReward->pq->script_count--;

				array<array<unsigned char>^>^ temp = gcnew array<array<unsigned char>^>(SelectedReward->pq->script_count);
				Array::Copy(SelectedReward->pq->scripts, 0, temp, 0, dataGridView_reward_pq_scripts->CurrentCell->RowIndex);
				Array::Copy(SelectedReward->pq->scripts, dataGridView_reward_pq_scripts->CurrentCell->RowIndex+1, temp, dataGridView_reward_pq_scripts->CurrentCell->RowIndex, SelectedReward->pq->script_count - dataGridView_reward_pq_scripts->CurrentCell->RowIndex);
				SelectedReward->pq->scripts = temp;

				dataGridView_reward_pq_scripts->Rows->RemoveAt(dataGridView_reward_pq_scripts->CurrentCell->RowIndex);
			}
		}
	}
	// reward pq messages
	private: System::Void change_reward_pq_messages(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
	{
		if(SelectedReward)
		{
			try
			{
				int r = dataGridView_reward_pq_messages->CurrentCell->RowIndex;
				switch(dataGridView_reward_pq_messages->CurrentCell->ColumnIndex)
				{
					case 0:		SelectedReward->pq->messages[r] = UnicodeString_to_ByteArray(Convert::ToString(dataGridView_reward_pq_messages->CurrentCell->Value), 128);
								break;
				}
				// call debug function
				TriggerDebug((Control^)sender);
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void add_reward_pq_message(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedReward)
		{
			SelectedReward->pq->message_count++;
			Array::Resize(SelectedReward->pq->messages, SelectedReward->pq->messages->Length+1);
			SelectedReward->pq->messages[SelectedReward->pq->messages->Length-1] = gcnew array<unsigned char>(128);

			dataGridView_reward_pq_messages->Rows->Add(gcnew array<String^>{""});
		}
	}
	private: System::Void remove_reward_pq_message(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedReward)
		{
			if(SelectedReward->pq->message_count>0 && dataGridView_reward_pq_messages->CurrentCell->RowIndex>-1)
			{
				SelectedReward->pq->message_count--;

				array<array<unsigned char>^>^ temp = gcnew array<array<unsigned char>^>(SelectedReward->pq->message_count);
				Array::Copy(SelectedReward->pq->messages, 0, temp, 0, dataGridView_reward_pq_messages->CurrentCell->RowIndex);
				Array::Copy(SelectedReward->pq->messages, dataGridView_reward_pq_messages->CurrentCell->RowIndex+1, temp, dataGridView_reward_pq_messages->CurrentCell->RowIndex, SelectedReward->pq->message_count - dataGridView_reward_pq_messages->CurrentCell->RowIndex);
				SelectedReward->pq->messages = temp;

				dataGridView_reward_pq_messages->Rows->RemoveAt(dataGridView_reward_pq_messages->CurrentCell->RowIndex);
			}
		}
	}
	//
	private: System::Void change_reward_influence(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedReward)
		{
			try
			{
				// check if value really changed
				if(SelectedReward->influence != Convert::ToInt32(textBox_reward_influence->Text))
				{
					SelectedReward->influence = Convert::ToInt32(textBox_reward_influence->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_reward_prestige(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedReward)
		{
			try
			{
				// check if value really changed
				if(SelectedReward->prestige != Convert::ToInt32(textBox_reward_prestige->Text))
				{
					SelectedReward->prestige = Convert::ToInt32(textBox_reward_prestige->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_reward_unknown_5(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedReward)
		{
			try
			{
				// check if value really changed
				if(SelectedReward->UNKNOWN_5 != Convert::ToInt32(textBox_reward_unknown_5->Text))
				{
					SelectedReward->UNKNOWN_5 = Convert::ToInt32(textBox_reward_unknown_5->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_reward_unknown_6(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedReward)
		{
			try
			{
				// check if value really changed
				if(SelectedReward->UNKNOWN_6 != Convert::ToInt32(textBox_reward_unknown_6->Text))
				{
					SelectedReward->UNKNOWN_6 = Convert::ToInt32(textBox_reward_unknown_6->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_reward_quest_slot_expansion(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedReward)
		{
			try
			{
				// check if value really changed
				if(SelectedReward->quest_slot_expansion != Convert::ToInt32(textBox_reward_quest_slot_expansion->Text))
				{
					SelectedReward->quest_slot_expansion = Convert::ToInt32(textBox_reward_quest_slot_expansion->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	// reward items
	private: System::Void change_reward_item_groups_count(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedReward)
		{
			try
			{
				// check if value really changed
				if(SelectedReward->item_groups_count != Convert::ToInt32(numericUpDown_reward_item_groups_count->Value))
				{
					SelectedReward->item_groups_count = Convert::ToInt32(numericUpDown_reward_item_groups_count->Value);

					// Group Added
					if(SelectedReward->item_groups->Length < SelectedReward->item_groups_count)
					{
						Array::Resize(SelectedReward->item_groups, SelectedReward->item_groups_count);
						// fill itemgroups
						for(int i=Column_reward_item_groups->Items->Count; i<SelectedReward->item_groups_count; i++)
						{
							// create empty itemgroup
							SelectedReward->item_groups[i] = gcnew ItemGroup();
							SelectedReward->item_groups[i]->items = gcnew array<Item^>(0);
							// add itemgroup to datagridview's combobox-column
							Column_reward_item_groups->Items->Add(i.ToString());
							// add itemgroup to checked lidtbox
							checkedListBox_reward_item_groups_flag->Items->Add("Group[" + i.ToString() + "] Flag", false);
						}

						MessageBox::Show("HINT: Added Item Group(s) contains no Items!");
					}

					// Group Removed
					if(SelectedReward->item_groups->Length > SelectedReward->item_groups_count)
					{
						// remove disposed itemgroups
						array<ItemGroup^>^ temp = gcnew array<ItemGroup^>(SelectedReward->item_groups_count);
						Array::Copy(SelectedReward->item_groups, temp, temp->Length);
						SelectedReward->item_groups = temp;

						// remove rows from datagrid
						for(int i=0; i<dataGridView_reward_item_group_items->RowCount; i++)
						{
							if(Convert::ToInt32(dataGridView_reward_item_group_items->Rows[i]->Cells[0]->Value) >= SelectedReward->item_groups_count)
							{
								dataGridView_reward_item_group_items->Rows->RemoveAt(i);
								i--;
							}
						}

						// remove group from combobox-column
						for(int i=SelectedReward->item_groups_count; i<Column_reward_item_groups->Items->Count; i++)
						{
							checkedListBox_reward_item_groups_flag->Items->RemoveAt(i);
							Column_reward_item_groups->Items->RemoveAt(Column_reward_item_groups->Items->Count-1);
						}
					}

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_reward_item_group_flag(System::Object^  sender, System::Windows::Forms::ItemCheckEventArgs^  e)
	{
		if(SelectedReward)
		{
			try
			{
				// check if value really changed
				if(SelectedReward->item_groups[e->Index]->unknown != (e->NewValue == CheckState::Checked))
				{
					SelectedReward->item_groups[e->Index]->unknown = (e->NewValue == CheckState::Checked);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_reward_items(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
	{
		if(SelectedReward)
		{
			try
			{
				// Rebuild all reward groups, instead of managing moving items between groups...
				SelectedReward->item_groups_count = Convert::ToInt32(numericUpDown_reward_item_groups_count->Value);
				SelectedReward->item_groups = gcnew array<ItemGroup^>(SelectedReward->item_groups_count);

				// create empty itemgroups
				for(int g=0; g<SelectedReward->item_groups->Length; g++)
				{
					SelectedReward->item_groups[g] = gcnew ItemGroup();
					if(checkedListBox_reward_item_groups_flag->CheckedItems->Contains(checkedListBox_reward_item_groups_flag->Items[g]))
					{
						SelectedReward->item_groups[g]->unknown = true;
					}
					else
					{
						SelectedReward->item_groups[g]->unknown = false;
					}
					SelectedReward->item_groups[g]->items_count = 0;
					SelectedReward->item_groups[g]->items = gcnew array<Item^>(0);
				}

				// scan all datagridview lines and add items to the corresponding itemgroups
				for(int r=0; r<dataGridView_reward_item_group_items->RowCount; r++)
				{
					int g = Convert::ToInt32(dataGridView_reward_item_group_items->Rows[r]->Cells[0]->Value);

					SelectedReward->item_groups[g]->items_count++;
					Array::Resize(SelectedReward->item_groups[g]->items, SelectedReward->item_groups[g]->items->Length+1);
					SelectedReward->item_groups[g]->items[SelectedReward->item_groups[g]->items->Length-1] = gcnew Item();
					SelectedReward->item_groups[g]->items[SelectedReward->item_groups[g]->items->Length-1]->id = Convert::ToInt32(dataGridView_reward_item_group_items->Rows[r]->Cells[1]->Value);
					SelectedReward->item_groups[g]->items[SelectedReward->item_groups[g]->items->Length-1]->unknown = Convert::ToBoolean(dataGridView_reward_item_group_items->Rows[r]->Cells[2]->Value);
					SelectedReward->item_groups[g]->items[SelectedReward->item_groups[g]->items->Length-1]->amount = Convert::ToInt32(dataGridView_reward_item_group_items->Rows[r]->Cells[3]->Value);
					SelectedReward->item_groups[g]->items[SelectedReward->item_groups[g]->items->Length-1]->probability = Convert::ToSingle(dataGridView_reward_item_group_items->Rows[r]->Cells[4]->Value);
					SelectedReward->item_groups[g]->items[SelectedReward->item_groups[g]->items->Length-1]->expiration = Convert::ToInt32(dataGridView_reward_item_group_items->Rows[r]->Cells[5]->Value);
				}

				// call debug function
				TriggerDebug((Control^)sender);
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void add_reward_item(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedReward)
		{
			// add item to the last item group
			int g = Convert::ToInt32(numericUpDown_reward_item_groups_count->Value-1);
			if(g > -1)
			{
				// add item directly to itemgroup instead of rebuilding all groups: change_reward_items(nullptr, nullptr)
				SelectedReward->item_groups[g]->items_count++;
				Array::Resize(SelectedReward->item_groups[g]->items, SelectedReward->item_groups[g]->items->Length+1);
				SelectedReward->item_groups[g]->items[SelectedReward->item_groups[g]->items->Length-1] = gcnew Item();

				SelectedReward->item_groups[g]->items[SelectedReward->item_groups[g]->items->Length-1]->id = 0;
				SelectedReward->item_groups[g]->items[SelectedReward->item_groups[g]->items->Length-1]->unknown = true;
				SelectedReward->item_groups[g]->items[SelectedReward->item_groups[g]->items->Length-1]->amount = 0;
				SelectedReward->item_groups[g]->items[SelectedReward->item_groups[g]->items->Length-1]->probability = 1.0;
				SelectedReward->item_groups[g]->items[SelectedReward->item_groups[g]->items->Length-1]->expiration = 0;

				dataGridView_reward_item_group_items->Rows->Add(gcnew array<String^>{g.ToString(), "0", "True", "0", "1.0", "0"});
			}
			else
			{
				MessageBox::Show("No Item Group found!\nPlease increase the Number of Item Groups!");
			}
		}
	}
	private: System::Void remove_reward_item(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedReward)
		{
			int r = dataGridView_reward_item_group_items->CurrentCell->RowIndex;
			int g = Convert::ToInt32(dataGridView_reward_item_group_items->Rows[r]->Cells[0]->Value);

			if(SelectedReward->item_groups[g]->items_count>0 && dataGridView_reward_item_group_items->CurrentCell->RowIndex>-1)
			{
				dataGridView_reward_item_group_items->Rows->RemoveAt(r);

				// datagridview row index != item index, which make it hard to find the removed item in the corresponding item group
				// rebuilding item groups instead of removing
				change_reward_items(nullptr, nullptr);

				// check for blank item group
				if(SelectedReward->item_groups[g]->items_count == 0)
				{
					MessageBox::Show("WARNING: Item Groups[" + g.ToString() + "] contains no Items!");
				}
			}
		}
	}
	// conversation
	private: System::Void change_conversation_prompt_text(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->conversation->PromptText != textBox_conversation_prompt_text->Text)
				{
					SelectedTask->conversation->PromptText = textBox_conversation_prompt_text->Text;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_conversation_general_text(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				// check if value really changed
				if(SelectedTask->conversation->GeneralText != textBox_conversation_general_text->Text)
				{
					SelectedTask->conversation->GeneralText = textBox_conversation_general_text->Text;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_conversation_dialog_unknown(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				int d = listBox_conversation_dialogs->SelectedIndex;

				// check if value really changed
				if(d > -1 && SelectedTask->conversation->dialogs[d]->unknown != Convert::ToInt32(textBox_conversation_dialog_unknown->Text))
				{
					SelectedTask->conversation->dialogs[d]->unknown = Convert::ToInt32(textBox_conversation_dialog_unknown->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_conversation_dialog_text(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				int d = listBox_conversation_dialogs->SelectedIndex;

				// check if value really changed
				if(d > -1 && SelectedTask->conversation->dialogs[d]->DialogText != textBox_conversation_dialog_text->Text)
				{
					SelectedTask->conversation->dialogs[d]->DialogText = textBox_conversation_dialog_text->Text;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_conversation_question_id(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				int d = listBox_conversation_dialogs->SelectedIndex;
				int q = listBox_conversation_questions->SelectedIndex;

				// check if value really changed
				if(d > -1 && q > -1 && SelectedTask->conversation->dialogs[d]->questions[q]->question_id != Convert::ToInt32(textBox_conversation_question_id->Text))
				{
					SelectedTask->conversation->dialogs[d]->questions[q]->question_id = Convert::ToInt32(textBox_conversation_question_id->Text);
					listBox_conversation_questions->Items[q] = "[" + textBox_conversation_question_id->Text + "] Question";

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_conversation_question_previous(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				int d = listBox_conversation_dialogs->SelectedIndex;
				int q = listBox_conversation_questions->SelectedIndex;

				// check if value really changed
				if(d > -1 && q > -1 && SelectedTask->conversation->dialogs[d]->questions[q]->previous_question != Convert::ToInt32(textBox_conversation_question_previous->Text))
				{
					SelectedTask->conversation->dialogs[d]->questions[q]->previous_question = Convert::ToInt32(textBox_conversation_question_previous->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_conversation_question_text(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				int d = listBox_conversation_dialogs->SelectedIndex;
				int q = listBox_conversation_questions->SelectedIndex;

				// check if value really changed
				if(d > -1 && q > -1 && SelectedTask->conversation->dialogs[d]->questions[q]->QuestionText != textBox_conversation_question_text->Text)
				{
					SelectedTask->conversation->dialogs[d]->questions[q]->QuestionText = textBox_conversation_question_text->Text;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void add_question(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			int d = listBox_conversation_dialogs->SelectedIndex;

			if(d > -1)
			{
				SelectedTask->conversation->dialogs[d]->question_count++;
				Array::Resize(SelectedTask->conversation->dialogs[d]->questions, SelectedTask->conversation->dialogs[d]->questions->Length+1);

				SelectedTask->conversation->dialogs[d]->questions[SelectedTask->conversation->dialogs[d]->questions->Length-1] = gcnew Question();
				SelectedTask->conversation->dialogs[d]->questions[SelectedTask->conversation->dialogs[d]->questions->Length-1]->crypt_key = SelectedTask->conversation->crypt_key;
				SelectedTask->conversation->dialogs[d]->questions[SelectedTask->conversation->dialogs[d]->questions->Length-1]->question_id = SelectedTask->conversation->dialogs[d]->questions->Length;
				if(SelectedTask->conversation->dialogs[d]->questions->Length > 1)
				{
					SelectedTask->conversation->dialogs[d]->questions[SelectedTask->conversation->dialogs[d]->questions->Length-1]->previous_question = SelectedTask->conversation->dialogs[d]->questions->Length-1;
				}
				else
				{
					SelectedTask->conversation->dialogs[d]->questions[SelectedTask->conversation->dialogs[d]->questions->Length-1]->previous_question = -1;
				}
				SelectedTask->conversation->dialogs[d]->questions[SelectedTask->conversation->dialogs[d]->questions->Length-1]->answer_count = 0;
				SelectedTask->conversation->dialogs[d]->questions[SelectedTask->conversation->dialogs[d]->questions->Length-1]->answers = gcnew array<Answer^>(0);
				SelectedTask->conversation->dialogs[d]->questions[SelectedTask->conversation->dialogs[d]->questions->Length-1]->QuestionText = "BLANK";

				listBox_conversation_questions->Items->Add("[" + SelectedTask->conversation->dialogs[d]->questions->Length + "] Question");
			}
		}
	}
	private: System::Void remove_question(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			int d = listBox_conversation_dialogs->SelectedIndex;
			int q = listBox_conversation_questions->SelectedIndex;

			if(d > -1 && q > -1 && SelectedTask->conversation->dialogs[d]->question_count>0)
			{
				SelectedTask->conversation->dialogs[d]->question_count--;

				array<Question^>^ temp = gcnew array<Question^>(SelectedTask->conversation->dialogs[d]->question_count);
				Array::Copy(SelectedTask->conversation->dialogs[d]->questions, 0, temp, 0, listBox_conversation_questions->SelectedIndex);
				Array::Copy(SelectedTask->conversation->dialogs[d]->questions, listBox_conversation_questions->SelectedIndex+1, temp, listBox_conversation_questions->SelectedIndex, SelectedTask->conversation->dialogs[d]->question_count - listBox_conversation_questions->SelectedIndex);
				SelectedTask->conversation->dialogs[d]->questions = temp;

				// try to automatic updating all id's and previous_links...
				for(int i=0; i<SelectedTask->conversation->dialogs[d]->questions->Length; i++)
				{
					SelectedTask->conversation->dialogs[d]->questions[i]->question_id = i+1;
					if(i > 0)
					{
						SelectedTask->conversation->dialogs[d]->questions[i]->previous_question = i;
					}
					else
					{
						SelectedTask->conversation->dialogs[d]->questions[i]->previous_question = -1;
					}
				}

				// refresh question listbox
				select_dialog(nullptr, nullptr);
			}
		}
	}
	private: System::Void change_conversation_answer_question_link(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				int d = listBox_conversation_dialogs->SelectedIndex;
				int q = listBox_conversation_questions->SelectedIndex;
				int a = listBox_conversation_answers->SelectedIndex;

				// check if value really changed
				if(d > -1 && q > -1 && a > -1 && SelectedTask->conversation->dialogs[d]->questions[q]->answers[a]->question_link != Convert::ToInt32(textBox_conversation_answer_question_link->Text))
				{
					SelectedTask->conversation->dialogs[d]->questions[q]->answers[a]->question_link = Convert::ToInt32(textBox_conversation_answer_question_link->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_conversation_answer_task_link(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				int d = listBox_conversation_dialogs->SelectedIndex;
				int q = listBox_conversation_questions->SelectedIndex;
				int a = listBox_conversation_answers->SelectedIndex;

				// check if value really changed
				if(d > -1 && q > -1 && a > -1 && SelectedTask->conversation->dialogs[d]->questions[q]->answers[a]->task_link != Convert::ToInt32(textBox_conversation_answer_task_link->Text))
				{
					SelectedTask->conversation->dialogs[d]->questions[q]->answers[a]->task_link = Convert::ToInt32(textBox_conversation_answer_task_link->Text);

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_conversation_answer_text(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			try
			{
				int d = listBox_conversation_dialogs->SelectedIndex;
				int q = listBox_conversation_questions->SelectedIndex;
				int a = listBox_conversation_answers->SelectedIndex;

				// check if value really changed
				if(d > -1 && q > -1 && a > -1 && SelectedTask->conversation->dialogs[d]->questions[q]->answers[a]->AnswerText != textBox_conversation_answer_text->Text)
				{
					SelectedTask->conversation->dialogs[d]->questions[q]->answers[a]->AnswerText = textBox_conversation_answer_text->Text;

					// call debug function
					TriggerDebug((Control^)sender);
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void add_answer(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			int d = listBox_conversation_dialogs->SelectedIndex;
			int q = listBox_conversation_questions->SelectedIndex;

			if(d > -1 && q > -1)
			{
				SelectedTask->conversation->dialogs[d]->questions[q]->answer_count++;
				Array::Resize(SelectedTask->conversation->dialogs[d]->questions[q]->answers, SelectedTask->conversation->dialogs[d]->questions[q]->answers->Length+1);

				SelectedTask->conversation->dialogs[d]->questions[q]->answers[SelectedTask->conversation->dialogs[d]->questions[q]->answers->Length-1] = gcnew Answer();
				SelectedTask->conversation->dialogs[d]->questions[q]->answers[SelectedTask->conversation->dialogs[d]->questions[q]->answers->Length-1]->crypt_key = SelectedTask->conversation->crypt_key;
				SelectedTask->conversation->dialogs[d]->questions[q]->answers[SelectedTask->conversation->dialogs[d]->questions[q]->answers->Length-1]->question_link = -2147483642;
				SelectedTask->conversation->dialogs[d]->questions[q]->answers[SelectedTask->conversation->dialogs[d]->questions[q]->answers->Length-1]->task_link = SelectedTask->ID;
				SelectedTask->conversation->dialogs[d]->questions[q]->answers[SelectedTask->conversation->dialogs[d]->questions[q]->answers->Length-1]->AnswerText = "OK";

				listBox_conversation_answers->Items->Add("[" + SelectedTask->conversation->dialogs[d]->questions[q]->answers->Length + "] Answer");
			}
		}
	}
	private: System::Void remove_answer(System::Object^  sender, System::EventArgs^  e)
	{
		if(SelectedTask)
		{
			int d = listBox_conversation_dialogs->SelectedIndex;
			int q = listBox_conversation_questions->SelectedIndex;
			int a = listBox_conversation_answers->SelectedIndex;

			if(d > -1 && q > -1 && a > -1 && SelectedTask->conversation->dialogs[d]->question_count>0)
			{
				SelectedTask->conversation->dialogs[d]->questions[q]->answer_count--;

				array<Answer^>^ temp = gcnew array<Answer^>(SelectedTask->conversation->dialogs[d]->questions[q]->answer_count);
				Array::Copy(SelectedTask->conversation->dialogs[d]->questions[q]->answers, 0, temp, 0, listBox_conversation_answers->SelectedIndex);
				Array::Copy(SelectedTask->conversation->dialogs[d]->questions[q]->answers, listBox_conversation_answers->SelectedIndex+1, temp, listBox_conversation_answers->SelectedIndex, SelectedTask->conversation->dialogs[d]->questions[q]->answer_count - listBox_conversation_answers->SelectedIndex);
				SelectedTask->conversation->dialogs[d]->questions[q]->answers = temp;

				// refresh question listbox
				select_question(nullptr, nullptr);
			}
		}
	}

#pragma endregion

#pragma region DEVELOPER FUNCTIONS

	// returns the id of the current task, if selected condition is true
	private: int developer_check_condition(Task^ task)
	{
		String^ condition = toolStripComboBox_developer_search->SelectedItem->ToString();

		if(condition == "Required be GM")
		{
			if(task->required_be_gm)
			{
				return task->ID;
			}
		}

		if(condition == "UNKNOWN_43")
		{
			if(task->UNKNOWN_43)
			{
				return task->ID;
			}
		}

		if(condition == "Prestige")
		{
			if(task->reward_success->prestige != 0)
			{
				return task->ID;
			}
			if(task->reward_failed->prestige != 0)
			{
				return task->ID;
			}
			for(int i=0; i<task->rewards_timed->Length; i++)
			{
				if(task->rewards_timed[i]->prestige != 0)
				{
					return task->ID;
				}
			}
		}

		if(condition == "Influence")
		{
			if(task->reward_success->influence != 0)
			{
				return task->ID;
			}
			if(task->reward_failed->influence != 0)
			{
				return task->ID;
			}
			for(int i=0; i<task->rewards_timed->Length; i++)
			{
				if(task->rewards_timed[i]->influence != 0)
				{
					return task->ID;
				}
			}
		}

		if(condition == "Event Gold")
		{
			if(task->reward_success->pq->event_gold != 0)
			{
				return task->ID;
			}
			if(task->reward_failed->pq->event_gold != 0)
			{
				return task->ID;
			}
			for(int i=0; i<task->rewards_timed->Length; i++)
			{
				if(task->rewards_timed[i]->pq->event_gold != 0)
				{
					return task->ID;
				}
			}
		}

		if(condition == "Reward PQ Chases")
		{
			if(task->reward_success->pq->chase_count != 0)
			{
				return task->ID;
			}
			if(task->reward_failed->pq->chase_count != 0)
			{
				return task->ID;
			}
			for(int i=0; i<task->rewards_timed->Length; i++)
			{
				if(task->rewards_timed[i]->pq->chase_count != 0)
				{
					return task->ID;
				}
			}
		}

		if(condition == "Reward PQ Items")
		{
			if(task->reward_success->pq->item_count != 0)
			{
				return task->ID;
			}
			if(task->reward_failed->pq->item_count != 0)
			{
				return task->ID;
			}
			for(int i=0; i<task->rewards_timed->Length; i++)
			{
				if(task->rewards_timed[i]->pq->item_count != 0)
				{
					return task->ID;
				}
			}
		}

		if(condition == "Reward PQ Scripts")
		{
			if(task->reward_success->pq->script_count != 0)
			{
				return task->ID;
			}
			if(task->reward_failed->pq->script_count != 0)
			{
				return task->ID;
			}
			for(int i=0; i<task->rewards_timed->Length; i++)
			{
				if(task->rewards_timed[i]->pq->script_count != 0)
				{
					return task->ID;
				}
			}
		}

		if(condition == "Reward PQ Messages")
		{
			if(task->reward_success->pq->message_count != 0)
			{
				return task->ID;
			}
			if(task->reward_failed->pq->message_count != 0)
			{
				return task->ID;
			}
			for(int i=0; i<task->rewards_timed->Length; i++)
			{
				if(task->rewards_timed[i]->pq->message_count != 0)
				{
					return task->ID;
				}
			}
		}

		if(condition == "Reward Unknown 5")
		{
			if(task->reward_success->UNKNOWN_5 != 0)
			{
				return task->ID;
			}
			if(task->reward_failed->UNKNOWN_5 != 0)
			{
				return task->ID;
			}
			for(int i=0; i<task->rewards_timed->Length; i++)
			{
				if(task->rewards_timed[i]->UNKNOWN_5 != 0)
				{
					return task->ID;
				}
			}
		}

		if(condition == "Reward Unknown 6")
		{
			if(task->reward_success->UNKNOWN_6 != 0)
			{
				return task->ID;
			}
			if(task->reward_failed->UNKNOWN_6 != 0)
			{
				return task->ID;
			}
			for(int i=0; i<task->rewards_timed->Length; i++)
			{
				if(task->rewards_timed[i]->UNKNOWN_6 != 0)
				{
					return task->ID;
				}
			}
		}

		if(condition == "Reward Timed")
		{
			if(task->rewards_timed->Length > 0)
			{
				return task->ID;
			}
		}

		return 0;
	}
	// returns a list of id's where selected condition is true
	// scans recursive into sub tasks
	private: String^ developer_scan(array<Task^>^ tasks)
	{
		String^log = "";

		for(int i=0; i<tasks->Length; i++)
		{
			int result = developer_check_condition(tasks[i]);
			if(result > 0)
			{
				log += result.ToString() + "\r\n";
			}
			if(tasks[i]->sub_quests->Length > 0)
			{
				log += developer_scan(tasks[i]->sub_quests);
			}
		}

		return log;
	}
	private: System::Void click_developer_search(System::Object^  sender, System::EventArgs^  e)
	{
		if(Tasks)
		{
			String^ log = "";
			log = developer_scan(Tasks);

			gcnew DebugWindow("Tasks Found", log);
		}
		else
		{
			MessageBox::Show("Please Load a File!");
		}
	}

#pragma endregion
};