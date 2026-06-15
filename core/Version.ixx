export module Version;
import TheMsg;

export struct Version {
	int major, minor, patch, _;
	Version(int major, int minor, int patch) :major(major), minor(minor), patch(patch) {}
	Version(const Version &x) :major(x.major), minor(x.minor), patch(x.patch) {}
};
export const Version theVersion { the_Version[0], the_Version[1], the_Version[2] };