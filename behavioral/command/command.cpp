#include "command.hpp"

// ============ Static Functions ============
static void printToConsole(std::string string) {
	std::cout << string << std::endl;
}

// ============ TV ============
TV::TV(bool isPowered,
	   int channel,
	   int volume) :
	isPowered(isPowered),
	channel(channel),
	volume(volume)
{ }

void TV::powerOn() {
	if (getIsPowered())	{
		printToConsole("TV is ALREADY powered on!");
	}
	else {
		setIsPowered(true);
		printToConsole("TV is powered on!");
	}
}

void TV::powerOff() {
	if (getIsPowered()) {
		setIsPowered(false);
		printToConsole("TV is powered off!");
	}
	else {
		printToConsole("TV is already off!");
	}
}

void TV::volumeUp() {
	if (getIsPowered() && getVolume() < MAXVOLUME) {
		setVolume(getVolume() + 1);
		printToConsole("TV volumed up!");
	}
	else if (getIsPowered() && getVolume() >= MAXVOLUME) {
		setVolume(MAXVOLUME); // make sure it's at the highest
		printToConsole("TV can't increase volume! Volume at it's highest");
	}
	else printToConsole("Can change volume -- TV is powered off!");
}

void TV::volumeDown() {
	if (getIsPowered() && getVolume() > MINVOLUME) {
		setVolume(getVolume() - 1);
		printToConsole("TV volumed down!");
	}
	else if (getIsPowered() && getVolume() <= MINVOLUME) {
		setVolume(MINVOLUME); // make sure it's at the lowest
		printToConsole("TV can't decrease volume! Volume at it's lowest");
	}
	else printToConsole("TV not powered -- can't decrease volume!");
}

void TV::channelUp() {
	if (getIsPowered() && getChannel() < MAXCHANNEL) {
		setChannel(getChannel() + 1);
		printToConsole("TV channeled up!");
	}
	else if (getIsPowered() && getChannel() >= MAXCHANNEL) {
		setChannel(MAXCHANNEL); // make sure it's at the highest
		printToConsole("TV can't increase channel! Channel at it's highest");
	}
	else printToConsole("TV not powered -- can't increase the channel!");
}

void TV::channelDown() {
	if (getIsPowered() && getChannel() > MINCHANNEL) {
		setChannel(getChannel() - 1);
		printToConsole("TV channeled down!");
	}
	else if (getIsPowered() && getChannel() <= MINCHANNEL) {
		setChannel(MINCHANNEL); // make sure it's at the lowest
		printToConsole("TV can't decrease channel! Channel at it's lowest");
	}
	else {
		printToConsole("TV not powered -- can't decrease the channel!");
	}
}

// ============ PowerOn ============
PowerOn::PowerOn(TV * tv) :
	tv(tv)
{ }

void PowerOn::execute() {
	getTV()->powerOn();
}

// ============ PowerOff ============
PowerOff::PowerOff(TV * tv) :
	tv(tv)
{ }

void PowerOff::execute() {
	getTV()->powerOff();
}

// ============ VolumeUp ============
VolumeUp::VolumeUp(TV * tv) :
	tv(tv)
{ }

void VolumeUp::execute() {
	getTV()->volumeUp();
}

// ============ VolumeDown ============
VolumeDown::VolumeDown(TV * tv) :
	tv(tv)
{ }

void VolumeDown::execute() {
	getTV()->volumeDown();
}

// ============ ChannelUp ============
ChannelUp::ChannelUp(TV * tv) :
	tv(tv)
{ }

void ChannelUp::execute() {
	getTV()->channelUp();
}

// ============ ChannelDown ============
ChannelDown::ChannelDown(TV * tv) :
	tv(tv)
{ }

void ChannelDown::execute() {
	getTV()->channelDown();
}

// ============ Invoker ============
TVRemote::TVRemote(TVCommand* tvCommand) :
	tvCommand(tvCommand)
{ }

TVCommand* TVRemote::getTVCommand() const {
	return this->tvCommand;
}

void TVRemote::setCommand(TVCommand* tvCommand) {
	this->tvCommand = tvCommand;
}

void TVRemote::command() const {
	getTVCommand()->execute();
}

// ============ Client Code ============
static void tvCommand(TVRemote * tvRemote, TVCommand * tvCommand) {
	tvRemote->setCommand(tvCommand);
	tvRemote->command();
}
// ============ Main ============
int main() {
	TV * tv = new TV(); // receiver
	TVRemote * tvRemote = new TVRemote(); // invoker

	// execute
	tvCommand(tvRemote, new PowerOn(tv));
	tvCommand(tvRemote, new VolumeUp(tv));
	tvCommand(tvRemote, new VolumeDown(tv));
	tvCommand(tvRemote, new ChannelUp(tv));
	tvCommand(tvRemote, new ChannelDown(tv));
	tvCommand(tvRemote, new PowerOff(tv));

	return 0;
}