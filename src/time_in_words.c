#include "time_in_words.h"

char* distance_of_time_in_words(uint64_t from_time, uint64_t to_time)
{
  enum { buffer_size = 1024 };
  char buffer[buffer_size];

  if (from_time > to_time) {
    uint64_t tmp = from_time;
    from_time = to_time;
    to_time = tmp;
  }

  uint64_t distance_in_minutes = (uint64_t)((to_time - from_time)/60.0);
  uint64_t distance_in_seconds = (to_time - from_time)

  if (distance_in_minutes == 0) {
    int written = snprintf(buffer, buffer_size, "Less than %d minutes", distance_in_minutes)
         ...);
    case distance_in_minutes
            when 0..1
              return distance_in_minutes == 0 ?
                     locale.t(:less_than_x_minutes, :count => 1) :
                     locale.t(:x_minutes, :count => distance_in_minutes) unless options[:include_seconds]
  }

          

              case distance_in_seconds
                when 0..4   then locale.t :less_than_x_seconds, :count => 5
                when 5..9   then locale.t :less_than_x_seconds, :count => 10
                when 10..19 then locale.t :less_than_x_seconds, :count => 20
                when 20..39 then locale.t :half_a_minute
                when 40..59 then locale.t :less_than_x_minutes, :count => 1
                else             locale.t :x_minutes,           :count => 1
              end

            when 2...45           then locale.t :x_minutes,      :count => distance_in_minutes
            when 45...90          then locale.t :about_x_hours,  :count => 1
            # 90 mins up to 24 hours
            when 90...1440        then locale.t :about_x_hours,  :count => (distance_in_minutes.to_f / 60.0).round
            # 24 hours up to 42 hours
            when 1440...2520      then locale.t :x_days,         :count => 1
            # 42 hours up to 30 days
            when 2520...43200     then locale.t :x_days,         :count => (distance_in_minutes.to_f / 1440.0).round
            # 30 days up to 60 days
            when 43200...86400    then locale.t :about_x_months, :count => (distance_in_minutes.to_f / 43200.0).round
            # 60 days up to 365 days
            when 86400...525600   then locale.t :x_months,       :count => (distance_in_minutes.to_f / 43200.0).round
            else
              if from_time.acts_like?(:time) && to_time.acts_like?(:time)
                fyear = from_time.year
                fyear += 1 if from_time.month >= 3
                tyear = to_time.year
                tyear -= 1 if to_time.month < 3
                leap_years = (fyear > tyear) ? 0 : (fyear..tyear).count{|x| Date.leap?(x)}
                minute_offset_for_leap_year = leap_years * 1440
                # Discount the leap year days when calculating year distance.
                # e.g. if there are 20 leap year days between 2 dates having the same day
                # and month then the based on 365 days calculation
                # the distance in years will come out to over 80 years when in written
                # english it would read better as about 80 years.
                minutes_with_offset = distance_in_minutes - minute_offset_for_leap_year
              else
                minutes_with_offset = distance_in_minutes
              end
              remainder                   = (minutes_with_offset % 525600)
              distance_in_years           = (minutes_with_offset.div 525600)
              if remainder < 131400
                locale.t(:about_x_years,  :count => distance_in_years)
              elsif remainder < 394200
                locale.t(:over_x_years,   :count => distance_in_years)
              else
                locale.t(:almost_x_years, :count => distance_in_years + 1)
              end
          end
        end
      end