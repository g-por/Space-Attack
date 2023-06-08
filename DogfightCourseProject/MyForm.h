#pragma once
#include "EndScreen.h"
namespace DogfightCourseProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		bool goLeft, goRight, shooting,  checkScore;//isGameOver,
		int score;
		int playerSpeed = 5;
		int enemySpeed;
		int bulletSpeed;
		int level = 1;
		Random^ rnd = gcnew Random();


	private: System::Windows::Forms::Timer^ gameTimer;
	public:


		MyForm(void)
		{
			InitializeComponent();
			resetGame();
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ enemy1;
	private: System::Windows::Forms::PictureBox^ enemy2;
	private: System::Windows::Forms::PictureBox^ enemy3;
	private: System::Windows::Forms::PictureBox^ bullet;
	private: System::Windows::Forms::PictureBox^ player;
	private: System::Windows::Forms::Label^ scoreTxt;

	private: System::ComponentModel::IContainer^ components;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->enemy1 = (gcnew System::Windows::Forms::PictureBox());
			this->enemy2 = (gcnew System::Windows::Forms::PictureBox());
			this->enemy3 = (gcnew System::Windows::Forms::PictureBox());
			this->bullet = (gcnew System::Windows::Forms::PictureBox());
			this->player = (gcnew System::Windows::Forms::PictureBox());
			this->scoreTxt = (gcnew System::Windows::Forms::Label());
			this->gameTimer = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->enemy1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->enemy2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->enemy3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bullet))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->player))->BeginInit();
			this->SuspendLayout();
			// 
			// enemy1
			// 
			this->enemy1->BackColor = System::Drawing::Color::Transparent;
			this->enemy1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"enemy1.Image")));
			this->enemy1->Location = System::Drawing::Point(53, 33);
			this->enemy1->Name = L"enemy1";
			this->enemy1->Size = System::Drawing::Size(168, 120);
			this->enemy1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->enemy1->TabIndex = 0;
			this->enemy1->TabStop = false;
			// 
			// enemy2
			// 
			this->enemy2->BackColor = System::Drawing::Color::Transparent;
			this->enemy2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"enemy2.Image")));
			this->enemy2->Location = System::Drawing::Point(489, 12);
			this->enemy2->Name = L"enemy2";
			this->enemy2->Size = System::Drawing::Size(141, 120);
			this->enemy2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->enemy2->TabIndex = 1;
			this->enemy2->TabStop = false;
			// 
			// enemy3
			// 
			this->enemy3->BackColor = System::Drawing::Color::Transparent;
			this->enemy3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"enemy3.Image")));
			this->enemy3->Location = System::Drawing::Point(975, 12);
			this->enemy3->Name = L"enemy3";
			this->enemy3->Size = System::Drawing::Size(126, 120);
			this->enemy3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->enemy3->TabIndex = 2;
			this->enemy3->TabStop = false;
			// 
			// bullet
			// 
			this->bullet->BackColor = System::Drawing::Color::Transparent;
			this->bullet->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bullet.Image")));
			this->bullet->Location = System::Drawing::Point(668, 440);
			this->bullet->Name = L"bullet";
			this->bullet->Size = System::Drawing::Size(45, 46);
			this->bullet->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->bullet->TabIndex = 3;
			this->bullet->TabStop = false;
			// 
			// player
			// 
			this->player->BackColor = System::Drawing::Color::Transparent;
			this->player->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"player.Image")));
			this->player->Location = System::Drawing::Point(905, 539);
			this->player->Name = L"player";
			this->player->Size = System::Drawing::Size(324, 109);
			this->player->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->player->TabIndex = 4;
			this->player->TabStop = false;
			// 
			// scoreTxt
			// 
			this->scoreTxt->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->scoreTxt->BackColor = System::Drawing::Color::Transparent;
			this->scoreTxt->Cursor = System::Windows::Forms::Cursors::Default;
			this->scoreTxt->Font = (gcnew System::Drawing::Font(L"Times New Roman", 28.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->scoreTxt->ForeColor = System::Drawing::Color::Lime;
			this->scoreTxt->Location = System::Drawing::Point(12, 189);
			this->scoreTxt->Name = L"scoreTxt";
			this->scoreTxt->Size = System::Drawing::Size(1074, 169);
			this->scoreTxt->TabIndex = 5;
			this->scoreTxt->Text = L"Score: 0";
			this->scoreTxt->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// gameTimer
			// 
			this->gameTimer->Enabled = true;
			this->gameTimer->Interval = 1;
			this->gameTimer->Tick += gcnew System::EventHandler(this, &MyForm::mainGameTimerEvent);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1113, 654);
			this->Controls->Add(this->player);
			this->Controls->Add(this->bullet);
			this->Controls->Add(this->enemy3);
			this->Controls->Add(this->enemy2);
			this->Controls->Add(this->enemy1);
			this->Controls->Add(this->scoreTxt);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"Space Attack";
			this->TransparencyKey = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::keyIsDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::keyisUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->enemy1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->enemy2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->enemy3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bullet))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->player))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void mainGameTimerEvent(System::Object^ sender, System::EventArgs^ e) {


		scoreTxt->Text = score.ToString();

		enemy1->Top += enemySpeed;
		enemy2->Top += enemySpeed;
		enemy3->Top += enemySpeed;

		if (enemy1->Top > 450|| enemy2->Top > 450 || enemy3->Top > 450) {
			gameOver();
		}

		if (goLeft == true && player->Left > -75)
		{
			player->Left -= playerSpeed;
		}
		if (goRight == true && player->Left < 660)
		{
			player->Left += playerSpeed;
		}

		if (shooting) {
			bulletSpeed = 20;
			bullet->Top -= bulletSpeed;
		}
		else {
			bullet->Left = -300;
			bulletSpeed = 0;
		}
		if (bullet->Top < -30) {
			shooting = false;
		}

		if (bullet->Bounds.IntersectsWith(enemy1->Bounds)) {
			score += 1;
			enemy1->Top = -350;
			enemy1->Left = rnd->Next(20,600);
			shooting = false;
			checkScore = true;
		}
		if (bullet->Bounds.IntersectsWith(enemy2->Bounds)) {
			score += 1;
			enemy2->Top = -650;
			enemy2->Left = rnd->Next(20, 600);
			shooting = false;
			checkScore = true;
		}
		if (bullet->Bounds.IntersectsWith(enemy3->Bounds)) {
			score += 1;
			enemy3->Top = -750;
			enemy3->Left = rnd->Next(20, 600);
			shooting = false;
			checkScore = true;
		}

		if (score != 0 && score % 10 == 0 && checkScore == true) {
			enemySpeed += 1;
			bulletSpeed += 1;
			playerSpeed += 1;
			level += 1;
			checkScore = false;
		}


	}
	private: System::Void keyIsDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Left)  //->Left)
		{
			goLeft = true;
		}
		if (e->KeyCode == Keys::Right)
		{
			goRight = true;
		}

	}
	private: System::Void keyisUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Left)  //->Left)
		{
			goLeft = false;
		}
		if (e->KeyCode == Keys::Right)
		{
			goRight = false;
		}

		if (e->KeyCode == Keys::Space && shooting == false) {
			shooting = true;
			bullet->Top = player->Top - 10;
			bullet->Left = player->Left + (player->Width/2.33);
		}

		//if (e->KeyCode == Keys::Enter && isGameOver == true) {
		//	resetGame();
		//}

	}
	private: System::Void resetGame() {
		gameTimer->Start();
		enemySpeed = 1;

		enemy1->Left = rnd->Next(20, 600);
		enemy2->Left = rnd->Next(20, 600);
		enemy3->Left = rnd->Next(20, 600);

		enemy1->Top = rnd->Next(0, 200)*-1;
		enemy2->Top = rnd->Next(0, 500)*-1;
		enemy3->Top = rnd->Next(0, 900)*-1;

		score = 0;
		bulletSpeed = 0;
		bullet->Left = -300;
		shooting = false;

		scoreTxt->Text = score.ToString();
	}
	private: System::Void gameOver() {
		//isGameOver = true;
		gameTimer->Stop();

		EndScreen^ final = gcnew EndScreen(score);
		this->Hide();
		final->ShowDialog(); // Викликати форму EndScreen модально
		this->Close();
		//scoreTxt->Text += Environment::NewLine + "GAME OVER" + Environment::NewLine + "Press Enter to try again";
	}

};
}
 