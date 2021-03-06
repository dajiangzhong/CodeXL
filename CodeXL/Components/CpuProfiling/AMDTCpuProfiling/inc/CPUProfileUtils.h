//==================================================================================
// Copyright (c) 2013-2016 , Advanced Micro Devices, Inc.  All rights reserved.
//
/// \author AMD Developer Tools Team
/// \file CPUProfileUtils.h
///
//==================================================================================

#ifndef __CPUPROFILEUTILS_H
#define __CPUPROFILEUTILS_H

#include <QStringList>

// AMDTCpuPerfEventUtils:
#include <AMDTCpuPerfEventUtils/inc/EventsFile.h>
#include <AMDTCpuPerfEventUtils/inc/ViewConfig.h>
#include <AMDTCpuPerfEventUtils/inc/IbsEvents.h>


// The list of events for which higher sample value is better
const unsigned int EventsBetterHigher[] =
{
    DE_IBS_CLU_PERCENTAGE,
    DE_IBS_CLU_BYTE_PER_EVICT,
    DE_IBS_CLU_ACCESS_PER_EVICT
};

// Suffix in column caption used to specify  that higher sample value is better
#define SUFFIX_HOTSPOT_BETTER_HIGH    " (Higher is better)"

/// -----------------------------------------------------------------------------------------------
/// \class Name: CPUProfileUtils
/// \brief Description:  This class is used to implement general utilities used by all CPU profile vies
/// -----------------------------------------------------------------------------------------------
class CPUProfileUtils
{
public:
    /// \brief Name:        addDataArrays
    /// \brief Description: Utility: add 2 data arrays
    /// \param[in]          pDestArray - the destination array
    /// \param[in]          pSourceArray - the source array
    static void AddDataArrays(gtVector<float>& destVector, const gtVector<float>& sourceVector) ;

    /// Return the column full name according to the column type and title:
    /// \param[in]          colType the requested column type
    /// \param[in]          colType the requested column title
    /// \param[in]          hwEvent the matching event details
    /// \param[in]          the postfix of the column (can contain NUMA node or core details)
    static QString GetColumnFullName(ColumnType colType, const QString& title, const CpuEvent& hwEvent, const QString& postfix);

    /// Returns true if higher sample value is better for the hot spot, false otherwise
    /// \param[in]          pEventsFile the reference to the object of class EventsFile
    /// \param[in]          hotSpotCaption the hot spot indicator caption
    static bool IsHotSpotBetterHigher(EventsFile* pEventsFile, const QString& hotSpotCaption);

    /// Returns true if the hot spot is a CLU metric, false otherwise
    /// \param[in]          pEventsFile the reference to the object of class EventsFile
    /// \param[in]          hotSpotCaption the hot spot indicator caption
    static bool IsHotSpotCluMetric(EventsFile* pEventsFile, const QString& hotSpotCaption);

    // List of strings (name/abbreviation/caption) related to the events for which higher sample value is better
    static QStringList m_hotSpotsBetterHigher;

    // List of hot spot captions of all CLU metrics
    static QStringList m_hotSpotsCluMetric;
};

#endif //__CPUPROFILEUTILS_H
