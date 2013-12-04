__author__ = 'WLH'
# -*- coding: UTF-8 –*-

class ModuleInfo(object):
    def __init__(self):
        self.Name = ''
        self.Priority = ''
        self.StackSize = ''
        self.MsgQue = ''
        self.Desc = ''

    def Dump(self):
        print '------------------ModuleInfo---------------------'
        print 'Name=' + self.Name
        print 'Priority=' + self.Priority
        print 'StackSize=' + self.StackSize
        print 'MsgQue=' + self.MsgQue
        print 'Desc=' + self.Desc
        print '---------------------end-------------------------'
