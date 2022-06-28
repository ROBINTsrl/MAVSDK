// WARNING: THIS FILE IS AUTOGENERATED! As such, it should not be edited.
// Edits need to be made to the proto files
// (see https://github.com/mavlink/MAVSDK-Proto/blob/master/protos/transponder/transponder.proto)

#include "transponder/transponder.grpc.pb.h"
#include "plugins/transponder/transponder.h"

#include "mavsdk.h"

#include "lazy_plugin.h"

#include "log.h"
#include <atomic>
#include <cmath>
#include <future>
#include <limits>
#include <memory>
#include <sstream>
#include <vector>

namespace mavsdk {
namespace mavsdk_server {

template<typename Transponder = Transponder, typename LazyPlugin = LazyPlugin<Transponder>>

class TransponderServiceImpl final : public rpc::transponder::TransponderService::Service {
public:
    TransponderServiceImpl(LazyPlugin& lazy_plugin) : _lazy_plugin(lazy_plugin) {}

    template<typename ResponseType>
    void fillResponseWithResult(ResponseType* response, mavsdk::Transponder::Result& result) const
    {
        auto rpc_result = translateToRpcResult(result);

        auto* rpc_transponder_result = new rpc::transponder::TransponderResult();
        rpc_transponder_result->set_result(rpc_result);
        std::stringstream ss;
        ss << result;
        rpc_transponder_result->set_result_str(ss.str());

        response->set_allocated_transponder_result(rpc_transponder_result);
    }

    static rpc::transponder::AdsbEmitterType
    translateToRpcAdsbEmitterType(const mavsdk::Transponder::AdsbEmitterType& adsb_emitter_type)
    {
        switch (adsb_emitter_type) {
            default:
                LogErr() << "Unknown adsb_emitter_type enum value: "
                         << static_cast<int>(adsb_emitter_type);
            // FALLTHROUGH
            case mavsdk::Transponder::AdsbEmitterType::NoInfo:
                return rpc::transponder::ADSB_EMITTER_TYPE_NO_INFO;
            case mavsdk::Transponder::AdsbEmitterType::Light:
                return rpc::transponder::ADSB_EMITTER_TYPE_LIGHT;
            case mavsdk::Transponder::AdsbEmitterType::Small:
                return rpc::transponder::ADSB_EMITTER_TYPE_SMALL;
            case mavsdk::Transponder::AdsbEmitterType::Large:
                return rpc::transponder::ADSB_EMITTER_TYPE_LARGE;
            case mavsdk::Transponder::AdsbEmitterType::HighVortexLarge:
                return rpc::transponder::ADSB_EMITTER_TYPE_HIGH_VORTEX_LARGE;
            case mavsdk::Transponder::AdsbEmitterType::Heavy:
                return rpc::transponder::ADSB_EMITTER_TYPE_HEAVY;
            case mavsdk::Transponder::AdsbEmitterType::HighlyManuv:
                return rpc::transponder::ADSB_EMITTER_TYPE_HIGHLY_MANUV;
            case mavsdk::Transponder::AdsbEmitterType::Rotocraft:
                return rpc::transponder::ADSB_EMITTER_TYPE_ROTOCRAFT;
            case mavsdk::Transponder::AdsbEmitterType::Unassigned:
                return rpc::transponder::ADSB_EMITTER_TYPE_UNASSIGNED;
            case mavsdk::Transponder::AdsbEmitterType::Glider:
                return rpc::transponder::ADSB_EMITTER_TYPE_GLIDER;
            case mavsdk::Transponder::AdsbEmitterType::LighterAir:
                return rpc::transponder::ADSB_EMITTER_TYPE_LIGHTER_AIR;
            case mavsdk::Transponder::AdsbEmitterType::Parachute:
                return rpc::transponder::ADSB_EMITTER_TYPE_PARACHUTE;
            case mavsdk::Transponder::AdsbEmitterType::UltraLight:
                return rpc::transponder::ADSB_EMITTER_TYPE_ULTRA_LIGHT;
            case mavsdk::Transponder::AdsbEmitterType::Unassigned2:
                return rpc::transponder::ADSB_EMITTER_TYPE_UNASSIGNED2;
            case mavsdk::Transponder::AdsbEmitterType::Uav:
                return rpc::transponder::ADSB_EMITTER_TYPE_UAV;
            case mavsdk::Transponder::AdsbEmitterType::Space:
                return rpc::transponder::ADSB_EMITTER_TYPE_SPACE;
            case mavsdk::Transponder::AdsbEmitterType::Unassgined3:
                return rpc::transponder::ADSB_EMITTER_TYPE_UNASSGINED3;
            case mavsdk::Transponder::AdsbEmitterType::EmergencySurface:
                return rpc::transponder::ADSB_EMITTER_TYPE_EMERGENCY_SURFACE;
            case mavsdk::Transponder::AdsbEmitterType::ServiceSurface:
                return rpc::transponder::ADSB_EMITTER_TYPE_SERVICE_SURFACE;
            case mavsdk::Transponder::AdsbEmitterType::PointObstacle:
                return rpc::transponder::ADSB_EMITTER_TYPE_POINT_OBSTACLE;
        }
    }

    static mavsdk::Transponder::AdsbEmitterType
    translateFromRpcAdsbEmitterType(const rpc::transponder::AdsbEmitterType adsb_emitter_type)
    {
        switch (adsb_emitter_type) {
            default:
                LogErr() << "Unknown adsb_emitter_type enum value: "
                         << static_cast<int>(adsb_emitter_type);
            // FALLTHROUGH
            case rpc::transponder::ADSB_EMITTER_TYPE_NO_INFO:
                return mavsdk::Transponder::AdsbEmitterType::NoInfo;
            case rpc::transponder::ADSB_EMITTER_TYPE_LIGHT:
                return mavsdk::Transponder::AdsbEmitterType::Light;
            case rpc::transponder::ADSB_EMITTER_TYPE_SMALL:
                return mavsdk::Transponder::AdsbEmitterType::Small;
            case rpc::transponder::ADSB_EMITTER_TYPE_LARGE:
                return mavsdk::Transponder::AdsbEmitterType::Large;
            case rpc::transponder::ADSB_EMITTER_TYPE_HIGH_VORTEX_LARGE:
                return mavsdk::Transponder::AdsbEmitterType::HighVortexLarge;
            case rpc::transponder::ADSB_EMITTER_TYPE_HEAVY:
                return mavsdk::Transponder::AdsbEmitterType::Heavy;
            case rpc::transponder::ADSB_EMITTER_TYPE_HIGHLY_MANUV:
                return mavsdk::Transponder::AdsbEmitterType::HighlyManuv;
            case rpc::transponder::ADSB_EMITTER_TYPE_ROTOCRAFT:
                return mavsdk::Transponder::AdsbEmitterType::Rotocraft;
            case rpc::transponder::ADSB_EMITTER_TYPE_UNASSIGNED:
                return mavsdk::Transponder::AdsbEmitterType::Unassigned;
            case rpc::transponder::ADSB_EMITTER_TYPE_GLIDER:
                return mavsdk::Transponder::AdsbEmitterType::Glider;
            case rpc::transponder::ADSB_EMITTER_TYPE_LIGHTER_AIR:
                return mavsdk::Transponder::AdsbEmitterType::LighterAir;
            case rpc::transponder::ADSB_EMITTER_TYPE_PARACHUTE:
                return mavsdk::Transponder::AdsbEmitterType::Parachute;
            case rpc::transponder::ADSB_EMITTER_TYPE_ULTRA_LIGHT:
                return mavsdk::Transponder::AdsbEmitterType::UltraLight;
            case rpc::transponder::ADSB_EMITTER_TYPE_UNASSIGNED2:
                return mavsdk::Transponder::AdsbEmitterType::Unassigned2;
            case rpc::transponder::ADSB_EMITTER_TYPE_UAV:
                return mavsdk::Transponder::AdsbEmitterType::Uav;
            case rpc::transponder::ADSB_EMITTER_TYPE_SPACE:
                return mavsdk::Transponder::AdsbEmitterType::Space;
            case rpc::transponder::ADSB_EMITTER_TYPE_UNASSGINED3:
                return mavsdk::Transponder::AdsbEmitterType::Unassgined3;
            case rpc::transponder::ADSB_EMITTER_TYPE_EMERGENCY_SURFACE:
                return mavsdk::Transponder::AdsbEmitterType::EmergencySurface;
            case rpc::transponder::ADSB_EMITTER_TYPE_SERVICE_SURFACE:
                return mavsdk::Transponder::AdsbEmitterType::ServiceSurface;
            case rpc::transponder::ADSB_EMITTER_TYPE_POINT_OBSTACLE:
                return mavsdk::Transponder::AdsbEmitterType::PointObstacle;
        }
    }

    static rpc::transponder::AdsbAltitudeType
    translateToRpcAdsbAltitudeType(const mavsdk::Transponder::AdsbAltitudeType& adsb_altitude_type)
    {
        switch (adsb_altitude_type) {
            default:
                LogErr() << "Unknown adsb_altitude_type enum value: "
                         << static_cast<int>(adsb_altitude_type);
            // FALLTHROUGH
            case mavsdk::Transponder::AdsbAltitudeType::PressureQnh:
                return rpc::transponder::ADSB_ALTITUDE_TYPE_PRESSURE_QNH;
            case mavsdk::Transponder::AdsbAltitudeType::Geometric:
                return rpc::transponder::ADSB_ALTITUDE_TYPE_GEOMETRIC;
        }
    }

    static mavsdk::Transponder::AdsbAltitudeType
    translateFromRpcAdsbAltitudeType(const rpc::transponder::AdsbAltitudeType adsb_altitude_type)
    {
        switch (adsb_altitude_type) {
            default:
                LogErr() << "Unknown adsb_altitude_type enum value: "
                         << static_cast<int>(adsb_altitude_type);
            // FALLTHROUGH
            case rpc::transponder::ADSB_ALTITUDE_TYPE_PRESSURE_QNH:
                return mavsdk::Transponder::AdsbAltitudeType::PressureQnh;
            case rpc::transponder::ADSB_ALTITUDE_TYPE_GEOMETRIC:
                return mavsdk::Transponder::AdsbAltitudeType::Geometric;
        }
    }

    static std::unique_ptr<rpc::transponder::AdsbVehicle>
    translateToRpcAdsbVehicle(const mavsdk::Transponder::AdsbVehicle& adsb_vehicle)
    {
        auto rpc_obj = std::make_unique<rpc::transponder::AdsbVehicle>();

        rpc_obj->set_icao_address(adsb_vehicle.icao_address);

        rpc_obj->set_latitude_deg(adsb_vehicle.latitude_deg);

        rpc_obj->set_longitude_deg(adsb_vehicle.longitude_deg);

        rpc_obj->set_altitude_type(translateToRpcAdsbAltitudeType(adsb_vehicle.altitude_type));

        rpc_obj->set_absolute_altitude_m(adsb_vehicle.absolute_altitude_m);

        rpc_obj->set_heading_deg(adsb_vehicle.heading_deg);

        rpc_obj->set_horizontal_velocity_m_s(adsb_vehicle.horizontal_velocity_m_s);

        rpc_obj->set_vertical_velocity_m_s(adsb_vehicle.vertical_velocity_m_s);

        rpc_obj->set_callsign(adsb_vehicle.callsign);

        rpc_obj->set_emitter_type(translateToRpcAdsbEmitterType(adsb_vehicle.emitter_type));

        rpc_obj->set_squawk(adsb_vehicle.squawk);

        rpc_obj->set_tslc_s(adsb_vehicle.tslc_s);

        return rpc_obj;
    }

    static mavsdk::Transponder::AdsbVehicle
    translateFromRpcAdsbVehicle(const rpc::transponder::AdsbVehicle& adsb_vehicle)
    {
        mavsdk::Transponder::AdsbVehicle obj;

        obj.icao_address = adsb_vehicle.icao_address();

        obj.latitude_deg = adsb_vehicle.latitude_deg();

        obj.longitude_deg = adsb_vehicle.longitude_deg();

        obj.altitude_type = translateFromRpcAdsbAltitudeType(adsb_vehicle.altitude_type());

        obj.absolute_altitude_m = adsb_vehicle.absolute_altitude_m();

        obj.heading_deg = adsb_vehicle.heading_deg();

        obj.horizontal_velocity_m_s = adsb_vehicle.horizontal_velocity_m_s();

        obj.vertical_velocity_m_s = adsb_vehicle.vertical_velocity_m_s();

        obj.callsign = adsb_vehicle.callsign();

        obj.emitter_type = translateFromRpcAdsbEmitterType(adsb_vehicle.emitter_type());

        obj.squawk = adsb_vehicle.squawk();

        obj.tslc_s = adsb_vehicle.tslc_s();

        return obj;
    }

    static rpc::transponder::TransponderResult::Result
    translateToRpcResult(const mavsdk::Transponder::Result& result)
    {
        switch (result) {
            default:
                LogErr() << "Unknown result enum value: " << static_cast<int>(result);
            // FALLTHROUGH
            case mavsdk::Transponder::Result::Unknown:
                return rpc::transponder::TransponderResult_Result_RESULT_UNKNOWN;
            case mavsdk::Transponder::Result::Success:
                return rpc::transponder::TransponderResult_Result_RESULT_SUCCESS;
            case mavsdk::Transponder::Result::NoSystem:
                return rpc::transponder::TransponderResult_Result_RESULT_NO_SYSTEM;
            case mavsdk::Transponder::Result::ConnectionError:
                return rpc::transponder::TransponderResult_Result_RESULT_CONNECTION_ERROR;
            case mavsdk::Transponder::Result::Busy:
                return rpc::transponder::TransponderResult_Result_RESULT_BUSY;
            case mavsdk::Transponder::Result::CommandDenied:
                return rpc::transponder::TransponderResult_Result_RESULT_COMMAND_DENIED;
            case mavsdk::Transponder::Result::Timeout:
                return rpc::transponder::TransponderResult_Result_RESULT_TIMEOUT;
        }
    }

    static mavsdk::Transponder::Result
    translateFromRpcResult(const rpc::transponder::TransponderResult::Result result)
    {
        switch (result) {
            default:
                LogErr() << "Unknown result enum value: " << static_cast<int>(result);
            // FALLTHROUGH
            case rpc::transponder::TransponderResult_Result_RESULT_UNKNOWN:
                return mavsdk::Transponder::Result::Unknown;
            case rpc::transponder::TransponderResult_Result_RESULT_SUCCESS:
                return mavsdk::Transponder::Result::Success;
            case rpc::transponder::TransponderResult_Result_RESULT_NO_SYSTEM:
                return mavsdk::Transponder::Result::NoSystem;
            case rpc::transponder::TransponderResult_Result_RESULT_CONNECTION_ERROR:
                return mavsdk::Transponder::Result::ConnectionError;
            case rpc::transponder::TransponderResult_Result_RESULT_BUSY:
                return mavsdk::Transponder::Result::Busy;
            case rpc::transponder::TransponderResult_Result_RESULT_COMMAND_DENIED:
                return mavsdk::Transponder::Result::CommandDenied;
            case rpc::transponder::TransponderResult_Result_RESULT_TIMEOUT:
                return mavsdk::Transponder::Result::Timeout;
        }
    }

    grpc::Status SubscribeTransponder(
        grpc::ServerContext* /* context */,
        const mavsdk::rpc::transponder::SubscribeTransponderRequest* /* request */,
        grpc::ServerWriter<rpc::transponder::TransponderResponse>* writer) override
    {
        if (_lazy_plugin.maybe_plugin() == nullptr) {
            return grpc::Status::OK;
        }

        auto stream_closed_promise = std::make_shared<std::promise<void>>();
        auto stream_closed_future = stream_closed_promise->get_future();
        register_stream_stop_promise(stream_closed_promise);

        auto is_finished = std::make_shared<bool>(false);
        auto subscribe_mutex = std::make_shared<std::mutex>();

        _lazy_plugin.maybe_plugin()->subscribe_transponder(
            [this, &writer, &stream_closed_promise, is_finished, subscribe_mutex](
                const mavsdk::Transponder::AdsbVehicle transponder) {
                rpc::transponder::TransponderResponse rpc_response;

                rpc_response.set_allocated_transponder(
                    translateToRpcAdsbVehicle(transponder).release());

                std::unique_lock<std::mutex> lock(*subscribe_mutex);
                if (!*is_finished && !writer->Write(rpc_response)) {
                    _lazy_plugin.maybe_plugin()->subscribe_transponder(nullptr);

                    *is_finished = true;
                    unregister_stream_stop_promise(stream_closed_promise);
                    stream_closed_promise->set_value();
                }
            });

        stream_closed_future.wait();
        std::unique_lock<std::mutex> lock(*subscribe_mutex);
        *is_finished = true;

        return grpc::Status::OK;
    }

    grpc::Status SetRateTransponder(
        grpc::ServerContext* /* context */,
        const rpc::transponder::SetRateTransponderRequest* request,
        rpc::transponder::SetRateTransponderResponse* response) override
    {
        if (_lazy_plugin.maybe_plugin() == nullptr) {
            if (response != nullptr) {
                auto result = mavsdk::Transponder::Result::NoSystem;
                fillResponseWithResult(response, result);
            }

            return grpc::Status::OK;
        }

        if (request == nullptr) {
            LogWarn() << "SetRateTransponder sent with a null request! Ignoring...";
            return grpc::Status::OK;
        }

        auto result = _lazy_plugin.maybe_plugin()->set_rate_transponder(request->rate_hz());

        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }

        return grpc::Status::OK;
    }

    void stop()
    {
        _stopped.store(true);
        for (auto& prom : _stream_stop_promises) {
            if (auto handle = prom.lock()) {
                handle->set_value();
            }
        }
    }

private:
    void register_stream_stop_promise(std::weak_ptr<std::promise<void>> prom)
    {
        // If we have already stopped, set promise immediately and don't add it to list.
        if (_stopped.load()) {
            if (auto handle = prom.lock()) {
                handle->set_value();
            }
        } else {
            _stream_stop_promises.push_back(prom);
        }
    }

    void unregister_stream_stop_promise(std::shared_ptr<std::promise<void>> prom)
    {
        for (auto it = _stream_stop_promises.begin(); it != _stream_stop_promises.end();
             /* ++it */) {
            if (it->lock() == prom) {
                it = _stream_stop_promises.erase(it);
            } else {
                ++it;
            }
        }
    }

    LazyPlugin& _lazy_plugin;

    std::atomic<bool> _stopped{false};
    std::vector<std::weak_ptr<std::promise<void>>> _stream_stop_promises{};
};

} // namespace mavsdk_server
} // namespace mavsdk