#ifndef USER_ACTION
#define USER_ACTION

enum UserActionType {
	MOUSE_OVER
};

struct UserAction {
	UserActionType type;
	int bidon;
};

#endif