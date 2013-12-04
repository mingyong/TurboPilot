__author__ = 'WLH'
# -*- coding: UTF-8 –*-

class UavObject(object):
    def __init__(self):
        self.Name = ''
        self.GcsAccess = 'rw'
        self.FlightAccess = 'rw'
        self.Desc = ''
        self.MemberList = []
        self.InstCnt = 1
        self.TypeID = 0xFF
        self.Setting = "FALSE"

    def Dump(self):
        print '--------------------------UavObject---------------------------'
        print "Name=" + self.Name
        print "Desc=" + self.Desc
        print "GcsAccess=" + self.GcsAccess
        print "FlightAccess=" + self.FlightAccess
        print "InstCnt" + str( self.InstCnt )
        for item in self.MemberList:
            item.Dump()
        print '------------------------------end-------------------------------'


class MemberInfo(object):
    def __init__(self):
        self.Name = ''
        self.Type = ''
        self.Unit = ''
        self.Note = ''
        self.Elements = ''

    def Dump(self):
        print '------------MemberInfo-------------'
        print  "Name =" + self.Name
        print  "Type =" + self.Type
        print  "Units =" + self.Unit
        print  "Note =" + self.Note
        print  "Elements =" + self.Elements
        print '---------------end------------------'
