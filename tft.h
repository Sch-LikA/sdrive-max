struct b_flags {
	char type : 1;		//ROUND, SQUARE
	char active : 1;
	char selected : 1;
};

struct button {
	char *name;
	unsigned int x;
	unsigned int y;
	unsigned int width;
	unsigned int heigth;
	unsigned int fg;	//foreground/fill color
	unsigned int bg;	//background/edge color
	unsigned int fc;	//Font color
	struct b_flags *flags;
	unsigned int (*pressed)(struct button *);
};

//#define nbuttons 6	//now automatically detected
struct page {
	void (*draw)(void);
	struct button *buttons;
	unsigned char nbuttons;
};

struct display {
	unsigned int width;
	unsigned int heigth;
	struct {
		unsigned char rot : 1;
		unsigned char scroll : 1;
		unsigned char boot_d1 : 1;
	} cfg;
	struct page *pages;
	//struct TSPoint *tp;	//unused
};

struct file_save {
	u32 dir_cluster;
	u16 file_index;
};

//functions for external use
void pretty_name(char *b);

void draw_Buttons ();

void outbox_P(const char *);
void outbox(char *);

void tft_Setup();

struct button * check_Buttons();
