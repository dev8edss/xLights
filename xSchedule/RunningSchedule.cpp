#include "RunningSchedule.h"
#include "Schedule.h"
#include "PlayList/PlayList.h"
#include <log4cpp/Category.hh>

RunningSchedule::RunningSchedule(PlayList* playlist, Schedule* schedule)
{
    _playlist = new PlayList(*playlist);
    _schedule = new Schedule(*schedule);

    //static log4cpp::Category &logger_base = log4cpp::Category::getInstance(std::string("log_base"));
    //logger_base.info("Running schedule create containing Playlist %s and Schedule %s 0x%lx.", (const char*)GetPlayList()->GetName().c_str(), (const char*)GetSchedule()->GetName().c_str(), this);
}

RunningSchedule::~RunningSchedule()
{
    //static log4cpp::Category &logger_base = log4cpp::Category::getInstance(std::string("log_base"));
    //logger_base.info("Running schedule containing Playlist %s and Schedule %s being destroyed 0x%lx.", (const char*)GetPlayList()->GetName().c_str(), (const char*)GetSchedule()->GetName().c_str(), this);

    _playlist->Stop();

    delete _playlist;
    _playlist = nullptr;
    delete _schedule;
    _schedule = nullptr;
}

bool RunningSchedule::operator<(const RunningSchedule& rs) const
{
    return *_schedule < *rs._schedule;
}
