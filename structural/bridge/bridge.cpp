#include <iostream>

#include "bridge.hpp"

enum State { OFF = 0, ON };

int const MAXIMUM_VOLUME = 10;
int const MINIMUM_VOLUME = 0;

int const MAXIMUM_CHANNEL = 100;
int const MINIMUM_CHANNEL = 1;

double const REWIND = 1.0;
double const FAST_FORWARD = 0.25;
double const FAST_REWIND = 0.25;

// ============= Movie =============
Movie::Movie(std::string name = "How to Code", double currentDuration = 0, double totalDuration = 60) :
    name(name),
    currentDuration(currentDuration),
    totalDuration(totalDuration)
{
    std::cout << "Movie created" << std::endl;
}

Movie::~Movie() {
    std::cout << "Movie destroyed" << std::endl;
}

// ============= TVDevice =============
TVDevice::TVDevice(Movie * movie, bool isPlaying, bool isMuted, bool isPowered, int volume, int channel) :
    movie(movie),
    isPlaying(isPlaying),
    isMuted(isMuted),
    isPowered(isPowered),
    volume(volume),
    channel(channel)
{
    std::cout << "TV Device created" << std::endl;
}

TVDevice::~TVDevice() {
    std::cout << "TV Device destroyed" << std::endl;
}

// ============= RadioDevice =============
RadioDevice::RadioDevice(bool isMuted, bool isPowered, int volume, int channel) :
    isPowered(isPowered),
    volume(volume),
    channel(channel)
{
    std::cout << "Radio Device created" << std::endl;
}

RadioDevice::~RadioDevice() {
    std::cout << "Radio Device destroyed" << std::endl;
}

// ============= Abstraction =============
Remote::Remote(Device * device) :
    device(device)
{
    std::cout << "Remote Device created" << std::endl;
}

Remote::~Remote() {
    std::cout << "Remote Device destroyed" << std::endl;
}

// turns the power on/off
bool Remote::TogglePower(Device * device) {
    if(device->GetPower()) {
        device->SetPower(State::OFF);
        std::cout << "Remote Device is OFF" << std::endl;
    }
    else {
        device->SetPower(State::ON);
        std::cout << "Remote Device is ON" << std::endl;
    }
        
    return device->GetPower();
}

// turns the volume on/off
bool Remote::ToggleMute(Device * device) {
    if(device->GetIsMuted()) {
        device->SetIsMuted(State::OFF);
        std::cout << "Remote Device is UNMUTED" << std::endl;
    }
    else {
        device->SetIsMuted(State::ON);
        std::cout << "Remote Device is MUTED" << std::endl;
    }
        
    return device->GetIsMuted();
}

// increases volume by one and check if not over maximum volume
int Remote::VolumeUp(Device * device)
{
    if(device->GetVolume() < MAXIMUM_VOLUME) {
        device->SetVolume(device->GetVolume() + 1);
    }

    return device->GetVolume();
}   

// decreases volume by one and check if not over minimum volume
int Remote::VolumeDown(Device * device) {
    if(device->GetVolume() > MINIMUM_VOLUME) {
        device->SetVolume(device->GetVolume() - 1);
    }

    return device->GetVolume();
}

// increases channel by one and check if not over maximum channel
int Remote::ChannelUp(Device * device) {
    if(device->GetChannel() < MAXIMUM_CHANNEL) {
        device->SetChannel(device->GetChannel() + 1);
    }

    return device->GetChannel();
}

// decrease channel by one and check if not over minimum channel
int Remote::ChannelDown(Device * device) {
    if(device->GetChannel() > MINIMUM_CHANNEL) {
        device->SetChannel(device->GetChannel() - 1);
    }

    return device->GetChannel();
}

// ============= Redefined Abstraction =============
TVRemote::TVRemote(Device * device) :
    Remote(device)
{
    std::cout << "TV Remote Device created" << std::endl;
}

TVRemote::~TVRemote() {
    std::cout << "TV Remote Device destroyed" << std::endl;
}

bool TVRemote::TogglePower(Device * device) {
    if(device->GetPower()) {
        device->SetPower(State::OFF);
        std::cout << "TV Remote Device is OFF" << std::endl;
    }
    else {
        device->SetPower(State::ON);
        std::cout << "TV Remote Device is ON" << std::endl;
    }
        
    return device->GetPower();
}

bool TVRemote::ToggleMute(Device * device)
{
    if(device->GetIsMuted()) {
        device->SetIsMuted(State::OFF);
        std::cout << "Remote Device is UNMUTED" << std::endl;
    }
    else {
        device->SetIsMuted(State::ON);
        std::cout << "Remote Device is MUTED" << std::endl;
    }
        
    return device->GetIsMuted();
}

int TVRemote::VolumeUp(Device * device)
{
    if(device->GetVolume() < MAXIMUM_VOLUME) {
        device->SetVolume(device->GetVolume() + 1);
    }

    return device->GetVolume();
}

int TVRemote::VolumeDown(Device * device)
{
    if(device->GetVolume() > MINIMUM_VOLUME) {
        device->SetVolume(device->GetVolume() - 1);
    }

    return device->GetVolume();
}

int TVRemote::ChannelUp(Device * device) {
    if(device->GetChannel() < MAXIMUM_CHANNEL) {
        device->SetChannel(device->GetChannel() + 1);
    }

    return device->GetChannel();
}

int TVRemote::ChannelDown(Device * device) {
    if(device->GetChannel() > MINIMUM_CHANNEL) {
        device->SetChannel(device->GetChannel() - 1);
    }

    return device->GetChannel();
}

bool TVRemote::TogglePlay(Device * device)
{
    TVDevice * tvDevice = dynamic_cast<TVDevice *>(device);

    if(tvDevice->GetIsPlaying()) {
        tvDevice->SetIsPlaying(State::OFF);
        std::cout << "TVDevice is NOT PLAYING" << std::endl;
    }
    else {
        tvDevice->SetIsPlaying(State::ON);
        std::cout << "TVDevice is PLAYING" << std::endl;
    }

    return tvDevice->GetIsPlaying();
}

// rewinds 1/4 of a minute 
double TVRemote::FastRewind(Device * device) {
    TVDevice * tvDevice = dynamic_cast<TVDevice *>(device);
    
    // edge case
    if(0 > tvDevice->GetMovie()->GetCurrentDuration() - FAST_REWIND) {
        tvDevice->GetMovie()->SetCurrentDuration(0);
    } 
    else {
        tvDevice->GetMovie()->SetCurrentDuration(tvDevice->GetMovie()->GetCurrentDuration() - FAST_REWIND);
    }

    return tvDevice->GetMovie()->GetCurrentDuration();
}

// rewinds 1 minute
double TVRemote::Rewind(Device * device) {   
    TVDevice * tvDevice = dynamic_cast<TVDevice *>(device);
    
    // edge case
    if(0 > tvDevice->GetMovie()->GetCurrentDuration() - REWIND) {
        tvDevice->GetMovie()->SetCurrentDuration(0);
    } 
    else {
        tvDevice->GetMovie()->SetCurrentDuration(tvDevice->GetMovie()->GetCurrentDuration() - REWIND);
    }

    return tvDevice->GetMovie()->GetCurrentDuration();
}

// skips 1/4 of a minute
double TVRemote::FastForward(Device * device)
{
    TVDevice * tvDevice = dynamic_cast<TVDevice *>(device);

    // edge case
    if(tvDevice->GetMovie()->GetTotalDuration() < tvDevice->GetMovie()->GetCurrentDuration() + FAST_FORWARD) {
        tvDevice->GetMovie()->SetCurrentDuration(tvDevice->GetMovie()->GetTotalDuration());
    }
    else {
        tvDevice->GetMovie()->SetCurrentDuration(tvDevice->GetMovie()->GetCurrentDuration() + FAST_FORWARD);
    }

    return tvDevice->GetMovie()->GetCurrentDuration();
}

// =============== Client Code ===============
// increases/decreases channel to requested new channel
static void ChangeChannelTo(Remote * remote, int changeChannelTo)
{
    do
    {
        if(remote->GetDevice()->GetChannel() < changeChannelTo)
            remote->GetDevice()->SetChannel(remote->ChannelUp(remote->GetDevice()));
        else
            remote->GetDevice()->SetChannel(remote->ChannelDown(remote->GetDevice()));

        std::cout << remote->GetDevice()->GetChannel() << std::endl;
    }
    while(remote->GetDevice()->GetChannel() != changeChannelTo);
}

// increases/decreases volume to requested new volume
static void ChangeVolumeTo(Remote * remote, int changeVolumeTo)
{
    do
    {
        if(remote->GetDevice()->GetVolume() < changeVolumeTo)
            remote->GetDevice()->SetVolume(remote->VolumeUp(remote->GetDevice()));
        else
            remote->GetDevice()->SetVolume(remote->VolumeDown(remote->GetDevice()));

        std::cout << remote->GetDevice()->GetVolume() << std::endl;
    }
    while(remote->GetDevice()->GetVolume() != changeVolumeTo);
}

// =============== Main ===============
int main()
{
    Device * radioDevice = new RadioDevice();
    Remote * radioRemote = new Remote(radioDevice);

    radioRemote->TogglePower(radioRemote->GetDevice());
    radioRemote->ToggleMute(radioRemote->GetDevice());
    ChangeVolumeTo(radioRemote, 4);
    ChangeChannelTo(radioRemote, 10);

    delete radioDevice;
    delete radioRemote;

    Movie * movie = new Movie("C++ is Awesome: The Movie", 50, 90);
    TVDevice * tvDevice = new TVDevice(movie);
    TVRemote * tvRemote = new TVRemote(tvDevice);
 
    tvRemote->TogglePower(tvRemote->GetDevice());
    tvRemote->ToggleMute(tvRemote->GetDevice());
    tvRemote->TogglePlay(tvRemote->GetDevice());
    ChangeVolumeTo(tvRemote, 7);
    ChangeChannelTo(tvRemote, 50);

    // changing movie time
    tvRemote->FastRewind(tvDevice);
    std::cout << "Current device: " << tvDevice->GetMovie()->GetCurrentDuration() << std::endl;
    tvRemote->FastForward(tvDevice);
    std::cout << "Current device: " << tvDevice->GetMovie()->GetCurrentDuration() << std::endl;
    tvRemote->Rewind(tvDevice);
    std::cout << "Current device: " << tvDevice->GetMovie()->GetCurrentDuration() << std::endl;

    delete movie;
    delete tvDevice;
    delete tvRemote;

    return 0;
}