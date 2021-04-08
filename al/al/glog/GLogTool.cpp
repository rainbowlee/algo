#include "GLogTool.h"


using namespace google;
void GLogTool::InitGLog()
{
	google::InitGoogleLogging("al");
	FLAGS_log_dir = "./log";
	FLAGS_minloglevel = GLOG_INFO;
	FLAGS_alsologtostderr = true;
	FLAGS_max_log_size = 100;
	FLAGS_logbufsecs = 0;
	FLAGS_stop_logging_if_full_disk = true;
	FLAGS_colorlogtostderr = true;
	google::SetLogFilenameExtension("log_");

	LOG(INFO) << "Init Glog";
	LOG(ERROR) << "Init Glog2" << std::endl;
}