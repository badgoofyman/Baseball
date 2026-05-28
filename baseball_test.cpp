#include "gmock/gmock.h"
#include "baseball.cpp"

class BaseballFixture : public testing::Test {
public:
	Baseball game;
	void assertIllegalArgument(string geussNumber) {
		try {
			game.guess(geussNumber);
			FAIL();
		}
		catch (exception e) {
			// PASS();
		}
	}
};


TEST_F(BaseballFixture, ThrowExceptionWhenInvalidCase) {
	assertIllegalArgument("12");
	assertIllegalArgument("12s");
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}