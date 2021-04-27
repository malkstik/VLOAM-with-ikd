#pragma once

#include <lidar_odometry_mapping/scan_registration.h>
#include <lidar_odometry_mapping/laser_odometry.h>
#include <lidar_odometry_mapping/laser_mapping.h>

namespace vloam {

    class LidarOdometryMapping {
        public:
            void init(ros::NodeHandle* nh_);

            void reset();

            void scanRegistrationIO(const pcl::PointCloud<pcl::PointXYZ>& laserCloudIn);
            void laserOdometryIO();
            void laserMappingIO();
        
        private:
            ros::NodeHandle* nh;
            int verbose_level;

            TicToc loam_timer;
            double frame_time; 

            ScanRegistration scan_registration;
            pcl::PointCloud<PointType>::Ptr laserCloud;
            pcl::PointCloud<PointType>::Ptr cornerPointsSharp;
            pcl::PointCloud<PointType>::Ptr cornerPointsLessSharp;
            pcl::PointCloud<PointType>::Ptr surfPointsFlat;
            pcl::PointCloud<PointType>::Ptr surfPointsLessFlat;

            LaserOdometry laser_odometry;
            Eigen::Quaterniond q_wodom_curr, q_w_curr;
            Eigen::Vector3d t_wodom_curr, t_w_curr;
            pcl::PointCloud<PointType>::Ptr laserCloudCornerLast;
            pcl::PointCloud<PointType>::Ptr laserCloudSurfLast;
            pcl::PointCloud<PointType>::Ptr laserCloudFullRes;
            bool skip_frame;

            LaserMapping laser_mapping;
    };

}